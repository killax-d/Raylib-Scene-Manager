# Include the compiling flags and required libraries
include ../cfg/makeconf

FILES = $(shell find . -type f -name '*.c' -printf "%p ")
OBJECTS = $(patsubst %.c, %.o, $(FILES))

all: $(APP)

# All the file (Folder recursive) are automatically added
$(APP): directories $(OBJECTS)
	$(CC) -o $(RELEASE_DIR)/$@ $(shell find ../build -type f -name '*.o' -printf "%p ") $(CLIBS)

directories:
	if [ ! -d "$(RELEASE_DIR)" ]; then mkdir "$(RELEASE_DIR)"; fi
	if [ ! -d "$(BUILD_DIR)" ]; then mkdir "$(BUILD_DIR)"; fi

# This satisfy all the above targets, with a single regex (compile the .c to generate the .o compiled file)
%.o: %.c
	mkdir -p `dirname "$(BUILD_DIR)/$@"`
	$(CC) -c $< -o "$(BUILD_DIR)/$@" $(CFLAGS)


# Use "make clean" to remove all .o files in the current folder
clean:
	rm -rf $(BUILD_DIR)

# Use "make clean all" to remove all *.o files and the binary
purge:
	rm -rf $(BUILD_DIR)
	rm -rf $(RELEASE_DIR)