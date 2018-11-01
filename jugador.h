/*
jugador.h
Declaracion de la clase Jugador que hereda la parte publica de la clase
Persona.
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <iostream>
#include <string>
#include <fstream> 
#include <list>

using std::string;
using std::list;

/*
Declaracion de la estructura apuesta compuesto por el tipo de apuesta,
el valor al que realiza la apuesta y la cantidad que apuesta el jugador. 
*/

struct Apuesta{
			int tipo;
			string valor;
			int cantidad;			
		};


class Jugador : public Persona{
	private:
		int dinero_;
		string codigo_; 
		list<Apuesta> apuesta_;



	public:
		//Constructor de la clase Jugador con dos parametros obligatorios
		Jugador(string DNI, string codigo, string nombre="", string apellidos="",int edad=0, string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre,apellidos,edad,direccion,localidad,provincia,pais){codigo_=codigo; dinero_=1000;};
/*
setCodigo():
Funcion en linea que establece el codigo de cada jugado recibido como parametro
getCodigo():
Funcion en linea y constante que devuelve el codigo de cada jugador
*/
		inline void setCodigo(string codigo){codigo_=codigo;}
		inline string getCodigo()const {return codigo_;}
/*
setDinero():
Funcion en linea que establece el dinero de cada jugado recibido como parametro
getDinero():
Funcion en linea y constante que devuelve el dinero de cada jugador
*/		
		inline void setDinero(int dinero){dinero_=dinero;}
		inline int getDinero()const{return dinero_;}
/*
setApuestas():
Funcion que establece las apuestas realizadas por cada jugador
getApuestas():
Funcion en linea que devuelve la lista de apuestas ralizadas por cada jugador
*/
		void setApuestas();
		inline list<struct Apuesta> getApuestas()const{return apuesta_;}
		



	};



#endif


