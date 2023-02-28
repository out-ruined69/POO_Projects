#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<set>
#include <bits/stdc++.h>
using namespace std;

template <class numeClasa>
numeClasa add(numeClasa a, numeClasa b){
    return a+b;
}

template<class c1, int c2>
c1 add(c1 a, int b){
    a=a+b;
    return a;
}

template <class numeClasa>
void inter(numeClasa&a, numeClasa&b){
    numeClasa aux;
    aux=a;
    a=b;
    b=a;
}

template <class numeClasa>
class Maxim{
    numeClasa x1, x2;
public:
    Maxim(numeClasa a, numeClasa b){
        x1=a;
        x2=b;
    }

    numeClasa maimare();

};

template <class numeClasa>
numeClasa Maxim<numeClasa>::maimare(){
    if(x1>x2)
        return x1;
    else
        return x2;
}

class IOInterface {
public:
    virtual istream&read(istream&in)=0;
    virtual ostream&write(ostream&out)=0;
    //metodele sunt virtuale, urmand sa fie definite pt fiecare clasa

};

class Spectacol:virtual public IOInterface {
protected: //protected ca sa poate fi accesate de clasele derivate
    string locatie;
    int nr_locuri;
    float pret_bilet;
    double durata;
    string nume;
public:
    Spectacol();
    Spectacol(string locatie, int nr_locuri, float pret_bilet, double durata, string nume);
    Spectacol(const Spectacol&sp);
    istream& read(istream& in);

    ostream& write(ostream& out);
    Spectacol&operator= (const Spectacol& sp);
    Spectacol&operator+(const Spectacol& sp);
    istream& operator>>(istream& in);
    ostream & operator<<(ostream& out);
    void FullHouze() const; //metoda constanta
    int FullHouse();
    virtual void Gossip()=0;
    void AddPrice(int x); //nu poate fi const, modifica ceva
    string GetNume();
    bool operator== (const Spectacol &sp);
    bool operator> (const Spectacol&sp);
    ~Spectacol();

};

class Licitatie: virtual public Spectacol {
protected:
    string host;
    int nr_items;
    set<string> items;
public:
    Licitatie();
    Licitatie(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, string host, int nr_items, set<string> items);
    Licitatie(const Licitatie&lic);
    istream & read(istream & in);
    ostream & write(ostream & out);
    istream& operator>>(istream& in);
    ostream & operator<<(ostream& out);
    Licitatie operator= (const Licitatie& lic);
    void Gossip();
    void ShowItems() const;
    int GetNrItems() const;
    bool operator== (const Licitatie &lic);
    ~Licitatie();


};

class Concert:virtual public Spectacol {
protected:
    int nr_piese;
    bool cor;
    bool autotune;
public:
    Concert();
    Concert(string locatie,int nr_locuri,float pret_bilet,double durata,string nume, int nr_piese, bool cor, bool autotune);
    Concert(const Concert&con);
    Concert operator= (const Concert&con);
    istream& read (istream & in);
    ostream & write (ostream & out);
    Concert&operator+( Concert& con);
    istream& operator>>(istream& in);
    ostream & operator<<(ostream& out);
    void Gossip();
    bool operator== (const Concert &con);
    bool GetCA() const;
    ~Concert();


};

class Teatru:virtual public Spectacol {
protected:
    int nr_acte;
    bool decor;
    int nr_costume;
public:
    Teatru();
    Teatru(string locatie,int nr_locuri,float pret_bilet,double durata,string nume,int nr_acte,bool decor,int nr_costume);
    Teatru(const Teatru&tt);
    Teatru operator= (const Teatru& tt);
    istream& read (istream & in);
    ostream&write(ostream & out);
    bool operator== (const Teatru &tt);
    istream& operator>>(istream& in);
    ostream & operator<<(ostream& out);
    void Gossip(); //obligatoriu de scris , e redefinit
    int GetActe() const;
    ~Teatru();



};

class Musical: public virtual Concert, public virtual Teatru {
protected:
    bool live_music;
    map<string, list<string>> actor;
    int nr_dancers;
public:
    Musical();
    Musical(string locatie,int nr_locuri,float pret_bilet,double durata,string nume,int nr_acte,bool decor,int nr_costume,int nr_piese,bool cor,bool autotune,bool live_music,map<string, list<string>> actori,int nr_dancers);
    Musical(const Musical & mus);
    Musical operator=(const Musical & mus);
    istream & read (istream & in);
    ostream & write (ostream & out);
    void Gossip();
    istream& operator>>(istream& in);
    Musical operator+(Musical&mus);
    ostream & operator<<(ostream& out);
    bool operator== (const Musical &mus);
    string GetMainLead() const;
    ~Musical();

};

//Spectacol stuff
Spectacol::Spectacol() {

    this->locatie="scena";
    this->nr_locuri=0;
    this-> pret_bilet=0,0;
    this-> durata=0,0;
    this-> nume="Spectacol";
}

Spectacol::Spectacol(string locatie,int nr_locuri,float pret_bilet,double durata,string nume) {

    this->locatie=locatie;
    this->nr_locuri=nr_locuri;
    this-> pret_bilet=pret_bilet;
    this-> durata=durata;
    this-> nume=nume;
}

Spectacol::Spectacol(const Spectacol&sp) {

    this->durata=sp.durata;
    this->locatie=sp.locatie;
    this->nr_locuri=sp.nr_locuri;
    this->nume=sp.nume;
    this->pret_bilet=sp.pret_bilet;

}

Spectacol::~Spectacol() {
}

Spectacol&Spectacol::operator=(const Spectacol&sp){
    if(this!=&sp)
    {
        this->durata=sp.durata;
        this->locatie=sp.locatie;
        this->nr_locuri=sp.nr_locuri;
        this->nume=sp.nume;
        this->pret_bilet=sp.pret_bilet;
    }
    return *this;

}

Concert& Concert::operator+( Concert& con){
    con.pret_bilet=con.pret_bilet+this->pret_bilet;
    return con;
}

bool  Spectacol::operator== (const Spectacol &sp){

    if(this->nume==sp.nume)
        return true;
    else
        return false;

}
bool Spectacol::operator>(const Spectacol &sp) {
    if(this->pret_bilet>sp.pret_bilet)
        return true;
    else
        return false;
}
void Spectacol::FullHouze() const{

    int x;
    x=this->nr_locuri*this->pret_bilet;
    cout<<"Daca se vand toate biletele, s-ar incasa "<<x<<" RON pentru spectacolul "<<this->nume<<endl;

}
void Spectacol::AddPrice(int x){

    this->pret_bilet+=x;

}

string Spectacol::GetNume(){
    return this->nume;
}

int Spectacol::FullHouse() {

    int x;
    x=this->nr_locuri*this->pret_bilet;
    return x;

}

istream& Spectacol::read(istream& in) {
    cout << "Numele spectacolului: ";
    in>>this->nume;
    cout << "Introdu locatia spectacolului: ";
    in>>this->locatie;
    int ok=0;
    while(ok==0) {
        try {
            cout << "Introdu pretul biletului: ";
            in >> this->pret_bilet;
            if(this->pret_bilet<=0) throw 0;
            if(this->pret_bilet>1000) throw "scump";

            ok=1;
        }
        catch(int x){
            cout<<"Prea ieftin!"<<endl;
        }

        catch(...){
            cout<<"Scump!"<<endl;
        }

    }

    ok=0;
    while(ok==0) {
        try {
            cout << "Introdu durata spectacolului in minute: ";
            in >> this->durata;
            if(this->durata<=0) throw 0;
            if(this->durata>1000) throw "imposibil";

            ok=1;
        }
        catch(int x){
            cout<<"Imposibil din punct de vedere fizic!"<<endl;
        }

        catch(...){
            cout<<"Dureaza prea mult!"<<endl;
        }

    }

    ok=0;
    while(ok==0) {
        try {
            cout <<"Introdu numarul de locuri disponibile: ";
            in >> this->nr_locuri;
            if(this->nr_locuri<=0) throw 0;
            if(this->nr_locuri>10000) throw "imposibil";

            ok=1;
        }
        catch(int x){
            cout<<"Imposibil din punct de vedere fizic!"<<endl;
        }

        catch(...){
            cout<<"Nu avem destule scaune!"<<endl;
        }

    }

    return in;
}
istream& operator>>(istream& in, Spectacol &spectacol) {
    return spectacol.read(in);
}

ostream& Spectacol::write(ostream& out) {

    out<<"Numele spectacolului este "<<this->nume<<endl;
    out<<"Are loc la locatia "<<this->locatie<<endl;
    out<<"Un bilet costa "<<this->pret_bilet<<" RON "<<endl;
    out<<"Un spectacol dureaza "<<this->durata<<" minute "<<endl;
    out<<"Sunt "<<this->nr_locuri<<" locuri disponibile "<<endl;
    return out;

}

ostream&operator<<(ostream&out, Spectacol&spectacol){
    return spectacol.write(out);
}

//Licitatie Stuff

void Licitatie::ShowItems() const{

    for( auto i=this->items.begin();i!=this->items.end();i++)
        cout<<"\t "<<*i<<endl;

}

int Licitatie::GetNrItems() const{

    return this->nr_items;

}

Licitatie::Licitatie():Spectacol(){ //se apeleaza constructorul spectacolului fara parametrii

    this->host="Anonim";
    this->nr_items=0;
    this->items.empty();

}

Licitatie::Licitatie(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, string host, int nr_items, set<string> items):Spectacol(locatie, nr_locuri, pret_bilet, durata, nume) //se apeleaza constructorul spectacolului cu parametrii, nu mai specificam tipul, o chemam doar
{
    this->host=host;
    this->nr_items=nr_items;
    this->items.empty();
    for( auto i=items.begin();i!=items.end();i++)
        this->items.insert(*i);
}

Licitatie::Licitatie(const Licitatie&lic):Spectacol(lic) //apelam copyconstructor de la spectacol
{
    this->host=lic.host;
    this->nr_items=lic.nr_items;
    this->items.empty();
    for(auto i=lic.items.begin();i!=lic.items.end();i++)
        this->items.insert(*i);
}

Licitatie Licitatie::operator=(const Licitatie&lic)//apeleaza op egal de la spectacol
{
    if(this!=&lic)
    {
        Spectacol::operator=(lic);
        this->host=lic.host;
        this->nr_items=lic.nr_items;
        this->items.empty();
        for(auto i=lic.items.begin();i!=lic.items.end();i++)
            this->items.insert(*i);
    }
    return *this;
}

bool  Licitatie::operator== (const Licitatie &lic){

    if(this->nume==lic.nume)
        return true;
    else
        return false;

}

istream & Licitatie :: read(istream & in)
{
    Spectacol::read(in); // se apeleaza citirea de la spectacol
    cout<<"Cine este gazda?";
    in>>this->host;

    int ok=0;
    while(ok==0) {
        try {
            cout<<"Cate items se vand?";
            in>>this->nr_items;
            if(this->nr_items<=1) throw 0;
            if(this->nr_items>1000) throw "exces";

            ok=1;
        }
        catch(int x){
            cout<<"Prea putine items!"<<endl;
        }

        catch(...){
            cout<<"Prea multe items!"<<endl;
        }

    }

    this->items={};
    for(int i=0;i<this->nr_items;i++)
    {
        cout<<"Item "<<i+1<<":"<<endl;
        string aux;
        cin>>aux;
        this->items.insert(aux);
    }

    this->nr_items=this->items.size();
    return in;

}

ostream & Licitatie :: write(ostream & out)
{
    Spectacol::write(out); //se foloseste afisarea de la spectacol
    out<<"Gazda este "<<this->host<<endl;
    out<<"Se vand "<<this->nr_items<<" items"<<endl;

    for( auto i=this->items.begin();i!=this->items.end();i++)
        cout<<"\t "<<*i<<endl;

    return out;
}

void Licitatie::Gossip(){
    string aux;
    aux=this->host;
    if(aux[0]=='Z' && aux[0]=='z')
    {
        aux[0]='A';
    }
    else
        aux[0]+=1;

    cout<<"Se zvoneste ca gazda spectacolului "<<this->nume<<" este "<<aux<<endl;
    this->pret_bilet++;
//polimorfism: pentru licitatie se afiseaza gazda
}

Licitatie::~Licitatie(){

}

//Teatru Stuff
Teatru::Teatru():Spectacol(){
    this->decor=0;
    this->nr_acte=0;
    this->nr_costume=0;
}


void Teatru::Gossip(){
//polimorfism: pt teatru zvoneste daca va avea sau nu decor special
    if(this->decor==0)
        cout<<"Se zvoneste ca spectacolul "<<this->nume<<" va avea decor special..."<<endl;
    else
        cout<<"Se zvoneste ca spectacolul "<<this->nume<<" nu va avea decor special..."<<endl;

}

int Teatru::GetActe() const{

    return this->nr_acte;

}


Teatru::Teatru(string locatie, int nr_locuri, float pret, double durata, string nume, int nr_acte, bool decor, int nr_costume):Spectacol(locatie, nr_locuri,pret_bilet, durata, nume) //constructorul cu parametrii a spectacolului
{
    this->decor=decor;
    this->nr_acte=nr_acte;
    this->nr_costume=nr_costume;

}

Teatru::Teatru(const Teatru&tt):Spectacol(tt){ //este apleat copy constr pt spectacol

    this->decor=tt.decor;
    this->nr_acte=tt.nr_acte;
    this->nr_costume=tt.nr_costume;

}

Teatru Teatru::operator=(const Teatru&tt) //este apleat op egal pt spectacol
{
    if(this!=&tt)
    {
        Spectacol::operator=(tt);
        this->decor=tt.decor;
        this->nr_acte=tt.nr_acte;
        this->nr_costume=tt.nr_costume;

    }
    return *this;
}

bool  Teatru::operator== (const Teatru &tt){

    if(this->nume==tt.nume)
        return true;
    else
        return false;

}

ostream & Teatru :: write(ostream & out ){

    Spectacol::write(out); //afisarea pt spectacol
    out<<"Spectacolul are "<<this->nr_acte<<" numar de acte"<<endl;
    out<<"Spectacolul are nevoie de "<<this->nr_costume<<" costume"<<endl;
    if(this->decor==1)
        out<<"Spectacolul are nevoie de decor"<<endl;
    else
        out<<"Spectacolul nu are nevoie de decor"<<endl;
    return out;

}

istream & Teatru :: read(istream & in) {

    Spectacol::read(in); //citirea pt spectacol

    int ok=0;
    while(ok==0) {
        try {
            cout << "Cate acte are Spectacolul? ";
            in >> this->nr_acte;

            if(this->nr_acte<=1) throw 1;
            if(this->nr_acte>100) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine acte!"<<endl;
        }

        catch (...){
            cout<<"Prea multe acte!"<<endl;
        }
    }
    ok=0;
    while(ok==0) {
        try {
            cout << "Cate costume are Spectacolul? ";
            in >> this->nr_costume;

            if(this->nr_costume<0) throw 1;
            if(this-> nr_costume>1000) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine costume!"<<endl;
        }

        catch(...){
            cout<<"Prea multe costume!"<<endl;
        }
    }
    cout<<"Este nevoie de decor special? (1/0) ";
    in>>this->decor;

    return in;
}

Teatru::~Teatru(){}

//Concert Stuff

Concert::Concert():Spectacol()//constructorul fara parametrii pt spectacol
{
    this->cor=0;
    this->nr_piese=0;
    this->autotune=0;
}

Concert::Concert(string locatie,int nr_locuri,float pret_bilet,double durata,string nume, int nr_piese, bool cor, bool autotune):Spectacol(locatie, nr_locuri, pret_bilet, durata, nume) //constructorul cu parametrii pt spectacol
{
    this->cor=cor;
    this->nr_piese=nr_piese;
    this->autotune=autotune;
}

Concert::Concert(const Concert&con):Spectacol(con) //copy constr pt spectacol
{
    this->autotune=con.autotune;
    this->cor=con.autotune;
    this->nr_piese=con.nr_piese;
}

Concert Concert::operator=(const Concert&con){ //op egal pt spectacol

    if(this!=&con)
    {
        Spectacol::operator=(con);
        this->autotune=con.autotune;
        this->cor=con.autotune;
        this->nr_piese=con.nr_piese;
    }
    return *this;
}

bool  Concert::operator== (const Concert &con){

    if(this->nume==con.nume)
        return true;
    else
        return false;

}

istream & Concert :: read(istream & in)
{
    Spectacol::read(in); //se foloseste citirea de la spectacol
    cout<<"Spectacolul are nevoie de cor? (1/0)";
    in>>this->cor;
    cout<<"Spectacolul are nevoie de autotune? (1/0)";
    in>>this->autotune;
    int ok=0;
    while(ok==0) {
        try {
            cout << "Cate piese sunt in concert? ";
            in >> this->nr_piese;
            if(this->nr_piese<=1) throw 1;
            if(this->nr_piese>=1000) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine piese!"<<endl;
        }
        catch (...){
            cout<<"Prea multe piese!"<<endl;
        }
    }
    return in;
}

ostream &Concert :: write(ostream & out)
{
    Spectacol::write(out); //se foloseste afisarea de la spectacol
    out<<"Spectacolul are "<<this->nr_piese<<" piese"<<endl;
    if(this->autotune==1)
        out<<"Spectacolul are nevoie de autotune"<<endl;
    else
        out<<"Spectacolul nu are nevoie de autotune"<<endl;
    if(this->cor==1)
        out<<"Spectacolul are cor"<<endl;
    else
        out<<"Spectacolul nu are cor"<<endl;
    return out;

}


void Concert::Gossip(){
    if(this->autotune==0)
    {
        cout<<"Se zvoneste ca se va folosi autotune pentru concertul "<<this->nume<<" "<<endl;
        if(this->pret_bilet>0)
            this->pret_bilet--;

    }
    else
    {
        cout<<"Se zvoneste ca nu se va folosi autotune pentru concertul "<<this->nume<<" "<<endl;
        this->pret_bilet++;
    }
//polimorfism: pentru concert se afiseaza daca e sau nu autotune
}

bool Concert::GetCA() const {
    if(this->autotune==1 && this->cor==1)
        return 1;
    else
        return 0;
}

Concert::~Concert(){}

//Musical stuff

Musical::Musical():Teatru(),Concert(),Spectacol() //constructorul fara parametrii a tuturor claselor
{
    this->live_music=0;
    this->nr_dancers=0;
}

Musical::Musical(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, int nr_acte, bool decor, int nr_costume, int nr_piese, bool cor, bool autotune, bool live_music,map<string, list<string>> actori, int nr_dancers):
        Teatru(locatie, nr_locuri, pret_bilet, durata, nume, nr_acte, decor, nr_costume),
        Concert(locatie, nr_locuri, pret_bilet, durata, nume, nr_piese, cor, autotune),
        Spectacol(locatie, nr_locuri, pret_bilet, durata, nume) //constructorul cu parametrii tutuor claselor mai mari
{
    this->live_music=live_music;
    this->nr_dancers=nr_dancers;
    this->actor=actor;
}

Musical::Musical(const Musical&mus):Teatru(mus), Concert(mus), Spectacol(mus) //copyconstructorul tuturor claselor
{
    this->live_music=mus.live_music;
    this->nr_dancers=mus.nr_dancers;
    this->actor=mus.actor;
}

Musical Musical::operator+(Musical &mus) {
    mus.pret_bilet=mus.pret_bilet+this->pret_bilet;
    return mus;
}

Musical Musical::operator=(const Musical&mus)
{
    if(this!=&mus)
    {
        Spectacol::operator=(mus);
        Concert::operator=(mus);
        Teatru::operator=(mus);
        //se folosesc op egal de la toate clasele
        this->live_music=mus.live_music;
        this->nr_dancers=mus.nr_dancers;
        this->actor=mus.actor;
    }

    return *this;
}

bool  Musical::operator== (const Musical &mus){

    if(this->nume==mus.nume)
        return true;
    else
        return false;

}

istream & Musical  :: read (istream & in)
{
    Spectacol::read(in); //citirea de la spectacol

    cout<<"Spectacolul are nevoie de cor? ";
    in>>this->cor;
    cout<<"Spectacolul are nevoie de autotune? ";
    in>>this->autotune;
    int ok=0;
    while(ok==0) {
        try {
            cout << "Cate piese sunt in concert? ";
            in >> this->nr_piese;
            if(this->nr_piese<=1) throw 1;
            if(this->nr_piese>=1000) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine piese!"<<endl;
        }
        catch (...){
            cout<<"Prea multe piese!"<<endl;
        }
    }

    ok=0;

    ok=0;
    while(ok==0) {
        try {
            cout << "Cate acte are Spectacolul? ";
            in >> this->nr_acte;

            if(this->nr_acte<=1) throw 1;
            if(this->nr_acte>100) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine acte!"<<endl;
        }

        catch (...){
            cout<<"Prea multe acte!"<<endl;
        }
    }

    ok=0;
    while(ok==0) {
        try {
            cout << "Cate costume are Spectacolul? ";
            in >> this->nr_costume;

            if(this->nr_costume<0) throw 1;
            if(this-> nr_costume>1000) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Prea putine costume!"<<endl;
        }

        catch(...){
            cout<<"Prea multe costume!"<<endl;
        }
    }

    cout<<"Este nevoie de decor special? ";
    in>>this->decor;
    //nu m-am putut folosi de Teatru::read(in) si Concert::read(in) pt ca ar fi aparut de doua ori citirea de la tastatura

    ok=0;
    while(ok==0) {
        try {
            cout << "Cati dansatori sunt?";
            in >> this->nr_dancers;
            if(this->nr_dancers<0) throw 1;
            if(this->nr_dancers>100) throw "exces";
            ok=1;
        }

        catch (int x){
            cout<<"Nu poate fi un numar negativ!"<<endl;
        }

        catch(...){
            cout<<"Prea multi dansatori!"<<endl;
        }
    }

    cout<<"Este nevoie de musica live?";
    in>>this->live_music;

    string nume;
    actor.clear();
    int nr_actori;
    ok=0;
    while(ok==0) {
        try {
            cout << "Dati numarul de actori: ";
            cin >> nr_actori;
            if(nr_actori<=0) throw 1;
            if(nr_actori>100) throw "ex";
            ok=1;
        }
        catch (int x){
            cout<<"Prea putini actori!"<<endl;
        }
        catch (...){
            cout<<"Prea multi actori!"<<endl;
        }
    }

    for(int j=0;j<nr_actori;j++) {
        cout << "Dati numele actorului : ";
        cin >> nume;
        int nr;

        ok=0;
        while(ok==0) {
            try {
                cout << "Dati numarul de roluri: ";
                cin >> nr;
                if(nr<=0) throw 1;
                if(nr>100) throw "ex";
                ok=1;
            }
            catch (int x){
                cout<<"Prea putine roluri!"<<endl;
            }
            catch (...){
                cout<<"Prea multe roluri!"<<endl;
            }
        }

        list<string> roles = {};

        for (int i = 0; i < nr; i++) {
            string aux;
            cout<<"Rol "<<i+1<<": ";
            in >> aux;

            roles.push_back(aux);
        }

        actor.insert(pair<string, list<string>>(nume, roles));
    }
    return in;
}

ostream & Musical :: write (ostream & out)
{
    Spectacol::write(out);
    //afisarea de la spectacol
    out<<"Spectacolul are "<<this->nr_acte<<" numar de acte"<<endl;
    out<<"Spectacolul are nevoie de "<<this->nr_costume<<" costume"<<endl;
    if(this->decor==1)
        out<<"Spectacolul are nevoie de decor"<<endl;
    else
        out<<"Spectacolul nu are nevoie de decor"<<endl;


    out<<"Spectacolul are "<<this->nr_piese<<" piese"<<endl;
    if(this->autotune==1)
        out<<"Spectacolul are nevoie de autotune"<<endl;
    else
        out<<"Spectacolul nu are nevoie de autotune"<<endl;
    if(this->cor==1)
        out<<"Spectacolul are cor"<<endl;
    else
        out<<"Spectacolul nu are cor"<<endl;
//nu m-am putut folosi de Teatru::write(out) si Concert::write(out) pt ca ar fi aparut de doua ori afisarea
    out<<"Sunt "<<this->nr_dancers<<" dansatori "<<endl;

    for(auto pair : actor)
    {
        cout<<pair.first<<" cu rolurile: ";

        for(auto rol:pair.second)
            cout<<rol<<"  ";

        cout<<endl;
    }

    if(this->decor==0)
        out<<"Nu este nevoie de decor special"<<endl;
    else
        out<<"Este nevoie de decor special"<<endl;

    return out;



}

void Musical::Gossip()
{
    cout<<"Se zvoneste ca vor fi "<<this->actor.size()<<" actori"<<endl;
    this->pret_bilet++;
//polimorfism: pt musical se zvoneste cine e actorul principal
}


Musical::~Musical(){}

class myMenu{
private:
    static myMenu * obj;

    myMenu(){};
public:
    static myMenu * getInst(){
        if(!obj)
            obj = new myMenu();

        return obj;
    }

    void meniu(){

        vector<Spectacol*> evenimente;

        int k=1;
        int n=0;

        while(k==1){
            cout<<" 1 - Adaugare \n 2 - Afisare totala \n 3 - Eliminare \n 4 - Gossip \n 5 - Adaugare la pret \n 6 - Full-House \n 0 - Inchidere \n";
            int comanda1;
            cin>>comanda1;

            switch(comanda1){

                case 0:{
                    cout<<"C ya!";
                    k=0;
                    break;
                }

                case 1:{
                    system("CLS");
                    cout<<" 1 - Licitatie \n 2 - Concert \n 3 - Teatru \n 4 - Musical \n";
                    int com2;
                    cin>>com2;

                    switch (com2) {

                        case 1:
                        {
                            Licitatie lic;
                            cin>>lic;
                            evenimente.push_back(new Licitatie(lic));
                            n++;
                            break;
                        }

                        case 2:{
                            Concert con;
                            cin>>con;
                            evenimente.push_back(new Concert(con));
                            n++;
                            break;
                        }

                        case 3:{
                            Teatru tt;
                            cin>>tt;
                            evenimente.push_back(new Teatru(tt));
                            n++;
                            break;
                        }

                        case 4:{
                            Musical mus;
                            cin>>mus;
                            evenimente.push_back(new Musical(mus));
                            break;
                        }

                        default:{
                            cout<<"Nu exista!";
                            break;
                        }

                    }
                    break;
                }

                case 2:{
                    for(int i=0;i<evenimente.size();i++)
                        cout<<*evenimente[i]<<endl;
                    break;
                }

                case 3:{
                    system("CLS");
                    if(n==0)
                    {
                        cout << "Nu sunt elemente! " << endl;
                        break;
                    }
                    int poz;

                    int ok=0;

                    while(ok==0)
                    {
                        try{
                            cout<<"Dati pozitia care sa fie eliminata: ";
                            cin>>poz;
                            poz--;
                            if(poz<0) throw 1;
                            if(poz>=n) throw 2;
                            ok=1;
                        }
                        catch (int x){
                            cout<<"Nu exista aceasta pozitie!"<<endl;
                        }
                    }


                    evenimente.erase(evenimente.begin()+poz);
                    n--;
                    break;
                }

                case 4:{

                    if(n==0)
                    {
                        cout<<"Nu exista elemente!"<<endl;
                        break;
                    }

                    for(int i=0;i<n;i++)
                        evenimente[i]->Gossip();

                    break;

                }

                case 5: {

                    system("CLS");
                    if(n==0)
                    {
                        cout << "Nu sunt elemente! " << endl;
                        break;
                    }
                    int poz;

                    int ok=0;

                    while(ok==0)
                    {
                        try{
                            cout<<"Dati pozitia care sa fie promovata: ";
                            cin>>poz;
                            poz--;
                            if(poz<0) throw 1;
                            if(poz>=n) throw 2;
                            ok=1;
                        }
                        catch (int x){
                            cout<<"Nu exista aceasta pozitie!"<<endl;
                        }
                    }
                    int p;
                    cout<<"Dati cu cat sa se adauge: ";
                    cin>>p;
                    evenimente[poz]->AddPrice(p);

                    break;
                }

                case 6: {

                    if(n==0)
                    {
                        cout<<"Nu sunt spectacole!"<<endl;
                        break;
                    }

                    int suma=0;

                    for(int i=0;i<n;i++)
                    {
                        suma+=evenimente[i]->FullHouse();
                        evenimente[i]->FullHouze();
                    }

                    cout<<"In total s-ar incasa "<<suma<<endl;

                    break;
                }

                default:{
                    cout<<"Invalid!";
                    break;
                }

            }

        }

    }

};

myMenu*myMenu::obj=0;

int main()
{

    myMenu *meniulmeu=meniulmeu->getInst();
    meniulmeu->meniu();

    return 0;
}


