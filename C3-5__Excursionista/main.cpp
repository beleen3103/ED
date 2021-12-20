// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;

typedef struct {
	int nEquipos = 0;
	int excursionistas = 0;
}rescate;

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
rescate resolver(bintree<int> arbol) {
	rescate aux;
	if (arbol.left().empty() && arbol.right().empty()) { //si es una hoja
		aux.excursionistas += arbol.root(); //sumamos si hay excursionistas
		if (arbol.root() != 0) aux.nEquipos++; //si hay, necesitamos un equipo
		return aux;
	}
	else {
		rescate iz, der;
		if (!arbol.left().empty()) iz = resolver(arbol.left());
		if (!arbol.right().empty()) der = resolver(arbol.right());
		aux.nEquipos += iz.nEquipos + der.nEquipos; //sumamos los equipos que se necesitan en los hijos
		if (iz.excursionistas > der.excursionistas) aux.excursionistas += iz.excursionistas; //nos quedamos con el mayor numero de excursionistas
		else aux.excursionistas += der.excursionistas;
		aux.excursionistas += arbol.root(); // le sumamos los excursionistas que hay en este nodo
		if (aux.nEquipos == 0 && arbol.root() != 0) aux.nEquipos++; //si hay excursionistas, pero hasta ahora no se necesitaban equipos, sumamos 1
		return aux;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	rescate sol = resolver(arbol);
	// escribir sol
	cout << sol.nEquipos << " " << sol.excursionistas << "\n";

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