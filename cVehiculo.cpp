#include "cVehiculo.h"

cVehiculo::cVehiculo(Color color_, string patente, float precioDia, Tipo_Vehiculo tipo_)
{
	color = color_;
	Patente = patente;
	
	Precio_Dia = precioDia;
	tipo = tipo_;

	Estado = false; //no esta alquilado
	Verificado = true;//empieza con la seguridad verificada
	
	switch (tipo)
	{
	case Tipo_Vehiculo::Camioneta:
		Cant_Pasajeros = 5;
		break;
	case Tipo_Vehiculo::Moto:
		Cant_Pasajeros = 1;
		break;
	case Tipo_Vehiculo::Carro:
		Cant_Pasajeros = 5;
		break;
	case Tipo_Vehiculo::Monovolumen:
		Cant_Pasajeros = 8;
		break;
	}

	switch (tipo)
	{
	case Tipo_Vehiculo::Camioneta:
		Precio_Base = 50.0;
		break;
	case Tipo_Vehiculo::Moto:
		Precio_Base = 30.0;
		break;
	case Tipo_Vehiculo::Carro:
		Precio_Base = 40.0;
		break;
	case Tipo_Vehiculo::Monovolumen:
		Precio_Base = 70.0;
		break;
	}

}

cVehiculo::~cVehiculo()
{
}

void cVehiculo::VerificacionSeguridad()
{
	Verificado = true; 
	cout << "La seguridad del auto ha sido verificada" << endl;
}

void cVehiculo::VerificacionSeguridadPendiente()
{
	Verificado = false; 
	cout << "La verificacion del auto esta pendiente" << endl;
}

bool cVehiculo::VerificarAlquiler()
{
	if (Estado == true)
		return true;
	if (Estado == false)
		return false;
}

string cVehiculo::To_String()
{
	string col = To_String_Color();;
	string tip = To_string_Vehiculo();
	string aux = "DATOS DEL VEHICULO\nTipo de Vehiculo: " + tip =
		"\nColor: " + col +
		"\nPatente: " + Patente +
		"\nPrecio Base: " + to_string(Precio_Base) +
		"Precio por dia: " + to_string(Precio_Dia);
	return aux;


}

string cVehiculo::To_string_Vehiculo()
{
	switch (tipo)
	{
	case Tipo_Vehiculo::Camioneta:
		return "Camioneta";
		break;
	case Tipo_Vehiculo::Moto:
		return "Moto";
		break;
	case Tipo_Vehiculo::Carro:
		return "Carro";
		break;
	case Tipo_Vehiculo::Monovolumen:
		return "Monovolumen";
		break;
	default:
		return "";
		break;
	}
	return string();
}

string cVehiculo::To_String_Color()
{
	switch (color)
	{
	case Color::Amarillo:
		return "Amarillo";
		break;
	case Color::Rojo:
		return "Rojo";
		break;
	case Color::Negro:
		return "Negro";
		break;
	case Color::Plateado:
		return "Plateado";
		break;
	case Color::Blanco:
		return "Blanco";
		break;
	case Color::Morado:
		return "Morado";
		break;
	default:
		return "";
		break;
	}
	return string();
}

void cVehiculo::imprimir()
{
	cout <<To_String() << endl;
}
