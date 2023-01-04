//
// Created by Alex on 12/17/2022.
//

#ifndef OOP_PIESA_H
#define OOP_PIESA_H
#include <string>
#include <iostream>
#include <array>
struct pozitie {
    int x, y;
};
class Piesa {
protected:
    std::string Culoare;
    int x,y;
public:
    Piesa();

    Piesa(const std::string &new_culoare, int x,int y);

    Piesa(const Piesa &other);

    ~Piesa() ;

    Piesa &operator=(const Piesa &other) ;

    friend std::ostream& operator<<(std::ostream &os, const Piesa &st) ;

    std::string getculoare() const ;

    int getx() const;

    int gety() const;

    void setCuloare(const std::string &new_culoare) ;

    void setpozitie( const int new_x,int new_y);

    int virtual mutaripos(std::array<pozitie,4> &pozvalid,std::array<std::array<Piesa*, 8>, 8> mat,int randjucator);

};

class Rege : public Piesa
{

public:
    Rege();

    Rege(const std::string &new_culoare, int x,int y);

    Rege(const Piesa &other);

    int mutaripos(std::array<pozitie,4> &pozvalid,std::array<std::array<Piesa*, 8>, 8> mat,int randjucator);

};

#endif //OOP_PIESA_H
