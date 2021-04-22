#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Objeto.h"
using namespace std;

class Producto : Objeto{
	// constructor
public:
	Producto() {
	}

	Producto(string prod, int idmar, string des, string img, int pc,int pv, int exist, string fi) : Objeto(prod, idmar, des, img, pc, pv, exist, fi) {

	}
	
	// METODOS
		//set (modificar)
	void setproducto(string prod) { producto = prod; }
	void setidmarca(int idmar) { idmarca = idmar; }
	void setdescripcion(string des) { descripcion = des; }
	void setimagen(string img) { imagen = img; }
	void setprecio_costo(int pc) { precio_costo = pc; }
	void setprecio_venta(int pv) { precio_venta = pv; }
	void setexistencia(int exist) { existencia = exist; }
	void setfecha_ingreso(string fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getproducto() { return producto; }
	int getidmarca() { return idmarca; }
	string getdescripcion() { return descripcion; }
	string getimagen() { return imagen; }
	int getprecio_costo() { return precio_costo; }
	int getprecio_venta() { return precio_venta; }
	int getexistencia() { return existencia; }
	string getfecha_ingreso() { return fecha_ingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string m = to_string(idmarca);
		string c = to_string(precio_costo);
		string v = to_string(precio_venta);
		string e = to_string(existencia);

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,idmarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "','" + m + "','" + descripcion + "','" + imagen + "'," + c + ",'" + v + ",'" + e + ",'" + fecha_ingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso . . ." << endl;
			}
			else {
				cout << "Error al Ingresar . . ." << endl;
			}
		}
		else {
			cout << "Error en la Conexion . . ." << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de productos ------------" << endl;
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
				}
			}
			else {
				cout << "Error al Consultar . . ." << endl;
			}
		}
		else {
			cout << "Error en la Conexion . . ." << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux;
			cout << "\nIngrese el id del registro que desea eliminar: ";
			cin >> idaux;
			string eliminar = "delete from productos where idproducto = (" + idaux + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa . . ." << endl;
			}
			else {
				cout << "Error al eliminar . . ." << endl;
			}
		}
		else {
			cout << "Error en la Conexion . . ." << endl;
		}
		cn.cerrar_conexion();
	}

	// Metodos actualizar
	void actualizar_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("producto:\n ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo producto:\n ";
						getline(cin, producto);
						string modificar = "update productos set producto = '" + producto + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_idmarca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("idmarca: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo id marca:\n ";
						getline(cin, idmarca);
						string modificar = "update productos set idmarca = '" + idmarca + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_descripcion(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("descripcion:\n ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva descripcion:\n ";
						getline(cin, descripcion);
						string modificar = "update productos set descripcion = '" + descripcion + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_imagen() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("imagen:\n ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva imagen:\n ";
						getline(cin, imagen);
						string modificar = "update productos set imagen = '" + imagen + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_costo() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("precio costo:\n ") << fila[5] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo precio costo:\n ";
						getline(cin, precio_costo);
						string modificar = "update productos set precio_costo = '" + precio_costo + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_venta() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("precio venta:\n ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo precio venta:\n ";
						getline(cin, precio_venta);
						string modificar = "update productos set precio_venta = '" + precio_venta + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_existencia() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "\nIngrese el id del registro que desea modificar:\n ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto:\n " << fila[0] << endl;
					cout << ("existencia:\n ") << fila[7] << endl;
					cout << ("Desea modificarlo [s/n]:\n ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva existencia:\n ";
						getline(cin, existencia);
						string modificar = "update productos set existencia = '" + existencia + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_fecha() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from productos where idproducto =" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto: " << fila[0] << endl;
					cout << ("Fecha ingreso: ") << fila[8] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva fecha de ingreso: ";
						getline(cin, fecha_ingreso);
						string modificar = "update productos set fecha_ingreso = '" + fecha_ingreso + "' where idproducto =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}
};


