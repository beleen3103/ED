// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// función que resuelve el problema
// coste O(n+m) siendo n el tamaño inicial de la cola y m el de la de los colegas
void resolver(Queue<int>&cola, Queue<int>colegas,int const pringao) {
	int vuelta = 0, fin = cola.size(), nColegas = colegas.size();
	if (!colegas.empty()) {
		while (vuelta < fin) {
			if (cola.front() == pringao) {
				cola.push_back(cola.front());
				cola.pop_front();
				for (int i = 0; i < nColegas; i++) {
					cola.push_back(colegas.front());
					colegas.pop_front();
				}
			}
			else {
				cola.push_back(cola.front());
				cola.pop_front();
			}
			vuelta++;
		}
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Queue<int> cola, colegas;
	int aux, pringao;
	cin >> aux;
	while (aux != -1) {
		cola.push_back(aux);
		cin >> aux;
	}
	cin >> pringao;
	cin >> aux;
	while (aux != -1) {
		colegas.push_back(aux);
		cin >> aux;
	}
	
	
	cout << cola << "\n";
	cola.colar(pringao, colegas);
	//resolver(cola, colegas, pringao);
	cout << cola << "\n";


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