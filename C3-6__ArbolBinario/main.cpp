// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;

typedef struct {
	int min = 4000;
	int max = 0;
}respuesta;

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
respuesta resolver(bintree<int> arbol, bool& esBinario) {
	if (esBinario) {
		respuesta aux;
		if (arbol.left().empty() && arbol.right().empty()) return {arbol.root(), arbol.root()}; //si es una hoja devuelve el valor
		else {
			respuesta iz, der;
			if (!arbol.left().empty()) { //hijo izq
				iz = resolver(arbol.left(), esBinario);
				if (esBinario && arbol.root() <= iz.max) esBinario = false; //si aun no ha fallado pero la raiz es menor o igual que el mayor de la izq, no es binario
				else aux.min = iz.min; //si esta bien, el minimo es el minimo de la izquierda
			}
			else aux.min = arbol.root(); //si no hay iz, el minimo es la raiz
			if (esBinario) {
				if (!arbol.right().empty()) { //hijo der
					der = resolver(arbol.right(), esBinario);
					if (esBinario && arbol.root() >= der.min) esBinario = false; //si aun no ha fallado pero la raiz es mayor o igual que el menor de la derecha, no es binario
					else aux.max = der.max;  //si esta bien , el maximo es el maximo de la derecha
				}
				else aux.max = arbol.root(); //si no hay der, el maximo es la raiz
			}

			return aux;
		}
	}
	

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	
	bintree<int> arbol = leerArbol(-1);
	bool esBinario = true;
	if(!arbol.empty()) resolver(arbol, esBinario);

	// escribir sol
	cout << (esBinario ? "SI" : "NO") << "\n";

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