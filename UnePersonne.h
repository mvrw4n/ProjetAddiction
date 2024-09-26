#ifndef UNEPERSONNE_H
#define UNEPERSONNE_H

#include <vector>
#include <random>

class UnePersonne {
public:
    UnePersonne();
    void SolveSystem();
    const std::vector<double>& getC() const;
    const std::vector<double>& getS() const;
    const std::vector<double>& getE() const;
    const std::vector<double>& getV() const;
    const std::vector<double>& getA() const;

private:
    void updateValues(int t);
    void initialize();

    // Paramètres
    double Co, Sm, So, Eo, d, q, pref, p, h, k, b, Lambda, Rm, mE;
    int nbrSemaine;

    // Vecteurs pour stocker les résultats
    std::vector<double> C, S, E, Psi, V, A;
    std::default_random_engine generator;
    std::poisson_distribution<int> distribution;

    // Méthode pour générer des valeurs aléatoires selon une loi de Poisson
    double generatePoisson();
};

#endif // UNEPERSONNE_H
