#pragma once
#include "cCliente.h"
#include "cVehiculo.h"
#include <ctime>
//#define _CRT_SECURE_NO_WARNINGS

class cAlquiler
{
private:
	//Atributos
	cCliente* Cliente;
	cVehiculo* Vehiculo_Alquilado;
	tm* fecha_actual;
	tm* fecha_devolucion;
	int ID;
	float MontoTotal;

public:
	//constructor y destructor
	cAlquiler(cCliente* cliente, cVehiculo* vehiculo, tm* fecha_devolucion, int id);
	~cAlquiler();


	void CalcularMontoTotal();//Calcula el montom a pagar del alquiler del vehiculo
	void ElegirAuto(); // Da a elegir el vehiculo que el cliente desee
	void FinalizarAlquiler(); // Al devolver el vehiculo finaliza el alquiler
	int DiasdeReserva(); //Calcula los dias de reserva del vehiculo
	void Ejecutar_Alquiler(); //pasos a seguir del cliente 
	
	//getters  setters
	float getmontototal() { return MontoTotal; };
	int getid() { return ID; };
	string getclientename();
	string getstringcliente();
	bool getestadocliente();
	string to_string();
	void imprimir();

};

