all: clean build run

clean:
	rm target/trijam11.out

build:
	gcc -g src/*.* -Incurses src/*/*.* -o target/trijam11.out -lSDL2 -lSDL2_image -lSDL2_mixer -lm -D _DEBUG

run:
	target/trijam11.out