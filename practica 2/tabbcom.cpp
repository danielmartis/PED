#include "tabbporo.h"
using namespace std;

TNodoABB::TNodoABB(){
    TPoro item;
    TABBPoro iz,de;
}

TNodoABB::TNodoABB(TNodoABB &tn){
    this->item = tn.item;
    this->iz = tn.iz;
    this->de = tn.de;
}

TNodoABB::~TNodoABB(){
}

TNodoABB & TNodoABB::operator=(TNodoABB &tn){
    if (this != &na){
        delete this;
        this->item = tn.item;
        this->iz = tn.iz;
        this->de = tn.de;
    }
    return *this;
}

TABBCom::TABBCom() {
    nodo = NULL;
}

TABBCom::TABBCom(TABBCom &tac){
    TNodoABB *n = new TNodoABB();
    n = tac.nodo;
}

