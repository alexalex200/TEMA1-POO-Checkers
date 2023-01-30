//
// Created by Alex on 12/17/2022.
//

#ifndef OOP_JOC_H
#define OOP_JOC_H
#include "Piesa.h"
#include "Jucator.h"
#include <array>
#include <string.h>


class joc {
    std::array<std::array<Piesa*, 8>,8> mat;
    int lungimetable = 8, latimetable = 8, lungimebanda = 3, latimebanda = 4;

public:

    joc() ;

    joc(const joc &other);

    joc &operator=(const joc &other) ;

    ~joc() ;

    void ResetTabla() ;

    void afistabla() ;

    static int conversiemutare(pozitie &a,std::string m) ;

    void start() ;
};


#endif //OOP_JOC_H
