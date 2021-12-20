// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;

bintree<int> leerArbol(int vacio) {
	int raiz;
	cin >> raiz;
	if (raiz == vacio) return {};
	else {
		bintree<int> iz = leerArbol(vacio);
		bintree<int> der = leerArbol(vacio);
		return { iz, raiz, der };
	}
}

// función que resuelve el problema
int resolver(bintree<int> arbol, int& tramo) {
	if (arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() != 0) return 1 - arbol.root();
		else return 1;
	}
	else {
		int iz = 0, der = 0, res =0;
		if (!arbol.left().empty()) {
			iz = resolver(arbol.left(), tramo);
		}
		if (!arbol.right().empty()) {
			der = resolver(arbol.right(), tramo);
		}
		res = iz + der;
		if (arbol.root() != 0) res -= arbol.root();
		if (res < 0) res = 0;
		else if (res >= 3) tramo++;
		return res;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);
	int tramo = 0;
	if (!arbol.empty()) {
		int sol = resolver(arbol, tramo);
		if (sol >= 3) tramo--;
	}
	// escribir sol

	cout << tramo << "\n";
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