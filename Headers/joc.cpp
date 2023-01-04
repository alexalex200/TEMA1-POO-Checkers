//
// Created by Alex on 12/17/2022.
//

#include "joc.h"

/*
    int joc::mv(pozitie mutarestart, pozitie mutarefinal) {
        if (abs(mutarestart.x - mutarefinal.x) == 2 && abs(mutarestart.y - mutarefinal.y) == 2 &&
            mat[mutarestart.x + (mutarefinal.x - mutarestart.x) / 2][mutarestart.y +
                                                                     (mutarefinal.y - mutarestart.y) /
                                                                     2].EstePiesa() &&
            mat[mutarestart.x + (mutarefinal.x - mutarestart.x) / 2][mutarestart.y +
                                                                     (mutarefinal.y - mutarestart.y) /
                                                                     2].getculoare() !=
            mat[mutarestart.x][mutarestart.y].getculoare())
            return 1;
        return 0;
    }

    int joc::mv2(pozitie mutarestart, pozitie mutarefinal, int randjucator) {
        if (mat[mutarestart.x][mutarestart.y].getRege() == 0) {
            if (((mutarefinal.x - mutarestart.x == randjucator) && abs(mutarestart.y - mutarefinal.y) == 1) ||
                ((abs(mutarestart.x - mutarefinal.x) == 2 && abs(mutarestart.y - mutarefinal.y) == 2) &&
                 mat[mutarestart.x + randjucator][mutarestart.y +
                                                  (mutarefinal.y - mutarestart.y) / 2].EstePiesa() &&
                 mat[mutarestart.x + randjucator][mutarestart.y +
                                                  (mutarefinal.y - mutarestart.y) / 2].getculoare() !=
                 mat[mutarestart.x][mutarestart.y].getculoare())) {
                return 0;
            }
        } else {
            if ((abs(mutarestart.x - mutarefinal.x) == 1 && abs(mutarestart.y - mutarefinal.y) == 1) ||
                ((abs(mutarestart.x - mutarefinal.x) == 2 && abs(mutarestart.y - mutarefinal.y) == 2) &&
                 mat[mutarestart.x + (mutarefinal.x - mutarestart.x) / 2][mutarestart.y +
                                                                          (mutarefinal.y - mutarestart.y) /
                                                                          2].EstePiesa() &&
                 mat[mutarestart.x + (mutarefinal.x - mutarestart.x) / 2][mutarestart.y +
                                                                          (mutarefinal.y - mutarestart.y) /
                                                                          2].getculoare() !=
                 mat[mutarestart.x][mutarestart.y].getculoare())){
                return 0;
            }
        }
        return 1;
    }

*/
joc::joc() {
    for (int i = 0; i < lungimetable; i++)
        for (int j = 0; j < latimetable; j++) {
            if ((i + j) % 2 == 0 && (i < 3 || i > 4)) {
                if (i < lungimetable / 2)
                    mat[i][j] = new Piesa("A", i, j);
                else
                    mat[i][j] = new Piesa("N", i, j);
            } else
                mat[i][j] = nullptr;
        }
    /*
    afistabla();
    std::array<pozitie,4> pozitiilibere{};
    mat[5][7]->mutaripos(pozitiilibere,mat,-1);
    for(int i=0;i<4;i++)
    {
        //if(pozitiilibere[i].x!=-1)
        std::cout<<i+1<<"."<<pozitiilibere[i].x<<" "<<pozitiilibere[i].y<<'\n';
    }
    */
}

joc::joc(const joc &other)
        : mat(other.mat) {
    std::cout << " Constr Cop joc\n";
}

joc &joc::operator=(const joc &other) {
    if (&other != this) {
        for (int i = 0; i < lungimetable; i++)
            for (int j = 0; j < latimetable; j++) {
                this->mat[i][j] = other.mat[i][j];
                this->lungimetable = other.lungimetable;
                this->latimetable = other.latimetable;
                this->lungimebanda = other.lungimebanda;
                this->latimebanda = other.latimetable;
            }
    }
    return *this;
}

joc::~joc() {
    for (int i = 0; i < lungimetable; i++)
        for (int j = 0; j < latimetable; j++)
            delete mat[i][j];
}

void joc::ResetTabla() {
    for (int i = 0; i < lungimetable; i++)
        for (int j = 0; j < latimetable; j++)
            delete mat[i][j];

    for (int i = 0; i < lungimetable; i++)
        for (int j = 0; j < latimetable; j++) {
            if ((i + j) % 2 == 0 && (i < 3 || i > 4)) {
                if (i < lungimetable / 2)
                    mat[i][j] = new Piesa("A", i, j);
                else
                    mat[i][j] = new Piesa("N", i, j);
            } else
                mat[i][j] = nullptr;
        }
}

void joc::afistabla() {
    for (int i = 0; i < lungimebanda; i++) {
        for (int j = 0; j < (4 * latimetable + latimebanda); j++)
            if (j % 4 == 1 && i % 3 == 1 && j > 4)
                std::cout << char('A' + j / 4 - 1);
            else
                std::cout << ".";
        std::cout << "\n";
    }
    for (int i = 0; i < 3 * lungimetable; i++) {
        for (int j = 0; j < (4 * latimetable + latimebanda); j++) {
            if (j < 4) {
                if (i % 3 == 1 && j % 4 == 1)
                    std::cout << i / 3 + 1;
                else
                    std::cout << ".";
            } else {
                if ((j % 4 == 1 || j % 4 == 2) && i % 3 == 1 && mat[i / 3][(j - 4) / 4] != nullptr) {
                    if (j % 4 == 1) {
                        std::cout << mat[i / 3][(j - 4) / 4]->getculoare();
                        if (strstr(typeid(*mat[i / 3][(j - 4) / 4]).name(), "Rege"))
                            std::cout << "R";
                        else
                            std::cout << " ";
                    }
                } else {
                    if ((j / 4 + (i / 3 - 1)) % 2 == 0)
                        std::cout << "#";
                    else
                        std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
}

int joc::conversiemutare(pozitie &a, std::string m) {

    int sem1 = 0, sem2 = 0;
    std::string sep = " ,.;:";
    for (long long unsigned int i = 0; i < m.length(); i++) {
        if (sep.rfind(m[i])) {
            if ('a' <= tolower(m[i]) && tolower(m[i]) <= 'h') {
                a.y = tolower(m[i]) - 'a';
                sem1++;
            } else {
                if ('1' <= m[i] && m[i] <= '8') {
                    a.x = m[i] - '1';
                    sem2++;
                } else {
                    std::cout << "MUTARE INVALIDA din conversie1!!!";
                    return 0;
                }
            }
        }
    }
    if (sem1 != 1 || sem2 != 1) {
        std::cout << "MUTARE INVALIDA din conversie2!!!";
        return 0;
    }
    return 1;
}

void joc::start() {
    Jucator p1("N"), p2("A");
    std::cin >> p1 >> p2;
    int nrA = 1, nrN = 1;
    int randjucator = -1;
    char raspuns;
    do {
        do {
            afistabla();
            std::string mutare;
            std::cout << "Randul jucatorului " << (randjucator < 0 ? p1.getNume() : p2.getNume());
            std::array<pozitie,4> pozitiilibere{};
            pozitie mutarestart;
            int sem;
            do {
                sem=1;
                do {
                    std::cout << "\nAlege o piesa " << (randjucator < 0 ? "Neagra " : "Alba ");
                    std::getline(std::cin >> std::ws, mutare);
                }while (!conversiemutare(mutarestart, mutare)||mat[mutarestart.x][mutarestart.y] == nullptr);
                std::cout<<mutarestart.x<<" "<<mutarestart.y<<'\n';
                if((mat[mutarestart.x][mutarestart.y]->getculoare()!="N"&&randjucator==-1)||(mat[mutarestart.x][mutarestart.y]->getculoare()!="A"&&randjucator==1))
                    sem = 0;
            }while(sem==0||!mat[mutarestart.x][mutarestart.y]->mutaripos(pozitiilibere, mat, randjucator));
            for(int i=0;i<4;i++)
            {
                if(pozitiilibere[i].x!=-1)
                    std::cout<<i+1<<". "<<char('A'+pozitiilibere[i].y)<<" "<<pozitiilibere[i].x+1<<'\n';
            }

            int mutarefinal;
            do {
                std::cout << "Alege o mutare: ";
                std::cin >> mutarefinal;
                mutarefinal--;
            }while(pozitiilibere[mutarefinal].x==-1);

            mat[pozitiilibere[mutarefinal].x][pozitiilibere[mutarefinal].y]=mat[mutarestart.x][mutarestart.y];
            mat[pozitiilibere[mutarefinal].x][pozitiilibere[mutarefinal].y]->setpozitie(pozitiilibere[mutarefinal].x,pozitiilibere[mutarefinal].y);
            if(abs(pozitiilibere[mutarefinal].x-mutarestart.x)==2) {
                if (randjucator == -1)
                    nrA--;
                else
                    nrN--;
                delete mat[(pozitiilibere[mutarefinal].x+mutarestart.x)/2][(pozitiilibere[mutarefinal].y+mutarestart.y)/2];
                mat[(pozitiilibere[mutarefinal].x+mutarestart.x)/2][(pozitiilibere[mutarefinal].y+mutarestart.y)/2] = nullptr;
                randjucator = randjucator * (-1);
            }
            mat[mutarestart.x][mutarestart.y]= nullptr;
            if (pozitiilibere[mutarefinal].x == 0 || pozitiilibere[mutarefinal].x == 7)
                mat[pozitiilibere[mutarefinal].x][pozitiilibere[mutarefinal].y]=new Rege(*mat[pozitiilibere[mutarefinal].x][pozitiilibere[mutarefinal].y]);
            randjucator = randjucator * (-1);
            //system("cls");
        } while (nrA != 0 && nrN != 0);
        ResetTabla();
        if (nrA == 0) {
            p1.increment_scor();
            std::cout << "Castiga " << p1.getNume() << " Scor: " << p1.getscor() << '\n';
        } else {
            p2.increment_scor();
            std::cout << "Castiga " << p2.getNume() << " Scor: " << p2.getscor() << '\n';
        }
        std::cout << "Continuati [Y/N]:";
        std::cin >> raspuns;
        nrA = 1;
        nrN = 1;
    } while (toupper(raspuns) == 'Y');
}
