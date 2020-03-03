#ifndef _TCOMPLEJO_H
#define _TCOMPLEJO_H
#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdio.h>


using namespace std;

class TComplejo {
    friend ostream & operator<<(ostream &, const TComplejo &);
    //friend TComplejo operator+ (const double,const TComplejo&);
    //friend TComplejo operator- (const double, const TComplejo&);
    //friend TComplejo operator* (const double,const TComplejo&);

    private:
        double re; // Parte real
        double im; // Parte imaginaria
    public:
        //Constructor por defecto : ambas partes a 0;
        TComplejo();
        
        //Constructor con la parte real
        TComplejo(const double);
        
        //Constructor con parte real e imaginaria
        TComplejo(const double,const double);
        
        //Constructor de copia
        TComplejo (const TComplejo&);
        
        //Destructor
        ~TComplejo();
        
        //Sobrecarga del operador asignación
        TComplejo& operator= (const TComplejo&);
        
        // Sobrecarga de operadores
        
        TComplejo operator+ (const TComplejo&);
        TComplejo operator- (const TComplejo&);
        TComplejo operator* (const TComplejo&);
        TComplejo operator+ (const double);
        TComplejo operator- (const double);
        TComplejo operator* (const double);
        
        // Otros operadores
        
        bool operator== (const TComplejo&) const;
        bool operator!= (const TComplejo&) const;
        
        double Re() const; //Devuelve parte real
        double Im() const; //Devuelve parte imaginaria
        
        void Re(const double); //Modifica parte real
        void Im(const double); //Modifica parte imaginaria
        
        double Arg(void) const; //Calcula el Argumento(en radianes);
        double Mod(void) const; //Calcula el módulo;
        

};

#endif
