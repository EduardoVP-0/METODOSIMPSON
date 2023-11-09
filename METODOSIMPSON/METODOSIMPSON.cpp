// METODOSIMPSON.cpp
// EduardoVelazquez 3J

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double Sacarh(double x1, double xf, int n) {
	double h;
	h = (xf - x1) / n;
	return (h);
}

int Sacarn(double x1, double xf, double h){
	int n;
	n = (xf - x1) / h;
	return (n);
}




int main()
{
	int op, n, i;
	double x[100], y[100], h, xf, pares = 0, impares=0, integral=0;
	
	cout << "Ingrese x1: " << endl; cin >> x[0];
	cout << "Ingrese xf: " << endl; cin >> xf;

	cout << "\nElija la opcion del valor que desea ingresar: " << endl;
	cout << "1.- Numero de intervalos (n)" << endl;
	cout << "2.- Tamano de paso (h)" << endl;
	cout << "Opcion: "; cin >> op;

	switch (op) {
	case 1: 
		cout << "\nIngrese n: ";  cin >> n;
		h = Sacarh(x[0],xf,n);
		cout << "El valor de h es: " << h << endl;
		for (i = 1; i <= n; i++){
			x[i] = x[i - 1] + h;
		}
		for (i = 0; i <= n; i++) {
			y[i] = 5 * pow(x[i], 2) - (x[i] / 3);
		}

		for (i = 1; i <= n; i++) {
			if (i % 2 != 0) {
				pares = pares + y[i];
			}
		}
		pares = pares * 4;

		for (i = 2; i <= n-1; i++) {
			if (i % 2 == 0) {
				impares = impares + y[i];
			}
		}
		impares = impares * 2;

		integral = h / 3 * (y[0] + pares + impares + y[n]);

		cout << setw(4) << "i" << setw(13) << "X\t" << setw(11) << "Y";
		cout << "\n";
		for (i = 0; i <= n; i++) {
			cout << setprecision(8);
			cout << setw(4) << i + 1 << "\t" << setw(12) << x[i] << setw(12) << "\t" << y[i];
			cout << "\n";
		}
		cout << "\nLa aproximacion de la integral es: " << integral;
		break;

	case 2: 
		cout << "\nIngrese h: "; cin >> h;
		n = Sacarn(x[0], xf, h);
		cout << "El valor de n es: " << n << endl;
		for (i = 1; i <= n; i++) {
			x[i] = x[i - 1] + h;
		}
		for (i = 0; i <= n; i++) {
			y[i] = 5 * pow(x[i], 2) - (x[i] / 3);
		}

		for (i = 1; i <= n; i++) {
			if (i % 2 != 0) {
				pares = pares + y[i];
			}
		}
		pares = pares * 4;

		for (i = 2; i <= n - 1; i++) {
			if (i % 2 == 0) {
				impares = impares + y[i];
			}
		}
		impares = impares * 2;

		integral = h / 3 * (y[0] + pares + impares + y[n]);

		cout << setw(4) << "i" << setw(13) << "X\t" << setw(11) << "Y";
		cout << "\n";
		for(i=0;i<=n;i++){
			cout << setprecision(8);
			cout << setw(4) << i+1 << "\t" << setw(12) << x[i] << setw(12) << "\t" << y[i];
			cout << "\n";
		}
		cout << "\nLa aproximacion de la integral es: " << integral;
		break;

	default: 
		cout << "Opcion invalida"; break;
	}










	return 0;
}
