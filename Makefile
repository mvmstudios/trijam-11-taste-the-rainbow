EXPORT_FILE_NAME = "trijam11"

all: clean build run

clean:
	rm target/$(EXPORT_FILE_NAME)

# gcc -g src/*.* -Incurses src/*/*.* -o target/$(EXPORT_FILE_NAME) -lSDL2 -lSDL2_image -lm
build:
	gcc -g src/*.* -o target/$(EXPORT_FILE_NAME) -lSDL2 -lSDL2_image -lm

run:
	target/$(EXPORT_FILE_NAME)