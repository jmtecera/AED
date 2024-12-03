# Variables
CXX = g++
CXXFLAGS = -I. -I ../../aedtools -std=gnu++17 -Wall -Wextra -O2 -Wno-deprecated-copy -Wno-sign-compare -Wno-unused-parameter -Wno-implicit-fallthrough

# Source files and targets
TARGET = debug/compact_queues.bin
SRCS = compact_queues.cpp $(wildcard ../../aedtools/*.cpp)
JSON_FILES = $(wildcard *.json)

# make build
build: $(TARGET) run

$(TARGET): $(SRCS)
	mkdir -p debug
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

# make clean
clean:
	rm -rf debug
	rm -f $(TARGET)

.PHONY: all clean debug
