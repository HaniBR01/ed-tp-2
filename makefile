CC=g++
CFLAGS=-std=c++11 -Wall

OBJ = ./obj
BIN = ./bin
INCLUDE = ./include
SRC = ./src

Target = ./bin/main
Tolls = ${OBJ}/*.o
HEADER = ${INCLUDE}/clareira.hpp

#

make all:
	${OBJ}/clareira.o
	${OBJ}/main.o
	${Target}

#

make run:
	./bin/main

#

${Target}: ${Tolls}
	${CC} ${CFLAGS} -I ${HEADER} -o ${Target}

${OBJ}/clareira.o: ${INCLUDE}/clareira.hpp ${SRC}/clareira.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/clareira.hpp -c ${SRC}/clareira.cpp - o ${OBJ}/clareira.o:

${OBJ}/main.o: ${HEADER} ${INCLUDE}/main.hpp
	${CC} ${CFLAGS} -I ${HEADER} -c ${SRC}/main.cpp - o ${OBJ}/main.o:

clean:
	rm -f ${OBJ}/*.o
	rm -f ${BIN}/*