#include <iostream>
#include "tvectorcom.h"
using namespace std;

TVectorCom::TVectorCom() {
	c = NULL;
	tamano = 0;
}

TVectorCom::TVectorCom(const int tam) {
	tamano = tam;
	if (tamano <= 0)
		c = NULL;
	else
		c = new TComplejo [tamano];
}

TVectorCom::TVectorCom(const TVectorCom &tvc){
	this->tamano = tvc.tamano;
	this->c = new TComplejo[tvc.tamano];
	for (int i= 0; i<tvc.tamano; i++){
		this->c[i] = tvc.c[i];
	}
}

TVectorCom::~TVectorCom() {
	if (c != NULL){
		delete [] c;
		c = NULL;
	}
	tamano = 0;
}

bool TVectorCom::operator==(const TVectorCom &tvc) const{
	bool iguales;
	if (this->tamano != tvc.tamano)
		return false;

	else {
		for (int i = 0; i<tvc.tamano; i++){
			if(this->c[i] != tvc.c[i])
				return false;
		}
	}
	return true;
}

bool TVectorCom::operator!=(const TVectorCom &tvc) const{
	return !(*(this) == tvc);
}

TComplejo& TVectorCom::operator[](const int n) {
	if (n <= tamano && n > 0)
		return c[n-1];
	else
		return er;
}

TComplejo TVectorCom::operator[](const int n) const {
	if (n<= tamano && n > 0)
		return c[n-1];
	else{
		TComplejo tc;
		return tc;
	}
}

int TVectorCom::Tamano() const {
	return tamano;
}

int TVectorCom::Ocupadas() const {
	int contador = 0;
	for (int i = 0; i < tamano; i++){
		if (c[i].Re() != 0 || c[i].Im() != 0)
			contador++;
	}
	return contador;
}

bool TVectorCom::ExisteCom(const TComplejo &tc) const {
	for (int i = 0; i< tamano;i++){
		if(c[i].Re() == tc.Re() && c[i].Im() == tc.Im())
			return true;
	}
	return false;
}

void TVectorCom::MostrarComplejos(const double n) const{
    cout<< "[";
    bool mostrar = false;
	for(int i = 0; i< tamano; i++){
            if (c[i].Re() >= n){
                if(mostrar == true)
                    cout<<", ";
                cout<<c[i];
                mostrar = true;
            }
	}
    cout<<"]";
}

bool TVectorCom::Redimensionar(const int n) {
	if (n <= 0 || n == tamano)
		return false;
	if (n > 0 && n > tamano){
		TVectorCom tvc(n);
		for (int i = 0; i<this->tamano; i++)
			tvc.c[i] = this->c[i];
		delete [] this->c;
		this->tamano = n;
		this->c = new TComplejo[n];
		for (int i = 0; i < this->tamano; i++)
			this->c[i] = tvc.c[i];
		return true;
	}

	if (n > 0 && n < this->tamano){
		TVectorCom tvc(n);
		for (int i = 0; i<n; i++)
			tvc.c[i] = this->c[i];
		delete [] this->c;
		this-> tamano = n;
		this->c = new TComplejo[n];
		for (int i = 0; i<n; i++)
			this->c[i] = tvc.c[i];
		return true;
	}
}

ostream & operator<< (ostream &os, const TVectorCom &tvc) {
	os<<"[";
	if(tvc.Tamano() != 0){
		for (int i = 0; i<tvc.Tamano(); i++){
			os<<"(";
			os<<i+1;
			os<<") ";
			os<<tvc.c[i];
			if(i < tvc.Tamano()-1)
				os<<", ";
		}
	}
	os<<"]";
	return os;
}
