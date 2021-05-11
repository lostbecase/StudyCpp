Animal.o:Animal.cpp
	g++ $^ -c -o $@

Dog.o:Dog.cpp
	g++ $^ -c -o $@

Food.o:Food.cpp
	g++ $^ -c -o $@

main.o:main.cpp
	g++ $^ -c -o $@

.PHONY:clean
clean:
	rm *.o
	rm main

.PHONY:all
all:Animal.o Dog.o Food.o main.o
	g++ $^ -o main
