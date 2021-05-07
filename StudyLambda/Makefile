main.o:main.cpp
	g++ $^ -c -o $@

.PHONY:clean
clean:
	rm main

.PHONY:all
all:main.o
	g++ $^ -o main