#include "UnePersonne.h"
#include <algorithm> // pour std::min et std::max

UnePersonne::UnePersonne()
    : Co(0.9), Sm(0.1), So(Sm), Eo(0), d(0.2), q(0.8), pref(0.2),
      p(0.8), h(pref * Sm), k(pref * Sm / q), b(2 * d / q),
      Lambda(0.2), Rm(7), mE(0.01), nbrSemaine(300), 
      C(nbrSemaine + 1), S(nbrSemaine + 1), E(nbrSemaine + 1), 
      Psi(nbrSemaine + 1), V(nbrSemaine + 1), A(nbrSemaine + 1),
      distribution(Lambda) {
    initialize();
}

void UnePersonne::initialize() {
    C[0] = Co;
    S[0] = So;
    E[0] = Eo;
    Psi[0] = C[0] - S[0] - E[0];
    V[0] = std::max(0.0, std::min(Psi[0], 1.0));
    A[0] = q * V[0] + generatePoisson() * q * (1 - V[0]) / Rm;
}

double UnePersonne::generatePoisson() {
    return static_cast<double>(distribution(generator));
}

void UnePersonne::updateValues(int t) {
    C[t + 1] = (1 - d) * C[t] + b * std::min(1.0, 1 - C[t]) * A[t];
    S[t + 1] = S[t] + p * std::max(0.0, Sm - S[t]) - h * C[t] - k * A[t];
    E[t + 1] = E[t] - mE;
    Psi[t + 1] = C[t + 1] - S[t + 1] - E[t + 1];
    V[t + 1] = std::max(0.0, std::min(Psi[t + 1], 1.0));
    A[t + 1] = q * V[t + 1] + generatePoisson() * q * (1 - V[t + 1]) / Rm;
}

void UnePersonne::SolveSystem() {
    for (int i = 0; i < nbrSemaine; ++i) {
        updateValues(i);
    }
}

const std::vector<double>& UnePersonne::getC() const { return C; }
const std::vector<double>& UnePersonne::getS() const { return S; }
const std::vector<double>& UnePersonne::getE() const { return E; }
const std::vector<double>& UnePersonne::getV() const { return V; }
const std::vector<double>& UnePersonne::getA() const { return A; }
