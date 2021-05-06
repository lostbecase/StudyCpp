main.o:main.cpp
	g++ $^ -c -o $@

Calculator.o:Calculator.cpp
	g++ $^ -c -o $@

.PHONY:clean
clean:
	rm *.o
	rm main

.PHONY:all
all:main.o Calculator.o
	g++ $^ -o main