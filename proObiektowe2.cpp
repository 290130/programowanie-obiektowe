#include <iostream>
#include <string>
using namespace std;


class Osoba{
private:
    string nazwisko;
    string imie;
    int indeks;

public:
    //set
    void setNazwisko(string naz){
        nazwisko = naz;
    }
    void setImie(string im){
        imie = im;
    }
    void setIndeks(int ind){
        if(ind >= 100000 && ind <= 999999){
        indeks =ind;
        }else{cout<<"Indeks musi mieć 6 cyfr"<<endl;}
    }
    //get
    string getNazwisko(){
        return nazwisko;
    }
    string getImie(){
        return imie;
    }
    int getIndeks(){
        return indeks;
    }
};

const int MAX = 10;

void dodajOsobe(Osoba *os1, bool *obecnosci, string nazwisko, string imie, int indeks, int &liczbaOsob){

    os1[liczbaOsob].setNazwisko(nazwisko);
    os1[liczbaOsob].setImie(imie);
    os1[liczbaOsob].setIndeks(indeks);
    obecnosci[liczbaOsob] = false;
    liczbaOsob++;
}

void ustawObecnosc(Osoba *os1, bool *obecnosci, int liczbaOsob, int indeks, bool obecnosc){
    for(int i=0; i<liczbaOsob; i++){
        if(os1[i].getIndeks() == indeks){
            obecnosci[i] = obecnosc;
        }
    }
}


void drukujListe(Osoba *os1, bool *obecnosci, int liczbaOsob){
    for(int i=0; i<liczbaOsob; i++){
        cout<<os1[i].getNazwisko()<<" "<<os1[i].getImie()<<"  "<<os1[i].getIndeks()<<" - ";
        if(obecnosci[i]){
            cout<<"obecny"<<endl;
        }else{
            cout<<"nieobecny"<<endl;
        }
    }    
}


void usunOsobe(Osoba *os1, bool *obecnosci, int &liczbaOsob, int indeks){
    for(int i=0; i<liczbaOsob; i++){
        if(os1[i].getIndeks() == indeks){
            for(int j=i; j<liczbaOsob-1; j++){
               
                //nadpisywanie usuwanego przez następne
               
                // tabNazwiska[j] = tabNazwiska[j+1];
                // tabImiona[j] = tabImiona[j+1];
                // tabIndeksy[j] = tabIndeksy[j+1];
                // tabObecnosc[j] = tabObecnosc[j+1];
                os1[j] = os1[j+1];
                obecnosci[j] = obecnosci[j+1];
               
            }
            liczbaOsob--;
            break;
        }
    }
}


void edytujOsobe(Osoba *os1, int liczbaOsob, int indeks){
    for(int i=0; i<liczbaOsob; i++){
        if(os1[i].getIndeks() == indeks){
            int edycja = 0;
            cout<<"Co chcesz edytowac?\n 1. Nazwisko\n 2. Imie\n 3. Indeks"<<endl;
            cin>>edycja;
            switch(edycja){
                case 1:{
                    string nowe;
                    cout<<"Podaj nowe nazwisko: ";
                    cin>>nowe;
                    os1[i].setNazwisko(nowe);
                    break;
                }
                case 2:{
                    string nowe;
                    cout<<"Podaj nowe imie: ";
                    cin>>nowe;
                    os1[i].setImie(nowe);
                    break;
                }
                case 3:{
                    int nowy;
                    cout<<"Podaj nowy indeks: ";
                    cin>>nowy;
                    os1[i].setIndeks(nowy);
                    break;
                }
                default:
                    cout<<"nieznana operacja";
            }
            break;
        }
    }
}


int main(){
    // string Nazwiska[10];
    // string Imiona[10];
    // int Indeksy[10];
    // int liczbaOsob = 0;
    // bool Obecnosc[10];
   
    Osoba os1[10];
    bool obecnosci[10];
    int liczbaOsob = 0;
   
    string nazwisko;
    string imie;
    int indeks;
   
    while(true){
    int operacja =0;

    cout<<"Wybierz operacje:\n 1. Dodaj Osobe\n 2. Ustaw Obecnosc\n 3. Drukuj Liste\n 4. Usun Osobe\n 5. Edytuj Osobe\n 6. Wyjscie"<<endl;
    cin>>operacja;
    switch(operacja){
        case 1: // Dodawanie osoby
            cout<<"Podaj nazwisko:"<<endl;
            cin>>nazwisko;
            cout<<"Podaj imie:"<<endl;
            cin>>imie;
            cout<<"Podaj indeks:"<<endl;
            cin>>indeks;
            dodajOsobe(os1, obecnosci, nazwisko, imie, indeks, liczbaOsob);
            break;
        case 2: // Ustawianie obecnosci
            cout<<"Podaj indeks do ustawienia obecnosci: "<<endl;
            cin>>indeks;
            ustawObecnosc(os1, obecnosci, liczbaOsob, indeks, true);
            break;
        case 3: // wypisywanie listy
            cout<<"Lista: "<<endl;
            drukujListe(os1, obecnosci, liczbaOsob);
            break;
        case 4: //usuwanie osoby
            cout<<"Podaj indeks do usunięcia: "<<endl;
            cin>>indeks;
            usunOsobe(os1, obecnosci, liczbaOsob, indeks);
            break;
        case 5:
            cout<<"Podaj indeks osoby, ktora chcesz edytowac:"<<endl;
            cin>>indeks;
            edytujOsobe(os1, liczbaOsob, indeks);
            break;
        case 6:
            return 0;

        default:
            cout<<"nieznana operacja"<<endl;
    }
    }
}
