/*
persona.h
Declaracion de la clase Persona
*/

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using std::string;


class Persona{
	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		int edad_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;

	public:
		//Constructor de la clase Persona 
		Persona(string DNI, string nombre="", string apellidos="",int edad=0, string direccion="", string localidad="", string provincia="", string pais=""); //mirar parámetros obligatorios
/*
setDNI():
Funcion en linea que establece el DNI de cada persona que recibe como parametro 
getDNI():
Funcion en linea y constante que devuelve el DNI de cada persona
*/
		inline void setDNI(string dni){DNI_=dni;}
		inline string getDNI()const{return DNI_;}
/*
setNombre():
Funcion en linea que establece el nombre de cada persona que recibe 
como parametro
getNombre():
Funcion en linea y constante que devuelve el nombre cada persona
*/
		inline void setNombre(string nombre){nombre_=nombre;}
		inline string getNombre()const{return nombre_;}
/*
setApellidos():
Funcion en linea que establece los apellidos de cada persona que recibe 
como parametro
getApellidos():
Funcion en linea y constante que devuelve los apellidos de cada persona
*/
		inline void setApellidos(string apellidos){apellidos_=apellidos;}
		inline string getApellidos()const{return apellidos_;}
/*
setEdad():		
Funcion que establece la edad de cada persona que recibe como parametro,
devuelve false en caso de recibir una edad negativa.
getEdad():
Funcion en linea y constante que devuelve la edad de cada persona
*/
		bool setEdad(int edad);
		inline int getEdad()const{return edad_;}
/*
setDireccion():		
Funcion que establece la direccion de cada persona que recibe como parametro
getDireccion():
Funcion en linea y constante que devuelve la direccion de cada persona
*/
		inline void setDireccion(string direccion){direccion_=direccion;}
		inline string getDireccion()const{return direccion_;}
/*
setLocalidad():
Funcion en linea que establece la localidad de cada persona que recibe 
como parametro
getLocalidad():
Funcion en linea y constante que devuelve la localidad de cada persona
*/
		inline void setLocalidad(string localidad){localidad_=localidad;}
		inline string getLocalidad()const{return localidad_;}

/*
setProvincia():
Funcion en linea que establece la provincia de cada persona que recibe 
como parametro
getProvincia():
Funcion en linea y constante que devuelve la provincia de cada persona
*/
		inline void setProvincia(string provincia){provincia_=provincia;}
		inline string getProvincia()const{return provincia_;}
		
/*
setPais():
Funcion en linea que establece el pais donde reside cada persona que recibe
como parametro
getPais():
Funcion en linea y constante que devuelve el pais cada persona
*/
		inline void setPais(string pais){pais_=pais;}
		inline string getPais()const{return pais_;}

/*
Funcion que devuelve la concatenacion de los apellidos con el nombre 
del jugador separados por una coma
*/
		string getApellidosyNombre(); 

//Funcion que nos indica si una persona es mayor de edad
		bool mayor(); 



};



#endif
