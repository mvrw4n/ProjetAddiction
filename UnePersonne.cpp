#include <iostream>
#include <cmath>
#include "UnePersonne.h"

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
    
}