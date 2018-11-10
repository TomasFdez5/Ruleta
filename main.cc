/*
main.cc
Para compilar: g++  persona.cc jugador.cc crupier.cc ruleta.cc main.cc -o ruleta
*/

#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"

#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <fstream>

//using namespace ruleta;
using namespace std;

int main(){
	//Opcion del menu
	int opcion=1;
	int encontrado=0,resultado=0,numero=0,i=0,nApuestas=0;
	string vacio;

	list<Jugador>aux;
	list<Jugador>::iterator a1;
	Apuesta auxAp;

	//Declaracion de variables
	int jugTotal,sumaDinero,tiradas,bancaTotal, edad,dinero;
	string DNI,nombre,codigoCrupier,codigoJugador,apellidos,direccion,localidad,provincia,pais, valor;
	string cadena,apellido1,apellido2;
	//Declaracion de los objetos de las clases
	Persona p(DNI,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	Crupier c(DNI,codigoCrupier,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	Jugador j(DNI,codigoJugador,nombre,apellidos,edad,direccion,localidad,provincia,pais);
	Ruleta r(c);

		//cout<<"Intro para comenzar..."<<endl;
	do{
		//getchar();
		cout<<"______________________________________________"<<endl;
		cout<<"Elija una opción de la Ruleta:"<<endl;

		cout<<"1. Añadir a un jugador a la mesa"<<endl;//f

		cout<<"2. Eliminar a un jugador de la mesa"<<endl;//e

		cout<<"3. Ver el estado de la Ruleta "<<endl;//c

		cout<<"4. Cargar los jugadores del fichero jugadores.txt"<<endl;//a

		cout<<"5. Guardar en el Registro los jugadores"<<endl;//b

		cout<<"6. Girar la ruleta y mostrar premios"<<endl;//d

		cout<<"7. Añadir una apuesta a un jugador "<<endl;//g

		cout<<"8. Salir del programa "<<endl;//g

		cout<<"______________________________________________"<<endl;

		cout<<"Elija una opcion :"<<endl;
		cin>>opcion;

		switch(opcion){
			case 1:
				cout<<"______________________________________________"<<endl;
				cout<<"Introduzca los datos del jugador. Los marcados con * son campos obligatorios!"<<endl;
				cout<<"Introduzca su DNI* :"<<endl;
				getchar();
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					j.setDNI(cadena);
				}

				cout<<"Introduzca su codigo* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					j.setCodigo(cadena);
				}

				cout<<"Introduzca su nombre :"<<endl;
				getline(cin,cadena);
				j.setNombre(cadena);

				cout<<"Introduzca su primer apellido :"<<endl;
				getline(cin,apellido1);
				cout<<"Introduzca su segundo apellido :"<<endl;
				getline(cin,apellido2);
				apellidos=apellido1+" "+apellido2;
				j.setApellidos(apellidos);

				cout<<"Introduzca su edad :"<<endl;
				getline(cin,cadena);
				edad=atoi(cadena.c_str());				
				j.setEdad(edad);

				cout<<"Introduzca su direccion :"<<endl;
				getline(cin,cadena);
				j.setDireccion(direccion);

				cout<<"Introduzca su Localidad :"<<endl;
				getline(cin,cadena);
				j.setLocalidad(cadena);

				cout<<"Introduzca su Provincia :"<<endl;
				getline(cin,cadena);
				j.setProvincia(cadena);

				cout<<"Introduzca su Pais :"<<endl;
				getline(cin,cadena);
				j.setPais(cadena);

				cout<<"Introduzca el dinero de inicio :"<<endl;
				//cin>>dinero;
				getline(cin,cadena);
				dinero=atoi(cadena.c_str());
				j.setDinero(dinero);

				//Utilizamos el metodo de la clase ruleta.
				r.addJugador(j);

				cout<<"Jugador introducido con exito!"<<endl;
				cout<<"______________________________________________\n"<<endl;
				break;

			case 2:
				cout<<"______________________________________________"<<endl;
				cout<<"Introduzca el dni del jugador que desea eliminar :"<<endl;
				cin>>cadena;

				for(a1 = aux.begin();a1!=aux.end();a1++){
					if(strcmp(cadena.c_str(),(*a1).getDNI().c_str())==0){
						r.deleteJugador(cadena);
						encontrado=1;
						cout<<"Jugador eliminado con exito!"<<endl;
					}
				}
				if(encontrado==0){
					cout<<"No se ha encontrado al jugador que desea borrar..."<<endl;
				}

				cout<<"______________________________________________\n"<<endl;

				break;
			case 3:
				cout<<"______________________________________________"<<endl;

				cout<<"\tEstado de la ruleta :"<<endl;
				r.getEstadoRuleta(jugTotal,sumaDinero,tiradas,bancaTotal);
				cout<<"La ruleta contiene : "<<jugTotal<<" jugadores. \nEl dinero actual de la mesa es : "<<sumaDinero<<"€. \nLa bola se ha tirado : "<<tiradas<<" veces. \nEl dinero de la banca es : "<<bancaTotal<<"€."<<endl;

				cout<<"\tEstado de los jugadores :"<<endl;
				aux=r.getJugadores();
				for(a1 = aux.begin();a1!=aux.end();a1++){
					cout<<"El jugador con DNI "<<(*a1).getDNI()<<" con codigo "<<(*a1).getCodigo()<<" y su dinero restante es: "<<(*a1).getDinero()<<" €."<<endl;
				}
				cout<<"______________________________________________\n"<<endl;
				break;				
			case 4:
				cout<<"______________________________________________"<<endl;
				r.leeJugadores();
				cout<<"Jugadores cargados con exito!"<<endl;


				cout<<"______________________________________________\n"<<endl;
				break;
			case 5:
				cout<<"______________________________________________"<<endl;
				r.escribeJugadores();
				cout<<"Jugadores jugardados con exito!"<<endl;
				cout<<"______________________________________________\n"<<endl;

				break;
			case 6:
				cout<<"______________________________________________"<<endl;
				cout<<"Hagan sus apuestas.........No va mas!!"<<endl;
				r.giraRuleta();
				resultado=r.getBola();
				cout<<"La bola resultante ha sido : "<<resultado<<endl;
				r.getPremios();

				aux=r.getJugadores();
				for(a1=aux.begin();a1!=aux.end();a1++){
					if(r.Apostado()<0){
						cout<<"Jugador "<<a1->getCodigo()<<" con dni "<<a1->getDNI()<<endl;
						cout<<"Ha perdido "<<r.Apostado()<<" €."<<endl;
					}
					if(a1->getDinero()<0){
						cout<<"Al jugador "<<a1->getCodigo()<<" con dni "<<a1->getDNI()<<endl;
						cout<<"Le quedan "<<a1->getDinero()<<" €"<<endl;
						cout<<"Eliminando de la mesa...."<<endl;
						r.deleteJugador(a1->getDNI());
						cout<<"Jugador eliminado de la mesa!."<<endl;

					}
					if(r.Apostado()>0){
						cout<<"Jugador "<<a1->getCodigo()<<" con dni "<<a1->getDNI()<<endl;
						cout<<"Ha ganado "<<r.Apostado()<<" €."<<endl;
					}
				}

				resultado=r.getBanca()-1000000;
				if(resultado<0){
					cout<<"La banca ha perdido "<<resultado<<" €"<<endl;
				}
				else{
					cout<<"La banca ha ganado "<<resultado<<" €"<<endl;
				}

				cout<<"______________________________________________\n"<<endl;
				break;
			
			case 7:

				cout<<"\nIntroduzca cuantas apuestas desea realizar...\n";
				cin>>numero;
				cout<<"Introduzca el DNI del jugador para apostar\n";
				cin>>DNI;
				i=0;
				cout<<"Tipo de apuesta 1: Numero de la Bola\n";
				cout<<"Tipo de apuesta 2: Color \n";
				cout<<"Tipo de apuesta 3: Paridad(Par e Impar)\n";
				cout<<"Tipo de apuesta 4: Nivel(1-18(Bajo) y 19-36(Alto))\n";
				
				cadena=DNI+".txt";
				ofstream salida(cadena.c_str());
				
				do{
					cout<<"Apuesta numero "<<i<<endl;

					cout<<"\nIntroduzca su tipo de apuesta-> ";
					cin>>auxAp.tipo;  

					cout<<"\nIntroduzca su valor de apuesta-> ";
					cin>>auxAp.valor;
						
					cout<<"\nIntroduzca su cantidad de apuesta-> ";
					cin>>auxAp.cantidad;

					salida<<auxAp.tipo<<","<<auxAp.valor<<","<<auxAp.cantidad<<"\n";
					j.setApuestas();

					i++;
					nApuestas++;
				}while(numero>nApuestas);
				salida.close();
			break;
		}

	}while((opcion<8)&&(opcion>0));
	return 0;
}