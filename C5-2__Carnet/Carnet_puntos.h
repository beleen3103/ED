#ifndef _CARNET_PUNTOS_H_
#define _CARNET_PUNTOS_H_

#include <string>
#include "HashMap.h"
#include "List.h"
#include <stdexcept>
//#include <iostream>
using namespace std;



class Carnet {
public:
	void nuevo(const string dni) {
		if (_conductores.contains(dni)) { throw std::domain_error("Conductor duplicado"); }
		lista[15].push_front(dni);
		_conductores.insert(dni, InfoConductor(15, lista[15].begin()));
	}

	void quitar(string dni, unsigned int puntos) {
		if (!_conductores.contains(dni)) { throw std::domain_error("Conductor inexistente"); }
		int puntosAnt = _conductores.find(dni).value().puntos;
		if (_conductores.find(dni).value().puntos <= puntos) _conductores.find(dni).value().puntos = 0;
		else _conductores.find(dni).value().puntos -= puntos;
		lista[puntosAnt].erase(_conductores.find(dni).value().it);
		lista[_conductores.find(dni).value().puntos].push_front(dni);
		_conductores.find(dni).value().it = lista[_conductores.find(dni).value().puntos].begin();
	}

	int consultar(string dni) {
		if (!_conductores.contains(dni)) { throw std::domain_error("Conductor inexistente"); }
		return _conductores.at(dni).puntos;
	}



	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos >15) { throw std::domain_error("Puntos no validos"); }
		return lista[puntos].size();
	}


private:

	class InfoConductor{
	public:
		InfoConductor(unsigned int _puntos, List<string>::Iterator _it) : puntos(_puntos), it(_it) {}

		List<string>::Iterator it;
		unsigned int puntos;
	};
	List<string> lista[16];
	HashMap<string, InfoConductor> _conductores;
};


#endif
