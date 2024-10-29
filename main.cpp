#include <iostream>
#include <cmath>

using namespace std;

string leggiOperazione();
void previsioneBudget(float budget);
float raccoltaFondi(float budget);
float spesaImprevista(float budget);

int main() {
    string comando;
    float budget;
    
    cout << "Inserisci un budget" << endl;
    cin >> budget;
    comando = leggiOperazione();
    while (comando != "X") {
        if (comando == "R") {
            raccoltaFondi(budget);
        } else {
            if (comando == "P") {
                previsioneBudget(budget);
            } else {
                if (comando == "S") {
                    budget = spesaImprevista(budget);
                }
            }
        }
        comando = leggiOperazione();
    }
    cout << "Programma terminato. " << endl;
    return 0;
}

string leggiOperazione() {
    string comando;
    bool controllo;
    
    cout << "Inserire un operazione tra i seguenti valori: R P S X" << endl;
    do {
        cin >> comando;
        controllo = comando != "R" && comando != "P" && comando != "S" && comando != "X";
        if (controllo) {
            cout << "Devi inserire un operazione tra i seguenti valori: R P S X" << endl;
        }
    } while (controllo);
    
    return comando;
}

void previsioneBudget(float budget) {
    int percentuale;
    
    percentuale = rand() % 31 - 10;
    cout << "Hai selezionato l'operazione 'previsioneBudget', il budget attualmente è di " << budget << " e verrà moltiplicato alla seguente percentuale: " << percentuale << "%, ottendendo un risultato di: " << budget + budget * ((float) percentuale / 100) << endl;
}

float raccoltaFondi(float& budget) {
    float fondi;
    
    cout << "Inserisci i fondi raccolti: " << endl;
    cin >> fondi;
    budget = budget + fondi;
    cout << "Budget attuale: " << budget << endl;
    
    return budget;
}

float spesaImprevista(float budget) {
    budget = budget - rand() % 201;
    cout << "Budget attuale: " << budget << endl;
    
    return budget;
}
