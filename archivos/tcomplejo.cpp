#include "tcomplejo.h"
#include <math.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

TComplejo::TComplejo() {
    re = +0;
    im = +0;
}

TComplejo::TComplejo(const double real) {
    re = real;
    im = +0;
}

TComplejo::TComplejo(const double real,const double imag) {
    re = real;
    im = imag;
}


TComplejo::TComplejo (const TComplejo &tc) {
    this->re = tc.re;
    this->im = tc.im;
}

TComplejo::~TComplejo() {
    re = +0;
    im = +0;
}

TComplejo& TComplejo::operator=(const TComplejo &tc){
    this->re = tc.re;
    this->im = tc.im;
    return *this;
}

TComplejo TComplejo::operator+(const TComplejo &tc){
    TComplejo aux;
    aux.re = this->re + tc.re;
    aux.im = this->im + tc.im;
    return aux;
}

TComplejo TComplejo::operator-(const TComplejo &tc){
    TComplejo aux;
    aux.re = this->re - tc.re;
    aux.im = this->im -tc.im;
    return aux;
}

TComplejo TComplejo::operator*(const TComplejo &tc){
    TComplejo aux;
    double ima = tc.re * this->im;
    ima += this->im * tc.im;
    ima += this->re * tc.im;
    aux.re = this->re * tc.re;
    aux.im = ima;
    return aux;
}

TComplejo TComplejo::operator+(const double n){
    TComplejo tc(n);
    tc.re = this->re + tc.re;
    tc.im = this->im + tc.im;
    return tc;
}

TComplejo TComplejo::operator-(const double n){
    TComplejo tc(n);
    tc.re = this->re - tc.re;
    tc.im = this->im;
    return tc;
}

TComplejo TComplejo::operator*(const double n){
    TComplejo tc(n);
    double ima = tc.re * this->im;
    ima += this->im * tc.im;
    ima += this->re * tc.im;
    tc.re = this->re * tc.re;
    tc.im = ima;
    return tc;
}

bool TComplejo::operator==(const TComplejo &tc) const {
    if (this->re == tc.re && this->im == tc.im)
        return true;
    else
        return false;
}

bool TComplejo::operator!=(const TComplejo &tc) const {
    return !(*(this) == tc);
}

double TComplejo::Re() const {
    return re;
}

double TComplejo::Im() const{
    return im;
}

void TComplejo::Re(const double n) {
    re = n;
}

void TComplejo::Im(const double n) {
    im = n;
}

double TComplejo::Arg(void) const {
    double res;
    res = atan2(im,re);
    return res;
}

double TComplejo::Mod(void) const {
    double res;
    res = sqrt(pow(re,2) + pow(im,2));
    return res;
}

ostream & operator<<(ostream &os, const TComplejo &tc) {
    os<<"("<<tc.re<<" "<<tc.im<<")";
    return os;
}

TComplejo operator+(const double n, const TComplejo &tc){
    TComplejo aux;
    TComplejo n2(n);
    aux = n2 + tc;
    return aux;
}

TComplejo operator-(const double n, const TComplejo &tc){
    TComplejo aux;
    TComplejo n2(n);
    aux = n2 - tc;
    return aux;
}

TComplejo operator*(const double n, const TComplejo &tc){
    TComplejo aux;
    TComplejo n2(n);
    aux = n2 * tc;
    return aux;
}
