#include "tlistacom.h"
#include "tcomplejo.h"
#include <iostream>

using namespace std;

TListaNodo::TListaNodo() {
    e = TComplejo();
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &tln) {
    this->e = tln.e;
    this->anterior = NULL;
    this->siguiente = tln.siguiente;
}

TListaNodo::~TListaNodo() {
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo & TListaNodo:: operator= (const TListaNodo &tln){
  if (this != &tln){
    this->e = tln.e;
    this->anterior = tln.anterior;
    this->siguiente = tln.siguiente;
  }
}

TListaPos::TListaPos() {
  pos = NULL;
}

TListaPos::TListaPos(const TListaPos &tlp){
  this->pos = tlp.pos;
}

TListaPos::~TListaPos() {
  pos = NULL;
}

TListaPos & TListaPos::operator=(const TListaPos &tlp){
  if (this != &tlp){
    this->pos = tlp.pos;
  }
  return *this;
}

bool TListaPos::operator==(const TListaPos &tlp) const {
    return pos == tlp.pos;
}

bool TListaPos::operator!=(const TListaPos &tlp) const {
    return !(pos == tlp.pos);
}

TListaPos TListaPos::Anterior() const {
  TListaPos tlp;
  if(pos!= NULL)
    tlp.pos = pos->siguiente;
  else
    tlp.pos = NULL;
  return tlp;
}

TListaPos TListaPos::Siguiente() const {
    TListaPos tlp;
    if (pos != NULL)
      tlp.pos = pos->siguiente;
    else
      tlp.pos = NULL;
    return tlp;
}

bool TListaPos::EsVacia() const {
    if (pos == NULL)
      return true;
    return false;
}

TListaCom::TListaCom() {
  primero = NULL;
  ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &tlc){
   TListaPos aux;
   if(tlc.primero == NULL & tlc.ultimo == NULL){
      primero = NULL;
      ultimo = NULL;
   }
   else{
      for(aux.pos = tlc.Ultima().pos; !aux.EsVacia(); aux.pos = aux.Anterior().pos){
        this->InsCabeza(aux.pos->e);
      }
   }
}

TListaCom::~TListaCom() {
  TListaNodo *ptn;
  ptn = primero;
  while (ptn != NULL){
      primero = primero->siguiente;
      delete ptn;
      ptn = primero;
  }
}

TListaCom & TListaCom::operator=(const TListaCom &tlc){
    TListaPos aux;
    if (this != &tlc){
      this->~TListaCom();
      if (tlc.primero == NULL && tlc.ultimo == NULL ){
          primero = NULL;
          ultimo = NULL;
      }
      else{
        for(aux = tlc.Ultima(); !aux.EsVacia(); aux = aux.Anterior())
          InsCabeza(aux.pos->e);
      }
    }
    return *this;
}

bool TListaCom::operator==(const TListaCom &tlc ) const{
  if(this->Longitud() != tlc.Longitud()){
    return false;
  }
  else {
      TListaPos tlp;
      tlp = tlc.Primera();
      for (TListaPos tlp2 = Primera(); !tlp2.EsVacia(); tlp = tlp.Siguiente()){
          if (tlp.pos->e != tlp2.pos->e)
            return false;
          tlp2 = tlp2.Siguiente();
      }
  }
  return true;
}

bool TListaCom::operator!=(const TListaCom &tlc) const {
  return !(*(this) == tlc);
}

TListaCom TListaCom::operator+(const TListaCom &tlc) const {
    TListaCom nueva;
    for (TListaPos tlp = this->Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente())
        nueva.InsCabeza(tlp.pos->e);
    for (TListaPos tlp = tlc.Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente())
        nueva.InsCabeza(tlp.pos->e);
    return nueva;
}

TListaCom TListaCom::operator-(const TListaCom &tlc) const {
    TListaCom nueva;
    for (TListaPos tlp = this->Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente()){
        if(!tlc.Buscar(tlp.pos->e))
          nueva.Insertar(tlp.pos->e);
    }
    return nueva;
}

bool TListaCom::EsVacia() const {
   if(primera == NULL & ultima = NULL)
     return true;
   return false;
}

bool TListaCom::InsCabeza(const TComplejo &tc){
    if (primero == NULL && ultimo == NULL){
       TListaNodo *nodo = new TListaNodo();
       nodo->e = tc;
       this->primero = nodo;
       this->ultimo = nodo;
       return true;
    }
    else {
        TListaNodo *nodo = new TListaNodo();
        TListaPos aux;
        nodo->e = tc;
        aux = primero;
        nodo->siguiente = aux.pos;
        aux.pos->anterior = nodo;
        primero = nodo;
        return true;
    }
    return false;
}

bool TListaCom::InsertarI(const TComplejo &tc, TListaPos &tlp){

}

bool TListaCom::InsertarD(const TComplejo &tc, TListaPos &tlp ){

}

bool TListaCom::Borrar(const TComplejo &tc){
    for (TListaPos tlp = Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente()){
        if (tlp.pos->e == tc){
            Borrar(tlp);
            return true;
        }
    }
    return false;
}

bool TListaCom::BorrarTodos(const TComplejo &tc){
    bool borrado = false;
    for (TListaPos tlp = Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente()){
      if(tlp.pos->e == tc){
          aux = tlp.Siguiente();
          Borrar(tlp);
          tlp = aux;
          borrado = true;
      }
    }
    return borrado;
}

bool TListaCom::Borrar(TListaPos &tlp){
    bool encontrado = false;
    if (!EsVacia()){
        if (tlp == Primera()){
            if (primero == ultimo){
              primero = NULL;
              ultimo = NULL;
            }
            else {
              primero = primero->siguiente;
              primero->anterior = NULL;
            }
            encontrado = true;;
        }
        else if(tlp == Ultima()){
            ultimo = ultimo->anterior;
            ultimo->siguiente = NULL;
            encontrado = true;
        }
        else {
          for (TListaPosicion aux = Primera(); !aux.EsVacia(); aux = aux.Siguiente()){
              if (tlp == aux){
                  aux.pos->siguiente->anterior = aux.pos->anterior;
                  aux.pos->anterior->siguiente = aux.pos->siguiente;
                  encontrado = true;
              }
          }
        }
        if (encontrado == true){
          delete pos.pos;
          pos.pos = NULL;
        }
    }
    return encontrado;
}

TComplejo TListaCom::Obtener(const TListaPos &tlp) const{
    for (TListaPos aux = Primera(); !aux.EsVacia(); aux = aux.Siguiente()){
        if(aux == tlp)
          return tlp.pos->e;
    }
    TComplejo tc;
    return tc;
}

bool TListaCom::Buscar(const TComplejo &tc) const {
    for(TListaPosicion tlp = Primera(); !tlp.EsVacia(); tlp = tlp.Siguiente()){
        if(i,pos->e == p)
            return true;
    }
    return false;
}

int TListaCom::Longitud() const {
    int cont = 0;
    for (TListaPosicion aux = Primera(); !aux.EsVacia(); aux = aux.Siguiente())
      cont++;
    return cont;
}

TListaPos TListaCom::Primera() const {
    TListaPosicion tlp;
    tlp.pos = primero;
    return tlp;
}

TListaPos TListaCom::Ultima() const {
    TListaPosicion tlp;
    tlp.pos = ultimo;
    return tlp;
}

friend ostream & operator<<(ostream &os, const TListaCom &tlc){
  os<<"{";
  for (TListaPos tlp = tlc.Primera(); !EsVacia(); tlp = tlp.Siguiente()){
      os<<tlc.Obtener(tlp);
      if(tlp.Siguiente() != NULL)
        os<<" ";
  }
  os<<"}";
  return os;
}
