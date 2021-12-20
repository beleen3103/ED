// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
#include <string>
using namespace std;

bintree<char> leerArbol(string s, int& pos, char vacio) {
	char raiz;
	raiz = s[pos];

	if (raiz == vacio) {
		return {};
	}
	else {
		bintree<char> iz = leerArbol(s, ++pos, vacio);
		bintree<char> der = leerArbol(s, ++pos, vacio);
		return { iz, raiz, der };
	}

}

struct resultado {
	int altura = 0;
	int hojas = 0;
	int nodos = 0;
};

resultado resolverNiguel(bintree<char> arbol) {
	int hoja = 0;
	if (arbol.empty()) {
		return { 0, 0, 0 };
	}
	resultado iz = resolverNiguel(arbol.left());
	resultado der = resolverNiguel(arbol.right());
	if (iz.nodos == 0 && der.nodos == 0) {
		hoja = 1;
	}
	return{ (iz.altura > der.altura) ? iz.altura + 1 : der.altura + 1, iz.hojas + der.hojas + hoja, iz.nodos + der.nodos + 1 };
}

// función que resuelve el problema
void resolver(bintree<char> arbol, int h, resultado& res) {
	if (arbol.root() == NULL) {
		return;
	}
	else {
		h++;
		if (res.altura < h) res.altura = h;
		res.nodos++;	
		if (arbol.left().empty() && arbol.right().empty()) {
			res.hojas++;
		}
		else {
			if (!arbol.left().empty()) {
				resolver(arbol.left(), h, res);
			}
			if (!arbol.right().empty()) {
				resolver(arbol.right(), h, res);
			}
		}
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	resultado res;
	string aux;
	cin >> aux;
	int a = 0;
	bintree<char> arbol = leerArbol(aux, a, '.');
	if(!arbol.empty())res = resolverNiguel(arbol);
	// escribir sol
	cout << res.nodos << " " << res.hojas << " " << res.altura << "\n";


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