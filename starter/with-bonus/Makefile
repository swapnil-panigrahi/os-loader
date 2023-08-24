all: bin/loader bin/launcher bin/test
	@echo "Build done"

bin/loader:
	@$(MAKE) -C loader
	@mv loader/lib_simpleloader.so bin

bin/launcher:
	@$(MAKE) -C launcher
	@mv launcher/launch bin
	@echo "Files moved"

bin/test:
	@$(MAKE) -C test
clean:
	@$(MAKE) -C loader clean
	@$(MAKE) -C launcher clean
	@$(MAKE) -C test clean
	@echo "Cleaned"
