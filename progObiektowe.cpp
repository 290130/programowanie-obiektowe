#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
void dodajOsobe(string *tabNazwiska, string *tabImiona, int *tabIndeksy, bool *tabObecnosc, string nazwisko, string imie, int indeks, int &liczbaOsob){
    tabNazwiska[liczbaOsob] = nazwisko;
    tabImiona[liczbaOsob] = imie;
    tabIndeksy[liczbaOsob] = indeks;
    tabObecnosc[liczbaOsob] = false;
    liczbaOsob++;
}

void ustawObecnosc(int *tabIndeksy, bool *tabObecnosc, int liczbaOsob, int indeks, bool obecnosc){
    for(int i=0; i<liczbaOsob; i++){
        if(tabIndeksy[i] == indeks){
            tabObecnosc[i] = obecnosc;
        }
    }
}


void drukujListe(string *tabNazwiska, string *tabImiona, int *tabIndeksy, bool *tabObecnosc, int liczbaOsob){
    for(int i=0; i<liczbaOsob; i++){
        cout<<tabNazwiska[i]<<" "<<tabImiona[i]<<"  "<<tabIndeksy[i]<<" - ";
        if(tabObecnosc[i]){
            cout<<"obecny"<<endl;
        }else{
            cout<<"nieobecny"<<endl;
        }
    }    
}


void usunOsobe(string *tabNazwiska, string *tabImiona, int *tabIndeksy, bool *tabObecnosc, int &liczbaOsob, int indeks){
    for(int i=0; i<liczbaOsob; i++){
        if(tabIndeksy[i] == indeks){
            for(int j=i; j<liczbaOsob-1; j++){
                
                //nadpisywanie usuwanego przez następne
                tabNazwiska[j] = tabNazwiska[j+1];
                tabImiona[j] = tabImiona[j+1];
                tabIndeksy[j] = tabIndeksy[j+1];
                tabObecnosc[j] = tabObecnosc[j+1];
            }
            liczbaOsob--;
            break;
        }
    }
}


void edytujOsobe(string *tabNazwiska, string *tabImiona, int *tabIndeksy, int liczbaOsob, int indeks){
    for(int i=0; i<liczbaOsob; i++){
        if(tabIndeksy[i] == indeks){
            int edycja = 0;
            cout<<"Co chcesz edytowac?\n 1. Nazwisko\n 2. Imie\n 3. Indeks"<<endl;
            cin>>edycja;
            switch(edycja){
                case 1:
                    cout<<"Podaj nowe nazwisko: ";
                    cin>>tabNazwiska[i];
                    break;
                case 2:
                    cout<<"Podaj nowe imie: ";
                    cin>>tabImiona[i];
                    break;
                case 3:
                    cout<<"Podaj nowy indeks: ";
                    cin>>tabIndeksy[i];
                    break;
                default:
                    cout<<"nieznana operacja";
            }
            break;
        }
    }
}


int main(){
    string Nazwiska[10];
    string Imiona[10];
    int Indeksy[10];
    int liczbaOsob = 0;
    bool Obecnosc[10];
   
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
            dodajOsobe(Nazwiska, Imiona, Indeksy, Obecnosc, nazwisko, imie, indeks, liczbaOsob);
            break;
        case 2: // Ustawianie obecnosci
            cout<<"Podaj indeks do ustawienia obecnosci: "<<endl;
            cin>>indeks;
            ustawObecnosc(Indeksy, Obecnosc, liczbaOsob, indeks, true);
            break;
        case 3: // wypisywanie listy
            cout<<"Lista: "<<endl;
            drukujListe(Nazwiska, Imiona, Indeksy, Obecnosc, liczbaOsob);
            break;
        case 4: //usuwanie osoby
            cout<<"Podaj indeks do usunięcia: "<<endl;
            cin>>indeks;
            usunOsobe(Nazwiska, Imiona, Indeksy, Obecnosc, liczbaOsob, indeks);
            break;
        case 5:
            cout<<"Podaj indeks osoby, ktora chcesz edytowac:"<<endl;
            cin>>indeks;
            edytujOsobe(Nazwiska, Imiona, Indeksy, liczbaOsob, indeks);
            break;
        case 6:
            return 0;

        default:
            cout<<"nieznana operacja"<<endl;
    }
    }
}