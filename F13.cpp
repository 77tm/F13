/*  Toms Madžuls, tm22005
    F13. Dots teksta fails f. Uzrakstīt programmu, kura izveido failu f1, kurā, salīdzinot ar failu f,
    visi sastaptie cipari būtu nomainīti ar nākošo ciparu pēc moduļa 10, t.i., 0->1, 1->2, 2->3, …, 9->0.
    Programma izveidota: 20.02.2023
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int ok;

    do
    {
        string linija;
        char ieprieksejais;

        ifstream inFails;
        inFails.open("/Users/a77/Documents/programmesana/laboratorijas_darbi/F13/f.txt", ios::in); // ievades fails

        if (inFails)
        {
            cout << "Fails atverts" << endl;
        }
        else
        {
            cout << "Failu neizdevas atvert" << endl;
        }

        ofstream outFails("/Users/a77/Documents/programmesana/laboratorijas_darbi/F13/f1.txt", ios::out); // izvades fails

        while (getline(inFails, linija)) // kamer ievades faila ir jauna linija \n
        {
            for (char c : linija) // ejam cauri katram panemtas linijas char  //; for loop \n, linija[c]
            {
                if (c >= '0' && c <= '9') // vai isdigit(c)
                {
                    string s(1, c);  // ja cipars, tad izveidojam no vina string
                    int i = stoi(s); // un parliekam uz int
                    if (ieprieksejais == '-')
                    {
                        outFails << --i;
                        continue;
                    }
                    if (i == 9)
                    {
                        outFails << 0;
                    }
                    else
                    {
                        outFails << ++i;
                    }
                }
                else
                {
                    outFails << c; // ja nav cipars, tad vienkarsi parkopejam
                }
                ieprieksejais = c;
            }
            outFails << endl;
        }

        inFails.close();
        outFails.close();

        cout << endl
             << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
    return 0;
}