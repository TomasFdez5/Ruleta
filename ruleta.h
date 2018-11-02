/*ruleta.h
Declaracion de la clase Ruleta
*/

#ifndef RULETA_H_
#define RULETA_H_

#include "persona.h"
#include "crupier.h"
#include "jugador.h"
#include <list>
#include <time.h>


class Ruleta {
	private:
		int banca_;
		int bola_;
		list<class Jugador> jugadores_;
		Crupier crupier_;
		int tiradas_;

	public:
		/*
		Constructor de la clase Ruleta que recibe como parámetro un objeto 
		de la clase Crupier
		*/
		Ruleta(Crupier crupier);
/*
setBanca():		
Funcion que establece el valor de la banca que recibe como parametro,
devuelve false en caso de recibir un valor negativo.
getBanca():
Funcion en linea y constante que devuelve el valor de la banca
*/
		bool setBanca(int num);
		inline int getBanca() const{return banca_;}
/*
setBola():		
Funcion que establece el valor de la bola que recibe como parametro,
devuelve false en caso de recibir un valor negativo o mayor que 36.
getBola():
Funcion en linea y constante que devuelve el valor de la bola
*/
		bool setBola(int ball);
		inline int getBola() const{return bola_;}
/*
setCrupier():		
Funcion que establece el objeto crupier que recibe como parametro
getCrupier():
Funcion en linea y constante que devuelve el objeto crupier
*/
		inline void setCrupier(Crupier crup){ crupier_=crup;}
		Crupier getCrupier()const{return crupier_;}
/*
getJugadores():
Funcion que devuelve la lista de jugadores existentes
*/
		inline list<Jugador> getJugadores()const{return jugadores_;}

/*
addJugador():
Funcion que se encarga de añadir un jugador, recibido como parametro, a la lista de
jugadores y crear su fichero de apuestas
deleteJugador():
Funcion que elimina un jugador de la lista de jugadores por su DNI o por el objeto 
Jugador recibido como parametro (sobrecarga de funciones)
*/		
		bool addJugador(Jugador player);
		int deleteJugador(string dni);
		int deleteJugador(Jugador player);

/*
escribeJugadores():
Funcion que escribe la lista jugadores en un fichero de texto
leeJugadores():
Funcion que lee los datos de los jugadores del fichero de texto y los introduce en la lista
de jugadores
*/
		void escribeJugadores();
		void leeJugadores();
		
/*
giraRuleta():
Simula la tirada de la bola en la ruleta obteniendo un número aleatorio.
*/
		void giraRuleta();

/*
getPremios():
Funcion que se encarga de recorrer la lista de jugadores y actualiza el dinero
segun lo que ha ganado o ha perdido en cada una de sus apuestas
*/
		void getPremios();

/*
Funciones modificadoras del valor de la banca y dinero de cada jugador segun la
apuesta realizada
*/
		void apuestaSencilla(int &dinero, Apuesta p);
		void apuestaRojoNegro(int &dinero, Apuesta p);
		void apuestaParImpar(int &dinero, Apuesta p);
		void apuestaAltoBajo(int &dinero, Apuesta p);

//Funciones adicionales que comprueban la paridad, color y nivel del valor de la bola
		string color(int bola);
		string paridad(int bola);
		string AB(int bola);


		void getEstadoRuleta(int &jugTotal, int &sumaDinero,int &tiradas, int &bancaTotal);

};



#endif
