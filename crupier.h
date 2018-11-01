/*
crupier.h
Declaracion de la clase Crupier que hereda la parte publica de la clase
Persona.
*/

#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>


using std::string;

class Crupier : public Persona{
	private:
		string codigo_; 

	public:
		//Constructor de la clase Crupier
		Crupier(string DNI, string codigo, string nombre="", string apellidos="",int edad=0, string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre,apellidos,edad,direccion,localidad,provincia,pais){codigo_=codigo;};
/*
setCodigo():
Funcion en linea que establece el codigo de cada crupier recibido 
como parametro
getCodigo():
Funcion en linea y constante que devuelve el codigo de cada crupier
*/
		inline void setCodigo(string cod){codigo_=cod;}
		inline string getCodigo()const{return codigo_;}


};



#endif
