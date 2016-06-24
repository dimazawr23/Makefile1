./bin/discriminant: ./obj/main.o ./obj/discriminant.o ./bin
	g++ ./obj/main.o ./obj/discriminant.o -o ./bin/discriminant

./obj/main.o: ./src/main.c ./obj
	g++ -c ./src/main.c -o ./obj/main.o -Wall

./obj/discriminant.o: ./src/discriminant.c ./obj
	g++ -c ./src/discriminant.c -o ./obj/discriminant.o -Wall

./bin:
	mkdir bin

./obj:
	mkdir obj

.PHONY: clean
clean:
	rm -f -r bin/ obj/
