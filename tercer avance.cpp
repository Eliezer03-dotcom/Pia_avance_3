// tercer avance.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

//funciones
void Cita();
void listas();
void archivos();
void eliminar();
void modificar();


int cita, * N_cita, * preciount, * Cantra, * subtotal, * iva, * total, * hora;
string * nombre, * descripcion, * trata;
int * h, * m, * s,*v;
int main()
{
	int opc;
	cout << "Seleccione a donde quiere ir del menu" << endl;
	cout << "1.- Agregar Cita" << endl;
	cout << "2.- Mostrar Cita" << endl;
	cout << "3.- Limpiar pantalla" << endl;
	cout << "4.-Modificar" << endl;
	cout << "5.-Eliminar" << endl;
	cout << "6.-Salir" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		Cita();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void Cita()
{
	cout << "Escriba el num de citas que desea agregar " << endl;
	cin >> cita;
	N_cita = new int[cita]; //arreglos
	trata = new string[cita];
	h = new int[cita];
	m = new int[cita];
	s = new int[cita];
	v = new int[cita];
	Cantra = new int[cita];
	preciount = new int[cita];
	subtotal = new int[cita];
	iva = new int[cita];
	total = new int[cita];
	nombre = new string[cita];
	descripcion = new string[cita];
	for (int i = 0; i < cita; i++)
	{


		cout << "Ingrese el numero de la cita" << endl; //printf
		cin >> N_cita[i]; //scanf %d
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		cout << "Ingrese nombre" << endl;
		getline(cin, nombre[i]); //permite los espacios en el nombre
		cout << "Ingrese el tratamiento" << endl;
		getline(cin, trata[i]);
		cout << "Ingrese la Descripcion" << endl;
		//cin >> descripcion[i];
		getline(cin, descripcion[i]);

		while (v[i]<=10 )
		{

			cout << "Ingrese la hora de la cita en formato de 24h" << endl;
			cout << "Ingrese la hora:" << endl;
			cin >> h[i];
			cout << "Ingrese el minuto:" << endl;
			cin >> m[i];
			cout << "Ingrese el segundo:" << endl;
			cin >> s[i];

		
		
			
			if (h[i] <24 && h[i] >= 0 && m[i] <60 && m[i] >=0 && s[i] <60 && s[i] >= 0)
			{
			

				cout << "La hora es valida:"<<h[i] << ":" <<m[i] << ":" <<s[i] << endl;
				v[i] = 0;
				v[i] = 11;
			}
			else
			{
				cout << "La hora es invalida" << endl;
				v[i] = 9;
			}
			
		} 
			
		

		


		cout << "Ingrese la contidad del trataminetos" << endl;
		cin >> Cantra[i];
		cout << "Ingrese el precio unitario" << endl;
		cin >> preciount[i];
		cout << "El subtotal" << endl;
		subtotal[i] = (Cantra[i]) * (preciount[i]);
		cout << subtotal[i] << endl;
		cout << "El el iva es del 16%" << endl;
		iva[i] = subtotal[i] * 0.16;
		cout << "El total" << endl;
		total[i] = subtotal[i] + iva[i];
		cout<< total[i]<<endl;
		//* subtotal, * iva, * total

		/*char letra = 1;

   
*/

	}
}

void listas()
{
	for (int i = 0; i < cita; i++)
	{
		if (N_cita[i] == 0)
		{
			cout << "REGISTRO ELIMINADO" << i + 1 << endl;
		}
		else
		{
			cout << " registro" << i + 1 << endl;
			cout << N_cita[i] << endl;
			cout << nombre[i] << endl;
			cout << trata[i] << endl;
			cout << h[i] << ":" << m[i] << ":" << s[i] << endl;
			cout << descripcion[i] << endl;
			cout << preciount[i] << endl;
			cout << subtotal[i] << endl;
			cout << total[i] << endl;
		}
	}
}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "Citas";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	


	archivo << "Numero de cita" << "\t";
	archivo << "NOMBRE" << "\t";
	archivo << "TRATAMINETO" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "HORA" << "\t";
	archivo << "SUBTOTAL" << "\t";
	archivo << "TOTAL" << "\n";

	for (int i = 0; i < cita; i++)
	{
		if (N_cita[i] == 0)
		{

		}
		else
		{
			texto = N_cita[i];
			archivo << texto << "\t" << "\t";
			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = trata[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = descripcion[i];
			archivo << texto << "\t" ;
			texto  = h[i];
			archivo << texto << "\t" << "\t ";
			texto = subtotal[i];
			archivo << texto << "\t" << "\t ";
			texto = total[i];
			
		}

		archivo << texto << "\n " << "\n";

	}


	archivo.close();
}

void eliminar()
{
	int j;
	cout << "ingrese el  registro a eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando registro" << j + 1 << endl;

		N_cita[i] = 0;
		nombre[i] = " ";
		trata[i] = " ";
		h[i] = 0;
		m[i] = 0;
		s[i] = 0;
		descripcion[i] = " ";
		preciount[i]=0;
		subtotal[i] =0;
		total[i] =0;
	}
}


void toAscii(char& caracter)
{
	int c = (int)caracter;
	switch (c)
	{
	case -4:
		caracter = (char)129;
		break;
	case -31:
		caracter = (char)160;
		break;
	case -23:
		caracter = (char)130;
		break;
	case -19:
		caracter = (char)161;
		break;
	case -13:
		caracter = (char)162;
		break;
	case -6:
		caracter = (char)163;
		break;
	case -15:
		caracter = (char)164;
		break;
	case -36:
		caracter = (char)154;
		break;
	case -63:
		caracter = (char)181;
		break;
	case -55:
		caracter = (char)144;
		break;
	case -51:
		caracter = (char)214;
		break;
	case -45:
		caracter = (char)224;
		break;
	case -38:
		caracter = (char)233;
		break;
	case -47:
		caracter = (char)165;
		break;
	default:
		break;
	}
}


void modificar()
{
	int j, opcion;
	cout << "ingrese el numero registro a modificar";
	cin >> j;
	j = j - 1; // esto debido a que i inicia en 0
	cout << "ingrese que desea modificar 1.-N_cita,2.-Nombre, 3.- tratamiento" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese matricula" << endl;
			cin >> N_cita[i];
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			cout << "Ingrese nombre" << endl;
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese calf" << endl;
			cin >> trata[i];
			cout << "Ingrese calf lab" << endl;
			cin >> hora[i];
		}
	}


}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
