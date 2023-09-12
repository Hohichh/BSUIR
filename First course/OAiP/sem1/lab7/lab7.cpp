#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;


string shifrovka(string stroka) {
    
    for (int i = 0; i < stroka.length(); i++)
    {
        if (stroka[i] == 'a' || stroka[i] == 'b' || stroka[i] == 'c' || stroka[i] == 'd' || stroka[i] == 'e' || stroka[i] == 'f' || stroka[i] == 'g'
            || stroka[i] == 'h' || stroka[i] == 'i' || stroka[i] == 'j' || stroka[i] == 'k' || stroka[i] == 'l' || stroka[i] == 'm' || stroka[i] == 'n' || stroka[i] == 'o'
            || stroka[i] == 'p' || stroka[i] == 'q' || stroka[i] == 'r' || stroka[i] == 's' || stroka[i] == 't' || stroka[i] == 'u' || stroka[i] == 'v'
            || stroka[i] == 'w' || stroka[i] == 'x' || stroka[i] == 'y' || stroka[i] == 'z') {
                
            switch (stroka[i]) {
            case 'a': {
                stroka[i] = 'b';
                break;
            }
            case 'b': {
                stroka[i] = 'c';
                break;
            }
            case 'c': {
                stroka[i] = 'd';
                break;
            }
            case 'd': {
                stroka[i] = 'e';
                break;
            }
            case 'e': {
                stroka[i] = 'f';
                break;
            }
            case 'f': {
                stroka[i] = 'g';
                break;
            }
            case 'g': {
                stroka[i] = 'h';
                break;
            }
            case 'h': {
                stroka[i] = 'i';
                break;
            }
            case 'i': {
                stroka[i] = 'j';
                break;
            }
            case 'j': {
                stroka[i] = 'k';
                break;
            }
            case 'k': {
                stroka[i] = 'l';
                break;
            }
            case 'l': {
                stroka[i] = 'm';
                break;
            }
            case 'm': {
                stroka[i] = 'n';
                break;
            }
            case 'n': {
                stroka[i] = 'o';
                break;
            }
            case 'o': {
                stroka[i] = 'p';
                break;
            }
            case 'p': {
                stroka[i] = 'q';
                break;
            }
            case 'q': {
                stroka[i] = 'r';
                break;
            }
            case 'r': {
                stroka[i] = 's';
                break;
            }
            case 's': {
                stroka[i] = 't';
                break;
            }
            case 't': {
                stroka[i] = 'u';
                break;
            }
            case 'u': {
                stroka[i] = 'v';
                break;
            }
            case 'v': {
                stroka[i] = 'w';
                break;
            }
            case 'w': {
                stroka[i] = 'x';
                break;
            }
            case 'x': {
                stroka[i] = 'y';
                break;
            }
            case 'y': {
                stroka[i] = 'z';
                break;
            }
            case 'z': {
                stroka[i] = 'a';
                break;
            }
            }
        }

    }
    return stroka;
}
string deshifrovka(string stroka) {
    for (int i = 0; i < stroka.length(); i++)
    {
        if (stroka[i] == 'a' || stroka[i] == 'b' || stroka[i] == 'c' || stroka[i] == 'd' || stroka[i] == 'e' || stroka[i] == 'f' || stroka[i] == 'g'
            || stroka[i] == 'h' || stroka[i] == 'i' || stroka[i] == 'j' || stroka[i] == 'k' || stroka[i] == 'l' || stroka[i] == 'm' || stroka[i] == 'n' || stroka[i] == 'o'
            || stroka[i] == 'p' || stroka[i] == 'q' || stroka[i] == 'r' || stroka[i] == 's' || stroka[i] == 't' || stroka[i] == 'u' || stroka[i] == 'v'
            || stroka[i] == 'w' || stroka[i] == 'x' || stroka[i] == 'y' || stroka[i] == 'z') {

            switch (stroka[i]) {
            case 'a': {
                stroka[i] = 'z';
                break;
            }
            case 'b': {
                stroka[i] = 'a';
                break;
            }
            case 'c': {
                stroka[i] = 'b';
                break;
            }
            case 'd': {
                stroka[i] = 'c';
                break;
            }
            case 'e': {
                stroka[i] = 'd';
                break;
            }
            case 'f': {
                stroka[i] = 'e';
                break;
            }
            case 'g': {
                stroka[i] = 'f';
                break;
            }
            case 'h': {
                stroka[i] = 'g';
                break;
            }
            case 'i': {
                stroka[i] = 'h';
                break;
            }
            case 'j': {
                stroka[i] = 'i';
                break;
            }
            case 'k': {
                stroka[i] = 'j';
                break;
            }
            case 'l': {
                stroka[i] = 'k';
                break;
            }
            case 'm': {
                stroka[i] = 'l';
                break;
            }
            case 'n': {
                stroka[i] = 'm';
                break;
            }
            case 'o': {
                stroka[i] = 'n';
                break;
            }
            case 'p': {
                stroka[i] = 'o';
                break;
            }
            case 'q': {
                stroka[i] = 'p';
                break;
            }
            case 'r': {
                stroka[i] = 'q';
                break;
            }
            case 's': {
                stroka[i] = 'r';
                break;
            }
            case 't': {
                stroka[i] = 's';
                break;
            }
            case 'u': {
                stroka[i] = 't';
                break;
            }
            case 'v': {
                stroka[i] = 'u';
                break;
            }
            case 'w': {
                stroka[i] = 'v';
                break;
            }
            case 'x': {
                stroka[i] = 'w';
                break;
            }
            case 'y': {
                stroka[i] = 'x';
                break;
            }
            case 'z': {
                stroka[i] = 'y';
                break;
            }
            }
        }

    }
  
    return stroka;
}

void WriteToFile(string &stroka) {
    ofstream fout;
    fout.open("C:\\Users\\verko\\source\\repos\\lab7\\stroka.txt");
    if (fout.is_open()) {
        fout << stroka;
        fout.close();
        cout << "Ur input succesfully saved in stroka.txt\n";
       
    }
    else {
        cout << "\nSomething went wrong fith ur file...\n";
    }
}

void ReadFromFile() {
    ifstream fin;
    fin.open("C:\\Users\\verko\\source\\repos\\lab7\\stroka.txt");
    if (fin.is_open()) {
        string output;
        getline(fin, output);
        cout << "Ur string: ";
        cout << output << "\n\n";
       
    }
    else {
        cout<< "Something went wrong fith ur file...\n";
    }
    fin.close();
}

int main()
{
    cout << "Welcome to text encryption program!\n";
    cout << "input ur string: ";
    string stroka;
    getline(cin, stroka);
    cout << "\n";

    WriteToFile(stroka);
    ReadFromFile();
   
    cout << "Now ur text will be encrypted!\n";
    cout<<"Let's see: " << shifrovka(stroka) << "\n\n";
    cout << "Do you want to decrypt ur text?(Y/N)\n";
    char answer;
    cin >> answer;

    switch (answer) {
    case 'Y': 
    case 'y': cout << "Ok, here it is:\n";
        cout<< deshifrovka(shifrovka(stroka))<<"\n";
        break;
    case 'N':
    case 'n':  cout << "Ok, bye!\n";
        return 0;
        break;
    default: {
        cout << "Vyidi i vvedy normalno\n";
        return 0;
    }

    }

    
}

