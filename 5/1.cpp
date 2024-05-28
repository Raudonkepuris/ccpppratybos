#include<iostream>

using namespace std;

void labas(){
    cout << "Sveiki, esu funkcija!\n";
}

void labas(char L){
    switch (L)
    {
    case 'E':
        cout << "Hello, I'm a function!\n";
        break;
    
    case 'D':
        cout << "Hallo, ich bin eine Funktion!\n";
        break;

    case 'F':
        cout << "Bonjour, je suis une fonction!\n";
        break;

    default:
        break;
    }
}

int main(){
    labas();
    labas('E');
    labas('D');
    labas('F');
}