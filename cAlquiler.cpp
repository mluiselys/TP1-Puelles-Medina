#define _CRT_SECURE_NO_WARNINGS
#include "cAlquiler.h"
#include<sstream>


cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, tm* fecha_devolucion, int id)
{
	Cliente = cliente;
	Vehiculo_Alquilado = vehiculo;
	ID = id;
	MontoTotal = 0;
	this->fecha_devolucion = fecha_devolucion;

	//fecha actual
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fecha_actual = timeinfo;
}

cAlquiler::~cAlquiler() {
}

void cAlquiler::CalcularMontoTotal() {
	int cantidad_dias_reserva = DiasdeReserva();
	
	MontoTotal = (Vehiculo_Alquilado->getPreciobase() + Vehiculo_Alquilado->getpreciodia() * cantidad_dias_reserva);

	cout << "El monto total a pagar es: " << MontoTotal << endl;
}

void cAlquiler::ElegirAuto() {
	//verifica que el auto sea el mismo, que tenga la seguridad y que no este en alquiler para elegirlo
	if (Cliente->gettipo() == Vehiculo_Alquilado->gettipo() && Vehiculo_Alquilado->getEstado() == false && Vehiculo_Alquilado->getverificado() == true)
		Vehiculo_Alquilado->setestado(true);

}

void cAlquiler::FinalizarAlquiler() {
	fecha_actual->tm_mon = fecha_devolucion->tm_mon;
	fecha_actual->tm_mday = fecha_devolucion->tm_mday;
	fecha_actual->tm_year = fecha_devolucion->tm_year;//lo igualo para probar que funcione
	//verifica si la fecha actual es la misma que la de devolucion 
	if (fecha_actual->tm_mday == fecha_devolucion->tm_mday && fecha_actual->tm_mon == fecha_devolucion->tm_mon && fecha_actual->tm_year == fecha_devolucion->tm_year)
	{
		cout << "ALQUILER FINALIZADO\n" << endl;
		Vehiculo_Alquilado->setestado(false); //termina el alquiler
		Vehiculo_Alquilado->VerificacionSeguridadPendiente(); //llama a la verificacion de seguridad pendiente
	}
}

int cAlquiler::DiasdeReserva()
{
	
	int diasreserva;
	int dia = fecha_actual->tm_mday;
	int mes = fecha_actual->tm_mon + 1;
	int anio = fecha_actual->tm_year + 1900;

	//calculamos los dias desde el inicio de la era hasta esa fecha en las dos ocasiones y luego se restan 
	long int dias1 = (anio * 365) + (mes * 30) + dia;
	long int dias2 = ((fecha_devolucion->tm_year) * 365) + ((fecha_devolucion->tm_mon) * 30) + fecha_devolucion->tm_mday;
	diasreserva = dias2 - dias1;
	cout << "El cliente alquila el auto por " << diasreserva << " dias" << endl;
	return diasreserva;
	
}

string cAlquiler::getclientename()
{
	return Cliente->getNombreyapellido(); 
}

string cAlquiler::getstringcliente()
{
	return  Cliente->to_string();

}

bool cAlquiler::getestadocliente()
{
	return Cliente->getEstado();
}

void cAlquiler::Ejecutar_Alquiler()
{
	ElegirAuto();
	CalcularMontoTotal();
	Cliente->Pagar(this);
	FinalizarAlquiler();
}

string cAlquiler::to_string()
{
	stringstream ss;

	ss << Cliente->to_string() << endl;
	ss << "Vehiculo: " << Vehiculo_Alquilado << endl;
	ss << "ID del Alquiler: " << ID << endl;
	ss << "Monto total: " << MontoTotal << endl;

	return ss.str();
	
}

void cAlquiler::imprimir()
{
	string imprimir2 = to_string();
	cout << imprimir2;
}
