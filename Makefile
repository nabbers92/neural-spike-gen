OS := $(shell uname)
ARCH := $(shell uname -m)

# Compiler
ifeq ($(OS),Darwin)
	CXX := clang++ -arch $(ARCH)
else
	CXX := g++
endif

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := handTracker
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Code Lists
SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
INCDIRS := $(shell find include/**/* -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))

# LeapMotion Library Selection
ifeq ($(OS), Linux)
  	ifeq ($(ARCH), x86_64)
    	LEAP_LIBRARY := ./lib/libLeap.so -Wl,-rpath,./lib
  	else
    	LEAP_LIBRARY := ./lib/libLeap.so -Wl,-rpath,./lib
  	endif
else
  # OS X
  	LEAP_LIBRARY := ./lib/libLeap.dylib
endif

# Shared Compiler Flags
CFLAGS := -c
INC := -I include $(INCLIST) -I /usr/local/include
LIB := -L /usr/local/lib $(LEAP_LIBRARY)

# Compilation and Linking
$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "  Linking $(TARGET)"; $(CXX) $^ -o $(TARGET) $(LIB)

ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ./lib/libLeap.dylib $(TARGET)
endif

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "Compiling $<..."; $(CXX) $(CFLAGS) $(INC) -c -o $@ $<

# Make Commands
clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean