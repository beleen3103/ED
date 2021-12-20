// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"
using namespace std;

// función que resuelve el problema
List<int> resolver(List<int>& lista) {
	List<int>::Iterator it = lista.begin();
	int max = 0;
	while (it != lista.end()) {
		if (max <= it.elem()) {
			max = it.elem();
			it.next();
		}
		else  it = lista.erase(it);
	}
	return lista;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int aux;
	List<int> l;
	cin >> aux;
	while (aux != -1) {
		l.push_back(aux);
		cin >> aux;
	}

	List<int> sol = resolver(l);
	// escribir sol
	for (int i = 0; i < sol.size(); i++) {
		cout << sol.at(i);
		if(i != sol.size()-1) cout << " ";
	}
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