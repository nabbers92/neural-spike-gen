LEAP_LIBRARY := ./lib/libLeap.so -Wl,-rpath,./lib

handTracker: src/main.cpp
	$(CXX) -Wall -g -I./include src/main.cpp -o ./handTracker $(LEAP_LIBRARY)

clean:
	rm -rf handTracker handTracker.dSYM
