// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
#include <string>
using namespace std;

template <typename T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	cin >> raiz;
	if (raiz == vacio) return {};
	else {
		bintree<T> iz = leerArbol(vacio);
		bintree<T> der = leerArbol(vacio);
		return { iz, raiz, der };
	}

}

// función que resuelve el problema
template <typename T>
void resolver(bintree<T>const& arbol, T& min) {
	if (arbol.root() < min) min = arbol.root();
	
	if (!arbol.left().empty()) resolver(arbol.left(), min);
	if (!arbol.right().empty()) resolver(arbol.right(), min);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	string aux;
	cin >> aux;
	if (!std::cin)
		return false;

	if (aux == "P") {
		string vacio = "#";
		bintree<string> arbol = leerArbol(vacio);
		if (!arbol.empty()) {
			string min = arbol.root();
			resolver(arbol, min);
			cout << min;
		}
	}
	else if (aux == "N") {
		bintree<int> arbol = leerArbol(-1);
		if (!arbol.empty()) {
			int min = arbol.root();
			resolver(arbol, min);
				cout << min;
		}
	}

	cout << "\n";

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}