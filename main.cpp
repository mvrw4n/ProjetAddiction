#include <iostream>
#include "UnePersonne.h"
#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    // Création d'une personne et résolution du système
    UnePersonne p1;
    p1.SolveSystem();

    // Récupération des données
    const std::vector<double>& C = p1.getC();
    const std::vector<double>& S = p1.getS();
    const std::vector<double>& E = p1.getE();
    const std::vector<double>& V = p1.getV();
    const std::vector<double>& A = p1.getA();

    // Création d'un vecteur pour l'axe des semaines
    std::vector<double> weeks(C.size());
    for (size_t i = 0; i < weeks.size(); ++i) {
        weeks[i] = static_cast<double>(i);
    }
    hold(on);
    // Tracé des résultats
    plot(weeks, C, "r-")->display_name("Intensité de la fringale (C)");
    plot(weeks, S, "b-")->display_name("Intensité du self-contrôle (S)");
    plot(weeks, E, "g-")->display_name("Influence sociétale (E)");
    plot(weeks, V, "m-")->display_name("Niveau de vulnérabilité (V)");
    plot(weeks, A, "c-")->display_name("Addiction exercée (A)");

    // Définir les limites de l'axe des ordonnées si nécessaire
    ylim({0, 1});

    // Ajout des étiquettes des axes et du titre
    xlabel("Temps (semaines)");
    ylabel("Intensité/Niveau");
    title("Évolution des variables du modèle d’addiction au fil du temps");


    // Afficher le graphique
    show();
    hold(off);
    return 0;
}
