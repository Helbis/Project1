CXX = g++
libs = 
options = -Wall 
headers = menu.hpp student.hpp degree.hpp university.hpp 


all: main


main: main.cpp $(headers) 
	$(CXX) $(libs) $(options) $< -o $@ 

run:
	./main

clean:
	rm main 
