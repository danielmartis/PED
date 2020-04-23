#ifndef _TABBCOM_H
#define _TABBCOM_H
#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

class TNodoABB {
private:
    //Elemento del nodo
    TComplejo item;
    //Hijos izquierdo y derecho
    TABBCom iz,de;
public:
    //Constructor por defecto
    TNodoABB();
    //Constructor de igualdad
    TNodoABB(TNodoABB &);
    //Destructor
    ~TNodoABB();
    //Operador de igualdad.
    TNodoABB & operator=(TNodoABB &);
};

class TABBCom {
private:
    //Puntero al nodo
    TNodoABB * nodo;
    
    //AUXILIARES de los recorridos.
    void InordenAux(TVectorCom &, int &);
    void PreordenAux(TVectorCom &, int &);
    void PostordenAux(TVectorCom &, int &);
public:
    //Constructor por defecto
    TABBCom();
    
    //Cons de copia
    TABBCom(TABBCom &);
    
    // Destructor
    ~TABBCom ();
    
    // Sobrecarga del operador asignación
    TABBCom & operator=(TABBCom &);
    
    //Sobrecarga del operador igualdad
    bool operator==(TABBCom &);
    
    //Devuelve TRUE si el árbol esta vacío, FALSE  en caso contrario
    bool EsVacio();
    
    // Inserta el elemento en el árbol
    bool Insertar(TComplejo &);
    
    // Borra el elemento en el árbol
    bool Borrar(TComplejo &);
    
    // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
    bool Buscar(TComplejo &);
    
    // Devuelve el elemento en la raíz del árbol
    TComplejo Raiz();
    
    //Devuelve la altura del árbol (la altura de un árbol vacío es 0)
    int Altura();
    
    //Devuelve el número de nodos del árbol (un árbol vacío tiene 0 nodos)
    int Nodos();
    
    // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
    int NodosHoja();
    //Devuelve el recorrido en inorden
    TVectorCom Inorden();
    
    //Devuelve el recorrido en Preorden
    TVectorCom Preorden();
    
    //Devuelve el recorrido en Postorden.
    TVectorCom Postorden();
    
    //Devuelve el recorrido por niveles
    TVectorCom Niveles();
    
    //Sobrecarga del operador salida
    friend ostream & operator<<(ostream&, TABBCom &);
    
};



#endif