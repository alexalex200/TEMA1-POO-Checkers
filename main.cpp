#include <iostream>
#include <string>
#include <array>
//#include <SFML/Graphics.hpp>
#include "Headers/Piesa.h"
#include "Headers/Jucator.h"
#include "Headers/joc.h"


int main() {
    joc Checkers;
    try {
        Checkers.start();
    }
    catch(std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    //Checkers.afistabla();

}
