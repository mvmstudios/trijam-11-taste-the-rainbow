all: clean build run

clean:
	rm target/trijam11.out

build:
	gcc -g src/*.* -Incurses src/*/*.* -o target/trijam11.out -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm -D _DEBUG

run:
	target/trijam11.out

build_win:
	gcc -g src/*.* -Incurses src/*/*.* -o target/trijam11.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm -D _DEBUG