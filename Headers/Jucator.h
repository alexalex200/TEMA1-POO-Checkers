//
// Created by Alex on 12/17/2022.
//

#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H
#include <string>
#include <iostream>

class Jucator {
    std::string Culoare;
    std::string Nume;
    int scor = 0;

public:
    Jucator() ;

    Jucator(std::string new_nume, std::string &new_culoare);
    explicit Jucator(const std::string &new_culoare);
    Jucator(const Jucator &other);

    ~Jucator() ;

    Jucator &operator=(const Jucator &other) ;

    friend std::istream &operator>>(std::istream &is, Jucator &st)
        ;

    std::string getNume()const ;

    int getscor()const;

    void increment_scor();
};
#endif //OOP_JUCATOR_H
