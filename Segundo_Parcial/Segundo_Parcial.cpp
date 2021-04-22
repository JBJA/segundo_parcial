#include "Producto.h"
#include <iostream>
#include <string>
using namespace std;

void menu();
void menu_actualizar();

int main()
{
	string producto, descripcion, imagen, fecha_ingreso;
	int idmarca = 0, precio_costo = 0, precio_venta = 0, existencia = 0;
	Producto c = Producto(producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
	int entrada = 0, op=0;

	do {
		system("cls");
		menu();
		cout << "Opcion: ";
		cin >> entrada;
		switch (entrada) {
		case 1:
			system("cls");
			c.leer();
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Ingrese producto:\n";
			getline(cin,producto);
			cout << "Ingrese id marca:\n";
			cin>>idmarca;
			cin.ignore();
			cout << "Ingrese descripcion:\n";
			getline(cin, descripcion);
			cout << "Ingrese imagen:\n ";
			getline(cin, imagen);
			cout << "Ingrese precio costo:\n";
			cin >> precio_costo;
			cin.ignore();
			cout << "Ingrese precio venta:\n";
			cin >> precio_venta;
			cin.ignore();
			cout << "Ingrese existencia:\n";
			cin >> existencia;
			cin.ignore();
			cout << "Ingrese fecha ingreso:\n";
			getline(cin, fecha_ingreso);

			c.crear();
			c.leer();
			system("pause");
			break;

		case 3:
			c.leer();
			menu_actualizar();
			cout << "Opcion: ";
			cin >> op;
			switch (op) 
			{
				case 11:
					system("cls");
					c.leer();
					c.actualizar_producto();
					c.leer();
					system("pause");
					break;

				case 22:
					system("cls");
					c.leer();
					c.actualizar_idmarca();
					c.leer();
					system("pause");
					break;

				case 33:
					system("cls");
					c.leer();
					c.actualizar_descripcion();
					c.leer();
					system("pause");
					break;

				case 44:
					system("cls");
					c.leer();
					c.actualizar_costo();
					c.leer();
					system("pause");
					break;

				case 55:
					system("cls");
					c.leer();
					c.actualizar_venta();
					c.leer();
					system("pause");
					break;

				case 66:
					system("cls");
					c.leer();
					c.actualizar_existencia();
					c.leer();
					system("pause");
					break;

				case 77:
					system("cls");
					c.leer();
					c.actualizar_fecha();
					c.leer();
					system("pause");
					break;
			}while (op != 88);

			break;

		case 4:
			c.leer();
			c.eliminar();
			c.leer();
			system("pause");
			break;
		}
	} while (entrada != 5);

    system("pause");
    return 0;
}

void menu() {
	system("cls");
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "|               PRODUCTOS                |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    1. VER DATOS                        |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    2. AGREGAR DATOS                    |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    3. ACTUALIZAR DATOS                 |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    4. ELIMINAR DATOS                   |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|                5. SALIR                |" << endl;
	cout << "|________________________________________|" << endl;
}

void menu_actualizar() {
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "|              ACTUALIZAR                |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    11. MODIFICAR PRODUCTO               |" << endl;
	cout << "|    22. MODIFICAR ID MARCA               |" << endl;
	cout << "|    33. MODIFICAR DESCRIPCION            |" << endl;
	cout << "|    44. MODIFICAR PRECIO COSTO           |" << endl;
	cout << "|    55. MODIFICAR PRECIO VENTA           |" << endl;
	cout << "|    66. MODIFICAR EXISTENCIA             |" << endl;
	cout << "|    77. MODIFICAR FECHA INGRESO          |" << endl;
	cout << "|    88. REGRESAR                         |" << endl;
	cout << "|________________________________________|" << endl;
}
