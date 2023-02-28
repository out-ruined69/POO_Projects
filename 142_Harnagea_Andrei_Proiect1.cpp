#include <iostream>
#include <string.h>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

int i;

class Angajat {
    private:
        char*nume;
        char*prenume;
        int*shifts;
        float day;
        float salariu;
        char InitM;

        const int idAngajat;
        static int contorIdA;

    public:

        friend ostream& operator<<(ostream&, const Angajat& );
        friend istream& operator>>(istream&, Angajat& p);
        friend void OrdonareSalariu();
        friend void RemoveFirstEmployee();
        //friend void Disponibili(int zi);

        void citireA();
        void afisareA();

        Angajat (); //Empty construcotor

        Angajat(char*nume,char*prenume,int*shifts,char InitM,float day,float salariu); //const parametru


        Angajat(const Angajat&p); //copy const

        Angajat(char*nume,char*prenume) ; //2 param consy


        Angajat operator= (const Angajat& p);//op egal

            //Operatorul ++

        Angajat operator++() ;//il aduna si il afiseaza

        Angajat operator++(int) ; //il afiseaza cum e, dupa il aduna

            //OPERATOR +
        Angajat operator+=(float x) ;

        Angajat operator+(float x) ;

        friend Angajat operator+(float x, Angajat a) {
        a.salariu = a.salariu + x;
        return a;
    }

        Angajat operator+(Angajat a) ;
            //OPERATOR *

        friend Angajat operator*(float x, Angajat a) {
        a.salariu = a.salariu * x;
        return a;
    }

        Angajat operator*=(float x) ;

        Angajat operator*(float x);

        Angajat operator*(Angajat a) ;
        //OPERATORI COMPARARE

                    bool operator> (const Angajat &a);

                    bool operator== (const Angajat &a);

       explicit operator int() {
        return (int)this->salariu;
    }



       //SETTERS
       void setNumeA(char *nume);
       void setPrenumeA(char *prenume);
       void setShiftsA(int *shifts);
       void setDayA(float day);
       void setSalariuA(float salariu);
       void setInitMA(char InitM);

        //Getters
        char* getNumeA();
        char* getPrenumeA();
        int getShiftDayA(int ind);
        float getSalariuA();
        float getDayA();


         //Index overload
        int operator[](int index){
            if(index<7 && index>1)
        return shifts[index];
            else
                return 0;

        }



        ~Angajat () ;
};

class GiftShop {
    private:
        int nr_items;
        int *vizitatori;
        float incasari;
        float intretinere;
        float total;
        char *nume;
        bool deschis;
        vector <Angajat> employees;
    public:
        friend ostream& operator<<(ostream&, const GiftShop& );
        friend istream& operator>>(istream&, GiftShop& gs);
        friend void Disponibili(int zi);
         void MaximSalariu();
        void citireGS();
        void afisareGS();

        GiftShop(); //Constructor empty

        GiftShop(int nr_items, int *vizitatori, float incasari, float intretinere,float total, char *nume, bool deschis, vector<Angajat> employees); //constructor cu toti parametrii
        GiftShop(const GiftShop &gs);

        GiftShop operator= (const GiftShop &gs); //copy constructor

        GiftShop(float incasari, float intretinere); //constructir cu 2 parametrii

        //Operatorul ++

        GiftShop operator++();

        GiftShop operator++(int);

        //Operatorul +

        GiftShop operator+=(float x);

        GiftShop operator+(float x);

        GiftShop operator+(GiftShop a) ;

        friend GiftShop operator+(float x, GiftShop a) {
        a.total = a.total+ x;
        return a;
    }



        //Operatorul *

        GiftShop operator*=(float x);

        GiftShop operator*(float x) ;
        GiftShop operator*(GiftShop a) ;

        friend GiftShop operator*(float x, GiftShop a) {
        a.total = a.total * x;
        return a;
    }


        //Operatorii > si ==

    bool operator> (const GiftShop &gs);

    bool operator== (const GiftShop &gs);
            //Indexare
        Angajat operator[](int index) {

        return employees[index];
    }


        friend GiftShop operator+(Angajat&a,GiftShop g){ //ADAUGARE DOUA CLASE DIFERITE


        g.employees.push_back(a);
        return g;

        }

        friend GiftShop operator+(GiftShop g,Angajat&a){//ADAUGARE DOUA CLASE DIFERITE

        g.employees.push_back(a);
        return g;

        }

            //getters
        char *getNumeGS();
        float getIncasariGS();
        float getTotalGS();
        float getIntretinereGS();
        int *getVizitatoriGS();
        int getNrItemsGS();
        bool getDeschisGS();

        void showVizitatoriGS();

        void Disponibilitate(int ind) ;

            //setters
        void setIncasariGS(float incasari);
        void setTotalGS(float total);
        void setIntretinereGS(float intretinere);
        void setNrItemsGS(int nr_items);
        void setNumeGS(char *nume);
        void setDeschisGS(bool deschis);
        void setVizitatoriGS(int *vizitatori);

        void addEmployee(Angajat&a);

        void RemoveLastEmployee();

       void RemoveNEmployee(int ind);

        void FireAll() ;

        void PromoteEmployee(int ind,float x);

        void AfisareNumeEmployees();

         ~GiftShop();

};

class Reviews {
                private:
                    int *likes;
                    int *dislikes;
                    int total_likes;
                    int total_dislikes;
                    double raport;
                    char* platforma;

                public:
                    friend ostream& operator<<(ostream&, const Reviews& );
                    //friend class Exponat; //ii fac prieteni ca sa pot accesa in exponat likes dislikes etc.
                    friend istream& operator>>(istream&, Reviews&sc);
                    void citireRW();
                    void afisareRW();

                    Reviews();

                    Reviews(int*likes,int*dislikes,int total_dislikes,int total_likes, double raport, char*platforma);

                    Reviews(int *likes, int *dislikes, char *platforma);

                      int operator[](int index){
                        return likes[index]-dislikes[index];
                        }

                    Reviews(const Reviews &rw);
                    Reviews(int total_dislikes, int total_likes);
                    Reviews operator= (const Reviews &rw);

                    bool operator> (const Reviews &rw);

                    bool operator== (const Reviews &rw);

                    //OPERATOR ++

                    Reviews operator++();

                    Reviews operator++(int) ;

                    //OP +

                    Reviews operator+=(int x) ;

                    Reviews operator+(float x) ;

                    Reviews operator+(Reviews a) ;

                    friend Reviews operator+(float x, Reviews a) {
                        a.total_dislikes = a.total_dislikes + x*0.5;
                        a.total_likes = a.total_likes + x;
                        if(a.total_likes!=0 && a.total_dislikes!=0)
                        a.raport=double(a.total_likes)/double(a.total_dislikes);
                    else
                    if(a.total_dislikes==0 && a.total_likes!=0)
                        a.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(a.total_dislikes==0 && a.total_likes==0)
                        a.raport=-2; //exponatul e nou-postat
                    else
                        if(a.total_dislikes!=0 && a.total_likes==0)
                        a.raport=0;
                        return a;
                    }

                    //OP *

                    Reviews operator*=(int x) ;

                    Reviews operator*(float x) ;

                    Reviews operator*(Reviews a) ;

                    friend Reviews operator*(float x, Reviews a) {
                        a.total_dislikes = a.total_dislikes * x*0.5;
                        a.total_likes = a.total_likes * x;
                        if(a.total_likes!=0 && a.total_dislikes!=0)
                        a.raport=double(a.total_likes)/double(a.total_dislikes);
                    else
                    if(a.total_dislikes==0 && a.total_likes!=0)
                        a.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(a.total_dislikes==0 && a.total_likes==0)
                        a.raport=-2; //exponatul e nou-postat
                    else
                        if(a.total_dislikes!=0 && a.total_likes==0)
                        a.raport=0;
                        return a;
                    }

                    //Getters
                    int GetTotalLikesRW();
                    int GetTotalDislikesRW();
                    double GetRaportRW();
                    int* GetDislikesRW();
                    int* GetLikesRW();
                    char *getPlatformaRW();
                    int GetLikesDayRW(int i);
                    int GetDislikesDayRW(int i);

                    //Setters
                    void SetTotalLikesRW(int total_likes);

                    void SetRaportRW(double raport);
                    void SetTotalDislikesRW(int total_dislikes);
                    void SetLikesRW(int*likes);
                    void SetDislikesRW(int*dislikes);
                    void SetPlatformaRW(char*platforma);

                     explicit operator int() {
                    return (int)this->raport;
                    }

                    ~Reviews();
                        };

class Exponat {
    private:
        char *nume;
        char *autor;
        int vechime;
        char sector;
        Reviews social;

        const int idExponat;
        static int contorId;

            public:
        friend ostream& operator<<(ostream&, const Exponat& );
        friend istream& operator>>(istream&, Exponat&ex);

        void citireEX();
        void afisareEX();

        Exponat ();

        Exponat (char*nume,char*autor,char sector);

        Exponat(char *nume, Reviews &social, char *autor, int vechime, char sector);

        Exponat(const Exponat &exp);

        Exponat&operator=(const Exponat &exp);

        //Operatorul ++

        Exponat operator++();

        Exponat operator++(int);
        //Operatorul +

        Exponat operator+=(float x);
        Exponat operator+(float x);
        Exponat operator+(Exponat a);

        friend Exponat operator+(float x, Exponat a) {
        a.vechime = a.vechime+ x;
        return a;
    }

        //Operatorul *

        Exponat operator*=(float x);

        Exponat operator*(float x);

        Exponat operator*(Exponat a);


        friend Exponat operator*(float x, Exponat a) {
        a.vechime = a.vechime* x;
        return a;
    }


        //Operatorii de comparare

    bool operator> (const Exponat &ex);

    bool operator== (const Exponat &ex);

        explicit operator int() {
        return (int)this->vechime;
    }

        //Getters

        char *getNumeEx();
        int getIdExponat();
        char *getAutorEx();
        char getSectorEx();
        int getVechimeEx();
        static int getContorId(){return Exponat::contorId;}

        //Getters pt socials
        int getTotalLikesEx();
        int *getLikesEx();
        int getTotalDislikesEx();
        int *getDislikesEx();
        double getRaportEx();
        char *getPlatformaEx();


        //Setters
        void setNumeEx(char *nume);
        void setAutorEx(char *autor);
        void setSectorEx(char sector);
        void setVechimeEx(int vechime);

        //Setter pt Social
        void SetTotalLikesEx(int total_likes);
        void SetTotalDislikesEx(int total_dislikes);
        void SetRaportEx(double raport){this->social.SetRaportRW(raport);}
        void SetLikesEx(int*likes);
        void SetDislikesEx(int*dislikes);
        void SetPlatformaEx(char*platforma);

        void Promovare(int x);

         //Index overload
        int operator[](int index){
            if(index<strlen(this->nume))
        return nume[index];
        else
            return nume[1];
        }

        ~Exponat ();



};

Angajat::Angajat ():idAngajat(contorIdA++) {

        this->nume=new char[strlen("Nume")+1];
        strcpy(this->nume,"Nume");
        this->prenume=new char[strlen("Prenume")+1];
        strcpy(this->prenume,"Prenume");
        this->shifts=new int[8];
        for(int i=1;i<=7;i++)
            shifts[i]=0;
        InitM='#';
        this->day=0;
        this->salariu=0;


        }

Angajat::Angajat(char*nume,char*prenume,int*shifts,char InitM,float day,float salariu):idAngajat(contorIdA++) {

        this->nume=new char[strlen(nume+1)];
        strcpy(this->nume,nume);

        this->prenume=new char[strlen(prenume+1)];
        strcpy(this->prenume,prenume);

        //this->bool=new bool[8] dar nu are sens, am 7 zile setate
        this->shifts=shifts;

        this->InitM=InitM;

        this->day=day;
        this->salariu=salariu;

        }

        Angajat::Angajat(const Angajat&p):idAngajat(contorIdA++) {

        this->nume=new char[strlen(p.nume+1)];
        strcpy(this->nume,p.nume);

        this->prenume=new char[strlen(p.prenume+1)];
        strcpy(this->prenume,p.prenume);

        //this->bool=new bool[8] dar nu are sens, am 7 zile setate
        this->shifts=p.shifts;

        this->InitM=p.InitM;
        this->day=p.day;
        this->salariu=p.salariu;

        }

Angajat::Angajat(char*nume,char*prenume):idAngajat(contorIdA++) {

        this->nume=new char[strlen(nume+1)];
        strcpy(this->nume,nume);

        this->prenume=new char[strlen(prenume+1)];
        strcpy(this->prenume,prenume);
        this->shifts=new int[8];
        for(int i=1;i<=7;i++)
            shifts[i]=0;

        this->InitM='#';

        this->day=0;
        this->salariu=0;


        }


Angajat Angajat::operator= (const Angajat& p){

            if(this!=&p)
            {
                if(this->nume!=NULL)
                    delete[] this->nume;

                if(this->prenume!=NULL)
                    delete[] this->prenume;

                if(this->shifts!=NULL)
                    delete[] this->shifts;

                this->nume=new char[strlen(p.nume+1)];
                strcpy(this->nume,p.nume);

                this->prenume=new char[strlen(p.prenume+1)];
                strcpy(this->prenume,p.prenume);

                this->shifts=new int[8];
                for(int i=1;i<=7;i++)
                    this->shifts[i]=p.shifts[i];

                this->InitM=p.InitM;
                this->day=p.day;
                this->salariu=p.salariu;
            }
            return *this;

        }

            //Operatorul ++

Angajat Angajat::operator++() { //a++
        this->salariu++;
        return *this;
    }

Angajat Angajat::operator++(int) { //++a
            Angajat aux = *this;
            this->salariu++;
            return aux;
        }

            //OPERATOR +
Angajat Angajat::operator+=(float x) {
            this->salariu += x;
            return *this;
    }

Angajat Angajat::operator+(float x) {
        Angajat aux = *this;
        aux.salariu = aux.salariu + x;
        return aux;
    }

Angajat Angajat::operator+(Angajat a) {
        a.salariu = a.salariu + this->salariu;
        return a;
    }

            //OPERATOR *



Angajat Angajat::operator*=(float x) {
            this->salariu *= x;
            return *this;
    }

Angajat Angajat::operator*(float x) {
        Angajat aux = *this;
        aux.salariu = aux.salariu * x;
        return aux;
    }

Angajat Angajat::operator*(Angajat a) {
        a.salariu = a.salariu * this->salariu;
        return a;
    }

        //OPERATORI COMPARARE

                    bool Angajat::operator> (const Angajat &a){

                        if(this->salariu>a.salariu)
                            return true;
                        else
                            return false;

                    }

                    bool Angajat::operator== (const Angajat &a){

                        if(this->salariu==a.salariu)
                            return true;
                        else
                            return false;

                    }




       //SETTERS
       void Angajat::setNumeA(char *nume){delete[] this-> nume; this->nume=new char[strlen(nume)+1];strcpy(this->nume,nume);}
       void Angajat::setPrenumeA(char *prenume){delete[] this-> prenume; this->prenume=new char[strlen(prenume)+1];strcpy(this->prenume,prenume);}
       void Angajat::setShiftsA(int *shifts)
       {delete[] this-> shifts;
       this->shifts=new int[9];

       for(int i=1;i<=7;i++)
        this->shifts[i]=shifts[i];

       }
       void Angajat::setDayA(float day){this->day=day;}
       void Angajat::setSalariuA(float salariu){this->salariu=salariu;}
       void Angajat::setInitMA(char InitM){this->InitM=InitM;}

        //Getters
        char* Angajat::getNumeA(){return this->nume;}
        char* Angajat::getPrenumeA(){return this->prenume;}
        int Angajat::getShiftDayA(int ind){return this->shifts[ind];}
        float Angajat::getSalariuA(){return this->salariu;}
        float Angajat::getDayA(){return this->day;}


        Angajat::~Angajat () {

        if(this->nume!=NULL)
            delete[] this-> nume;

        if(this->prenume!=NULL)
            delete[] this-> prenume;

        if(this->shifts!=NULL)
            delete[] this->shifts;}

GiftShop::GiftShop(){

        this->nume=new char[strlen("Shoppy")+1];
        strcpy(this->nume,"Shoppy");

        this->nr_items=0;
        this->incasari=0;
        this->total=0;
        this->intretinere=0;
        this->vizitatori=NULL;
        this->vizitatori=new int[8];
        this->deschis=0;
        vector <Angajat> employees = {};
        for(int i=0;i<=7;i++)
            vizitatori[i]=0;


        }

         GiftShop::GiftShop(int nr_items, int *vizitatori, float incasari, float intretinere,float total, char *nume, bool deschis, vector<Angajat> employees)
        {

            this->nume=new char[strlen(nume)+1];
            strcpy(this->nume,nume);
            this->total=total;
            this->nr_items=nr_items;
            this->vizitatori=new int[14];
            this->vizitatori=vizitatori;
            this->incasari=incasari;
            this->intretinere=intretinere;
            this->total=this->incasari-this->intretinere;
            //this->employees=employees;
            if(this->nr_items==0)
                this->deschis=0;
            else
                this->deschis=1;

            for(int i=0;i<employees.size();i++)
                this->employees.push_back(employees[i]);

        }

         GiftShop::GiftShop(const GiftShop &gs){


            this->nume=new char[strlen(gs.nume)+1];
            strcpy(this->nume,gs.nume);

            this->nr_items=gs.nr_items;
            this->vizitatori=new int[14];
            this->vizitatori=gs.vizitatori;
            this->incasari=gs.incasari;
            this->intretinere=gs.intretinere;
            this->total=this->incasari-this->intretinere;
            this->deschis=gs.deschis;

            for(int i=0;i<employees.size();i++)
                this->employees.push_back(gs.employees[i]);


        }

        GiftShop  GiftShop::operator= (const GiftShop &gs){ //Operatorul =

            if(this!=&gs) //in caz ca pune cineva a=a
            {
                if(this->nume!=NULL)
                    delete[] this->nume;

                if(this->vizitatori!=NULL)
                    delete[] this->vizitatori;


            this->nume=new char[strlen(gs.nume)+1];
            strcpy(this->nume,gs.nume);
            this->employees=employees;

            this->nr_items=gs.nr_items;
            this->vizitatori=new int[9];
            //this->vizitatori=gs.vizitatori;
            for(int i=1;i<=7;i++)
                this->vizitatori[i]=gs.vizitatori[i];

            this->incasari=gs.incasari;
            this->intretinere=gs.intretinere;
            this->total=gs.total;
            this->deschis=gs.deschis;
            for(int i=0;i<gs.employees.size();i++)
                this->employees.push_back(gs.employees[i]);


            }
            return *this;

        }

         GiftShop::GiftShop(float incasari, float intretinere) {

        this->nume=new char[strlen("Shoppy")+1];
        strcpy(this->nume,"Shoppy");

        this->nr_items=0;
        this->vizitatori=NULL;
        this->vizitatori=new int[8];
        this->deschis=0;
        for(int i=1;i<=7;i++)
            vizitatori[i]=0;
        this->incasari=incasari;
        this->intretinere=intretinere;
        this->total=this->incasari-this->intretinere;
        this->employees={};


        }

        //Operatorul ++

        GiftShop  GiftShop::operator++() {

        this->total++;
        return *this;

        }

        GiftShop  GiftShop::operator++(int) {
            GiftShop aux = *this;
            this->total++;
            return aux;
        }

        //Operatorul +

        GiftShop  GiftShop::operator+=(float x) {
            this->total += x;
            return *this;
    }

        GiftShop  GiftShop::operator+(float x) {
        GiftShop aux = *this;
        aux.total = aux.total + x;
        return aux;
    }

        GiftShop  GiftShop::operator+(GiftShop a) {
        a.total = a.total + this->total;
        return a;
    }

        //Operatorul *

        GiftShop  GiftShop::operator*=(float x) {
            this->total *= x;
            return *this;
    }

        GiftShop  GiftShop::operator*(float x) {
        GiftShop aux = *this;
        aux.total = aux.total * x;
        return aux;
    }

        GiftShop  GiftShop::operator*(GiftShop a) {
        a.total = a.total * this->total;
        return a;
    }

        //Operatorii > si ==

    bool  GiftShop::operator> (const GiftShop &gs){

        if(this->total>gs.total)
            return true;
                else
            return false;

                    }

    bool  GiftShop::operator== (const GiftShop &gs){

        if(this->total==gs.total)
            return true;
                else
            return false;

                    }
            //Indexare


            //getters
        char * GiftShop::getNumeGS(){return this->nume;}
        float  GiftShop::getIncasariGS(){return this->incasari;}
        float  GiftShop::getTotalGS(){return this->total;}
        float  GiftShop::getIntretinereGS(){return this->intretinere;}
        int * GiftShop::getVizitatoriGS(){return this->vizitatori;}
        int  GiftShop::getNrItemsGS(){return this->nr_items;}
        bool  GiftShop::getDeschisGS(){return this->deschis;}

        void  GiftShop::showVizitatoriGS(){for(int i=0;i<12;i++) cout<<"Ziua "<<i+1<<"-Nr de vizitatori "<<this->vizitatori[i]<<" "<<endl;cout<<endl;}

    void  GiftShop::Disponibilitate(int ind) {

            int found=-1;
            if(ind<1 || ind > 7)
                cout<<"Zi invalida!"<<endl;
                else
{
    for(int i=0;i<this->employees.size();i++)
            if(employees[i].getShiftDayA(ind)!=0)
                {cout<<employees[i].getNumeA()<<" lucreaza in ziua "<<ind<<endl;
                found=1;
                }
        if(found==-1)
            cout<<"Niciun angajat nu lucreaza in aceasta zi :("<<endl;}

        }

            //setters
        void  GiftShop::setIncasariGS(float incasari){this->incasari=incasari; this->total=this->incasari-this->intretinere;}
        void  GiftShop::setTotalGS(float total){this->total=total;}
        void  GiftShop::setIntretinereGS(float intretinere){this->intretinere=intretinere; this->total=this->incasari-this->intretinere;}
        void  GiftShop::setNrItemsGS(int nr_items){this->nr_items=nr_items; if(this->nr_items==0) this->deschis=0;}
        void  GiftShop::setNumeGS(char *nume){delete[] this-> nume; this->nume=new char[strlen(nume)+1];strcpy(this->nume,nume);}
        void  GiftShop::setDeschisGS(bool deschis){this->deschis=deschis;}
        void  GiftShop::setVizitatoriGS(int *vizitatori){delete[] this-> vizitatori; this->vizitatori=new int[14];this->vizitatori=vizitatori;}

        void  GiftShop::addEmployee(Angajat&a){
        this->employees.push_back(a);

        }

         void  GiftShop::RemoveLastEmployee(){

            if(this->employees.size()==0)
                cout<<"Nu exista angajati!"<<endl;
            else
                this->employees.pop_back();

        }

        void  GiftShop::RemoveNEmployee(int ind){

            if(this->employees.size()<ind-1 || this->employees.size()==0)
                cout<<"Nu exista acest angajat\n!";
            else
                this->employees.erase(this->employees.begin()+ind-1);


        }

        void  GiftShop::FireAll() {

        if(this->employees.size()!=0)
            this->employees.clear();

        }

        void  GiftShop::PromoteEmployee(int ind,float x){

        if(this->employees.size()<ind-1 || this->employees.size()==0 || ind<=0)
            cout<<"Nu exista acest angajat!"<<endl;
        else
            {this->employees[ind-1]+=x;
            if(this->employees[ind-1].getSalariuA()<=0)
                this->employees[ind-1].setSalariuA(0);}

        }

        void  GiftShop::AfisareNumeEmployees(){
            if(this->employees.size()==0)
                cout<<"Nu exista!"<<endl;
            else
        for(i=0;i<this->employees.size();i++)
            cout<<this->employees[i].getNumeA()<<" "<<this->employees[i].getPrenumeA()<<endl;

        }

        void GiftShop::MaximSalariu(){

            if(this->employees.size()==0)
                cout<<"Nu exista angajati!"<<endl;
            else
            {
                float maxi=0;
                for(i=0;i<this->employees.size();i++)
                    if(this->employees[i].getSalariuA()>maxi)
                        maxi=this->employees[i].getSalariuA();
                for(i=0;i<this->employees.size();i++)
                    if(this->employees[i].getSalariuA()==maxi)
                        cout<<this->employees[i].getNumeA()<<" are salariul maxim de "<<maxi<<endl;
            }

        }


         GiftShop::~GiftShop(){

            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->vizitatori!=NULL)
                delete[] this->vizitatori;

        }

Reviews::Reviews(){ //Constructor

                    this->total_likes=0;
                    this->total_dislikes=0;
                    this->raport=0;
                    this->platforma=new char[strlen("Internet")+1];
                    strcpy(this->platforma,"Internet");
                    this->likes=new int[9];
                    for(int i=1;i<=7;i++)
                        this->likes=0;
                    this->dislikes=new int[9];
                    for(int i=1;i<=7;i++)
                        this->dislikes=0;


                    }

Reviews::Reviews(int*likes,int*dislikes,int total_dislikes,int total_likes, double raport, char*platforma){

                    this->total_dislikes=total_dislikes;
                    this->total_likes=total_likes;

                    this->likes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->likes[i]=likes[i];
                        }
                    this->dislikes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->dislikes[i]=dislikes[i];
                        }

                    if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                    else
                    if(this->total_dislikes==0 && total_likes!=0)
                        this->raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(this->total_dislikes==0 && total_likes==0)
                        this->raport=-2; //exponatul e nou-postat
                    else
                        if(this->total_dislikes!=0 && total_likes==0)
                        this->raport=0;

                    this->platforma=new char[strlen(platforma)+1];
                    strcpy(this->platforma,platforma);
                    this->raport=raport;

                    }

Reviews::Reviews(int *likes, int *dislikes, char *platforma){ //constructor toti parametrii pt reviews

                    //this->likes=likes;
                    //this->dislikes=dislikes;
                    this->total_dislikes=0;
                    this->total_likes=0;

                    this->likes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->likes[i]=likes[i];
                        this->total_likes+=this->likes[i];}
                    this->dislikes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->dislikes[i]=dislikes[i];
                        this->total_dislikes+=this->dislikes[i];}

                    if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                    else
                    if(this->total_dislikes==0 && total_likes!=0)
                        this->raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(this->total_dislikes==0 && total_likes==0)
                        this->raport=-2; //exponatul e nou-postat
                    else
                        if(this->total_dislikes!=0 && total_likes==0)
                        this->raport=0;

                    this->platforma=new char[strlen(platforma)+1];
                    strcpy(this->platforma,platforma);

                    }

Reviews::Reviews(const Reviews &rw){  //Constructor Copiere

                    this->total_dislikes=rw.total_dislikes;
                    this->total_likes=rw.total_likes;

                    this->likes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->likes[i]=rw.likes[i];
                        }
                    this->dislikes=new int[9];
                    for(int i=1;i<=7;i++)
                        {this->dislikes[i]=rw.dislikes[i];
                        }

                    this->raport=rw.raport;

                    this->platforma=new char[strlen(platforma)+1];
                    strcpy(this->platforma,rw.platforma);

                    }
Reviews::Reviews(int total_dislikes, int total_likes){ //constructor 2 parametrii

                    this->total_dislikes=total_dislikes;
                    this->total_likes=total_likes;

                    if(this->total_dislikes!=0)
                                this->raport=float(this->total_likes)/float(this->total_dislikes);
                            if(this->total_dislikes==0)
                                this->raport=-1; //Nu are dislikes, e perfecta
                            if(this->total_dislikes==0 && this->total_likes==0)
                                this->raport=-2; //De abia a fost introdusa

                    }
Reviews Reviews::operator= (const Reviews &rw){ //Op egal

                        if(this!=&rw)
                        {
                            if(this->platforma!=NULL)
                                delete[] this-> platforma;
                            if(this->likes!=NULL)
                                delete[] this-> likes;
                            if(this->dislikes!=NULL)
                                delete[] this-> dislikes;

                                //this->total_dislikes=rw.total_dislikes;
                               // this->total_likes=rw.total_likes;

                                this->likes=new int[9];
                                for(int i=1;i<=7;i++)
                                    {this->likes[i]=rw.likes[i];
                                    }
                                this->dislikes=new int[9];
                                for(int i=1;i<=7;i++)
                                    {this->dislikes[i]=rw.dislikes[i];
                                    }

                                this->raport=rw.raport;

                                this->platforma=new char[strlen(platforma)+1];
                                strcpy(this->platforma,rw.platforma);

                        }

                    return *this;

                    }

                    bool Reviews::operator> (const Reviews &rw){

                        if(this->raport>rw.raport)
                            return true;
                        else
                            return false;

                    }

                    bool Reviews::operator== (const Reviews &rw){

                        if(this->raport==rw.raport)
                            return true;
                        else
                            return false;

                    }

                    //OPERATOR ++

                    Reviews Reviews::operator++() {

                        this->total_dislikes --;
                        this->total_likes ++;
                        if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                        else
                        if(this->total_dislikes==0 && this->total_likes!=0)
                            this->raport=-1; //exponatul e perfect daca raportul e -1
                        else
                        if(this->total_dislikes==0 && this->total_likes==0)
                            this->raport=-2; //exponatul e nou-postat
                        else
                            if(this->total_dislikes!=0 && this->total_likes==0)
                        this->raport=0;
                        return *this;

                        }

                    Reviews Reviews::operator++(int) {
                        Reviews aux = *this;
                        this->total_dislikes --;
                        this->total_likes ++;
                        if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                        else
                        if(this->total_dislikes==0 && this->total_likes!=0)
                            this->raport=-1; //exponatul e perfect daca raportul e -1
                        else
                        if(this->total_dislikes==0 && this->total_likes==0)
                            this->raport=-2; //exponatul e nou-postat
                        else
                            if(this->total_dislikes!=0 && this->total_likes==0)
                        this->raport=0;
                        return *this;
            return aux;
        }

                    //OP +

                    Reviews Reviews::operator+=(int x) {
                        this->total_dislikes += x*0.5;
                        this->total_likes += x;
                        if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                        else
                        if(this->total_dislikes==0 && this->total_likes!=0)
                            this->raport=-1; //exponatul e perfect daca raportul e -1
                        else
                        if(this->total_dislikes==0 && this->total_likes==0)
                            this->raport=-2; //exponatul e nou-postat
                        else
                            if(this->total_dislikes!=0 && this->total_likes==0)
                        this->raport=0;
                        return *this;
                    }

                    Reviews Reviews::operator+(float x) {
                        Reviews aux = *this;
                        aux.total_dislikes = aux.total_dislikes + x*0.5;
                        aux.total_likes = aux.total_likes + x;
                        if(aux.total_likes!=0 && aux.total_dislikes!=0)
                        aux.raport=double(aux.total_likes)/double(aux.total_dislikes);
                    else
                    if(aux.total_dislikes==0 && aux.total_likes!=0)
                        aux.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(aux.total_dislikes==0 && aux.total_likes==0)
                        aux.raport=-2; //exponatul e nou-postat
                    else
                        if(aux.total_dislikes!=0 && aux.total_likes==0)
                        aux.raport=0;
                        return aux;
                    }

                    Reviews Reviews::operator+(Reviews a) {
                        a.total_dislikes = a.total_dislikes + this->total_dislikes*0.5;
                        a.total_likes = a.total_likes + this->total_likes;
                        if(a.total_likes!=0 && a.total_dislikes!=0)
                        a.raport=double(a.total_likes)/double(a.total_dislikes);
                    else
                    if(a.total_dislikes==0 && a.total_likes!=0)
                        a.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(a.total_dislikes==0 && a.total_likes==0)
                        a.raport=-2; //exponatul e nou-postat
                    else
                        if(a.total_dislikes!=0 && a.total_likes==0)
                        a.raport=0;
                        return a;
                    }

                    //OP *

                    Reviews Reviews::operator*=(int x) {
                        this->total_dislikes *= x*0.5;
                        this->total_likes *= x;
                        if(this->total_likes!=0 && this->total_dislikes!=0)
                        this->raport=double(this->total_likes)/double(this->total_dislikes);
                        else
                        if(this->total_dislikes==0 && this->total_likes!=0)
                            this->raport=-1; //exponatul e perfect daca raportul e -1
                        else
                        if(this->total_dislikes==0 && this->total_likes==0)
                            this->raport=-2; //exponatul e nou-postat
                        else
                            if(this->total_dislikes!=0 && this->total_likes==0)
                        this->raport=0;
                        return *this;
                    }

                    Reviews Reviews::operator*(float x) {
                        Reviews aux = *this;
                        aux.total_dislikes = aux.total_dislikes * x*0.5;
                        aux.total_likes = aux.total_likes * x;
                        if(aux.total_likes!=0 && aux.total_dislikes!=0)
                        aux.raport=double(aux.total_likes)/double(aux.total_dislikes);
                    else
                    if(aux.total_dislikes==0 && aux.total_likes!=0)
                        aux.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(aux.total_dislikes==0 && aux.total_likes==0)
                        aux.raport=-2; //exponatul e nou-postat
                    else
                        if(aux.total_dislikes!=0 && aux.total_likes==0)
                        aux.raport=0;
                        return aux;
                    }

                    Reviews Reviews::operator*(Reviews a) {
                        a.total_dislikes = a.total_dislikes * this->total_dislikes*0.5;
                        a.total_likes = a.total_likes * this->total_likes;
                        if(a.total_likes!=0 && a.total_dislikes!=0)
                        a.raport=double(a.total_likes)/double(a.total_dislikes);
                    else
                    if(a.total_dislikes==0 && a.total_likes!=0)
                        a.raport=-1; //exponatul e perfect daca raportul e -1
                    else
                    if(a.total_dislikes==0 && a.total_likes==0)
                        a.raport=-2; //exponatul e nou-postat
                    else
                        if(a.total_dislikes!=0 && a.total_likes==0)
                        a.raport=0;
                        return a;
                    }


                    //Getters
                    int Reviews::GetTotalLikesRW(){return this->total_likes;}
                    int Reviews::GetTotalDislikesRW(){return this->total_dislikes;}
                    double Reviews::GetRaportRW(){return this->raport;}
                    int* Reviews::GetDislikesRW(){return this->dislikes;}
                    int* Reviews::GetLikesRW(){return this->likes;}
                    char *Reviews::getPlatformaRW(){return this->platforma;}
                    int Reviews::GetLikesDayRW(int i){return this->likes[i];}
                    int Reviews::GetDislikesDayRW(int i){return this->dislikes[i];}

                    //Setters
                    void Reviews::SetTotalLikesRW(int total_likes)
                        {this->total_likes=total_likes;
                            if(this->total_dislikes!=0)
                                this->raport=float(this->total_likes)/float(this->total_dislikes);
                            if(this->total_dislikes==0)
                                this->raport=-1; //Nu are dislikes, e perfecta
                            if(this->total_dislikes==0 && this->total_likes==0)
                                this->raport=-2; //De abia a fost introdusa
                        }
                     void Reviews::SetTotalDislikesRW(int total_dislikes)
                        {this->total_dislikes=total_dislikes;
                            if(this->total_dislikes!=0)
                                this->raport=float(this->total_likes)/float(this->total_dislikes);
                            if(this->total_dislikes==0)
                                this->raport=-1; //Nu are dislikes, e perfecta
                            if(this->total_dislikes==0 && this->total_likes==0)
                                this->raport=-2; //De abia a fost introdusa
                        }
                    void Reviews::SetRaportRW(double raport){this->raport=raport;}

                    void Reviews::SetLikesRW(int*likes){this->likes=likes;}
                    void Reviews::SetDislikesRW(int*dislikes){this->dislikes=dislikes;}
                    void Reviews::SetPlatformaRW(char*platforma){this->platforma=platforma;}



Reviews::~Reviews(){

                    if(this->platforma!=NULL)
                        delete[] this->platforma;
                    if(this->likes!=NULL)
                        delete[] this-> likes;
                    if(this->dislikes!=NULL)
                        delete[] this-> dislikes;

                    }


Exponat::Exponat ():idExponat(contorId++){

        //Constructor
        this->nume=new char[strlen("Expus")+1];
        strcpy(this->nume,"Expus");
        this->autor=new char[strlen("Autor")+1];
        strcpy(this->autor,"Autor");
        this->vechime=0;
        this->sector='X';


        }

Exponat::Exponat (char*nume,char*autor,char sector):idExponat(contorId++) { //Constructor 2 parametriiv

        this->nume=new char[strlen(nume+1)];
        strcpy(this->nume,nume);

        this->autor=new char[strlen(autor+1)];
        strcpy(this->autor,autor);
        this->sector=sector;

        }

Exponat::Exponat(char *nume, Reviews &social, char *autor, int vechime, char sector):idExponat(contorId++){ //Constructor toti parametrii

        this->nume=new char[strlen(nume+1)];
        strcpy(this->nume,nume);

        this->autor=new char[strlen(autor+1)];
        strcpy(this->autor,autor);

        this->vechime=vechime;
        this->sector=sector;

        this->social=social;

        }

Exponat::Exponat(const Exponat &exp):idExponat(contorId++){



        this->nume=new char[strlen(exp.nume+1)];
        strcpy(this->nume,exp.nume);

        this->social=exp.social;

        this->autor=new char[strlen(exp.autor+1)];
        strcpy(this->autor,exp.autor);

        this->vechime=exp.vechime;
        this->sector=exp.sector;

        }

Exponat&Exponat::operator=(const Exponat&exp){

        if(this!=&exp)
        {
            if(this->nume!=NULL)
                delete[] this-> nume;

            if(this->autor!=NULL)
                delete[] this-> autor;
            this->nume=new char[strlen(exp.nume+1)];
            strcpy(this->nume,exp.nume);

            this->autor=new char[strlen(exp.autor+1)];
            strcpy(this->autor,exp.autor);

            this->vechime=exp.vechime;
            this->sector=exp.sector;
            this->social=exp.social;

        }
        return *this;


        }

Exponat Exponat::operator++(int) {
            Exponat aux = *this;
            this->vechime++;
            return aux;
        }

Exponat Exponat::operator++() {

        this->vechime++;
        return *this;

        }

Exponat Exponat::operator+=(float x) {
            this->vechime += x;
            return *this;
    }

Exponat Exponat::operator+(float x) {
        Exponat aux = *this;
        aux.vechime = aux.vechime + x;
        return aux;
    }



Exponat Exponat::operator+(Exponat a) {
        a.vechime = a.vechime + this->vechime;
        return a;
    }

Exponat Exponat::operator*=(float x) {
            this->vechime *= x;
            return *this;
    }

Exponat Exponat::operator*(float x) {
        Exponat aux = *this;
        aux.vechime = aux.vechime * x;
        return aux;
    }

Exponat Exponat::operator*(Exponat a) {
        a.vechime = a.vechime * this->vechime;
        return a;
    }

bool Exponat::operator> (const Exponat &ex){

        if(this->vechime>ex.vechime)
            return true;
                else
            return false;
    }

bool Exponat::operator== (const Exponat &ex){

        if(this->vechime==ex.vechime)
            return true;
                else
            return false;

                    }

            //Getters
        char* Exponat::getNumeEx(){return this->nume;}
        int Exponat::getIdExponat() {return this->idExponat;}
        char* Exponat::getAutorEx(){return this->autor;}
        char Exponat::getSectorEx(){return this->sector;}
        int Exponat::getVechimeEx(){return this->vechime;}
            //Getters pt socials
        int Exponat::getTotalLikesEx(){return this->social.GetTotalLikesRW();}
        int *Exponat::getLikesEx(){return this->social.GetLikesRW();}
        int Exponat::getTotalDislikesEx(){return this->social.GetTotalDislikesRW();}
        int *Exponat::getDislikesEx(){return this->social.GetDislikesRW();}
        double Exponat::getRaportEx(){return this->social.GetRaportRW();}
        char *Exponat::getPlatformaEx(){return this->social.getPlatformaRW();}

        void Exponat::setNumeEx(char *nume){delete[] this-> nume; this->nume=new char[strlen(nume)+1];strcpy(this->nume,nume);}
        void Exponat::setAutorEx(char *autor){delete[] this-> autor; this->autor=new char[strlen(autor)+1];strcpy(this->autor,autor);}
        void Exponat::setSectorEx(char sector){this->sector=sector;}
        void Exponat::setVechimeEx(int vechime){this->vechime=vechime;}

        //Setter pt Social
        void Exponat::SetTotalLikesEx(int total_likes){this->social.SetTotalLikesRW(total_likes);}
        void Exponat::SetTotalDislikesEx(int total_dislikes){this->social.SetTotalDislikesRW(total_dislikes);}
        //void SetRaportEx(int raport){this->social.SetRaportRW(raport);}
        void Exponat::SetLikesEx(int*likes){this->social.SetLikesRW(likes);}
        void Exponat::SetDislikesEx(int*dislikes){this->social.SetDislikesRW(dislikes);}
        void Exponat::SetPlatformaEx(char*platforma){this->social.SetPlatformaRW(platforma);}

void Exponat::Promovare(int x){

        this->social+=50;


        }


Exponat::~Exponat () {

        if(this->nume!=NULL)
            delete[] this-> nume;

        if(this->autor!=NULL)
            delete[] this-> autor;

        }

void GiftShop::citireGS() //CITIRE GIFTSHOP
{
    cout<<"Numele este "<<endl;
    char s[101];
    cin>>s;
    if(this->nume!=NULL)
        delete [] this->nume;
    this->nume=new char[strlen(s)+1];
    strcpy(this->nume,s);

    cout<<"Cate suveniruri se vand? ";cin>>this->nr_items;
    cout<<"Cati lei a incasat magazinul? ";cin>>this->incasari;
    cout<<"Cati lei au costat intretinerile? ";cin>>this->intretinere;
    cout<<"Introduceti vizitatorii saptamanali: ";
    for(int i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";cin>>this->vizitatori[i];}
    this->total=this->incasari-this->intretinere;
    if(this->nr_items==0)
        this->deschis=0;
    else
        this->deschis=1;

}

void GiftShop::afisareGS() //AFFISARE GIFTCHOP
{
    cout<<"Numele magazinului este "<<this->nume<<endl;
    cout<<"Se vand "<<this->nr_items<<" suveniruri"<<endl;
    cout<<"Magazinul a incasat "<<this->incasari<<" lei"<<endl;
    cout<<"Intretinerele au costat "<<this->intretinere<<" lei"<<endl;
    cout<<"In total au ramas "<<this->total<<" lei"<<endl;
    cout<<"Vizitatorii dintr-o saptamana "<<endl;
    for(int i=1;i<=7;i++)
        cout<<"\t Ziua "<<i<<" nr de vizitatori "<<this->vizitatori[i]<<endl;
    if(this->deschis==0)
        cout<<"Magazinul este inchis"<<endl;
    else
        cout<<"Magazinul este deschis"<<endl;
}

void Reviews::citireRW() //CITIRE REVIEWS
{
    cout<<"Platforma se numeste ";
    char s[101];
    cin>>s;
    if(this->platforma!=NULL)
        delete [] this->platforma;
    this->platforma=new char[strlen(s)+1];
    strcpy(this->platforma,s);

    if(this->dislikes!=NULL)
        delete [] this->dislikes;
    this->dislikes=new int[8];

    if(this->likes!=NULL)
        delete [] this->likes;
    this->likes=new int[8];


    cout<<"Introduceti like-urile dintr-o saptamana: ";
    for(int i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";cin>>this->likes[i];}
    cout<<"\nIntroduceti dislike-urile dintr-o saptamana: ";
    for(int i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";cin>>this->dislikes[i];}

            for(int i=1;i<=7;i++)
                {
                this->total_likes+=this->likes[i];}

                for(int i=1;i<=7;i++)
                {
                this->total_dislikes+=this->dislikes[i];}

    if(this->dislikes==0 && this->likes==0)
        this->raport=-2; //e nou
    else
        if(this->likes==0 && this->dislikes!=0)
        this->raport=0; //nu are likes
    else
        if(this->likes!=0 && this->dislikes==0)
        this->raport=-1; //nu are dislikes
    else
        if(this->likes!=0 && this->dislikes!=0)
        this->raport=float(this->total_likes)/float(this->total_dislikes);


}

void Reviews::afisareRW() //AFISARE REVIEWS
{
 cout<<"Platforma se numeste "<<this->platforma<<endl;
    cout<<"Like-urile respectiv dislike-urile dintr-o saptamana";
    for(int i=1;i<=7;i++)
        cout<<"\nZiua "<<i<<"\n\t Likes: "<<this->likes[i]<<" Dislikes: "<<this->dislikes[i];
    cout<<"\nTotal likes "<<this->total_likes<<endl;
    cout<<"Total dislikes "<<this->total_dislikes<<endl;
    if(this->raport==0)
        cout<<"Exponatul nu are likes!"<<endl;
    if(isinf(this->raport))
        cout<<"Exponatul nu are niciun dislike!"<<endl;
    if(isnan(this->raport))
        cout<<"Exponatul nu are nici likes, nici dislikes"<<endl;
    if(int(this->raport)>0)
        cout<<"Raportul likes/dislikes "<<this->raport<<endl;

}

istream& operator>>(istream&in, Angajat&p){ //CIN ANGAJAT

cout<<"Numele angajatului ";
char s[101];
    in>>s;
    if(p.nume!=NULL)
        delete [] p.nume;
    p.nume=new char[strlen(s)+1];
    strcpy(p.nume,s);
cout<<"Prenumele angajatului ";
    in>>s;
    if(p.prenume!=NULL)
        delete [] p.prenume;
    p.prenume=new char[strlen(s)+1];
    strcpy(p.prenume,s);
    cout<<"Initiala mamei: ";in>>p.InitM;
cout<<"Cat este platit angajatul intr-o zi?";in>>p.day;
    if(p.shifts!=NULL)
        delete [] p.shifts;
    p.shifts=new int[8];
cout<<"Introduceti zilele in care lucreaza angajatul ";
for(int i=1;i<=7;i++)
{
    cout<<"\nZiua "<<i<<": ";
    int aux;
    in>>aux;
    if(aux!=0)
        p.shifts[i]=1;
    else
        p.shifts[i]=0;

}

cout<<endl;

p.salariu=0;
for(int i=1;i<=7;i++)
    if(p.shifts[i]!=0)
        p.salariu=p.salariu+p.day;

return in;

}

ostream& operator<<(ostream&out,const Angajat&p) { //COUT ANGAJAT

out<<"Id anagajat "<<p.idAngajat<<endl;
out<<"Nume si prenume angajat "<<p.nume<<" "<<p.prenume<<endl;
out<<"Initiala mamei "<<p.InitM<<endl;
out<<"Intr-o zi angajatul este platit "<<p.day<<endl;
out<<"Angajatul are salariul saptamanal de "<<p.salariu<<endl;
out<<"Angajatul lucreaza in zilele: ";
for(int i=1;i<=7;i++)
{
    if(p.shifts[i]!=0)
        out<<"\nZiua "<<i;
}
out<<endl;
return out;
}

void Angajat::citireA(){ //CITIRE ANGAJAT

cout<<"Numele angajatului ";
char s[101];
    cin>>s;
    if(this->nume!=NULL)
        delete [] this->nume;
    this->nume=new char[strlen(s)+1];
    strcpy(this->nume,s);
cout<<"Prenumele angajatului ";
    cin>>s;
    if(this->prenume!=NULL)
        delete [] this->prenume;
    this->prenume=new char[strlen(s)+1];
    strcpy(this->prenume,s);
    if(this->shifts!=NULL)
        delete [] this->shifts;
    this->shifts=new int[8];
cout<<"Introduceti zilele in care lucreaza angajatul ";
for(int i=1;i<=7;i++)
{
    cout<<"\nZiua "<<i<<": ";cin>>this->shifts[i];

}

cout<<endl;
cout<<"Initiala mamei: ";cin>>this->InitM;
cout<<"Cat este platit angajatul intr-o zi?";cin>>this->day;
this->salariu=0;
for(i=1;i<=7;i++)
    if(this->shifts[i]!=0)
        this->salariu=this->salariu+this->day;

}

void Angajat::afisareA(){ //AFISARE ANGAJAT

cout<<"Id anagajat "<<this->idAngajat<<endl;
cout<<"Nume si prenume angajat "<<this->nume<<" "<<this->prenume<<endl;
cout<<"Initiala mamei "<<this->InitM<<endl;
cout<<"Intr-o zi angajatul este platit "<<this->day<<endl;
cout<<"Angajatul are salariul saptamanal de "<<this->salariu<<endl;
cout<<"Angajatul lucreaza in zilele: ";
for(i=1;i<=7;i++)
{
    if(this->shifts[i]!=0)
        cout<<"\nZiua "<<i;
}
cout<<endl;

}

void Exponat::citireEX() //CITIRE EXPONAT
{
    cout<<"Numele este "<<endl;
    char s[101];
    cin>>s;
    if(this->nume!=NULL)
        delete [] this->nume;
    this->nume=new char[strlen(s)+1];
    strcpy(this->nume,s);

    cout<<"Autorul este "<<endl;
    cin>>s;
    if(this->autor!=NULL)
        delete [] this->autor;
    this->autor=new char[strlen(s)+1];
    strcpy(this->autor,s);

    cout<<"Vechimea este "<<endl;
    cin>>this->vechime;
    cout<<"Sectorul este "<<endl;
    cin>>this->sector;

    this->social.citireRW();

}

void Exponat::afisareEX() //AFISARE EXPONAT
{
   cout<<"Numele exponatului este "<<this->nume<<endl;
    cout<<"Are ID-ul "<<this->idExponat<<endl;
    cout<<"Numele autorului este "<<this->autor<<endl;
    cout<<"Are "<<this->vechime<<" ani."<<endl;
    cout<<"Se afla in sectorul "<<this->sector<<endl;

    this->social.afisareRW();

}

ostream& operator<<(ostream& out, const Reviews&sc) //COUT REVIEWS
{

    out<<"Platforma se numeste "<<sc.platforma<<endl;
    out<<"Like-urile respectiv dislike-urile dintr-o saptamana";
    for(i=1;i<=7;i++)
        out<<"\nZiua "<<i<<"\n\t Likes: "<<sc.likes[i]<<" Dislikes: "<<sc.dislikes[i];
    out<<"\nTotal likes "<<sc.total_likes<<endl;
    out<<"Total dislikes "<<sc.total_dislikes<<endl;
    if(sc.total_likes==0 && sc.total_dislikes!=0)
        out<<"Exponatul nu are likes!"<<endl;
    if(isinf(sc.raport))
        out<<"Exponatul nu are niciun dislike!"<<endl;
    if(isnan(sc.raport))
        out<<"Exponatul nu are nici likes, nici dislikes"<<endl;
    if(sc.raport>0)
        out<<"Raportul likes/dislikes "<<sc.raport<<endl;
    //out<<sc.raport;

return out;

}

istream& operator>>(istream&in, Reviews&sc)//CIN REVIEWS
{

    cout<<"Platforma se numeste ";
    char s[101];
    in>>s;
    if(sc.platforma!=NULL)
        delete [] sc.platforma;
    sc.platforma=new char[strlen(s)+1];
    strcpy(sc.platforma,s);

    if(sc.dislikes!=NULL)
        delete [] sc.dislikes;
    sc.dislikes=new int[8];

    if(sc.likes!=NULL)
        delete [] sc.likes;
    sc.likes=new int[8];
    sc.total_dislikes=0;
    sc.total_likes=0;

    cout<<"Introduceti like-urile dintr-o saptamana: \n";
    for(i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";in>>sc.likes[i];}
    cout<<"\nIntroduceti dislike-urile dintr-o saptamana: \n";
    for(i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";in>>sc.dislikes[i];}

            for(i=1;i<=7;i++)
                {
                sc.total_likes+=sc.likes[i];}

                for(i=1;i<=7;i++)
                {
                sc.total_dislikes+=sc.dislikes[i];}

    if(sc.dislikes==0 && sc.likes==0)
        sc.raport=-2; //e nou
    if(sc.likes==0 && sc.dislikes!=0)
        sc.raport=0; //nu are likes
    if(sc.likes!=0 && sc.dislikes==0)
        sc.raport=-1; //nu are dislikes
    if(sc.likes!=0 && sc.dislikes!=0)
        sc.raport=float(sc.total_likes)/float(sc.total_dislikes);

return in;

}

ostream& operator<<(ostream& out, const Exponat&ex) //COUT EXPONAT
{

out<<"Numele exponatului este "<<ex.nume<<endl;
out<<"Are ID-ul "<<ex.idExponat<<endl;
out<<"Numele autorului este "<<ex.autor<<endl;
out<<"Are "<<ex.vechime<<" ani."<<endl;
out<<"Se afla in sectorul "<<ex.sector<<endl;
out<<ex.social;

return out;

}

ostream& operator<<(ostream& out,const GiftShop&gs){ //COUT GIFTSHOP

    out<<"Numele magazinului este "<<gs.nume<<endl;
    out<<"Se vand "<<gs.nr_items<<" suveniruri"<<endl;
    out<<"Magazinul a incasat "<<gs.incasari<<" lei"<<endl;
    out<<"Intretinerele au costat "<<gs.intretinere<<" lei"<<endl;
    out<<"In total au ramas "<<gs.total<<" lei"<<endl;
    out<<"Vizitatorii dintr-o saptamana "<<endl;

    for(i=1;i<=7;i++)
        out<<"\t Ziua "<<i<<" nr de vizitatori "<<gs.vizitatori[i]<<endl;

    if(gs.employees.size()==0)
        cout<<"Nu sunt angajati!\n";
    else
    {
        cout<<"Angajatii sunt:\n";
    for(int i=0;i<gs.employees.size();i++)
        cout<<gs.employees[i]<<endl;
    }

    return out;

}

istream& operator>> (istream&in, Exponat&ex) //CIN EXPONAT
{
    cout<<"Numele este "<<endl;
    char s[101];
    in>>s;
    if(ex.nume!=NULL)
        delete [] ex.nume;
    ex.nume=new char[strlen(s)+1];
    strcpy(ex.nume,s);

    cout<<"Autorul este "<<endl;
    in>>s;
    if(ex.autor!=NULL)
        delete [] ex.autor;
    ex.autor=new char[strlen(s)+1];
    strcpy(ex.autor,s);

    cout<<"Vechimea este "<<endl;
    in>>ex.vechime;
    cout<<"Sectorul este(litera) "<<endl;
    in>>ex.sector;

    cin>>ex.social;
    return in;

    }


istream& operator>>(istream&in,GiftShop&gs) //Cin GIFTSHOP
{

    cout<<"Numele GiftShopului este "<<endl;
    char s[101];
    in>>s;
    if(gs.nume!=NULL)
        delete [] gs.nume;
    gs.nume=new char[strlen(s)+1];
    strcpy(gs.nume,s);

    cout<<"Cate suveniruri se vand? ";in>>gs.nr_items;
    cout<<"Cati lei a incasat magazinul? ";in>>gs.incasari;
    cout<<"Cati lei au costat intretinerile? ";in>>gs.intretinere;
    cout<<"Introduceti vizitatorii saptamanali: ";
    for(i=1;i<=7;i++)
        {cout<<"Ziua "<<i<<" ";in>>gs.vizitatori[i];}
    gs.total=gs.incasari-gs.intretinere;
    if(gs.nr_items==0)
        gs.deschis=0;
    else
        gs.deschis=1;
    int k=1,comanda;
    cout<<"Introduceti Angajatii: \n";
    while (k == 1) {
            cout << "1 - Adaugare\n";
            cout << "2 - Stop\n";
            cin >> comanda;
            switch(comanda) {

                case 1: {
                    Angajat a;
                    cin >> a;
                    gs.employees.push_back(a);
                    break;
                }
                case 2: {
                    k = 0;
                    break;
                }
                default: {
                    cout << "Comanda incorecta\n";
                    break;
                }
            }
        }

    return in;


}




int Exponat::contorId=420; //Nu ai cum sa faci setters pt contor si id, sunt read-only
int Angajat::contorIdA=1234;
int main()

{

Exponat *p;

GiftShop gs;

int l=1,k=1,comanda1,comanda2,comanda3,n=0,x;

p=new Exponat[100];



while(k==1)
{if (system("CLS")) system("clear");
    cout<<"1 - GiftShop \n2 - Exponate \n0 - Inchidere\n";
    cin>>comanda1;
        switch(comanda1)
        {if (system("CLS")) system("clear");
        case 1: //Giftshop operation
            { l=1;
                while(l==1)
                {
                    cout<<"1 - Citire/Rescriere\n2 - Afisare\n3 - Upadate\n4 - Afisare angajatii care lucreaza intr-o zi\n5 - Afisare doar numele angajatilor\n6 - Salariul maxim \n0 - Return"<<endl;
                    cin>>comanda2;
                        switch(comanda2)
                        {
                        case 1:
                            {if (system("CLS")) system("clear");
                                cin>>gs;
                            break;}

                        case 2:
                            {
                                cout<<gs;
                                break;
                            }
                        case 4:
                            {int ind;
                            cout<<"Dati ziua ";
                            cin>>ind;
                            gs.Disponibilitate(ind);
                            break;
                                            }

                         case 5:
                                            {
                                                gs.AfisareNumeEmployees();
                                                break;
                                            }
                         case 6:
                            {
                                gs.MaximSalariu();
                                break;
                            }

                        case 3:
                            {int mod=1;
                                while(mod==1)
                                {
                                    cout<<"1 - Adaugare la total\n2 - Redenumire GiftShop\n3 - Adaugare angajat\n4 - Sterge ultimul angajat\n5 - Sterge al n-ulea angajat\n6 - Concediaza toti angajatii\n7 - Promoveaza angajatul n  \n0 - Return"<<endl; //Update Giftshop
                                    cin>>comanda3;
                                        switch(comanda3)
                                        {
                                        case 1:
                                            {cout<<"Dati suma de adaugat"<<endl;
                                            cin>>x;
                                            gs+=x;
                                            break;}

                                        case 2:
                                            {
                                                cout<<"Numele nou este "<<endl;
                                                char s[101],*naux;
                                                cin>>s;
                                                if(naux!=NULL)
                                                    delete [] naux;
                                                naux=new char[strlen(s)+1];
                                                strcpy(naux,s);
                                                gs.setNumeGS(naux);
                                                break;
                                            }

                                        case 3:
                                            {
                                                Angajat a;
                                                cin>>a;
                                                gs.addEmployee(a);
                                                break;
                                            }

                                        case 4:
                                            {
                                                gs.RemoveLastEmployee();
                                                break;
                                            }

                                        case 5:
                                            {      cout<<"Dati pozitia angajatului ce trebuie sters"<<endl;
                                                cin>>x;
                                                gs.RemoveNEmployee(x);
                                                break;
                                            }

                                        case 6:
                                            {
                                                cout<<"Ati concediat toti angajatii....."<<endl;
                                                gs.FireAll();
                                                break;
                                            }

                                        case 7:
                                            {
                                                int ind;
                                                cout<<"Dati pozitia angajatului ce trebuie promovat";
                                                cin>>ind;
                                                cout<<"Dati suma cu care se promoveaza";
                                                cin>>x;

                                                gs.PromoteEmployee(ind,x);
                                                break;

                                            }


                                        case 0:
                                            {
                                                mod=0;
                                                break;
                                            }
                                                        }
                                }
                            }break;

                        case 0:
                            {
                                l=0;
                                break;
                            }
                        default:
                            {cout<<"Valoare gresita!"<<endl;
                            break;}

                        }

                }
                break;
            }

            case 2: //Exponat operations
            { l=1;
                  while(l==1)
                  {
                      cout<<"1 - Adaugare Exponat\n2 - Afisarea tuturor exponatelor \n3 - Afisare cate elemente sunt in colectie\n4 - Afisarea celui mai vechi exponat \n5 - Imbatranirea exponatului i \n6 - Afisarea exponatelor anumitui autor\n7 - Afisarea celui mai bun raport likes/dislikes \n0 - Return"<<endl;
                      cin>>comanda2;
                        switch(comanda2)
                        {case 1:
                            {
                              cin>>p[n];
                              n++;



                                break;
                            }
                        case 2:
                            {
                                int j=0;
                                while(j<n)
                                {i=0;
                                i=j;
                                cout<<p[i];
                                j=j+1;
                                }
                                break;
                            }
                        case 3:
                            {
                                cout<<"Sunt "<<n<<" exponate"<<endl;
                                break;

                            }

                        case 4:
                            {
                                if(n==0)
                                    cout<<"Nu sunt elemente!"<<endl;
                                else
                                {

                                int maxi,ind;
                                maxi=p[0].getVechimeEx();
                                ind=0;
                                for(i=0;i<n;i++)
                                    if(maxi<p[i].getVechimeEx())
                                        {maxi=p[i].getVechimeEx();
                                        }

                                for(i=0;i<n;i++)
                                    if(p[i].getVechimeEx()==maxi)
                                cout<<"Cel mai vechi exponat este "<<p[i].getNumeEx()<<" cu vechimea de "<<maxi<<endl;
                                }
                                break;

                            }
                        case 5:
                            {   cout<<"Dati vechimea ";cin>>x;
                                cout<<"Dati pozitia ";cin>>i;
                                i--;
                                if(i<0 || i>=n)
                                cout<<"Nu exista!"<<endl;
                                else
                              p[i]+=x;
                              break;
                            }
                        case 6:
                            {
                                cout<<"Dati autorul: ";
                                char s[101],*naux;
                                cin>>s;
                                if(naux!=NULL)
                                    delete [] naux;
                                naux=new char[strlen(s)+1];
                                strcpy(naux,s);
                                int found=-1;
                                for(i=0;i<n;i++)
                                    if(strcmp(naux,p[i].getAutorEx())==0)
                                        {cout<<p[i].getNumeEx()<<" ";
                                        found=1;
                                        }
                                if(found==-1)
                                    cout<<"Nu se afla autorul in colectia noastra!";
                                cout<<endl;
                                break;


                            }

                        case 7:
                            {
                                if(n!=0)
                                {


                                int ind;
                                int found=-1;
                                double maxi;
                                maxi=p[0].getRaportEx();
                                ind=0;
                                for(i=0;i<n;i++)
                                    {
                                        if(found==-1)
                                        {if(maxi<p[i].getRaportEx())
                                        {maxi=p[i].getRaportEx();
                                        ind=i;}
                                        }

                                        if(p[i].getTotalDislikesEx()==0)
                                        {cout<<p[i].getNumeEx()<<" nu are dislikes!"<<endl;
                                        found=1;
                                        }


                                    }
                                if(found==-1)
                                cout<<"Cel mai apreciat exponat este "<<p[ind].getNumeEx()<<" cu raportul de apreciere "<<maxi<<endl;}
                                else
                                    cout<<"Nu exista exponate!"<<endl;
                                break;
                            }




                        case 0:
                            {
                                l=0;
                                break;
                            }
                        default:
                            {
                                cout<<"Valoarea gresita!"<<endl;
                            }
                  }}break;
            }

            case 0:{//Inchidere
                               cout<<"Va multumim!";
                                k=0;
                                break;
                            }

        default:
            {cout<<"Valoare gresita!"<<endl;
            break;}

        }
}

delete[] p;


return 0;
}
