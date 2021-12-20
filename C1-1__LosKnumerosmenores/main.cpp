// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Error.h"
#include "SetOfInts3.h"
using namespace std;

// función que resuelve el problema
SetOfInts3 resolver(vector<int> const& v, const int n) {
	SetOfInts3 sol;
	
	for (int i = 0; i < n; i++) { if(!sol.contains(v[i])) sol.add(v[i]); }
	for (int i = n; i < v.size(); i++) {
		if (!sol.contains(v[i]) && v[i] < sol.getMax()) {
			sol.removeMax();
			sol.add(v[i]);
		}
	}


	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	SetOfInts3 sol;
	vector<int> v;
	cin >> n;
	if (n == 0)
		return false;
	int c;
	cin >> c;
	while (c != -1) {
		v.push_back(c);
		cin >> c;
	}
	sol = resolver(v, n);

	// escribir sol
	
	cout << sol;
	cout << "\n";
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