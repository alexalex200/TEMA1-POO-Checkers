//
// Created by Alex on 12/17/2022.
//

#include "Piesa.h"

Piesa::Piesa()
        : Culoare(""), x(-1), y(-1) {}

Piesa::Piesa(const std::string &new_culoare, int new_x, int new_y)
        : Culoare(new_culoare), x(new_x), y(new_y) {}

Piesa::Piesa(const Piesa &other)
        : Culoare(other.Culoare), x(other.x), y(other.y) {
    std::cout << " Constr Cop Piesa\n";
}

Piesa::~Piesa() {
    std::cout << "Destr Piesa\n";
}

Piesa &Piesa::operator=(const Piesa &other) {
    if (&other != this) {
        this->Culoare = other.Culoare;
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Piesa &st) {
    os << "Culoare: " << st.Culoare << ", x: " << st.x << ", y:" << st.y << "\n";
    return os;
}

std::string Piesa::getculoare() const {
    return Culoare;
}

int Piesa::getx() const {
    return x;
}

int Piesa::gety() const {
    return y;
}

void Piesa::setpozitie( const int new_x,int new_y)
{
    x=new_x;
    y=new_y;
}
int Piesa::mutaripos(std::array<pozitie, 4> &pozvalid, std::array<std::array<Piesa *, 8>, 8> mat,int randjucator) {
    int sem=0,i=0;
    for(int j=0;j<4;j++)
        pozvalid[j].x=pozvalid[j].y=-1;
    if (randjucator == 1) {
        if (x + 1 < 8 &&  y + 1 < 8) {
            if (mat[x + 1][y + 1] != nullptr ) {
                if ((x + 2 < 8 &&  y + 2 < 8) && mat[x+2][y+2] == nullptr && mat[x + 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                    pozvalid[i].x = x + 2;
                    pozvalid[i].y = y + 2;
                    sem=1;
                    i++;
                }
            } else {
                pozvalid[i].x = x + 1;
                pozvalid[i].y = y + 1;
                sem=1;
                i++;
            }
        }
        if ( x + 1 < 8 && -1 < y - 1 ) {
            if (mat[x + 1][y - 1] != nullptr ) {
                if ((x + 2 < 8 && -1 < y - 2 ) && mat[x+2][y-2] == nullptr && mat[x + 1][y - 1]->getculoare()!=mat[x][y]->getculoare()) {
                    pozvalid[i].x = x + 2;
                    pozvalid[i].y = y - 2;
                    sem=1;
                }
            } else {
                pozvalid[i].x = x + 1;
                pozvalid[i].y = y - 1;
                sem=1;
            }
        }
    } else {
        if (-1 < x - 1 && y + 1 < 8) {
            if (mat[x - 1][y + 1] != nullptr ) {
                if ((-1 < x - 2 && y + 2 < 8) && mat[x-2][y+2] == nullptr && mat[x - 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                    pozvalid[i].x = x - 2;
                    pozvalid[i].y = y + 2;
                    sem=1;
                    i++;
                }
            } else {
                pozvalid[i].x = x - 1;
                pozvalid[i].y = y + 1;
                sem=1;
                i++;
            }
        }
        if (-1 < x - 1 && -1 < y - 1) {
            if (mat[x - 1][y - 1] != nullptr ) {
                if ((-1 < x - 2 && -1 < y - 2) && mat[x-2][y-2] == nullptr && mat[x - 1][y - 1]->getculoare()!=mat[x][y]->getculoare()) {
                    pozvalid[i].x = x - 2;
                    pozvalid[i].y = y - 2;
                    sem=1;
                }
            } else {
                pozvalid[i].x = x - 1;
                pozvalid[i].y = y - 1;
                sem=1;
            }
        }
    }

    if(!sem)
        std::cout<<"Piesa aleasa nu poate fi mutata !";
    return sem;
}

Rege::Rege()
        : Piesa("", -1, -1) {}

Rege::Rege(const std::string &new_culoare, int new_x, int new_y)
        : Piesa(new_culoare, new_x, new_y) {}

Rege::Rege(const Piesa &other)
        : Piesa(other.getculoare(), other.getx(), other.gety()) {
    std::cout << " Constr Cop Piesa\n";
}

int Rege::mutaripos(std::array<pozitie, 4> &pozvalid, std::array<std::array<Piesa *, 8>, 8> mat,int randjucator) {
    int sem=0,i=0;
    for(int j=0;j<4;j++)
        pozvalid[j].x=pozvalid[j].y=-1;
    if(randjucator==1)
    {
        std::cout<<"";
    }
    if (x + 1 < 8 && y + 1 < 8) {
        if (mat[x + 1][y + 1] != nullptr ) {
            if ((x + 2 < 8 && y + 2 < 8) && mat[x+2][y+2] == nullptr && mat[x + 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                pozvalid[i].x = x + 2;
                pozvalid[i].y = y + 2;
                sem=1;
                i++;
            }
        } else {
            pozvalid[i].x = x + 1;
            pozvalid[i].y = y + 1;
            sem=1;
            i++;
        }
    }
    if (x + 1 < 8 && -1 < y - 1) {
        if (mat[x + 1][y - 1] != nullptr) {
            if ((x + 2 < 8 && -1 < y - 2) && mat[x+2][y-2] == nullptr && mat[x + 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                pozvalid[i].x = x + 2;
                pozvalid[i].y = y + 2;
                sem=1;
                i++;
            }
        } else {
            pozvalid[i].x = x + 1;
            pozvalid[i].y = y - 1;
            sem=1;
            i++;
        }
    }
    if (-1 < x - 1 && y + 1 < 8) {
        if (mat[x - 1][y + 1] != nullptr ) {
            if ((-1 < x - 2 && y + 2 < 8) && mat[x-2][y+2] == nullptr && mat[x + 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                pozvalid[i].x = x + 2;
                pozvalid[i].y = y + 2;
                sem=1;
                i++;
            }
        } else {
            pozvalid[i].x = x - 1;
            pozvalid[i].y = y + 1;
            sem=1;
            i++;
        }
    }
    if (-1 < x - 1 && -1 < y - 1 ) {
        if (mat[x - 1][y - 1] != nullptr ) {
            if ((-1 < x - 2 && -1 < y - 2 ) && mat[x-2][y-2] == nullptr && mat[x + 1][y + 1]->getculoare()!=mat[x][y]->getculoare()) {
                pozvalid[i].x = x + 2;
                pozvalid[i].y = y + 2;
                sem=1;
            }
        } else {
            pozvalid[i].x = x - 1;
            pozvalid[i].y = y - 1;
            sem=1;
        }
    }
    if(!sem)
        std::cout<<"Piesa aleasa nu poate fi mutata !";
    return sem;
}

