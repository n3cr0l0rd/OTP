all: otp

otp: main.o encrypt.o decrypt.o
	gcc main.o encrypt.o decrypt.o -Wall -Wextra -o otp

main.o: src/main.c
	gcc -g -c src/main.c -Wall -Wextra -o main.o

encrypt.o: src/encrypt.c
	gcc -g -c src/encrypt.c -Wall -Wextra -o encrypt.o

decrypt.o: src/decrypt.c
	gcc -g -c src/decrypt.c -Wall -Wextra -o decrypt.o

clean:
	rm -rf *o
