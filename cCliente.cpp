#include "cCliente.h"
#include "cAlquiler.h"
#include<sstream>

cCliente::cCliente(string dni, string email, string NombreyApe, int telf, Tipo_Vehiculo tipo_) {
	DNI = dni;
	Email = email;
	NombreyApellido = NombreyApe;
	Telefono = telf;
	tipo = tipo_;
	Estado_pagado = false;
}

cCliente::~cCliente() {

}

void cCliente::Pagar(cAlquiler* alquiler) 
{

	if (alquiler->getclientename() == NombreyApellido) //si es el mismo cliente, cambia el estado a pagado
	{
		alquiler->getestadocliente() == true;
		cout << "PAGADO\n" << endl;
	}
	else
	{
		cout << "Este no es el alquiler que le coresponde al cliente" << endl;
		cout << "NO ESTA PAGO\n" << endl;
		Estado_pagado = false;
	}
}

string cCliente::to_string()
{
	stringstream ss;

	ss << "CLIENTE: " << endl;

	ss << "DNI: " << DNI << endl;
	ss << "Email: " << Email << endl;
	ss << "Nombre y Apellido: " << NombreyApellido << endl;
	ss << "Telefono: " << Telefono << endl;
	

	return ss.str();
}

void cCliente::imprimir()
{
	string imprimir2 = to_string();
	cout << imprimir2;
}
