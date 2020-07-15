CC = clang++
GCC_FLAGS = -I include -std=c++11 -Wall -O2 -g
PROGRAMA = marketplace

all: cliente.o clientepj.o conta.o agencia.o main.o
	$(CC) $(GCC_FLAGS) -o $(PROGRAMA) cliente.o clientepj.o conta.o agencia.o main.o
cliente.o: src/cliente.cpp include/cliente.hpp
	$(CC) $(GCC_FLAGS) -c src/cliente.cpp
clientepj.o: src/clientepj.cpp include/clientepj.hpp
	$(CC) $(GCC_FLAGS) -c src/clientepj.cpp
conta.o: src/conta.cpp include/clientepj.hpp include/cliente.hpp include/agencia.hpp
	$(CC) $(GCC_FLAGS) -c src/conta.cpp
agencia.o: src/agencia.cpp 
	$(CC) $(GCC_FLAGS) -c src/agencia.cpp

main.o: src/main.cpp include/fila.hpp include/conta.hpp
	$(CC) $(GCC_FLAGS) -c src/main.cpp

clean:
	rm *.o
	rm $(PROGRAMA)
