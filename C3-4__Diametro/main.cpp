// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;

bintree<char> leerArbol(const char vacio) {
	char raiz;
	cin >> raiz;
	if (raiz == vacio) return {};
	else {
		bintree<char> iz = leerArbol(vacio);
		bintree<char> der = leerArbol(vacio);
		return { iz, raiz, der };
	}
}

// función que resuelve el problema
int resolver(bintree<char> arbol, int& max) {
	int act = 0, iz = 0, der = 0;
	if (arbol.left().empty() && arbol.right().empty()) { //si es una hoja, devuelves uno por el nodo
		if (1 > max) max = 1;
		return 1;
	}
	else {
		if (!arbol.left().empty()) iz = resolver(arbol.left(), max);
		if (!arbol.right().empty()) der = resolver(arbol.right(), max);
		act = 1 + iz + der;
		if (max < act) max = act;
		if (iz < der) return der + 1;
		else return iz + 1;	
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> arbol = leerArbol('.');
	int max = 0;
	if (!arbol.empty()) {
		int sol = resolver(arbol, max);
		// escribir sol
	}
	cout << max;
	cout << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}