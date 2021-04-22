#pragma once
#include <iostream>
using namespace std;
class Objeto
{
protected: string producto, descripcion, imagen, fecha_ingreso;
		 int idmarca=0, existencia=0, precio_costo = 0, precio_venta = 0;
protected:
	Objeto() {
	}
	Objeto(string prod, int idmar, string des, string img, int pc, int pv, int exist, string fi) {
		producto = prod;
		idmarca = idmar;
		descripcion = des;
		imagen = img;
		precio_costo = pc;
		precio_venta = pv;
		existencia = exist;
		fecha_ingreso = fi;
	}
};

