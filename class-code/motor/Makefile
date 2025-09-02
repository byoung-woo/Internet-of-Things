main: main.o motor.o   # main 타겟은 main.o와 motor.o를 의존합니다.
    gcc -o main main.o motor.o -lwiringPi   # main을 생성하기 위해 main.o와 motor.o를 링크합니다. wiringPi 라이브러리도 링크됩니다.

motor.o: motor.c motor.h   # motor.o 타겟은 motor.c와 motor.h를 의존합니다.
    gcc -c motor.c   # motor.c를 컴파일하여 motor.o를 생성합니다.

main.o: main.c motor.h   # main.o 타겟은 main.c와 motor.h를 의존합니다.
    gcc -c main.c   # main.c를 컴파일하여 main.o를 생성합니다.
