all: clean build run

clean:
	rm target/trijam11.out

build:
	gcc -g src/*.* -Incurses src/*/*.* -o target/trijam11.out -lSDL2 -lSDL2_image -lm

run:
	target/trijam11.out