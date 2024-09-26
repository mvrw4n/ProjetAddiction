#ifndef UNEPERSONNE_H
#define UNEPERSONNE_H

class UnePersonne {
private:
    double C0; // je définis tous les paramètres qui vont permettre de caractériser une personne
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
    static const int N = 300;//Pour l'instant je fais avec des tableaux de taille fixe donc obligé d'initialiser N
    double C[N];
    double S[N];
    double E[N];
    double Psi[N];
    double V[N];
    double A[N];

public:
    UnePersonne(); //Constructeur par défault, il va permettre d'initialiser chaque valeur de paramètre 
    //Pour l'instant je fais que le constructeurs par défault.
    //on peut mettre les setters après 
    const double* getC() const; //les getters qui permettent d'accèder aux tableaux qu'on va tracer 
    const double* getE() const;
    const double* getPsi() const;
    const double* getV() const;
    const double* getA() const;
    const double* getS() const;

    void SolveSystem();//Il suffira d'appliquer SolveSystem à la personne et on aura les valeurs des tableaux 
    //on accèdera à ces tableaux grâce aux getters

};

#endif // UNEPERSONNE_H

