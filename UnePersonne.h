#ifndef UNEPERSONNE_H
#define UNEPERSONNE_H

class UnePersonne {
private:
    double C0;
    double Smax;
    double S0;
    double E0;
    double lambda0;
    double d;
    double q;
    double p;
    double h;
    double k;
    double b;
    double Rmax;
    double mE;
    double mLambda;
    static const int N = 300;
    double C[N];
    double S[N];
    double E[N];
    double Psi[N];
    double V[N];
    double A[N];

public:
    UnePersonne();
    const double* getC() const;
    const double* getE() const;
    const double* getPsi() const;
    const double* getV() const;
    const double* getA() const;
    const double* getS() const;

    void SolveSystem();
};

#endif // UNEPERSONNE_H

