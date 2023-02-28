#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

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
        Spectacol operator= (const Spectacol& sp);
        void FullHouze() const; //metoda constanta
        int FullHouse();
        void Gossip();
        void AddPrice(int x); //nu poate fi const, modifica ceva
        string GetNume();
        ~Spectacol();

};

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
/*
void Spectacol::Gossip(){

cout<<"Se zvoneste ca spectacolul"<<this->nume<<" dureaza "<<this->durata<<" minute"<<endl;
this->pret_bilet++;
}
*/


class Licitatie: virtual public Spectacol {
    protected:
        string host;
        int nr_items;
        string *items;
    public:
        Licitatie();
        Licitatie(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, string host, int nr_items, string * items);
        Licitatie(const Licitatie&lic);
        istream & read(istream & in);
        ostream & write(ostream & out);
        Licitatie operator= (const Licitatie& lic);
        void Gossip();
        void ShowItems() const;
        int GetNrItems() const;
        ~Licitatie();


};

void Licitatie::ShowItems() const{

for( int i=0;i<this->nr_items;i++)
    cout<<"\t "<<this->items[i]<<endl;

}

int Licitatie::GetNrItems() const{

return this->nr_items;

}

Licitatie::Licitatie():Spectacol(){ //se apeleaza constructorul spectacolului fara parametrii

this->host="Anonim";
this->nr_items=0;
this->items=new string[this->nr_items];
this->items=NULL;

}

Licitatie::Licitatie(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, string host, int nr_items, string * items):Spectacol(locatie, nr_locuri, pret_bilet, durata, nume) //se apeleaza constructorul spectacolului cu parametrii, nu mai specificam tipul, o chemam doar
{
    this->host=host;
    this->nr_items=nr_items;
    this->items=new string[nr_items+1];

    for(int i=0;i<nr_items;i++)
        this->items[i]=items[i];
}

Licitatie::Licitatie(const Licitatie&lic):Spectacol(lic) //apelam copyconstructor de la spectacol
{
    this->host=lic.host;
    this->nr_items=lic.nr_items;
    this->items=new string[lic.nr_items+1];

    for(int i=0;i<nr_items;i++)
        this->items[i]=lic.items[i];
}

Licitatie Licitatie::operator=(const Licitatie&lic)//apeleaza op egal de la spectacol
{
    if(this!=&lic)
    {
        Spectacol::operator=(lic);
        this->host=lic.host;
        this->nr_items=lic.nr_items;
        this->items=new string[lic.nr_items+1];
        for(int i=0;i<lic.nr_items;i++)
            this->items[i]=lic.items[i];
    }
    return *this;
}



istream & Licitatie :: read(istream & in)
{
    Spectacol::read(in); // se apeleaza citirea de la spectacol
    cout<<"Cine este gazda?";
    in>>this->host;
    cout<<"Cate items se vand?";
    in>>this->nr_items;
    this->items=new string[this->nr_items+1];

    for(int i=0;i<this->nr_items;i++)
        {
        cout<<"Introduceti Item "<<i+1<<" : ";
        in>>this->items[i];
        }
    return in;

}

ostream & Licitatie :: write(ostream & out)
{
    Spectacol::write(out); //se foloseste afisarea de la spectacol
    out<<"Gazda este "<<this->host<<endl;
    out<<"Se vand "<<this->nr_items<<" items"<<endl;

    for(int i=0;i<this->nr_items;i++)
        out<<"\t Item "<<i+1<<" : "<<this->items[i]<<endl;

    return out;
}

void Licitatie::Gossip(){
string aux;
aux=this->host;
aux[0]+=1;
cout<<"Se zvoneste ca gazda spectacolului "<<this->nume<<" este "<<aux<<endl;
this->pret_bilet++;
//polimorfism: pentru licitatie se afiseaza gazda
}

Licitatie::~Licitatie(){
if(this->items!=NULL)
    delete this->items;

}

class Teatru:virtual public Spectacol {
    protected:
        int nr_actori;
        int nr_acte;
        bool decor;
        int nr_costume;
    public:
        Teatru();
        Teatru(string locatie,int nr_locuri,float pret_bilet,double durata,string nume,int nr_actori,int nr_acte,bool decor,int nr_costume);
        Teatru(const Teatru&tt);
        Teatru operator= (const Teatru& tt);
        istream& read (istream & in);
        ostream&write(ostream & out);
        void Gossip(); //obligatoriu de scris , e redefinit
        int GetActe() const;
        ~Teatru();



};
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
        void Gossip();
        bool GetCA() const;
        ~Concert();


};
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

class Musical: public virtual Teatru, public virtual Concert {
    protected:
        bool live_music;
        string main_lead;
        int nr_dancers;
    public:
        Musical();
        Musical(string locatie,int nr_locuri,float pret_bilet,double durata,string nume, int nr_actori,int nr_acte,bool decor,int nr_costume,int nr_piese,bool cor,bool autotune,bool live_music,string main_lead,int nr_dancers);
        Musical(const Musical & mus);
        Musical operator=(const Musical & mus);
        istream & read (istream & in);
        ostream & write (ostream & out);
        void Gossip();
        string GetMainLead() const;
        ~Musical();

};

void Musical::Gossip()
{
    string aux=this->main_lead;
    aux[0]+=1;
    cout<<"Se spune ca actorul principal al spectacolului "<<this->nume<<" este "<<aux<<"..."<<endl;
//polimorfism: pt musical se zvoneste cine e actorul principal
}

string Musical::GetMainLead() const{

return this->main_lead;

}

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

Spectacol Spectacol::operator=(const Spectacol&sp){
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

istream& Spectacol::read(istream& in) { //mostemirea de la class iointerface
    cout << "Numele spectacolului: ";
    in >> this->nume;
    cout << "Introdu locatia spectacolului: ";
    in >> this->locatie;
    cout << "Introdu pretul biletului: ";
    in >> this->pret_bilet;
    cout << "Introdu durata spectacolului in minute: ";
    in >> this->durata;
    cout <<"Introdu numarul de locuri disponibile: ";
    in >> this->nr_locuri;
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

//Teatru Stuff
Teatru::Teatru():Spectacol(){
    this->decor=0;
    this->nr_actori=0;
    this->nr_acte=0;
    this->nr_costume=0;
}



Teatru::Teatru(string locatie, int nr_locuri, float pret, double durata, string nume, int nr_actori, int nr_acte, bool decor, int nr_costume):Spectacol(locatie, nr_locuri,pret_bilet, durata, nume) //constructorul cu parametrii a spectacolului
{
    this->decor=decor;
    this->nr_actori=nr_actori;
    this->nr_acte=nr_acte;
    this->nr_costume=nr_costume;

}

Teatru::Teatru(const Teatru&tt):Spectacol(tt){ //este apleat copy constr pt spectacol

    this->decor=tt.decor;
    this->nr_actori=tt.nr_actori;
    this->nr_acte=tt.nr_acte;
    this->nr_costume=tt.nr_costume;

}

Teatru Teatru::operator=(const Teatru&tt) //este apleat op egal pt spectacol
{
    if(this!=&tt)
    {
    Spectacol::operator=(tt);
    this->decor=tt.decor;
    this->nr_actori=tt.nr_actori;
    this->nr_acte=tt.nr_acte;
    this->nr_costume=tt.nr_costume;

    }
    return *this;
}

ostream & Teatru :: write(ostream & out ){

    Spectacol::write(out); //afisarea pt spectacol
    out<<"Spectacolul are "<<this->nr_acte<<" numar de acte"<<endl;
    out<<"Spectacolul are "<<this->nr_actori<<" actori "<<endl;
    out<<"Spectacolul are nevoie de "<<this->nr_costume<<" costume"<<endl;
    if(this->decor==1)
        out<<"Spectacolul are nevoie de decor"<<endl;
    else
        out<<"Spectacolul nu are nevoie de decor"<<endl;
    return out;

}

istream & Teatru :: read(istream & in) {

    Spectacol::read(in); //citirea pt spectacol
    cout<<"Cate acte are Spectacolul? ";
    in>>this->nr_acte;
    cout<<"Cati actori are Spectacolul? ";
    in>>this->nr_actori;
    cout<<"Cate costume are Spectacolul? ";
    in>>this->nr_costume;
    cout<<"Este nevoie de decor special? ";
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

istream & Concert :: read(istream & in)
{
    Spectacol::read(in); //se foloseste citirea de la spectacol
    cout<<"Spectacolul are nevoie de cor? ";
    in>>this->cor;
    cout<<"Spectacolul are nevoie de autotune? ";
    in>>this->autotune;
    cout<<"Cate piese sunt in concert? ";
    in>>this->nr_piese;
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

Concert::~Concert(){}

//Musical stuff

Musical::Musical():Teatru(),Concert(),Spectacol() //constructorul fara parametrii a tuturor claselor
{
    this->live_music=0;
    this->nr_dancers=0;
    this->main_lead="Anonim";
}

Musical::Musical(string locatie, int nr_locuri, float pret_bilet, double durata, string nume, int nr_actori, int nr_acte, bool decor, int nr_costume, int nr_piese, bool cor, bool autotune, bool live_music, string main_lead, int nr_dancers):
    Teatru(locatie, nr_locuri, pret_bilet, durata, nume, nr_actori, nr_acte, decor, nr_costume),
     Concert(locatie, nr_locuri, pret_bilet, durata, nume, nr_piese, cor, autotune),
     Spectacol(locatie, nr_locuri, pret_bilet, durata, nume) //constructorul cu parametrii tutuor claselor mai mari
{
    this->live_music=live_music;
    this->nr_dancers=nr_dancers;
    this->main_lead=main_lead;
}

Musical::Musical(const Musical&mus):Teatru(mus), Concert(mus), Spectacol(mus) //copyconstructorul tuturor claselor
{
    this->live_music=mus.live_music;
    this->nr_dancers=mus.nr_dancers;
    this->main_lead=mus.main_lead;
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
        this->main_lead=mus.main_lead;
    }

    return *this;
}

istream & Musical  :: read (istream & in)
{
    Spectacol::read(in); //citirea de la spectacol

    cout<<"Spectacolul are nevoie de cor? ";
    in>>this->cor;
    cout<<"Spectacolul are nevoie de autotune? ";
    in>>this->autotune;
    cout<<"Cate piese sunt in concert? ";
    in>>this->nr_piese;

    cout<<"Cate acte are Spectacolul? ";
    in>>this->nr_acte;
    cout<<"Cati actori are Spectacolul? ";
    in>>this->nr_actori;
    cout<<"Cate costume are Spectacolul? ";
    in>>this->nr_costume;
    cout<<"Este nevoie de decor special? ";
    in>>this->decor;
    //nu m-am putut folosi de Teatru::read(in) si Concert::read(in) pt ca ar fi aparut de doua ori citirea de la tastatura
    cout<<"Cati dansatori sunt?";
    in>>this->nr_dancers;
    cout<<"Cine este actorul principal?";
    in>>this->main_lead;
    cout<<"Este nevoie de musica live?";
    in>>this->live_music;

    return in;
}

ostream & Musical :: write (ostream & out)
{
    Spectacol::write(out);
    //afisarea de la spectacol
    out<<"Spectacolul are "<<this->nr_acte<<" numar de acte"<<endl;
    out<<"Spectacolul are "<<this->nr_actori<<" actori "<<endl;
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
    out<<"Actorul principal este "<<this->main_lead<<endl;
    if(this->decor==0)
        out<<"Nu este nevoie de decor special"<<endl;
    else
        out<<"Este nevoie de decor special"<<endl;

    return out;



}

Musical::~Musical(){}

void Meniu(){

int k=1,com=0,l=1,com2=0;
vector <Concert> concerte;
vector <Licitatie> licitatii;
vector <Teatru> teatre;
vector <Musical> musicals;

while(k!=0)
{
    cout<<" 1 - Concert \n 2 - Teatru \n 3 - Licitatie \n 4 - Musical \n 5 - Zvonuri \n 6 - Full-House \n 7 - Afisare numele spectacolelor \n 0 - Inchidere"<<endl;
    cin>>com;
        switch(com)
        {case 0:
            {
                k=0;
                cout<<"C ya!"<<endl;
                break;
            }
        case 5:
            {
                for(int i=0;i<concerte.size();i++)
                    concerte[i].Gossip();
                for(int i=0;i<teatre.size();i++)
                    teatre[i].Gossip();
                for(int i=0;i<licitatii.size();i++)
                    licitatii[i].Gossip();
                for(int i=0;i<musicals.size();i++)
                    musicals[i].Gossip();
                break;
            }
        case 7:
            {
                if(teatre.size()==0 && concerte.size()==0 && musicals.size()==0 && licitatii.size()==0 )
                    cout<<"Nu sunt spectacole de orice fel!"<<endl;
                else
                {
                    for(int i=0;i<concerte.size();i++)
                    cout<<concerte[i].GetNume()<<endl;
                for(int i=0;i<teatre.size();i++)
                    cout<<teatre[i].GetNume()<<endl;
                for(int i=0;i<licitatii.size();i++)
                    cout<<licitatii[i].GetNume()<<endl;
                for(int i=0;i<musicals.size();i++)
                    cout<<musicals[i].GetNume()<<endl;
                }
                break;
            }
        case 6:
            {
                int total=0;

               for(int i=0;i<concerte.size();i++)
                    {concerte[i].FullHouze();
                    total+=concerte[i].FullHouse();}

                for(int i=0;i<teatre.size();i++)
                    {teatre[i].FullHouze();
                    total+=teatre[i].FullHouse();}

                for(int i=0;i<licitatii.size();i++)
                    {licitatii[i].FullHouze();
                    total+=licitatii[i].FullHouse();}

                for(int i=0;i<musicals.size();i++)
                    {musicals[i].FullHouze();
                    total+=musicals[i].FullHouse();}

                cout<<"In total s-ar incasa "<<total<<" RON."<<endl;
                break;
            }
        case 1:
            {   system("CLS");
                cout<<"Operatii cu Concert"<<endl;
                l=1;
                    while(l!=0)
                    {
                        cout<<" 1 - Adaugare \n 2 - Afisare \n 3 - Eliminare ultimul concert\n 4 - Adaugare pret \n 5 - Afisare concertele care au si cor, si autotune \n 0 - Revenire"<<endl;
                        cin>>com2;
                            switch(com2)
                            {
                            case 0:
                                {
                                    l=0;
                                    break;
                                }
                            case 1:
                                {
                                    Concert con;
                                    cin>>con;
                                    concerte.push_back(con); //se adauga un element
                                    break;
                                }
                            case 2:
                                {
                                    if(concerte.size()==0)
                                        cout<<"Nu exista concerte!"<<endl;
                                    else
                                    for(int i=0;i<concerte.size();i++)
                                        cout<<concerte[i]<<endl;
                                    break;
                                }
                            case 3:
                                {
                                    if(concerte.size()==0)
                                        cout<<"Nu exista concerte!"<<endl;
                                    else
                                   concerte.pop_back();
                                   break;
                                }
                            case 5:
                                {
                                    if(concerte.size()==0)
                                        cout<<"Nu exista concerte!"<<endl;
                                    else
                                    for(int i=0;i<concerte.size();i++)
                                        if(concerte[i].GetCA()==1)
                                            cout<<" \t"<<concerte[i].GetNume()<<endl;
                                    break;
                                }
                            case 4:
                                {
                                    int x,y;
                                    cout<<"Dati care concert sa i sa adauge la pret :"<<endl;
                                    cin>>x;
                                    x--;

                                    if(concerte.size()<x || concerte.size()==0 || x<0)
                                        cout<<"Nu exista acest concert!"<<endl;
                                    else
                                        {
                                            cout<<"Dati valoarea de adaugat"<<endl;
                                            cin>>y;
                                            concerte[x].AddPrice(y);
                                        }break;
                                }
                            default:
                                {
                                    cout<<"Valoare gresita!"<<endl;
                                    break;
                                }
                            }
                    }
                 break;
            }
        case 2:
            {
                system("CLS");
                cout<<"Operatii cu Teatru"<<endl;
                l=1;
                    while(l!=0)
                    {
                        cout<<" 1 - Adaugare \n 2 - Afisare \n 3 - Eliminare ultimul teatru\n 4 - Adaugare pret \n 5 - Maxim acte \n 0 - Revenire"<<endl;
                        cin>>com2;
                            switch(com2)
                            {
                            case 0:
                                {
                                    l=0;
                                    break;
                                }
                            case 1:
                                {
                                    Teatru tt;
                                    cin>>tt;
                                    teatre.push_back(tt); //se adauga un element
                                    break;
                                }
                            case 2:
                                {
                                    if(teatre.size()==0)
                                        cout<<"Nu exista teatre!"<<endl;
                                    else
                                    for(int i=0;i<teatre.size();i++)
                                        cout<<teatre[i]<<endl;
                                    break;
                                }
                            case 3:
                                {
                                    if(teatre.size()==0)
                                        cout<<"Nu exista teatre!"<<endl;
                                    else
                                   teatre.pop_back();
                                   break;
                                }
                            case 4:
                                {
                                     int x,y;
                                    cout<<"Dati care teatrul sa i sa adauge la pret :"<<endl;
                                    cin>>x;
                                    x--;

                                    if(teatre.size()<x || teatre.size()==0 || x<0)
                                        cout<<"Nu exista acest teatru!"<<endl;
                                    else
                                        {
                                            cout<<"Dati valoarea de adaugat"<<endl;
                                            cin>>y;
                                            teatre[x].AddPrice(y);
                                        }break;
                                }
                            case 5:
                                {
                                    int maxi=0;
                                    if(teatre.size()==0)
                                        cout<<"Nu exista teatre"<<endl;
                                    else
                                        for(int i=0;i<teatre.size();i++)
                                            if(teatre[i].GetActe()>maxi)
                                                maxi=teatre[i].GetActe();
                                    for(int i=0;i<teatre.size();i++)
                                        if(teatre[i].GetActe()==maxi)
                                            cout<<teatre[i].GetNume()<<" are numarul maxim de acte de "<<maxi<<endl;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Valoare gresita!"<<endl;
                                    break;
                                }
                            }
                    }
                 break;
            }
        case 3:
            {
                system("CLS");
                cout<<"Operatii cu Licitatie"<<endl;

                l=1;
                    while(l!=0)
                    {
                        cout<<" 1 - Adaugare \n 2 - Afisare \n 3 - Eliminare ultima licitatie \n 4 - Adaugare pret \n 5 - Afisare toate items care se vand \n 0 - Revenire"<<endl;
                        cin>>com2;
                            switch(com2)
                            {
                            case 0:
                                {
                                    l=0;
                                    break;
                                }
                            case 1:
                                {
                                    Licitatie lic;
                                    cin>>lic;
                                    licitatii.push_back(lic); //se adauga un element
                                    break;
                                }
                            case 2:
                                {
                                    if(licitatii.size()==0)
                                        cout<<"Nu exista licitatii!"<<endl;
                                    else
                                    for(int i=0;i<licitatii.size();i++)
                                        cout<<licitatii[i]<<endl;
                                    break;
                                }
                            case 3:
                                {
                                    if(licitatii.size()==0)
                                        cout<<"Nu exista licitatii!"<<endl;
                                    else
                                   licitatii.pop_back();
                                   break;
                                }
                            case 4:
                                {
                                    int x,y;
                                    cout<<"Dati care licitatia sa i sa adauge la pret :"<<endl;
                                    cin>>x;
                                    x--;

                                    if(licitatii.size()<x || licitatii.size()==0 || x<0)
                                        cout<<"Nu exista aceasta licitatie!"<<endl;
                                    else
                                        {
                                            cout<<"Dati valoarea de adaugat"<<endl;
                                            cin>>y;
                                            licitatii[x].AddPrice(y);
                                        }
                                        break;
                                }
                            case 5:
                                {
                                    int total=0;
                                    if(licitatii.size()==0)
                                        cout<<"Nu exista licitatii!"<<endl;
                                    else
                                    for(int i=0;i<licitatii.size();i++)
                                    {
                                       licitatii[i].ShowItems();
                                       total+=licitatii[i].GetNrItems();
                                    }

                                    cout<<"In total sunt "<<total<<" items"<<endl;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Valoare gresita!"<<endl;
                                    break;
                                }
                            }
                    }

                break;
            }
        case 4:
            {
                system("CLS");
                cout<<"Operatii cu Musical"<<endl;

                l=1;
                    while(l!=0)
                    {
                        cout<<" 1 - Adaugare \n 2 - Afisare \n 3 - Eliminare ultimul musical \n 4 - Adaugare pret \n 5 - Afisare toti actorii principali \n 0 - Revenire"<<endl;
                        cin>>com2;
                            switch(com2)
                            {
                            case 0:
                                {
                                    l=0;
                                    break;
                                }
                            case 1:
                                {
                                    Musical mus;
                                    cin>>mus;
                                    musicals.push_back(mus); //se adauga un element
                                    break;
                                }
                            case 2:
                                {
                                    if(musicals.size()==0)
                                        cout<<"Nu exista musicals!"<<endl;
                                    else
                                    for(int i=0;i<musicals.size();i++)
                                        cout<<musicals[i]<<endl;
                                    break;
                                }
                            case 5:
                                {
                                    if(musicals.size()==0)
                                        cout<<"Nu exista musicals!"<<endl;
                                    else
                                    {cout<<"Actorii sunt:"<<endl;
                                        for(int i=0;i<musicals.size();i++)
                                            cout<<"\t "<<musicals[i].GetMainLead()<<endl;
                                            }
                                            break;
                                }

                            case 4:

                                {
                                    int x,y;
                                    cout<<"Dati care musical sa i sa adauge la pret :"<<endl;
                                    cin>>x;
                                    x--;

                                    if(musicals.size()<x || musicals.size()==0 || x<0)
                                        cout<<"Nu exista acest musical!"<<endl;
                                    else
                                        {
                                            cout<<"Dati valoarea de adaugat"<<endl;
                                            cin>>y;
                                            musicals[x].AddPrice(y);
                                        }
                                    break;
                                }

                            case 3:
                                {
                                    if(musicals.size()==0)
                                        cout<<"Nu exista musicals!"<<endl;
                                    else
                                   musicals.pop_back();
                                   break;
                                }
                            default:
                                {
                                    cout<<"Valoare gresita!"<<endl;
                                    break;
                                }
                            }
                    }

                break;
            }
        default:
            {
                system("CLS");
                cout<<"Valoare gresita!"<<endl;
                break;
            }
}}

}

int main()
{
    /*
    vector<Spectacol*> evenimente;

    Musical x;
    Concert y;
    Teatru z;
    Licitatie w;

    evenimente.push_back(new Musical(x)); // up implicit
    evenimente.push_back(new Concert(y));
    evenimente.push_back(new Teatru(z));
    evenimente.push_back(new Licitatie(w));

    for(int i=0;i<4;i++)
        cout<<*evenimente[i]<<endl;


*//*
    animal  *a1=new caine(); //upcasting implicit;

    a1->vorbeste();

    animal* a2;

    caine c1;

    pisica p1;


    *a2= (animal&)c1; //upcasting explicit
    a2=static_cast<animal*>(&c1);
    *a2=static_cast<animal&>(c1);
    cout<<&c1<<endl<<&a2<<endl<<a2<<endl;


    a2->vorbeste();
*/
/*
    Spectacol *s1 =new Concert(); //upcasrting implicit

    //s1->Gossip(); //nu se poate, nu e gossip pt spectacol

    Spectacol * s2;

    Teatru t2;

    *s2=(Spectacol&)t2; //upcasting explicit
    s2=static_cast<Spectacol*>(&t2);
    *s2=static_cast<Spectacol&>(t2);

    cout<<&t2<<endl<<&s2<<endl<<s2<<endl;
    */

    Meniu();
    return 0;
}


