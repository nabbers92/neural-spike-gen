# Platform
UNAME_S := $(shell uname -s)

# Compiler
ifeq ($(UNAME_S),Darwin)
	CC := clang++ -arch x86_64
else
	CC := g++
endif

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := handTracker
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

LEAP_LIBRARY := ./lib/libLeap.so -Wl,-rpath,./lib

handTracker: src/main.cpp
	$(CXX) -Wall -g -I./include src/main.cpp -o ./handTracker $(LEAP_LIBRARY)

clean:
	rm -rf handTracker handTracker.dSYM
