#ifndef _TCOMPLEJO_H_
#define _TCOMPLEJO_H_

#include "tcomplejo.h"

class TVectorCom {

	private:
		TComplejo *c;
		int tamano;
		TComplejo er;
	public:

		//Forma canónica
		TVectorCom();
		TVectorCom(const int);
		TVectorCom(const TVectorCom &);
		~TVectorCom();
		TVectorCom & operator=(const TVectorCom &);

		//Sobrecarga operador igualdad
		bool operator ==(const TVectorCom &) const;
		//Sobrecarga del operador desigualdad
		bool operator !=(const TVectorCom &) const;
		//Sobrecarga del operador corchete (parte IZQUIERDA)
		TComplejo & operator[](const int);
		//Sobrecarga del operador corchete (parte DERECHA)
		TComplejo operator[](const int) const;
		//Tamaño del vector (posiciones TOTALES)
		int Tamano() const;
		//Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector
		int Ocupadas() const;
		//Devuelve TRUE si existe el TComplejo en el vector.
		bool ExisteCom(const TComplejo &) const;
		//Mostrar por pantalla los elementos TComplejo del vector con
		//PARTE REAL IGUAL O POSTERIOR al argumento
		void MostrarComplejos(const double) const;
		//REDIMENSIONAR el vector de TComplejo
		bool Redimensionar(const int);

		//Funciones amigas
		friend ostream & operator<<(ostream &, const TVectorCom &);

};

#endif
