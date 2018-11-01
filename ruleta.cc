#include "ruleta.h"
#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <list>

using namespace std;

	Ruleta::Ruleta(Crupier crupier):crupier_(crupier){
		srand(time(NULL));
		bola_=-1;
		banca_=1000000;
	}

	bool Ruleta::addJugador(Jugador player){	
		list<Jugador>::iterator i; //i es un iterador para recorrer la lista
								   //i es un puntero al inicio de la lista

		for(i=jugadores_.begin(); i!=jugadores_.end();i++){
			if(player.getDNI()==(*i).getDNI()){ //se pone (*i) pq accedemos al contenido del puntero en la lista
				return false; 
			}
		}
		jugadores_.push_back(player);
		string cadena=player.getDNI()+".txt";
		ifstream salida(cadena.c_str());
		if(salida){
			cout<<"El fichero existe."<<endl;
			return false;
		}
		else{
			ofstream salida(cadena.c_str());
			salida.close();
		}
		return true;
	}

	bool Ruleta::setBanca(int num){
		if(num<0){
			return false;
		}
		else{
			banca_=num;
			return true;
		}
	}

	bool Ruleta::setBola(int ball){
		if((ball<0)||(ball>36)){
			return false;
		}
		else{
			bola_=ball;
			return true;
		}
	}


	int Ruleta::deleteJugador(string dni){
		list<Jugador>::iterator i; //i es un iterador para recorrer la lista
								   //i es un puntero al inicio de la lista
		if(jugadores_.empty()){
			return -1;
		}
		for(i=jugadores_.begin(); i!=jugadores_.end();i++){
			if(dni==(*i).getDNI()){ //se pone (*i) pq accedemos al contenido del puntero en la lista
				jugadores_.erase(i);
				return 1;
			}
		}
		return -2;
	}
/*
En esta funcion utilizaremos la sobrecarga de funciones
Realizando la llamada a la funcion deleteJugador introduciendole otro parametro
*/

	int Ruleta::deleteJugador(Jugador player){
		list<Jugador>::iterator i; //i es un iterador para recorrer la lista
								   //i es un puntero al inicio de la lista
		if(jugadores_.empty()){
			return -1;
		}
		for(i=jugadores_.begin(); i!=jugadores_.end();i++){
			if(player.getDNI()==(*i).getDNI()){ //se pone (*i) pq accedemos al contenido del puntero en la lista
				jugadores_.erase(i);
				return 1;
			}
		}
		return -2;
	}

/*
La siguiente funcion se encarga de escribir los jugadores existentes en la lista
en un fichero de texto denominador jugadores.txt
*/

	void Ruleta::escribeJugadores(){

		list<Jugador>::iterator i; 
		/*		
		Creacion y apertura del fichero con flujo de salida.
		Comprobacion de la apertura del fichero.
		*/
		ofstream fichero_s("jugadores.txt");
		
		for(i=jugadores_.begin(); i!=jugadores_.end();i++){
			/*
			Utilizamos el operador << para escribir directamente sobre el fichero
			concatenando con las comas consiguiendo un formato:
			DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
			*/
			fichero_s<<(*i).getDNI()<<","<< (*i).getCodigo()<<","<< (*i).getNombre()<<","<< (*i).getApellidos()<<","<< (*i).getDireccion()<<","<< (*i).getLocalidad()<<","<< (*i).getProvincia()<<","<< (*i).getPais()<<","<< (*i).getDinero()<<endl;
		}


		fichero_s.close();
		//cerramos el fichero

	}


/*
Lectura de los datos de los jugadores en el fichero anteriormente creado.
Vaciado de la lista previo a insertar los datos leidos.
*/
	void Ruleta::leeJugadores(){

		ifstream fichero_e("jugadores.txt");
		jugadores_.clear();
		string DNI,cadena, nombre, codigo, apellidos, direccion, localidad, provincia, pais;
		int dinero=0;
		/*
		Leemos el fichero hasta que encontremos el final.
		Vamos guardando los datos sobre el jugador en sus respectivas variables.
		*/	
		while(!fichero_e.eof()){
			getline(fichero_e,DNI,',');
			if (DNI.empty()){
				break;
			}
			getline(fichero_e,codigo,',');
			Jugador j1(DNI,codigo);

			getline(fichero_e,nombre,',');
			j1.setNombre(nombre);

			getline(fichero_e,apellidos,',');
			j1.setApellidos(apellidos);

			getline(fichero_e,direccion,',');
			j1.setDireccion(direccion);

			getline(fichero_e,localidad,',');
			j1.setLocalidad(localidad);

			getline(fichero_e,provincia,',');
			j1.setProvincia(provincia);

			getline(fichero_e,pais,',');
			j1.setPais(pais);

			getline(fichero_e,cadena,'\n');
			cadena=atoi(cadena.c_str());
			j1.setDinero(dinero);
		
			jugadores_.push_back(j1);
		}
		fichero_e.close();
	}

	void Ruleta::giraRuleta(){
		bola_=rand()%37;
		tiradas_=tiradas_+1;
	}




/*
Recorre la lista actualizando el dinero de los jugadores segun su premio.
Actualiza el valor de la banca segun los premios que ha repartido.
*/
	void Ruleta::getPremios(){
		list<Apuesta>listaapuestas;
		list<Jugador>::iterator a1;
		list<Apuesta>::iterator b2;

		/*
		Recorremos la lista de jugadores para comprobar su lista de apuestas
		*/
		for(a1=jugadores_.begin(); a1!=jugadores_.end();a1++){
			int dinero=0;			//variable que guarda el dinero ganado o perdido
			(*a1).setApuestas();	//Establezco las apuestas del jugador (*a1)
			listaapuestas=(*a1).getApuestas(); //relleno mi lista con las apuestas del jugador
			dinero=(*a1).getDinero();//tomo el dinero que tiene el jugador

			//Recorro la lista de apuestas y compruebo que tipo de apuestas
			//ha realizado
			for(b2=listaapuestas.begin(); b2!=listaapuestas.end();b2++){
				switch((*b2).tipo){
					case 1:
					//Apuesta sencilla
						apuestaSencilla(dinero,(*b2));
						cout<<"TIENE "<<(*a1).getDinero()<<endl;
						cout<<"Banca TIENE"<<getBanca()<<endl;
						break;
					case 2:
					//Rojo o negro
						apuestaRojoNegro(dinero,(*b2));
						cout<<"TIENE"<<(*a1).getDinero()<<endl;
						cout<<"Banca TIENE"<<getBanca()<<endl;
						break;
					case 3:
					//Par o impar
						apuestaParImpar(dinero,(*b2));
						cout<<"TIENE"<<(*a1).getDinero()<<endl;
						cout<<"Banca TIENE"<<getBanca()<<endl;
						break;

					case 4:
					//Alto o bajo
						apuestaAltoBajo(dinero,(*b2));
						cout<<"TIENE"<<(*a1).getDinero()<<endl;
						cout<<"Banca TIENE"<<getBanca()<<endl;
						break;

			//el parámetro (*b2) hace refencia a la apuesta de cada jugador
			//con el accedemos a la cantidad apostada y el valor de la apuesta

				}
				//Establezco el nuevo dinero
				(*a1).setDinero(dinero);

				//Lo escribo en el fichero de jugadores
				escribeJugadores();

			}
		}
	}



	void Ruleta::apuestaSencilla(int &dinero, Apuesta p){
		if((bola_==atoi(p.valor.c_str()))){
			dinero=dinero+(p.cantidad)*35;
			banca_=banca_-(p.cantidad)*35;
		}
		else{
			//Perdemos lo que apostamos no lo que vamos a ganar
			dinero=dinero-(p.cantidad);
			banca_=banca_+(p.cantidad);
		}
		


	}
	void Ruleta::apuestaRojoNegro(int &dinero, Apuesta p){
		if((bola_!=0 && p.valor==color(bola_))){
			dinero=dinero+(p.cantidad);
			banca_=banca_-(p.cantidad);
		}
		else{
			dinero=dinero-(p.cantidad);
			banca_=banca_+(p.cantidad);
		}
		
	}

	string Ruleta::color(int bola){
		switch(bola){
			case 1:
				return "rojo";
			case 3:
				return "rojo";
			case 5:
				return "rojo";
			case 7:
				return "rojo";
			case 9:
				return "rojo";
			case 12:
				return "rojo";
			case 14:
				return "rojo";
			case 16:
				return "rojo";
			case 18:
				return "rojo";
			case 19:
				return "rojo";
			case 21:
				return "rojo";
			case 23:
				return "rojo";
			case 25:
				return "rojo";
			case 27:
				return "rojo";
			case 30:
				return "rojo";
			case 32:
				return "rojo";
			case 34:
				return "rojo";
			case 36:
				return "rojo";
		//En el caso de que no cumpla ningun case...
			default:
				return "negro";
		}
	}

	void Ruleta::apuestaParImpar(int &dinero, Apuesta p){
		if((bola_!=0 && p.valor==paridad(bola_))){
			dinero=dinero+(p.cantidad);
			banca_=banca_-(p.cantidad);
		}
		else{
			dinero=dinero-(p.cantidad);
			banca_=banca_+(p.cantidad);
		}

	}

	string Ruleta::paridad(int bola){
		if(bola%2==0){return "par";}
		else{return "impar";}
	}

	void Ruleta::apuestaAltoBajo(int &dinero, Apuesta p){
		if((bola_!=0 && p.valor==AB(bola_))){
			dinero=dinero+(p.cantidad);
			banca_=banca_-(p.cantidad);
		}
		else{
			dinero=dinero-(p.cantidad);
			banca_=banca_+(p.cantidad);
		}
	}

	string Ruleta::AB(int bola){
		if(bola>0 && bola< 19){return "bajo";}
		else{return "bajo";}
	}



	void GetEstadoRuleta(int &jugTotal, int &sumaDinero,int &tiradas, int &bancaTotal){
		list<Jugaor>::iterator i;
		sumaDinero=0;
		for (i = jugadores_.begin(); i !=jugadores_.end(); i++){
			sumaDinero=sumaDinero+(*i).getDinero;
		}
		sumaDinero=sumaDinero+getBanca();
		jugTotal=jugadores_.size();
		tiradas=tiradas_;
		bancaTotal=getBanca();
	}
