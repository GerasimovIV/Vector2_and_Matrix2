
all: compile
	g++ *.o -o test

compile:
	g++ -c *.cpp
	g++ -c *.h
clean:
	rm *.o test

