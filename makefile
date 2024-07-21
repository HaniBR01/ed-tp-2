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
main2test = ${BIN}/main2
TestTarget = ${BIN}/testheap
mainTolls = ${OBJ}/floresta.o ${OBJ}/heap.o ${OBJ}/main.o
main2Tolls = ${OBJ}/florestaLista.o ${OBJ}/heap.o ${OBJ}/main2.o
heapTest = ${OBJ}/floresta.o ${OBJ}/heap.o ${OBJ}/test.heap.o
HEADER = ${INCLUDE}/floresta.hpp ${INCLUDE}/heap.hpp

# Regra padrão
#all: ${Target} ${TestTarget}

# Regras de construção
main: ${mainTolls}
	${CC} ${CFLAGS} ${mainTolls} -o ${Target}
#	chmod +x ${Target}

main2: ${main2Tolls}
	${CC} ${CFLAGS} ${main2Tolls} -o ${main2test}

${TestTarget}: ${heapTest}
	${CC} ${CFLAGS} ${heapTest} -o ${TestTarget}
#	chmod +x ${TestTarget}

${OBJ}/floresta.o: ${SRC}/floresta.cpp ${INCLUDE}/floresta.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/floresta.cpp -o ${OBJ}/floresta.o

${OBJ}/florestaLista.o: ${SRC}/florestaLista.cpp ${INCLUDE}/florestaLista.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/florestaLista.cpp -o ${OBJ}/florestaLista.o

${OBJ}/heap.o: ${SRC}/heap.cpp ${INCLUDE}/heap.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/heap.cpp -o ${OBJ}/heap.o

${OBJ}/main.o: ${SRC}/main.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/main.cpp -o ${OBJ}/main.o

${OBJ}/main2.o: ${SRC}/main2.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/main2.cpp -o ${OBJ}/main2.o	

${OBJ}/test.heap.o: ${SRC}/test.heap.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/test.heap.cpp -o ${OBJ}/test.heap.o

# gerador de grafos

grafos.o: ./test/geradorGrafo.cpp
	${CC} ${CFLAGS} -c ./test/geradorGrafo.cpp -o ${OBJ}/grafos.o

grafos: ./obj/grafos.o
	${CC} ${CFLAGS} ./obj/grafos.o -o ${BIN}/grafos

# Regra de limpeza
clean:
	rm -f ${OBJ}/*.o
	rm -f ${BIN}/*
