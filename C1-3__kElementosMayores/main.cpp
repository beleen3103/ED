
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
#include <string>
#include <vector>
#include "Error.h"
using namespace std;

// función que resuelve el problema
template <class T>
Set<T> resolver(int k, vector<T> v) {
	Set<T> sol;
	int i = 0;
	while (i < v.size() && k>0) {
		if (!sol.contains(v[i])) {
			sol.add(v[i]);
			k--;
		}
		i++;
	}
	while(i<v.size()){
		if (sol.getMin() < v[i] && !sol.contains(v[i])) {
			sol.removeMin();
			sol.add(v[i]);
		}
		i++;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char dato;

	cin >> dato;
	if (!std::cin)
		return false;
	
	int k;
	cin >> k;

	if (dato == 'N') {
		vector<int> h;
		int x;
		cin >> x;
		while (x != -1) {
			h.push_back(x);
			cin >> x;
		}
		Set<int> sol = resolver(k, h);
		cout << sol;
	}
	else {
		vector<string> h;
		string x;
		while (x != "FIN") {
			h.push_back(x);
			cin >> x;
		}
		Set<string> sol = resolver(k, h);
		cout << sol;
	}

	cout << "\n";

	// escribir sol


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