/*
main.cc
Para compilar: g++  persona.cc jugador.cc crupier.cc ruleta.cc main.cc -o ruleta
*/

#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"

#include <string.h>
#include <stdlib.h>
#include <list>
#include <fstream>

using namespace std;

int main(){
	//Opcion del menu
	int opcion;

	//Declaracion de variables
	int jugTotal,sumaDinero,tiradas,bancaTotal, edad,diner;
	string DNI,nombre,codigoCrupier,codigoJugador,apellidos,direccion,localidad,provincia,pais, valor;
	string cadena,apellido1,apellido2;
	//Declaracion de los objetos de las clases
	Persona p(DNI,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	crupier c(DNI,codigoCrupier,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	Jugador j(DNI,codigoJugador,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	Ruleta r(c);

	do{
		cout<<"______________________________________________"<<endl;
		cout<<"Elija una opción de la Ruleta:"<<endl;

		cout<<"1. Añadir a un jugador a la mesa"<<endl;//f

		cout<<"2. Eliminar a un jugador de la mesa"<<endl;//e

		cout<<"3. Ver el estado de la Ruleta "<<endl;//c

		cout<<"4. Cargar la Ruleta con el registro"<<endl;//a

		cout<<"5. Guardar en el Registro los jugadores"<<endl;//b

		cout<<"6. Girar la ruleta y mostrar premios"<<endl;//d

		cout<<"7. Salir del programa "<<endl;//g
		cout<<"______________________________________________"<<endl;

		switch(opcion){
			case 1:
				cout<<"______________________________________________"<<endl;
				cout<<"Introduzca los datos del jugador..."<<endl;
				cout<<"Introduzca su DNI :"<<endl;
				cinn>>cadena;
				j.setDNI(cadena);

				cout<<"Introduzca su nombre :"<<endl;
				cin>>cadena;
				j.setNombre(cadena);

				cout<<"Introduzca su primer apellido :"<<endl;
				cin>>apellido1;
				cout<<"Introduzca su segundo apellido :"<<endl;
				cin>>apellido2;
				apellidos=apellido1+" "+apellido2;
				j.setApellido(apellidos);

				cout<<"Introduzca su edad :"<<endl;
				cin>>edad;
				j.setEdad(edad);

				cout<<"Introduzca su direccion :"<<endl;
				getline(cin,cadena);
				j.setDireccion(direccion);

				cout<<"Introduzca su Localidad :"<<endl;
				cin>>cadena;
				j.setLocalidad(cadena);

				cout<<"Introduzca su Provincia :"<<endl;
				cin>>cadena;
				j.setProvincia(cadena);

				cout<<"Introduzca su Pais :"<<endl;
				cin>>cadena;
				j.setPais(cadena);

				cout<<"Introduzca el dinero de inicio :"<<endl;
				cin>>dinero;
				j.setDinero(dinero);

				//Utilizamos el metodo de la clase ruleta.
				r.addJugador(j);

				cout<<"Jugador introducido con exito!"<<endl;
				cout<<"______________________________________________"<<endl;
				break;

			case 2:
			case 3:
				cout<<"______________________________________________"<<endl;

				r.getEstadoRuleta(jugTotal,sumaDinero,tiradas,bancaTotal);
				cout<<"La ruleta contiene : "<<jugTotal<<". \nEl dinero actual de la mesa es : "<<sumaDinero<<"€. \nLa bola se ha tirado : "<<tiradas<<" veces. \nEl dinero de la banca es : "<<bancaTotal<"€."<<endl;

				cout<<"______________________________________________"<<endl;
				break;				
			case 4:
			case 5:
			case 6:
			

		}





	}while((opcion!=7)&&(opcion>0));
	return 0;
}