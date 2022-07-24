main.exe: sorts.o main.o sort_utility.o
	g++ sorts.o main.o sort_utility.o -o main.exe
main.o:  main.cpp
	g++ -c main.cpp

sort_utility.o: ./0_headers/utilities/sort_utility.h ./utilities/sort_utility.cpp
	g++ -c ./utilities/sort_utility.cpp

sorts.o: ./0_headers/sorts/sorts.h ./sorts/sorts.cpp 
	g++ -c ./sorts/sorts.cpp 

clean:
	rm *.o *.exe