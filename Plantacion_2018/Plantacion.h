#ifndef Plantacion_
#define Plantacion_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_f = 100;
const int MAX_col = 100;


typedef struct {
	string id;
	int num_f, num_col;
	int matriz[MAX_f][MAX_col];
}tPlantacion;

bool cargar(tPlantacion& plantac);
int calcularPlatanosParcela(tPlantacion& plantac, int x, int y, int l);


#endif
