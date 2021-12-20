// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Consultorio.h"
using namespace std;


// función que resuelve el problema

void listaPacientes(Consultorio cons, Medico m, int d) {
	List<Paciente> lista = cons.listaPacientes(m, d);
	cout << "Doctor " << m << " dia " << d << "\n";
	for(int i = 0; i < lista.size(); i++){
		//cout
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int consultas;
	Consultorio cons;
	cin >> consultas;
	if (!std::cin)
		return false;
	for (int i = 0; i < consultas; i++) {
		string caso, p,m;

		cin >> caso;
		
		if (caso == "nuevoMedico") {
			cin >> m;
			cons.nuevoMedico(m);
		}
		else if (caso == "piseConsulta") {
			cin >> p, m;
			int dia, hora, min;
			cin >> dia, hora;
			cin.ignore();
			cin >> min;
			Fecha f(dia, hora, min);
			cons.pideCita(p, m, f);
		}
		else if (caso == "listaPacientes") {

		}
		else if (caso == "siguientePaciente") {
			cin >> m;
			cons.siguientePaciente(m);
		}
		else if (caso == "atiendeConsulta") {
			cin >> m;
			cons.atiendeConsulta(m);
		}
	}

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