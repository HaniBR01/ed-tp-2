# Define o compilador e as flags
CC = g++
CFLAGS = -std=c++11 -Wall

# Define diretórios
OBJ = ./obj
BIN = ./bin
INCLUDE = ./include
SRC = ./src

# Define os alvos finais e os objetos
Target = ${BIN}/main
TestTarget = ${BIN}/testheap
Tolls = ${OBJ}/floresta.o ${OBJ}/heap.o ${OBJ}/main.o
TestTolls = ${OBJ}/floresta.o ${OBJ}/heap.o ${OBJ}/test.heap.o
HEADER = ${INCLUDE}/floresta.hpp ${INCLUDE}/heap.hpp

# Regra padrão
#all: ${Target} ${TestTarget}

# Regras de construção
${Target}: ${Tolls}
	${CC} ${CFLAGS} ${Tolls} -o ${Target}
#	chmod +x ${Target}

${TestTarget}: ${TestTolls}
	${CC} ${CFLAGS} ${TestTolls} -o ${TestTarget}
#	chmod +x ${TestTarget}

${OBJ}/floresta.o: ${SRC}/floresta.cpp ${INCLUDE}/floresta.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/floresta.cpp -o ${OBJ}/floresta.o

${OBJ}/heap.o: ${SRC}/heap.cpp ${INCLUDE}/heap.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/heap.cpp -o ${OBJ}/heap.o

${OBJ}/main.o: ${SRC}/main.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/main.cpp -o ${OBJ}/main.o

${OBJ}/test.heap.o: ${SRC}/test.heap.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/test.heap.cpp -o ${OBJ}/test.heap.o

# Regra de limpeza
clean:
	rm -f ${OBJ}/*.o
	rm -f ${BIN}/*
