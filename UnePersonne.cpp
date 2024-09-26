#include <iostream>
#include <cmath>
#include <random>
#include "UnePersonne.h"

using namespace std;

UnePersonne :: UnePersonne(){
    C0=0.9;
    Smax=0.1;
    S0 = Smax;
    E0 = 0;
    d = 0.2;
    q = 0.8;
    pref = 0.2;
    p = 0.8;
    h = pref * Smax;
    k = pref * Smax / q;
    b = 2 * d / q;
    lambda0 = 0.2;
    Rmax = 7;
    mE = 0.01;
    mLambda =  0.001;
    C[0]=C0;
    S[0]=S0;
    E[0]=E0;
    Psi[0]=C[0]-S[0]-E[0];
    V[0]=fmax(0,fmin(Psi[0],1));
    random_device rd;  
    mt19937 gen(rd()); 
    int nombre = poisson_distribution<int>(lambda0)(gen);
    A[0]=q*V[0]+nombre*q*(1-V[0])/Rmax;
}

void UnePersonne :: SolveSystem(){
    random_device rd;  
    mt19937 gen(rd()); 

    for (int i = 0; i < N - 1; i++){  // Modifié pour éviter le dépassement
        C[i+1] = (1 - d) * C[i] + b * fmin(1, 1 - C[i]) * A[i];
        S[i+1] = S[i] + p * fmax(0, Smax - S[i]) - h * C[i] - k * A[i];
        E[i+1] = E[i] - mE;
        Psi[i+1] = C[i+1] - S[i+1] - E[i+1];
        V[i+1] = fmax(0, fmin(Psi[i+1], 1));

        int nombre = poisson_distribution<int>(lambda0)(gen);
        A[i+1] = q * V[i+1] + nombre * q * (1 - V[i+1]) / Rmax;
    }
}
    // Retourne le tableau C
const double* UnePersonne::getC() const {
    return C;
}

// Retourne le tableau E
const double* UnePersonne::getE() const {
    return E;
}

// Retourne le tableau Psi
const double* UnePersonne::getPsi() const {
    return Psi;
}

// Retourne le tableau V
const double* UnePersonne::getV() const {
    return V;
}

// Retourne le tableau A
const double* UnePersonne::getA() const {
    return A;
}

// Retourne le tableau S
const double* UnePersonne::getS() const {
    return S;
}
