all: output run clean

output: 
	g++ -std=c++11 main.cpp -o output

run:
	./output

clean: 
	rm output