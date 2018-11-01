
#include "persona.h"
#include "jugador.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream> //LIBERIRA PARA UTILIZACION DE FICHEROS
#include <list>



using namespace std;

void Jugador::setApuestas(){
	apuesta_.clear(); //La funcion Clear me borra el contenido de la lista
	string nombre=(getDNI()+".txt");
	ifstream entrada(nombre.c_str());
	
	if(entrada.fail()){
		exit(-1);
	}
	/*
	Como la funcion es un string tenemos que convertirlo con la 
	función c_str() ATENTOOO!!!!
	*/

	struct Apuesta aux;
	string tipo, valor,cantidad;
	string cadena21;
	while(!entrada.eof()){
		getline(entrada,tipo,',');
		if(strcmp(tipo.c_str(),cadena21.c_str())==0){
			break;
		}
		aux.tipo=atoi(tipo.c_str());
		getline(entrada,valor,',');
		aux.valor=valor;
		getline(entrada,cantidad);
		aux.cantidad=atoi(cantidad.c_str());
		apuesta_.push_back(aux);
	}
	
	entrada.close();

}