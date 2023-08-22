all: bin/loader bin/launcher bin/test
	@echo "Build done"

bin/loader:
	@$(MAKE) -C loader

bin/launcher:
	@$(MAKE) -C launcher

bin/test:
	@$(MAKE) -C test

	@mkdir -p bin
	@mv test/fib bin
	@mv launcher/launch bin
	@echo "Files moved"

clean:
	@rm -rf bin
	@$(MAKE) -C loader clean
	@$(MAKE) -C launcher clean
	@$(MAKE) -C test clean
	@echo "Cleaned"
