#pragma once
#include <iostream>
#include <string>
#include "cEnum.h"
using namespace std;
class cVehiculo
{
	private:
		//Atributos
		int Cant_Pasajeros; //en el constructor se inicializa de una vez
		float Precio_Base;
		float Precio_Dia;
		bool Estado;
		bool Verificado;
		string Patente;
		Color color; 
		Tipo_Vehiculo tipo;


	public:
		//constructor
		cVehiculo(Color color_, string patente, float precioDia, Tipo_Vehiculo tipo);
		//Destructor
		~cVehiculo();

		//Verifica la seguridad del vehiculo
		void VerificacionSeguridad();
		//Informa que la seguridad de vehiculo esta pendiente
		void VerificacionSeguridadPendiente();
		//Verifica si el vehiculo est alquilado 
		bool VerificarAlquiler();

		//setters y getters
		void setestado(bool estado_) { Estado = estado_; }
		int getCantPasajeros() { return Cant_Pasajeros; };
		Color getcolor() { return color; };
		bool getEstado() { return Estado; };
		string getpatente() { return Patente; };
		float getPreciobase() { return Precio_Base; };
		float getpreciodia() { return Precio_Dia; };
		Tipo_Vehiculo gettipo() { return tipo; };
		bool getverificado() { return Verificado; };
		
		//Se imprime
		string To_String();
		string To_string_Vehiculo();
		string To_String_Color();
		void imprimir();


};

