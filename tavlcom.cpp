#include "tavlcom.h"
#include "tvectorcom.h"
#include <queue>
using namespace std;

TNodoAVL::TNodoAVL(){
    TComplejo item;
    TAVLCom iz,de;
}

TNodoAVL::TNodoAVL(TNodoAVL &tn){
    cout<<this;
    this->item = tn.item;
    this->iz = tn.iz;
    this->de = tn.de;
}

TNodoAVL::~TNodoAVL(){
}

TNodoAVL & TNodoAVL::operator=(TNodoAVL &tn){
    if (this != &tn){
        this->~TNodoAVL();
        this->item = tn.item ;
        this->iz = tn.iz;
        this->de = tn.de;
    }
    return *this;
}

TAVLCom::TAVLCom() {
    raiz = NULL;
}

TAVLCom::TAVLCom(const TAVLCom &tac){
    if(!tac.EsVacio()){
        TNodoAVL *n = new TNodoAVL();
        n->item = tac.raiz->item;
        n->iz = tac.raiz->iz;
        n->de = tac.raiz->de;
        this->raiz = n;
    }
    else {
        this->raiz = NULL;
    }
}

TAVLCom::~TAVLCom(){
    if (this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}

TAVLCom & TAVLCom::operator=(const TAVLCom &tac){
    if(!(*this == tac)){
        this->~TAVLCom();
        if(!tac.EsVacio()){
            TNodoAVL *n = new TNodoAVL();
            n->item = tac.raiz->item;
            n->iz = tac.raiz->iz;
            n->de = tac.raiz->de;
            this->raiz = n;
        }
        else{
            this->raiz = NULL;
        }
    }
    return *this;
}

bool TAVLCom::operator==(const TAVLCom &tac) const{
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

bool TAVLCom::EsVacio() const{
    if (this->raiz == NULL)
        return true;
    return false;
}

int TAVLCom::calcularFe() const{
    return this->raiz->de.Altura() - this->raiz->iz.Altura();
}

void TAVLCom::rotacionesIzquierda(){
    if (this->raiz->iz.raiz->fe == -1){
        rotacionII();
    }
    else
        rotacionID();
}

void TAVLCom::rotacionesDerecha(){
    if (this->raiz->de.raiz->fe == 1)
        rotacionDD();
    else
        rotacionDI();
}

void TAVLCom::rotacionII(){
    TNodoAVL *n = new TNodoAVL();
    TNodoAVL *n2 = new TNodoAVL();
    *n = *(this->raiz->iz.raiz);
    *n2 = *(this->raiz);
    n2->iz = n->de;
    n->de.raiz = n2;
    this->raiz = n;
}

void TAVLCom::rotacionID(){
    
}

void TAVLCom::rotacionDI(){
    
}

void TAVLCom::rotacionDD(){
    TNodoAVL *n = new TNodoAVL();
    TNodoAVL *n2 = new TNodoAVL();
    *n = *(this->raiz->de.raiz);
    *n2 = *(this->raiz);
    n2->de = n->iz;
    n->iz.raiz = n2;
    this->raiz = n;
}

bool TAVLCom::Insertar(const TComplejo &tc){
    if(this->raiz == NULL){
        TNodoAVL *n = new TNodoAVL();
        n->item = tc;
        raiz = n;
        return true;
    }
    
    else if(this->Buscar(tc) == true)
        return false;
    
    else if (this->raiz->item.Mod() == tc.Mod() && this->raiz->item.Re() == tc.Re() && this->raiz->item.Im() == tc.Im())
        return false;
    
    else if (this->raiz->item.Mod() > tc.Mod())
        this->raiz->iz.Insertar(tc);
    
    else if (this->raiz->item.Mod() < tc.Mod())
        this->raiz->de.Insertar(tc);
    
    else if (this->raiz->item.Mod() == tc.Mod()){
        if(this->raiz->item.Re() == tc.Re()){
            if(this->raiz->item.Im() > tc.Im())
                this->raiz->iz.Insertar(tc);
            
            else if(this->raiz->item.Im() < tc.Im())
                this->raiz->de.Insertar(tc);
        }
        else if (this->raiz->item.Re() > tc.Re())
            this->raiz->iz.Insertar(tc);
        
        else if (this->raiz->item.Re() < tc.Re())
            this->raiz->de.Insertar(tc);
    }
    this->raiz->fe = calcularFe();
    if (this->raiz->fe == -2)
        rotacionesIzquierda();
    else if (this->raiz->fe == 2)
        rotacionesDerecha();
    return true;
}

TComplejo & TAVLCom::conseguirMayor(){
    if (!this->raiz->de.EsVacio()){
        this->raiz->de.conseguirMayor();
    }
    else{
        return this->raiz->item;
    }
}

bool TAVLCom::Borrar(const TComplejo &tc){
    if (this->Buscar(tc) == false)
        return false;
    else if (this->raiz->item == tc){
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            delete this->raiz;
            this->raiz = NULL;
            return true;
        }
        else if (this->raiz->iz.EsVacio()){
            this->raiz = this->raiz->de.raiz;
        }
        else if (this->raiz->de.EsVacio()){
            this->raiz = this->raiz->iz.raiz;
        }
        
        else{
            TComplejo tac = this->raiz->iz.conseguirMayor();
            this->raiz->item = tac;
            this->raiz->iz.Borrar(tac);
            /*if(this->raiz->iz.raiz->item.Mod() > this->raiz->item.Mod()){
                tac = this->raiz->iz.ConseguirMayor();
                TComplejo aux = this->raiz->item;
                this->raiz->iz.raiz->item = aux;
                this->raiz->item = tac;
            }*/
        }
    }
    else {
        this->raiz->de.Borrar(tc);
        this->raiz->iz.Borrar(tc);
    }
    
    return true;
}

bool TAVLCom::Buscar(const TComplejo &tc) const{
    if (this->raiz == NULL)
        return false;
    else if(this->raiz->item != tc && this->raiz->iz.raiz == NULL && this->raiz->de.raiz == NULL)
        return false;
    
    else if (this->raiz->item == tc)
        return true;
    else if (this->raiz->iz.raiz != NULL && this->raiz->de.raiz != NULL)
        return (this->raiz->iz.Buscar(tc) || this->raiz->de.Buscar(tc));
    
    else if (this->raiz->iz.raiz == NULL)
        return this->raiz->de.Buscar(tc);
    else if (this->raiz->de.raiz == NULL)
        return this->raiz->iz.Buscar(tc);
}
    

TComplejo TAVLCom::Raiz() const{
    if (this->EsVacio())
        return TComplejo();
    return this->raiz->item;
}

int TAVLCom::Altura() const{
    if (this->EsVacio())
        return 0;
    else
        return 1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura());
}

int TAVLCom::Nodos() const{
    if (this->EsVacio())
        return 0;
    else
        return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
}

int TAVLCom::NodosHoja() const{
    int raizs = 0;
    if (this->EsVacio())
        return 0;
    else if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio())
        raizs++;
    else 
        raizs = raizs + this->raiz->iz.NodosHoja() + this->raiz->de.NodosHoja();
    return raizs;
}

TVectorCom TAVLCom::Inorden() const{
    int posicion = 1;
    TVectorCom v(Nodos());
    InordenAux(v,posicion);
    return v;
}

void TAVLCom::InordenAux(TVectorCom &aux, int &pos) const {
    if (this->raiz != NULL){
        this->raiz->iz.InordenAux(aux, pos);
        pos++;
        aux[pos-1] = this->raiz->item;
        this->raiz->de.InordenAux(aux,pos);
    }
}

TVectorCom TAVLCom::Preorden() const {
    TVectorCom v(this->Nodos());
    int i = 1;
    PreordenAux(v, i);
    return v;
}

void TAVLCom::PreordenAux(TVectorCom &aux, int &pos) const {
    if(this->raiz != NULL){
        aux[pos] = this->raiz->item;
        pos++;
        this->raiz->iz.PreordenAux(aux, pos);
        this->raiz->de.PreordenAux(aux, pos);
    }
}

TVectorCom TAVLCom::Postorden() const {
    TVectorCom v(this->Nodos());
    int i = 1;
    PostordenAux(v, i);
    return v;
}

void TAVLCom::PostordenAux(TVectorCom &aux, int &pos) const {
    if (this->raiz != NULL){
        this->raiz->iz.PostordenAux(aux, pos);
        this->raiz->de.PostordenAux(aux, pos);
        aux[pos] = this->raiz->item;
        pos++;
    }
}



ostream & operator <<(ostream & os, TAVLCom &tac){
    os<<tac.Inorden();
    return os;
}
    
        
    

