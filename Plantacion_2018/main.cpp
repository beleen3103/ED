#include "Plantacion.h"

int main() {
	tPlantacion plantac;
	int num;

	cargar(plantac);
	num = calcularPlatanosParcela(plantac, 2, 2, 4);

	cout << num << endl;
	

	system("pause");
	return 0;
}