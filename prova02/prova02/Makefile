GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2 
PROGRAMA = diary
all: App.o Date.o Diary.o Time.o aux.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) App.o Date.o Diary.o Time.o aux.o main.o
App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

aux.o: src/aux.cpp include/aux.h
	$(GCC) $(GCC_FLAGS) -c src/aux.cpp

Diary.o: src/Diary.cpp include/Diary.h include/aux.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

main.o: src/main.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

doc.html: diary.md
	pandoc diary.md -f markdown -t html -o doc.html
	

clean: 
	rm rf *.o

