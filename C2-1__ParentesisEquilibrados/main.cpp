
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Stack.h"
using namespace std;


// función que resuelve el problema
bool resolver(string d) {
	Stack<char> pila;
	bool equilibrado = true;
	int i = 0;
	while (i < d.length() && equilibrado) {
		if (d[i] == '[' || d[i] == '{' || d[i] == '(') pila.push(d[i]);
		else if (d[i] == ']') {
			if (pila.empty() || pila.top() != '[') equilibrado = false;
			else pila.pop();
		}
		else if (d[i] == ')') {
			if (pila.empty() || pila.top() != '(') equilibrado = false;
			else pila.pop();
		}
		else if (d[i] == '}') {
			if (pila.empty() || pila.top() != '{') equilibrado = false;
			else pila.pop();
		}

		i++;
	}
	if (equilibrado && pila.empty()) return true;
	else return false;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string h;
	getline(cin, h);
	if (!std::cin)
		return false;

	bool sol = resolver(h);

	// escribir sol

	cout << (sol ? "SI" : "NO") << "\n";


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