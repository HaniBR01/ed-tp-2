CC = g++
CFLAGS = -std=c++11 -Wall

# Diretórios
OBJ = ./obj
BIN = ./bin
INCLUDE = ./include
SRC = ./src

# Cabeçalho
HEADER = ${INCLUDE}/florestaMatriz.hpp ${INCLUDE}/heap.hpp ${INCLUDE}/florestaMatriz.hpp ${INCLUDE}/excessoes.hpp
MatrizTolls = ${OBJ}/florestaMatriz.o ${OBJ}/heap.o ${OBJ}/matriz.o ${OBJ}/excessoes.o
ListaTolls = ${OBJ}/florestaLista.o ${OBJ}/heap.o ${OBJ}/lista.o ${OBJ}/excessoes.o
testTempTolls = ${OBJ}/florestaMatriz.o ${OBJ}/florestaLista.o ${OBJ}/heap.o ${OBJ}/testeTemporal.o ${OBJ}/excessoes.o

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

testeTemp: ${testTempTolls}
	${CC} ${CFLAGS} ${testTempTolls} -o ./bin/testeTemporal

${OBJ}/florestaMatriz.o: ${SRC}/florestaMatriz.cpp ${INCLUDE}/florestaMatriz.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/florestaMatriz.cpp -o ${OBJ}/florestaMatriz.o

${OBJ}/florestaLista.o: ${SRC}/florestaLista.cpp ${INCLUDE}/florestaLista.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/florestaLista.cpp -o ${OBJ}/florestaLista.o

${OBJ}/excessoes.o: ${SRC}/excessoes.cpp ${INCLUDE}/excessoes.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/excessoes.cpp -o ${OBJ}/excessoes.o

${OBJ}/heap.o: ${SRC}/heap.cpp ${INCLUDE}/heap.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/heap.cpp -o ${OBJ}/heap.o

${OBJ}/matriz.o: ${SRC}/matriz.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/matriz.cpp -o ${OBJ}/matriz.o

${OBJ}/testeTemporal.o: ${SRC}/testeTemporal.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/testeTemporal.cpp -o ${OBJ}/testeTemporal.o

${OBJ}/lista.o: ${SRC}/lista.cpp ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/lista.cpp -o ${OBJ}/lista.o	

# gerador de grafos

grafos.o: ./test/geradorGrafo.cpp
	${CC} ${CFLAGS} -c ./test/geradorGrafo.cpp -o ${OBJ}/grafos.o

grafos: ./obj/grafos.o
	${CC} ${CFLAGS} ./obj/grafos.o -o ${BIN}/grafos

# testes:
runM:
	./bin/testeTemporal < ./test/aleatorio100-5-1.txt
	./bin/testeTemporal < ./test/aleatorio100-50-1.txt
	./bin/testeTemporal < ./test/aleatorio100-500-1.txt
	./bin/testeTemporal < ./test/aleatorio200-10-1.txt
	./bin/testeTemporal < ./test/aleatorio200-100-1.txt
	./bin/testeTemporal < ./test/aleatorio200-1000-1.txt
	./bin/testeTemporal < ./test/aleatorio300-15-1.txt
	./bin/testeTemporal < ./test/aleatorio300-150-1.txt
	./bin/testeTemporal < ./test/aleatorio300-1500-1.txt
	./bin/testeTemporal < ./test/aleatorio400-20-1.txt
	./bin/testeTemporal < ./test/aleatorio400-200-1.txt
	./bin/testeTemporal < ./test/aleatorio400-2000-1.txt
	./bin/testeTemporal < ./test/aleatorio500-25-1.txt
	./bin/testeTemporal < ./test/aleatorio500-250-1.txt
	./bin/testeTemporal < ./test/aleatorio500-2500-1.txt
	./bin/testeTemporal < ./test/aleatorio600-30-1.txt
	./bin/testeTemporal < ./test/aleatorio600-300-1.txt
	./bin/testeTemporal < ./test/aleatorio600-3000-1.txt
	./bin/testeTemporal < ./test/aleatorio700-35-1.txt
	./bin/testeTemporal < ./test/aleatorio700-350-1.txt
	./bin/testeTemporal < ./test/aleatorio700-3500-1.txt
	./bin/testeTemporal < ./test/aleatorio800-40-1.txt
	./bin/testeTemporal < ./test/aleatorio800-400-1.txt
	./bin/testeTemporal < ./test/aleatorio800-4000-1.txt
	./bin/testeTemporal < ./test/aleatorio900-45-1.txt
	./bin/testeTemporal < ./test/aleatorio900-450-1.txt
	./bin/testeTemporal < ./test/aleatorio900-4500-1.txt
	./bin/testeTemporal < ./test/aleatorio1000-50-1.txt
	./bin/testeTemporal < ./test/aleatorio1000-500-1.txt
	./bin/testeTemporal < ./test/aleatorio1000-5000-1.txt

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
