// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
using namespace std;


// función que resuelve el problema
int resolver(Arbin<int> arbol, int generaciones, int&generacionDef, bool& esCorrecto) {
	if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
		if (generacionDef < generaciones) generacionDef = generaciones; //estamos en una hoja, miramos las generaciones
		return arbol.raiz(); //devolvemos la edad de la raiz
	}
	else {
		int primerHijo = -1, segundoHijo = -1;
		if (esCorrecto) {
			if(arbol.hijoIz().esVacio() && !arbol.hijoDr().esVacio()) esCorrecto = false; //si hay segundo hijo pero no primero, false
			else {
				generaciones++;
				primerHijo = resolver(arbol.hijoIz(), generaciones, generacionDef, esCorrecto); //comprobamos el arbol hijo izquierdo
				if (esCorrecto) {
					if (!arbol.hijoDr().esVacio()) segundoHijo = resolver(arbol.hijoDr(), generaciones, generacionDef, esCorrecto); //si existe, comprobamos el arbol hijo derecho
					if (esCorrecto) if (arbol.raiz() - primerHijo < 18 || (segundoHijo != -1 && primerHijo - segundoHijo < 2)) esCorrecto = false; // si el padre les saca menos de 18 o el mayor no le saca 2 años al menor, false
				}

			}
		}
	return arbol.raiz();
		
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Arbin<int> arbol = arbol.leerArbol(-1);
	int generaciones = 0;
	bool esCorrecto = true;

	if(!arbol.esVacio()) resolver(arbol, 1, generaciones, esCorrecto);
	// escribir sol
	cout << (esCorrecto ? "SI" : "NO");
	if (esCorrecto) cout << " " << generaciones;
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