
#include <iostream>
#include <string>
#include "persona.h"


using std::string;


	Persona::Persona(string DNI, string nombre, string apellidos,int edad, string direccion, string localidad, string provincia, string pais){
		DNI_=DNI;
		nombre_=nombre;
		apellidos_=apellidos;
		edad_=edad;
		direccion_=direccion;
		localidad_=localidad;
		provincia_=provincia;
		pais_=pais;
	}
		
	bool Persona::setEdad(int edad){ 
		if(edad<0){
			return false;		
		}
		else{
			edad_=edad;
			return true;
		}
	}
		
	string Persona::getApellidosyNombre(){//devuelve apellidos,nombre
		string cadena;
		cadena = apellidos_+", "+nombre_;
		return cadena;
	} 

	bool Persona::mayor(){ //devuelve si una persona es mayor de edad
		if ( edad_>18){
			return true;
		}
		else{
			return false;
		}
	} 






