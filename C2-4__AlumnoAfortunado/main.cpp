// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"
using namespace std;


// función que resuelve el problema
int resolver(Queue<int>& clase, int const salto) {
	int fuera = salto;
	while (clase.size() > 1) {
		if (fuera == 0) {
			clase.pop_front();
			fuera = salto;
		}
		else {
			clase.push_back(clase.front());
			clase.pop_front();
			fuera--;
		}
		
	}
	return clase.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, salto;
	cin >> N >> salto;
	if (N == 0 && salto == 0)
		return false;
	Queue<int> clase;
	for (int i = 0; i < N; i++) {
		clase.push_back(i+1);
	}
	int afortunado = resolver(clase, salto);

	// escribir sol

	cout << afortunado << "\n";
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