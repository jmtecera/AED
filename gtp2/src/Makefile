# Variables
CXX = g++
CXXFLAGS = -I. -I ../../aedtools -std=gnu++17 -Wall -Wextra -O2 -Wno-deprecated-copy -Wno-sign-compare -Wno-unused-parameter -Wno-implicit-fallthrough

# Source files and targets
SRCS = $(wildcard *.cpp)
TARGETS = $(SRCS:.cpp=.bin)

# make build
build: $(TARGETS)

%.bin: %.cpp
	mkdir -p debug
	$(CXX) $(CXXFLAGS) -o debug/$@ $^

run:
	@echo "Usage: make run <ex>"
	@exit 1

run-%: debug/%.bin
	@echo "Running ./debug/$*.bin"
	./debug/$*.bin

# make clean
clean:
	rm -rf debug
	rm -f $(TARGETS)

.PHONY: all clean debug
