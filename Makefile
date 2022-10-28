OS := $(shell uname)
ARCH := $(shell uname -m)

# Compiler
ifeq ($(OS),Darwin)
	CXX := clang++ -arch x86_64
else
	CXX := g++
endif


ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := ./lib/x64/libLeap.so -Wl,-rpath,../lib/x64
  else
    LEAP_LIBRARY := ./lib/x86/libLeap.so -Wl,-rpath,../lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := ./lib/libLeap.dylib
endif

handTracker: src/main.cpp
	$(CXX) -Wall -g -I./include src/main.cpp -o handTracker $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ./lib/libLeap.dylib handTracker
endif

clean:
	rm -rf handTracker handTracker.dSYM
