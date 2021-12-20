#ifndef _CONSULTORIO_H
#define _CONSULTORIO_H

#include "HashMap.h"
#include <string>
#include "List.h"
#include "TreeMap.h"
using namespace std;

typedef string Medico, Paciente;
typedef struct {
	int hora, min;
	string nombre;
}tPaciente;

class Fecha {
public:

	Fecha(int d, int h, int m) {
		this->d = d;
		this->h = h;
		this->m = m;
	}

	int getDia() { return d; }
	int getHora() { return h; }
	int getMinuto() { return m; }


	bool &operator< (Fecha other) {
		bool res;
		if (this->getDia() < other.getDia()) res = true;
		else if (this->getDia() == other.getDia()) {
			if (this->getHora() < other.getHora()) res = true;
			else if (this->getHora() == other.getHora()) {
				if (this->getMinuto() < other.getMinuto()) res = true;
				else res = false;
			}
			else res = false;
		}
		else res = false;

		return res;
	}


private:
	int d, m, h;


};

class Consultorio {

public:


	void nuevoMedico(Medico m) {
		TreeMap<Fecha, Paciente> l;
		consultas.insert(m, l);
	}

	void pideCita(Paciente p, Medico m, Fecha f) {
		if (!consultas.contains(m)) {}
		else if (consultas.at(m).contains(f)) {}

		consultas.at(m).insert(f, p);
		consultas.
	}

	Paciente siguientePaciente(Medico m) {
		if (!consultas.contains(m)) {}
		else if (consultas.at(m).empty()) {}

		return consultas.at(m).begin().value();
	}

	void atiendeConsulta(Medico m) {
		if (!consultas.contains(m)) {}
		else if (consultas.at(m).empty()) {}

		consultas.at(m).erase(consultas.at(m).begin().key());
	}

	List<Paciente> listaPacientes(Medico m, int d) {
		//return listaPorDias[d].at(m);
	}

private:

	class InfoMedicos{
	public:

		InfoMedicos(Fecha _f, Paciente _p) :
			f(_f), p(_p) {}
		//	//this->p = p;
		//	
		Fecha f;
		Paciente p;
	
		List<TreeMap<Fecha, tPaciente>&> listaPorDias;
		TreeMap<Fecha, Paciente>& lista;
	};
	HashMap<Medico,InfoMedicos> consultas;


	

};








#endif

