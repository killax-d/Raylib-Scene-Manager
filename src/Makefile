# Include the compiling flags and required libraries
include ../cfg/makeconf

FILES = $(shell find . -type f -name '*.c' -printf "%p ")
OBJECTS = $(patsubst %.c, %.o, $(FILES))

all: $(APP)

# All the file (Folder recursive) are automatically added
$(APP): $(OBJECTS)
	if [ ! -d "$(RELEASE_DIR)" ]; then mkdir "$(RELEASE_DIR)"; fi
	$(CC) -o $(RELEASE_DIR)/$@ $^ $(CLIBS)

# This satisfy all the above targets, with a single regex (compile the .c to generate the .o compiled file)
%.o: %/%.c
	$(CC) -c $< $(CFLAGS)

# Use "make clean" to remove all .o files in the current folder
clean:
	rm -rf $(OBJECTS)

# Use "make clean all" to remove all *.o files and the binary
purge:
	rm -rf $(OBJECTS)
	rm -f ../$(APP)