#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;

ifstream fin ("intrebariEn.txt");
ifstream f ("intrebariRo.txt");


int main()
{
    SetConsoleOutputCP( 65001 );
    int lan;
    string c;
    cout << "Alege limba\n1. Romana\n2. Engleza\n";
    getline(cin, c);
    if (c[0]-'0' == 1) {
        lan = 1;
    }
    else {
        lan = 2;
    }
    system("cls");
    string r, intrebare;
    vector <string> intrebari;
    vector <int> iIntrebari;
    srand(time(0));
    int punctaj = 0;
    while (1) {
        if (lan == 1) {
            getline(f, r);
        }
        else {
            getline(fin, r);
        }
        int totalCorecte = 0;
        if (isdigit(r[0])) {
            if (r[0] - '0' == 9) {
                break;
            }
            intrebari.push_back(r);
        }
        else if (r.size() > 0) {
            intrebare = r;
        }
        else {
            while (totalCorecte == 0) {
                cout << intrebare << "\n";
                iIntrebari.clear();
                while (iIntrebari.size() < 4) {
                    int randomNumber = rand() % 10;
                    if (randomNumber < intrebari.size() && find(iIntrebari.begin(), iIntrebari.end(), randomNumber) == iIntrebari.end()) {
                        cout << iIntrebari.size() + 1 << ". " << intrebari[randomNumber].substr(2) << "\n";
                        iIntrebari.push_back(randomNumber);
                        if (intrebari[randomNumber][0] - '0' == 1) {
                            totalCorecte ++;
                        }
                    }
                }
                if (totalCorecte == 0) {
                    system("cls");
                }
            }
            string raspunsuri;
            getline(cin, raspunsuri);
            int corecte = 0, rasGresit = 0;
            vector<pair <int, int> > feedback;
            for (int i = 0; i < raspunsuri.size(); i ++) {
                if (isdigit(raspunsuri[i])) {
                    int raspuns = raspunsuri[i] - '0';
                    if (raspuns >= 1 && raspuns <= 4) {
                        raspuns --;
                        int idx = iIntrebari[raspuns];
                        if (intrebari[idx][0] - '0' == 1) {
                            corecte ++;
                            feedback.push_back({raspuns, 1});
                        }
                        else {
                            rasGresit = 1;
                            feedback.push_back({raspuns, 0});
                        }
                    }
                }
            }
            if (corecte == totalCorecte && rasGresit == 0) {
                punctaj += 3;
            }
            else if (corecte != 0 && rasGresit == 0) {
                punctaj += 1;
            }
            cout << "Raspunsuri corecte: " << corecte << "\n";
            for (int i = 0; i < iIntrebari.size(); i ++) {
                int idx = iIntrebari[i];
                if (intrebari[idx][0] - '0' == 1) {
                    cout << i+1 << ": corect\n";
                }
                else {
                    cout << i+1 << ": gresit\n";
                }
            }
            if (rasGresit == 1) {
                cout << "Punctaj la aceasta intrebare: 0\n";
            }
            cout << "Punctaj total: " << punctaj << "\n";
            cout << "Apasa Enter pentru a continua\n";
            string waiting;
            getline(cin, waiting);
            system("cls");
            if (waiting.size() > 1) {
                break;
            }
            intrebari.clear();
        }
    }
    cout << "Punctaj: " << punctaj;
    getline(cin, c);
    return 0;
}
