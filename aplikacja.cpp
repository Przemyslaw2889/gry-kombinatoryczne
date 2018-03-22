#include <iostream>
#include <string>

using namespace std;

const short Maxrozmiar = 10;
const short MaxRozmiarWzorca = 3;

bool czyRowne(char* slowo1, char* slowo2) {
    for (int i = 0; slowo1[i] != NULL && slowo2[i] != NULL; i++)
        if (slowo1[i] != slowo2[i]) return 0;
    return 1;
}

bool czyRowneAbelowo(const char* slowo, int pocz1, int kon1, int pocz2, int kon2) {
    if (kon1 - pocz1 != kon2 - pocz2 || kon1<pocz1) return 0;
    int n = kon1 - pocz1 + 1;
    bool* juzWybrane= new bool[n];
    for (int i = 0; i < n; i++) juzWybrane[i] = 0;
    bool znalezionoPare = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (slowo[pocz1 + i] == slowo[pocz2 + j] && juzWybrane[j]==0) {
                juzWybrane[j] = 1;
                znalezionoPare = 1;
                break;
            }
        }
        if (znalezionoPare == 0) {
            delete[] juzWybrane;
            return 0;
        }
        znalezionoPare = 0;
    }
    delete[] juzWybrane;
    return 1;
}

char* Wstaw(char* slowo, char znak, int pozycja) {
    char temp = slowo[pozycja];
    char temp2;
    slowo[pozycja] = znak;
    while (temp != NULL) {
        temp2= slowo[pozycja+1];
        slowo[pozycja+1]=temp;
        temp = temp2;
        pozycja++;
    }
    slowo[pozycja+1] = NULL;
    return slowo;
}

int rozmiar(const char* slowo) {
    int i = 0;
    while (slowo[i] != NULL) { i++; }
    return i;
}

bool czyWystepujeWzorzec1(const char* slowo,const char* wzorzec, int dlugosc) {
    bool czy = 0;
    for (int i = 0; i + rozmiar(wzorzec)*dlugosc <= rozmiar(slowo); i++) {
        czy = 1;
        for (int j = 0; j < rozmiar(wzorzec); j++) {
            for (int k = j+1; k < rozmiar(wzorzec); k++) {
                if (wzorzec[j] == wzorzec[k] && !czyRowneAbelowo(slowo,i +j*dlugosc,i+(j+1)*dlugosc-1, i + k * dlugosc, i + (k + 1)*dlugosc - 1) ) {
                    czy = 0;
                }
            }
        }
        if (czy) return 1;
    }
    return 0;
}

bool czyWystepujeWzorzec(const char* slowo,const char* wzorzec) {
    for (int i = 1; i*rozmiar(wzorzec) <= rozmiar(slowo); i++)
        if (czyWystepujeWzorzec1(slowo, wzorzec, i)) return 1;
    return 0;
}

char* generujAlfabet(const char* slowo) {
    char* A=new char[Maxrozmiar];
    int ile = 0;
    bool juzJest;
    for (int i = 0; i < rozmiar(slowo); i++) {
        juzJest = 0;
        for (int j = 0; j < ile; j++) {
            if (slowo[i] == A[j]) {
                juzJest = 1; break;
            }
        }
        if (!juzJest) {
            A[ile] = slowo[i];
            ile++;
        }
    }
    A[ile] = NULL;
    return A;
    delete A;
}

void wypisz(const char* slowo) {
    cout << "{"<<slowo[0];
    for (int i = 1; i<rozmiar(slowo); i++) cout <<","<< slowo[i];
    cout <<"}"<< endl;
}

int main() {
    while (true) {
        cout <<endl<< "Witaj w abelowej grze w zabronione wzorce!" << endl;
        cout<< "Wybierz tryb gry, w ktory chcesz zagrac." << endl;
        cout << "0 - gracz vs gracz" << endl;
        cout << "1 - gracz vs komputer" << endl;
        cout << "2 - komputer vs gracz" << endl;
        cout << "3 - komputer vs komputer" << endl;
        int wybor;
        cin >> wybor; cin.get();

        //Ustalamy alfabet. 
        string alfabet("abc");
        string wzorzec("xx");
        string slowo("");

        switch(wybor)
        {
        case 0:
        {
            int wygrany = 2;
            int miejsce = 0;
            string litera;
            while(slowo.length() < Maxrozmiar)
            {

                cout << "### Aktualne slowo: " << slowo << "###" << endl;
                cout << "Gracz1: Podaj na ktorym miejscu Gracz 2 ma wstawic litere (od 0 do " << slowo.length() << ")" << endl;
                cin >> miejsce;
                cout << "Gracz2: Podaj litere ktora chcesz wstawic (mozliwe: " << alfabet << ")" << endl;
                cin >> litera;
                slowo.insert(miejsce, litera);
                if(czyWystepujeWzorzec(slowo.c_str(), wzorzec.c_str()))
                {
                    cout << "Wygral gracz 1, gratulacje" << endl;
                    wygrany = 1;
                    break;
                }
            }
            if(wygrany==2) cout << "Wygral gracz 2, gratulacje" << endl;
            break; 
        } 
        case 1:

            char ciag[Maxrozmiar];
            char wz[MaxRozmiarWzorca];

            cout << "Podaj ciag wyjsciowy: ";
            cin.getline(ciag, Maxrozmiar);
            cout << "Podaj wzorzec: ";
            cin.getline(wz, MaxRozmiarWzorca);
            if (czyWystepujeWzorzec(ciag, wz)) cout << "Wzorzec wystepuje!" << endl;
            else cout << "Wzorzec nie wystepuje!" << endl;

            break;
        case 2:

            break;
        case 3:

            break;
        default:
            cout << "Wybierz tryb gry z powyzszych!" << endl;
            break;
        }
    }
    //system("pause");
    return 0;
}

