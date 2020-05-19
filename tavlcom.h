#ifndef _TAVLCOM_H
#define _TAVLCOM_H
#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <math.h>
#include <ctype.h>
#include <stdio.h>

class TNodoAVL;



class TAVLCom {
    friend class TNodoAVL;
private:
    TNodoAVL *raiz;
    
    // Auxiliar recorrido inorden
    void InordenAux(TVectorCom &, int &) const;
    
    // Auxiliar recorrido preorden
    void PreordenAux(TVectorCom &, int &) const;
    
    // Auxiliar recorrido postorden
    void PostordenAux(TVectorCom &, int &) const;
    
    // Calculo de fe
    int calcularFe() const;
    
    //Rotaciones ii e id
    void rotacionesIzquierda();
    // Rotaciones di y dd
    void rotacionesDerecha();
    
    void rotacionII();
    void rotacionID();
    void rotacionDD();
    void rotacionDI();
    
    TComplejo & conseguirMayor();
public:
    //Constructor por defecto
    TAVLCom();
    
    //Constructor de copia
    TAVLCom(const TAVLCom &);
    
    //Destructor
    ~TAVLCom();
    
    // Sobrecarga del operador asignación
    TAVLCom & operator=(const TAVLCom &);
    
    // Sobrecarga del operador igualdad
    bool operator==(const TAVLCom &) const;
    
    //Sobrecarga del operador desigualdad
    bool operator!=(const TAVLCom &) const;
    
    // Devuelve true si el arbol esta vacio, false en caso contrario
    bool EsVacio() const;
    
    // Inserta el elemento TComepljo en el arbol
    bool Insertar(const TComplejo &);
    
    // Devuelve true si el elemento esta en el arbol, false en caso contrario
    bool Buscar(const TComplejo &) const;
    
    // Borra un TComplejo del arbol avl
    bool Borrar(const TComplejo &);
    
    // Devuelve la altura del arbol
    int Altura() const;
    
    //Devuelve el elemento TComplejo raiz del arbol avl
    TComplejo Raiz() const;
    
    //Devuelve el numero de nodos del arbol
    int Nodos() const;
    
    //Devuelve el numero de nodos hoja en el arbol
    int NodosHoja() const;
    
    //Devuelve el recorrido inorden
    TVectorCom Inorden() const;
    
    //Devuelve el recorrido preorden
    TVectorCom Preorden() const;
    
    //Devuelve el recorrido en postorden
    TVectorCom Postorden() const;
    
    //Sobrecarga del operador salida (inorden)
    friend ostream & operator<< (ostream &, TAVLCom &);
};

class TNodoAVL {
    friend class TAVLCom;
private:
    //El elemento del nodo
    TComplejo item;
    
    // Subárbol izquierdo y dercho
    TAVLCom iz,de;
    
    // Factor de equilibrio
    int fe;
    
public:
    //Constructor por defecto
    TNodoAVL();
    
    //Constructor de copia
    TNodoAVL(TNodoAVL &);

    //Destructor
    ~TNodoAVL();
    
    // Sobrecarga del operador asignación
    TNodoAVL & operator=(TNodoAVL &);
    
};
    
#endif
    
    
    