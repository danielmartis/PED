#ifndef _TABBCOM_H
#define _TABBCOM_H
#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;
class TNodoABB;
class TABBCom {
    friend class TNodoABB;
private:
    //Puntero al nodo
    TNodoABB * nodo;
    
    //AUXILIARES de los recorridos.
    void InordenAux(TVectorCom &, int &) const;
    void PreordenAux(TVectorCom &, int &) const;
    void PostordenAux(TVectorCom &, int &) const;
public:
    //Constructor por defecto
    TABBCom();
    
    //Cons de copia
    TABBCom(TABBCom &);
    
    // Destructor
    ~TABBCom ();
    
    // Sobrecarga del operador asignación
    TABBCom & operator=(const TABBCom &);
    
    //Sobrecarga del operador igualdad
    bool operator==(const TABBCom &) const;
    
    //Devuelve TRUE si el árbol esta vacío, FALSE  en caso contrario
    bool EsVacio() const;
    
    // Inserta el elemento en el árbol
    bool Insertar(const TComplejo &);
    
    // Borra el elemento en el árbol
    bool Borrar(TComplejo &);
    
    // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
    bool Buscar(const TComplejo &) const;
    
    // Devuelve el elemento en la raíz del árbol
    TComplejo Raiz();
    
    //Devuelve la altura del árbol (la altura de un árbol vacío es 0)
    int Altura();
    
    //Devuelve el número de nodos del árbol (un árbol vacío tiene 0 nodos)
    int Nodos() const;
    
    // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
    int NodosHoja();
    //Devuelve el recorrido en inorden
    TVectorCom Inorden() const;
    
    //Devuelve el recorrido en Preorden
    TVectorCom Preorden() const;
    
    //Devuelve el recorrido en Postorden.
    TVectorCom Postorden() const;
    
    //Devuelve el recorrido por niveles
    TVectorCom Niveles() ;
    
    //Sobrecarga del operador salida
    friend ostream & operator<<(ostream&,TABBCom &);
    
    TComplejo ConseguirMayor() const;
};
class TNodoABB {
    friend class TABBCom;
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





#endif