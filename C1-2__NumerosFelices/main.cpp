// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts1.h"
using namespace std;


// función que resuelve el problema
void resolver(int n, SetOfInts1& sol, bool& feliz) {
	int a = 0; bool s = false;
	while (n >= 10) {
		int s = n % 10;
		a += (n % 10)*(n % 10);
		n = n / 10;
	}
	a += n * n;

	s = sol.contains(a);
	sol.add(a);
	if (a == 1) {
		feliz = true;
	}
	else if (!s) resolver(a, sol, feliz);
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	SetOfInts1 sol;
	sol.add(n);
	bool feliz = false;
	if (n == 1) feliz = true;
	else resolver(n, sol, feliz);

	// escribir sol
	cout << sol;
	cout << (feliz ? " 1" : " 0") << "\n";
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