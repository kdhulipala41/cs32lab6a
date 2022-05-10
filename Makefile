#CXX=clang++
CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter #-Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

#BINARIES=testStudent testRoster1 testRoster2 testRoster3

#all: ${BINARIES}

lab6Test: lab6Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f lab6Test *.o
