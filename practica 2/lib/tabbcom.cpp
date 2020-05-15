#include "tabbcom.h"
#include "tvectorcom.h"
#include <queue>
using namespace std;

TNodoABB::TNodoABB(){
    TComplejo item;
    TABBCom iz,de;
}

TNodoABB::TNodoABB(TNodoABB &tn){
    cout<<this;
    this->item = tn.item;
    this->iz = tn.iz;
    this->de = tn.de;
}

TNodoABB::~TNodoABB(){
}

TNodoABB & TNodoABB::operator=(TNodoABB &tn){
    if (this != &tn){
        this->~TNodoABB();
        this->item = tn.item ;
        this->iz = tn.iz;
        this->de = tn.de;
    }
    return *this;
}

TABBCom::TABBCom() {
    nodo = NULL;
}

TABBCom::TABBCom(const TABBCom &tac){
    if(!tac.EsVacio()){
        TNodoABB *n = new TNodoABB();
        n->item = tac.nodo->item;
        n->iz = tac.nodo->iz;
        n->de = tac.nodo->de;
        this->nodo = n;
    }
    else {
        this->nodo = NULL;
    }
}

TABBCom::~TABBCom(){
    if (this->nodo != NULL){
        delete this->nodo;
        this->nodo = NULL;
    }
}

TABBCom & TABBCom::operator=(const TABBCom &tac){
    if(!(*this == tac)){
        this->~TABBCom();
        if(!tac.EsVacio()){
            TNodoABB *n = new TNodoABB();
            n->item = tac.nodo->item;
            n->iz = tac.nodo->iz;
            n->de = tac.nodo->de;
            this->nodo = n;
        }
        else{
            this->nodo = NULL;
        }
    }
    return *this;
}

bool TABBCom::operator==(const TABBCom &tac) const{
    if(this->Nodos() == 0 && tac.Nodos() == 0){
        return true;
    }
    
    if(this->Nodos() != tac.Nodos()){
        return false;
    }
    for (int i = 1; i<= tac.Nodos(); i++){
        if(!tac.Buscar(this->Inorden()[i])){
            return false;
        }
    }
    
    for (int i = 1; i<=this->Nodos(); i++){
        if (!tac.Buscar(this->Inorden()[i])){
            return false;
        }
    }
    return true;
}

bool TABBCom::EsVacio() const{
    if (this->nodo == NULL)
        return true;
    return false;
}

bool TABBCom::Insertar(const TComplejo &tc){
    if(this->nodo == NULL){
        TNodoABB *n = new TNodoABB();
        n->item = tc;
        nodo = n;
        return true;
    }
    
    else if(this->Buscar(tc) == true)
        return false;
    else if (this->nodo->item.Mod() == tc.Mod() && this->nodo->item.Re() == tc.Re() && this->nodo->item.Im() == tc.Im())
        return false;
    else if (this->nodo->item.Mod() > tc.Mod())
        this->nodo->iz.Insertar(tc);
    else if (this->nodo->item.Mod() < tc.Mod())
        this->nodo->de.Insertar(tc);
    else if (this->nodo->item.Mod() == tc.Mod()){
        if(this->nodo->item.Re() == tc.Re()){
            if(this->nodo->item.Im() > tc.Im())
                this->nodo->iz.Insertar(tc);
            else if(this->nodo->item.Im() < tc.Im())
                this->nodo->de.Insertar(tc);
        }
        else if (this->nodo->item.Re() > tc.Re())
            this->nodo->iz.Insertar(tc);
        else if (this->nodo->item.Re() < tc.Re())
            this->nodo->de.Insertar(tc);
    }
    return true;
}

TComplejo & TABBCom::ConseguirMayor() const{
    if (!this->nodo->de.EsVacio()){
        this->nodo->de.ConseguirMayor();
    }
    else{
        return this->nodo->item;
    }
}



bool TABBCom::Borrar(TComplejo &tc){
    if (this->Buscar(tc) == false)
        return false;
    else if (this->nodo->item == tc){
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()){
            delete this->nodo;
            this->nodo = NULL;
            return true;
        }
        else if (this->nodo->iz.EsVacio()){
            this->nodo = this->nodo->de.nodo;
        }
        else if (this->nodo->de.EsVacio()){
            this->nodo = this->nodo->iz.nodo;
        }
        
        else{
            TComplejo tac = this->nodo->iz.ConseguirMayor();
            this->nodo->item = tac;
            this->nodo->iz.Borrar(tac);
            /*if(this->nodo->iz.nodo->item.Mod() > this->nodo->item.Mod()){
                tac = this->nodo->iz.ConseguirMayor();
                TComplejo aux = this->nodo->item;
                this->nodo->iz.nodo->item = aux;
                this->nodo->item = tac;
            }*/
        }
    }
    else {
        this->nodo->de.Borrar(tc);
        this->nodo->iz.Borrar(tc);
    }
    
    return true;
}

bool TABBCom::Buscar(const TComplejo &tc) const{
    if (this->nodo == NULL)
        return false;
    else if(this->nodo->item != tc && this->nodo->iz.nodo == NULL && this->nodo->de.nodo == NULL)
        return false;
    
    else if (this->nodo->item == tc)
        return true;
    else if (this->nodo->iz.nodo != NULL && this->nodo->de.nodo != NULL)
        return (this->nodo->iz.Buscar(tc) || this->nodo->de.Buscar(tc));
    
    else if (this->nodo->iz.nodo == NULL)
        return this->nodo->de.Buscar(tc);
    else if (this->nodo->de.nodo == NULL)
        return this->nodo->iz.Buscar(tc);
}
    

TComplejo TABBCom::Raiz(){
    if (this->EsVacio())
        return TComplejo();
    return this->nodo->item;
}

int TABBCom::Altura(){
    if (this->EsVacio())
        return 0;
    else
        return 1 + max(this->nodo->iz.Altura(), this->nodo->de.Altura());
}

int TABBCom::Nodos() const{
    if (this->EsVacio())
        return 0;
    else
        return 1 + this->nodo->iz.Nodos() + this->nodo->de.Nodos();
}

int TABBCom::NodosHoja(){
    int nodos = 0;
    if (this->EsVacio())
        return 0;
    else if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        nodos++;
    else 
        nodos = nodos + this->nodo->iz.NodosHoja() + this->nodo->de.NodosHoja();
    return nodos;
}

TVectorCom TABBCom::Inorden() const{
    int posicion = 1;
    TVectorCom v(Nodos());
    InordenAux(v,posicion);
    return v;
}

void TABBCom::InordenAux(TVectorCom &aux, int &pos) const {
    if (this->nodo != NULL){
        this->nodo->iz.InordenAux(aux, pos);
        pos++;
        aux[pos-1] = this->nodo->item;
        this->nodo->de.InordenAux(aux,pos);
    }
}

TVectorCom TABBCom::Preorden() const {
    TVectorCom v(this->Nodos());
    int i = 1;
    PreordenAux(v, i);
    return v;
}

void TABBCom::PreordenAux(TVectorCom &aux, int &pos) const {
    if(this->nodo != NULL){
        aux[pos] = this->nodo->item;
        pos++;
        this->nodo->iz.PreordenAux(aux, pos);
        this->nodo->de.PreordenAux(aux, pos);
    }
}

TVectorCom TABBCom::Postorden() const {
    TVectorCom v(this->Nodos());
    int i = 1;
    PostordenAux(v, i);
    return v;
}

void TABBCom::PostordenAux(TVectorCom &aux, int &pos) const {
    if (this->nodo != NULL){
        this->nodo->iz.PostordenAux(aux, pos);
        this->nodo->de.PostordenAux(aux, pos);
        aux[pos] = this->nodo->item;
        pos++;
    }
}



TVectorCom TABBCom::Niveles() {    
    int nodos = this->Nodos();
    TVectorCom v(nodos);
    int i = 1;
    if(nodos != 0){
        queue<TABBCom*> cola;
        TABBCom *aux;
        cola.push(this);
        while(cola.size() != 0){
            aux = cola.front();
            cola.pop();
            v[i] = aux->nodo->item;
            if(aux->nodo->iz.nodo != NULL)
                cola.push(&(aux->nodo->iz));
            if(aux->nodo->de.nodo != NULL)
                cola.push(&(aux->nodo->de));
            i++;
        }
    }
    return v;
}

TComplejo TABBCom::Devolver(const TComplejo tc){
    if (this->nodo->item == tc){
        return this->nodo->item;
    }
    else {
        if (this->nodo->iz.Buscar(tc))
            return this->nodo->iz.Devolver(tc);
        else
            return this->nodo->de.Devolver(tc);
    }
}

ostream & operator <<(ostream & os, TABBCom &tac){
    os<<tac.Niveles();
    return os;
}
    
        
    

