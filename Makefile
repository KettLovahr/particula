FILES = main.cpp
LIBS = -lSDL2

build:
	clang ${FILES} -o particula ${LIBS}
