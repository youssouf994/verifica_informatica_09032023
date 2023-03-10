#include <iostream>
#define dim 10

using namespace std;

struct dipendenti
{
    string nome;
    string cognome;
    double stipendio;
    int presente;
};

void genera_archivio(dipendenti dip[], int dime )
{
    int i;

    for (i = 0; i < dime; i++)
    {
        dip[i].nome = " ";
        dip[i].cognome = " ";
        dip[i].stipendio = -1;
        dip[i].presente = 0;
    }
}

void carica(dipendenti dip[], int dime)
{
    int i, stip, pos=-1, check=0;
    string nome, cognome;

    for (i = 0; i < dime; i++)
    {
        if (dip[i].presente == 0)
        {
            check++;
        }
    }

    if (check < 1)
    {
        cout << "memoria piena" << endl;
    }

    else
    {
        cout << "hai a disposizione " << check << " posizioni in memoria" << endl;
        cout << "inserire nome dipendente" << endl;
        cin >> nome;
        cout << "inserire cognome" << endl;
        cin >> cognome;
        cout << "inserire stipendio" << endl;
        cin >> stip;

        i = 0;
        while (dip[i].presente == 1)
        {
            i++;
        }

        dip[i].nome = nome;
        dip[i].cognome = cognome;
        dip[i].stipendio = stip;
        dip[i].presente = 1;
    }
}

void visualizza(dipendenti dip[], int dime)
{
    int i;
    bool check = false;

    for (i = 0; i < dime; i++)
    {
        if (dip[i].presente == 1)
        {
            check = true;
            cout << "nome: " << dip[i].nome << endl;
            cout << "cognome: " << dip[i].cognome << endl;
            cout << "stipendio: " << dip[i].stipendio << endl;
        }
        else
        {

        }
    }

    if (check == false)
    {
        cout << "archivio vuoto" << endl;
    }
}

string cerca(dipendenti dip[], int dime)
{
    int i, x = 0;
    string cerca, dato;

    cout << "inserire cognome da cercare" << endl;
    cin >> cerca;

    for (i = 0; i < dime; i++)
    {
        if (dip[i].cognome == cerca)
        {
            cout << "nome: " << dip[i].nome << endl;
            cout << "cognome: " << dip[i].cognome << endl;
            cout << "stipendio: " << dip[i].stipendio << endl;
            x = 1;
            dato = dip[i].cognome;
        }
    }

    if (x == 0)
    {
        cout << "dipendente non trovato" << endl;
    }

    return dato;
}

void cancella(dipendenti dip[], int dime)
{
    string check;
    int i;

    check = cerca(dip, dim);

    for (i = 0; i < dime; i++)
    {
        if (check == dip[i].cognome)
        {
            dip[i].presente = 0;
        }
    }
}

int main()
{
    dipendenti dip[10];
    char seleziona;

    genera_archivio(dip, dim);

    do
    {
        cout << "r.ripristina" << endl;
        cout << "c.carica" << endl;
        cout << "v.visualizza" << endl;
        cout << "s.cerca" << endl;
        cout << "e.cancella" << endl;
        cin >> seleziona;

        switch (seleziona)
        {
            case 'c':
            case'C':
                carica(dip, dim);
                break;

            case 'r':
            case 'R':
                genera_archivio(dip, dim);
                break;

            case 'v':
            case 'V':
                visualizza(dip, dim);
                break;

            case 's':
            case 'S':
                cerca(dip, dim);
                break;

            case 'e':
            case 'E':
                cancella(dip, dim);
                break;

            case 27:
                break;

            default:
                cout << "scelta errata" << endl;
                break;
        }
    } while (seleziona != 27);

    return 0;
}

