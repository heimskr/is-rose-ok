CXX      := clang++
CXXFLAGS := $(shell pkg-config --cflags curlpp) -Wall -Wextra -std=c++20 -Iinclude -O3
LDFLAGS  := $(shell pkg-config --libs   curlpp)

.PHONY: clean

test: tests
	./tests

tests: src/test.o src/Rose.o
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o tests
