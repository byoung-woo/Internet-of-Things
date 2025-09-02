main: main.o stepmotor.o
	gcc -o main main.o stepmotor.o -lwiringPi

stepmotor.o: stepmotor.c stepmotor.h
	gcc -c stepmotor.c

main.o: main.c stepmotor.h
	gcc -c main.c

clean:
	rm -f *.o
	rm -f main
