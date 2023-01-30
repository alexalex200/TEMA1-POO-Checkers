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
    static int nrpiesealbe,nrpiesenegre;
    int x,y;
public:
    Piesa();

    Piesa(const std::string &new_culoare, int x,int y);

    Piesa(const Piesa &other);

    virtual ~Piesa() ;

    Piesa &operator=(const Piesa &other) ;

    friend std::ostream& operator<<(std::ostream &os, const Piesa &st) ;

    std::string getculoare() const ;

    int getx() const;

    int gety() const;

    void setpozitie( const int new_x,int new_y);

    virtual int mutaripos(std::array<pozitie,4> &pozvalid,std::array<std::array<Piesa*, 8>, 8> mat,int randjucator);

    virtual char getnume();

    int static getnrpiesealbe();

    int static getnrpiesenegre();
};

class Rege : public Piesa
{

public:
    Rege();

    Rege(const std::string &new_culoare, int x,int y);

    explicit Rege(const Piesa &other);

    int mutaripos(std::array<pozitie,4> &pozvalid,std::array<std::array<Piesa*, 8>, 8> mat,int randjucator) override;

    char getnume() override;
};

#endif //OOP_PIESA_H
