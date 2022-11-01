#include <iostream>
#include <string>

struct pozitie
{
    int x,y;
};
class Piesa
{
private:
    std::string Culoare;
    int Rege;
public:
    Piesa(const std::string new_culoare,int new_rege)
            :Culoare(new_culoare),Rege(new_rege){}

    Piesa(const Piesa& other)
            :Culoare(other.Culoare),Rege(other.Rege){
        std::cout<<" Constr Cop Piesa\n";
    }

    ~Piesa() {
        std::cout << "Destr Piesa\n";
    }

    Piesa& operator= (const Piesa& other) {
        if(&other != this) {
            this->Culoare = other.Culoare;
            this->Rege= other.Rege;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Piesa& st) {
        os << "Culoare: " << st.Culoare << ", Rege: " << st.Rege << "\n";
        return os;
    }
    std::string getculoare()
    {
        return Culoare;
    }

    void setRege()
    {
        Rege= true;
    }

    int getRege()const
    {
        return Rege;
    }
};

class Jucator
{
    std::string Culoare;
    std::string Nume;
    int scor;

public:
    Jucator(const std::string new_culoare)
            :Culoare(new_culoare),scor(0){}

    Jucator(const std::string new_nume,const std::string new_culoare)
            :Culoare(new_culoare),Nume(new_nume),scor(0){}

    Jucator(const Jucator& other)
            :Culoare(other.Culoare),Nume(other.Nume),scor(other.scor){
        std::cout<<" Constr Cop Jucator\n";
    }

    ~Jucator() {
        std::cout << "Destr Jucator\n";
    }

    Jucator& operator= (const Jucator& other) {
        if(&other != this) {
            this->Culoare = other.Culoare;
            this->Nume= other.Nume;
            this->scor= other.scor;
        }
        return *this;
    }
    friend std::istream& operator>>(std::istream& is,Jucator& st) {
        std::cout<<"Nume jucator:";
        is>>st.Nume;
        return is;
    }
    std::string getNume()
    {
        return Nume;
    }
    int getscor()
    {
        return scor;
    }
    void increment_scor()
    {
        scor++;
    }
};

class joc
{
    Piesa *mat[8][8];
    //Jucator p1("N"),p2("A")   DA EROARE ????????

public:

    joc()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<8;j++)
                if((i+j)%2==1)
                    mat[i][j]=new Piesa("A",0);
                else
                    mat[i][j]=nullptr;

        for(int i=5;i<8;i++)
            for(int j=0;j<8;j++)
                if((i+j)%2==1)
                    mat[i][j]=new Piesa("N",0);
                else
                    mat[i][j]=nullptr;
        for(int i=3;i<5;i++)
            for(int j=0;j<8;j++)
                mat[i][j]=nullptr;
    }

    joc& operator= (const joc& other) {
        if(&other != this) {
            for(int i=0;i<8;i++)
                for(int j=0;j<8;j++)
                    this->mat[i][j] = other.mat[i][j];
        }
        return *this;
    }

    ~joc()
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                delete mat[i][j];
    }

    void afistabla()
    {
        for(int i=0;i<3;i++){
            for(int j=0;j<36;j++)
                if(j%4==1&&i%3==1&&j>4)
                    std::cout<<char('A'+j/4-1);
                else
                    std::cout<<".";
            std::cout<<"\n";
        }
        for(int i=0;i<24;i++){
            for(int j=0;j<36;j++)
            {
                if(j<4){
                    if(i%3==1&&j%4==1)
                        std::cout<<i/3+1;
                    else
                        std::cout<<".";
                }
                else
                {
                    if((j%4==1||j%4==2)&&i%3==1&&mat[i/3][(j-4)/4]!= nullptr){
                        if(j%4==1) {
                            std::cout << mat[i / 3][(j - 4) / 4]->getculoare();
                            if(mat[i / 3][(j - 4) / 4]->getRege()==1)
                                std::cout<<"R";
                            else
                                std::cout<<" ";
                        }
                    }
                    else
                    {
                        if((j/4+(i/3-1))%2==0)
                            std::cout<<"#";
                        else
                            std::cout<<" ";
                    }
                }
            }
            std::cout<<"\n";
        }
    }

    int conversiemutare(pozitie &a,pozitie &b,std::string m)
    {

        int sem1=0,sem2=0;
        std::string sep=" ,.;:";
        for(long long unsigned int i=0;i<m.length();i++)
        {
            if(sep.rfind(m[i]))
            {
                if('a'<=m[i]&&m[i]<='h')
                {
                    if(sem1==0)
                        a.y=m[i]-'a';
                    else
                        b.y=m[i]-'a';
                    sem1++;
                }
                else
                {
                    if('1'<=m[i]&&m[i]<='8')
                    {
                        if(sem2==0)
                            a.x=m[i]-'1';
                        else
                            b.x=m[i]-'1';
                        sem2++;
                    }
                    else
                    {
                        std::cout<<"MUTARE INVALIDA !!!";
                        return 0;
                    }
                }
            }
        }
        if(sem1!=2||sem2!=2)
        {
            std::cout<<"MUTARE INVALIDA !!!";
            return 0;
        }
        return 1;
    }

    int mutarevalida(pozitie ms,pozitie mf,int rj)
    {
        if(mat[ms.x][ms.y]==nullptr)
        {
            std::cout<<"MUTARE INVALIDA 4!!!";
            return 0;
        }

        if((rj==1&&mat[ms.x][ms.y]->getculoare()=="N")||(rj==-1&&mat[ms.x][ms.y]->getculoare()=="A")){
            std::cout<<"MUTARE INVALIDA 3!!!";
            return 0;
        }

        if(mat[mf.x][mf.y]!=nullptr)
        {
            std::cout<<"MUTARE INVALIDA 5!!!";
            return 0;
        }
        if(mat[ms.x][ms.y]->getRege()==0) {
            if (!(((mf.x - ms.x == rj) && abs(ms.y - mf.y) == 1) || ((abs(ms.x - mf.x) == 2 && abs(ms.y - mf.y) == 2) &&
                                                                     mat[ms.x + rj][ms.y + (mf.y - ms.y) / 2] != nullptr &&
                                                                     mat[ms.x + rj][ms.y +
                                                                                    (mf.y - ms.y) / 2]->getculoare() !=
                                                                     mat[ms.x][ms.y]->getculoare()))) {
                std::cout << "MUTARE INVALIDA 6!!!";
                return 0;
            }
        }
        else
        {
            if (!((abs(ms.x - mf.x) == 1 && abs(ms.y - mf.y) == 1) || ((abs(ms.x - mf.x) == 2 && abs(ms.y - mf.y) == 2) &&
                                                                       mat[ms.x + (mf.x - ms.x) / 2][ms.y + (mf.y - ms.y) / 2] != nullptr &&
                                                                       mat[ms.x + (mf.x - ms.x) / 2][ms.y +
                                                                                                     (mf.y - ms.y) / 2]->getculoare() !=
                                                                       mat[ms.x][ms.y]->getculoare()))) {
                std::cout << "MUTARE INVALIDA 7!!!";
                return 0;
            }
        }
        return 1;
    }

    void start()
    {
        Jucator p1("N"),p2("A");
        std::cin>>p1>>p2;
        int nrA=12,nrN=12;
        int randjucator=-1;
        do
        {
            afistabla();
            std::string mutare;
            std::cout<<"Randul jucatorului "<<(randjucator<0?p1.getNume():p2.getNume());
            pozitie mutarestart,mutarefinal;
            do
            {
                std::cout<<"\nIntroduceti o mutare:";
                std::getline(std::cin>>std::ws,mutare);
            }while(!conversiemutare(mutarestart,mutarefinal,mutare)||!mutarevalida(mutarestart,mutarefinal,randjucator));

            if(abs(mutarestart.x-mutarefinal.x)==2&&abs(mutarestart.y-mutarefinal.y)==2&&mat[mutarestart.x+(mutarefinal.x-mutarestart.x)/2][mutarestart.y+(mutarefinal.y-mutarestart.y)/2]!=nullptr&&mat[mutarestart.x+(mutarefinal.x-mutarestart.x)/2][mutarestart.y+(mutarefinal.y-mutarestart.y)/2]->getculoare()!=mat[mutarestart.x][mutarestart.y]->getculoare())
            {
                mat[mutarestart.x+(mutarefinal.x-mutarestart.x)/2][mutarestart.y+(mutarefinal.y-mutarestart.y)/2]=nullptr;
                if(randjucator==-1)
                    nrA--;
                else
                    nrN--;
                randjucator=randjucator*(-1);
            }
            mat[mutarefinal.x][mutarefinal.y]=mat[mutarestart.x][mutarestart.y];
            mat[mutarestart.x][mutarestart.y]=nullptr;
            if(mutarefinal.x==0||mutarefinal.x==7)
                mat[mutarefinal.x][mutarefinal.y]->setRege();
            randjucator=randjucator*(-1);
            //system("cls");
        }while(nrA!=0&&nrN!=0);
        if(nrA==0)
        {
            p1.increment_scor();
            std::cout<<"Castiga "<<p1.getNume() << " Scor: "<<p1.getscor();
        }
        else
        {
            p2.increment_scor();
            std::cout<<"Castiga "<<p2.getNume() << " Scor: "<<p2.getscor();
        }
        std::string raspuns;
        std::cout<<"Continuati [Y/N]:";
        std::cin>>raspuns;
        if(raspuns=="Y")
            start();
        else
            exit(0);
    }
};
int main()
{
    joc Checkers;
    Checkers.start();
}
