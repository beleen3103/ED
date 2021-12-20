// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include "Queue.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	deque<int> lista;
	int n, aux;
	cin >> n;
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		if (aux > 0) lista.push_back(aux);
		else lista.push_front(aux);
	}

	Queue<int> sol;
	while (!lista.empty()) {
		sol.push_back(lista.front());
		lista.pop_front();
	}


	// escribir sol
	cout << sol << "\n";
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
