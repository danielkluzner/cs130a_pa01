CXX = g++
ARGS = -std=c++11

all: Dictionary.o dictionary_test.o
	$(CXX) $(ARGS) Dictionary.o dictionary_test.o -o test

Dictionary.o: Dictionary.cpp
	$(CXX) -c Dictionary.cpp

dictionary_test.o: dictionary_test.cpp
	$(CXX) -c dictionary_test.cpp

clean:
	rm -f *.o *~ test

