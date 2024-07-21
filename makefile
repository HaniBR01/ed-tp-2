CC = g++
CFLAGS = -std=c++11 -Wall

# Diretórios
OBJ = ./obj
BIN = ./bin
INCLUDE = ./include
SRC = ./src

# Cabeçalho
HEADER = ${INCLUDE}/florestaMatriz.hpp ${INCLUDE}/heap.hpp ${INCLUDE}/florestaMatriz.hpp
MatrizTolls = ${OBJ}/florestaMatriz.o ${OBJ}/heap.o ${OBJ}/matriz.o
ListaTolls = ${OBJ}/florestaLista.o ${OBJ}/heap.o ${OBJ}/lista.o

# Targets
Matriz = ${BIN}/matriz
Lista = ${BIN}/tp2.out


# Compilação Total
allsubmetido:
	make ${Lista}
	make ${Matriz}

# Regras de construção
${Matriz}: ${MatrizTolls}
	${CC} ${CFLAGS} ${MatrizTolls} -o ${Matriz}

${Lista}: ${ListaTolls}
	${CC} ${CFLAGS} ${ListaTolls} -o ${Lista}

${OBJ}/florestaMatriz.o: ${SRC}/florestaMatriz.cpp ${INCLUDE}/florestaMatriz.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/florestaMatriz.cpp -o ${OBJ}/florestaMatriz.o

${OBJ}/florestaLista.o: ${SRC}/florestaLista.cpp ${INCLUDE}/florestaLista.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/florestaLista.cpp -o ${OBJ}/florestaLista.o

${OBJ}/heap.o: ${SRC}/heap.cpp ${INCLUDE}/heap.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/heap.cpp -o ${OBJ}/heap.o

${OBJ}/matriz.o: ${SRC}/matriz.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/matriz.cpp -o ${OBJ}/matriz.o

${OBJ}/lista.o: ${SRC}/lista.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/lista.cpp -o ${OBJ}/lista.o	

# gerador de grafos

grafos.o: ./test/geradorGrafo.cpp
	${CC} ${CFLAGS} -c ./test/geradorGrafo.cpp -o ${OBJ}/grafos.o

grafos: ./obj/grafos.o
	${CC} ${CFLAGS} ./obj/grafos.o -o ${BIN}/grafos

# testes:
runM:
	./bin/matriz < ./test/teste00.txt
	./bin/matriz < ./test/teste01.txt
	./bin/matriz < ./test/teste02.txt
	./bin/matriz < ./test/teste03.txt
	./bin/matriz < ./test/teste04.txt
	./bin/matriz < ./test/teste05.txt
	./bin/matriz < ./test/teste06.txt
	./bin/matriz < ./test/teste07.txt
	./bin/matriz < ./test/teste08.txt
	./bin/matriz < ./test/teste09.txt
	./bin/matriz < ./test/teste10.txt
	./bin/matriz < ./test/teste11.txt
	./bin/matriz < ./test/teste12.txt
	./bin/matriz < ./test/teste13.txt

runL:
	./bin/tp2.out < ./test/teste00.txt
	./bin/tp2.out < ./test/teste01.txt
	./bin/tp2.out < ./test/teste02.txt
	./bin/tp2.out < ./test/teste03.txt
	./bin/tp2.out < ./test/teste04.txt
	./bin/tp2.out < ./test/teste05.txt
	./bin/tp2.out < ./test/teste06.txt
	./bin/tp2.out < ./test/teste07.txt
	./bin/tp2.out < ./test/teste08.txt
	./bin/tp2.out < ./test/teste09.txt
	./bin/tp2.out < ./test/teste10.txt
	./bin/tp2.out < ./test/teste11.txt
	./bin/tp2.out < ./test/teste12.txt
	./bin/tp2.out < ./test/teste13.txt

# Regra de limpeza
clean:
	rm -f ${OBJ}/*.o
	rm -f ${BIN}/*
