CC = clang++
GCC_FLAGS = -I include -std=c++11 -Wall -O2 -g
PROGRAMA = marketplace

all: Client.o Market.o main.o
	$(CC) $(GCC_FLAGS) -o $(PROGRAMA) Client.o Market.o  main.o
Client.o: src/Client.cpp include/Client.hpp include/Products.hpp
	$(CC) $(GCC_FLAGS) -c src/Client.cpp

Market.o: src/Market.cpp include/Market.hpp include/Products.hpp
	$(CC) $(GCC_FLAGS) -c src/Market.cpp

main.o: src/main.cpp include/Market.hpp include/Client.hpp
	$(CC) $(GCC_FLAGS) -c src/main.cpp

clean:
	rm *.o
	rm $(PROGRAMA)
