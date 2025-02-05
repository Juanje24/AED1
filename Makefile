a.out: main.o diccionario.o tablahash.o ArbolTrie.o
	g++ main.o diccionario.o tablahash.o ArbolTrie.o -o a.out -g

main.o: main.cpp diccionario.h tablahash.h ArbolTrie.h
	g++ main.cpp -c -g

diccionario.o: diccionario.cpp diccionario.h tablahash.h ArbolTrie.h
	g++ diccionario.cpp -c -g

ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h
	g++ ArbolTrie.cpp -c -g
	
tablahash.o : tablahash.cpp tablahash.h
	g++ tablahash.cpp -c -g
	
	

