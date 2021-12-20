#include "Plantacion.h"

bool cargar(tPlantacion& plantac) {
	bool carga = false;
	ifstream fich;

	fich.open("plantacion.txt");
	if (fich.is_open()) {
		carga = true;

		fich >> plantac.id >> plantac.num_f >> plantac.num_col;
		for (int i = 0; i < plantac.num_f; i++) {
			for (int j = 0; j < plantac.num_col; j++) {
				fich >> plantac.matriz[i][j];
			}
		}
	}
	for (int i = 0; i < plantac.num_f; i++) {
		for (int j = 0; j < plantac.num_col; j++) {
			cout<< plantac.matriz[i][j];
			cout << " ";
		}
		cout << endl;
	}
	fich.close();
	return carga;
}

int calcularPlatanosParcela(tPlantacion& plantac, int x, int y, int l) {
	int platanos = 0;

	for (int i = x; i < l+x; i++) {
		for (int j = y; j < l+y; j++) {
			if (i < plantac.num_f && j < plantac.num_col) {
				platanos += plantac.matriz[i][j];
			}
		}
	}
	return platanos;
}