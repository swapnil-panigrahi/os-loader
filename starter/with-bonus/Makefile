.PHONY: all clean

BIN_DIR := bin
LOADER_TARGET := loader
LAUNCHER_TARGET := launch
TEST_TARGET := test

all: $(BIN_DIR)/$(LOADER_TARGET) $(BIN_DIR)/$(LAUNCHER_TARGET) $(BIN_DIR)/$(TEST_TARGET)
	@echo "Build done"

$(BIN_DIR)/$(LOADER_TARGET):
	@$(MAKE) -C loader

$(BIN_DIR)/$(LAUNCHER_TARGET):
	@$(MAKE) -C launcher

$(BIN_DIR)/$(TEST_TARGET):
	@$(MAKE) -C test

	@mkdir -p $(BIN_DIR)
	@mv loader/lib_simpleloader.so $(BIN_DIR)
	@mv launcher/$(LAUNCHER_TARGET) $(BIN_DIR)
	@echo "Files moved"

clean:
	@rm -rf $(BIN_DIR)
	@$(MAKE) -C loader clean
	@$(MAKE) -C launcher clean
	@$(MAKE) -C test clean
	@echo "Cleaned"
