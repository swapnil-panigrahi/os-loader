#include "loader.h"

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
    if (memcmp(elf32Ehdr.e_ident, ELFMAG, SELFMAG) == 0) {
      printf("this is a valid elf file\n");
    } else {printf("this is an invalid elf file\n"); exit(1);}
    fclose(elf_file);
  }
  // 2. passing it to the loader for carrying out the loading/execution
  load_and_run_elf(argv[1]);
  // 3. invoke the cleanup routine inside the loader
  loader_cleanup();
  return 0;
}
