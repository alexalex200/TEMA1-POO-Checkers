//
// Created by Alex on 12/17/2022.
//

#include "Jucator.h"

Jucator::Jucator() {}

Jucator::Jucator(std::string new_nume, std::string &new_culoare)
        : Culoare(new_culoare), Nume(std::move(new_nume)) {}

Jucator::Jucator(std::string &new_culoare)
        : Culoare(new_culoare), Nume("") {}

Jucator::Jucator(const Jucator &other)
        : Culoare(other.Culoare), Nume(other.Nume), scor(other.scor) {
    std::cout << " Constr Cop Jucator\n";
}

Jucator::~Jucator() {
    std::cout << "Destr Jucator\n";
}

Jucator & Jucator::operator=(const Jucator &other) {
    if (&other != this) {
        this->Culoare = other.Culoare;
        this->Nume = other.Nume;
        this->scor = other.scor;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Jucator &st) {
    std::cout << "Nume jucator:";
    is >> st.Nume;
    return is;
}

std::string Jucator::getNume() const {
    return Nume;
}

int Jucator::getscor() const {
    return scor;
}

void Jucator::increment_scor() {
    scor++;
}
