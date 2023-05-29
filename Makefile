OBJ_NAME = ExecutableName
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) #Selects all, you can list one by one.
BUILD_DIR = build/debug

CC = clang++
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

# Detect machine architecture
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    UNAME_M := $(shell uname -m)
    ifeq ($(UNAME_M),x86_64)
		LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image
		INCLUDE_PATHS = -Iinclude/linux
		LIBRARY_PATHS = -Llib/linux
    else
		LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image
		INCLUDE_PATHS = -Iinclude/linux
		LIBRARY_PATHS = -Llib/linux
    endif
else ifeq ($(UNAME_S),Darwin)
	LINKER_FLAGS = -lsdl2 -lsdl2_ttf -lsdl2_image
	INCLUDE_PATHS = -Iinclude/macos
	LIBRARY_PATHS = -Llib/macos
else
    $(error Unsupported platform: $(UNAME_S))
endif

# Compile command
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME).app

clean:
	rm -f $(BUILD_DIR)/$(OBJ_NAME).app
	rm -fR $(BUILD_DIR)/$(OBJ_NAME).app.dSYM
	