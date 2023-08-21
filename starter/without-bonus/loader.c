#include "loader.h"

Elf32_Ehdr *ehdr;
Elf32_Phdr *phdr;
int fd;

/*
 * release memory and other cleanups
 */
void loader_cleanup() {
  if (ehdr) free(ehdr);
  if (phdr) free(phdr);
  if (fd) fd=0;
}

/*
 * Load and run the ELF executable file
 */
void load_and_run_elf(char** exe) {
  fd = open(exe[0], O_RDONLY);
  unsigned char dump=0;
  // 1. Load entire binary content into the memory from the ELF file.
  Elf32_Ehdr ehdr;
  read(fd,&ehdr,sizeof(Elf32_Ehdr));

  Elf32_Phdr phdr[ehdr.e_phnum];
  lseek(fd,ehdr.e_phoff,SEEK_SET);
  read(fd,phdr,ehdr.e_phentsize*ehdr.e_phnum);

  Elf32_Phdr phdr_entry;
  // 2. Iterate through the PHDR table and find the section of PT_LOAD type that contains the address of the entrypoint method in fib.c
  for(int i=0; i<ehdr.e_phnum;i++){
    if (phdr[i].p_type==PT_LOAD){
      if (phdr[i].p_vaddr<=ehdr.e_entry && ehdr.e_entry<=phdr[i].p_vaddr+phdr[i].p_memsz){
        phdr_entry=phdr[i];
        lseek(fd,phdr[i].p_offset,SEEK_SET);
        break;
      }
    }
  }

  // 3. Allocate memory of the size "p_memsz" using mmap function and then copy the segment content
  void *segment = mmap(NULL, phdr_entry.p_memsz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);
  read(fd,segment,phdr_entry.p_filesz);
  // 4. Navigate to the entrypoint address into the segment loaded in the memory in above step
  // 5. Typecast the address to that of function pointer matching "_start" method in fib.c.
  int (*_start)() =(int(*)())(segment + (ehdr.e_entry - phdr_entry.p_vaddr));
  // 6. Call the "_start" method and print the value returned from the "_start"
  int result = _start();
  printf("User _start return value = %d\n",result);
}

int main(int argc, char** argv) 
{
  if(argc != 2) {
    printf("Usage: %s <ELF Executable> \n",argv[0]);
    exit(1);
  }
  // 1. carry out necessary checks on the input ELF file
  Elf32_Ehdr elf32Ehdr;
  FILE* elf_file = fopen(argv[1], "rb");
  if(elf_file){
      fread(&elf32Ehdr, sizeof(elf32Ehdr), 1, elf_file);
      if (memcmp(elf32Ehdr.e_ident, ELFMAG, SELFMAG) != 0) {printf("This is an invalid elf file\n"); exit(1);}
      fclose(elf_file);
  }
  // 2. passing it to the loader for carrying out the loading/execution
  load_and_run_elf(&argv[1]);
  // 3. invoke the cleanup routine inside the loader  
  loader_cleanup();
  return 0;
}