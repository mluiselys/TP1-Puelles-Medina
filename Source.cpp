#include"cAlquiler.h"
#include"cCliente.h"
#include"cEnum.h"
#include"cVehiculo.h"
#include<iostream>
	using namespace std;

int main()
{
	//VEHICULOS 
	cVehiculo* v1 = new cVehiculo(Color::Rojo, "ASD 123", 60.0, Tipo_Vehiculo::Camioneta);
	cVehiculo* v2 = new cVehiculo(Color::Amarillo, "QWE 456", 50.0, Tipo_Vehiculo::Carro);
	cVehiculo* v3 = new cVehiculo(Color::Blanco, "ZXC 678", 70.0, Tipo_Vehiculo::Monovolumen);
	cVehiculo* v4 = new cVehiculo(Color::Morado, "LKJ 098", 40.0, Tipo_Vehiculo::Moto);

	//CLIENTES
	cCliente* c1 = new cCliente("35486248", "cliente1@hotmail.com", "Juan Perez", 1154678521, Tipo_Vehiculo::Camioneta);
	cCliente* c2 = new cCliente("40852963", "cliente2@gmail.com", "Luiselys Medina", 1178945612, Tipo_Vehiculo::Carro);
	cCliente* c3 = new cCliente("36852951", "cliente3@gmail.com", "Lucia Puelles", 1185249636, Tipo_Vehiculo::Monovolumen);
	cCliente* c4 = new cCliente("20852465", "cliente4@gmail.com", "Joaquin Gomez", 1173918426, Tipo_Vehiculo::Moto);
	cCliente* c5 = new cCliente("1779885", "cliente4@gmail.com", "Maria Jose", 1197134862, Tipo_Vehiculo::Camioneta);

	//FECHAS DE DEVOLUCION
	tm* f_devolucion1 = new tm({ 0,0,0,5,1,2022,0,0,0 });
	tm* f_devolucion2 = new tm({ 0,0,0,5,12,2021,0,0,0 });
	tm* f_devolucion3 = new tm({ 0,0,0,21,9,2021,0,0,0 });
	tm* f_devolucion4 = new tm({ 0,0,0,10,10,2021,0,0,0 });
	tm* f_devolucion5 = new tm({ 0,0,0,11,11,2022,0,0,0 });


	//ALQUILERES
	cAlquiler* alquiler1 = new cAlquiler(c1, v1, f_devolucion1, 01);
	cAlquiler* alquiler2 = new cAlquiler(c2, v4, f_devolucion2, 02);
	cAlquiler* alquiler3 = new cAlquiler(c2, v2, f_devolucion3, 03);
	cAlquiler* alquiler4 = new cAlquiler(c3, v3, f_devolucion4, 04);
	cAlquiler* alquiler5 = new cAlquiler(c5, v1, f_devolucion5, 05);

	alquiler1->ElegirAuto();
	alquiler2->ElegirAuto();
	alquiler3->ElegirAuto();
	alquiler4->ElegirAuto();
	alquiler5->ElegirAuto();

	alquiler1->CalcularMontoTotal();
	alquiler2->CalcularMontoTotal();
	alquiler3->CalcularMontoTotal();
	alquiler4->CalcularMontoTotal();
	alquiler5->CalcularMontoTotal();


	c1->Pagar(alquiler1);
	c2->Pagar(alquiler2);//no deberia pagarlo
	c2->Pagar(alquiler3);//ahora si deberia funcionar
	c3->Pagar(alquiler4);
	c5->Pagar(alquiler5);


	
	alquiler1->FinalizarAlquiler();
	alquiler2->FinalizarAlquiler();
	alquiler3->FinalizarAlquiler();
	alquiler4->FinalizarAlquiler();
	alquiler5->FinalizarAlquiler();

	//BORRAMOS MEMORIA
	delete alquiler1;
	delete alquiler2;
	delete alquiler3;
	delete alquiler4;
	delete alquiler5;
	

	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete c5;

	delete v1;
	delete v2;
	delete v3;
	delete v4;

	delete f_devolucion1;
	delete f_devolucion2;
	delete f_devolucion3;
	delete f_devolucion4;
	delete f_devolucion5;

	return 0;
}
