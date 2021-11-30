#include "notes.h"
#include <limits>
#include <unistd.h>
#include <iostream>

using namespace std;

void printHelp()
{
    cout << "1) dodaj notatke" << endl;
    cout << "2) usun notaki" << endl;
    cout << "3) usun notatke" << endl;
    cout << "4) wyswietl notatke" << endl;
    cout << "5) edytuj notatke" << endl;
}

void NoteAdd(NoteDirector nd){
    int option;
    cout << "Typ 1 - jednoliniowa" << endl;
    cout << "Typ 2 - wieloliniowa" << endl;
    cout << "Podaj typ notatki: " << endl;
    cin >> option;
    
    string title;
    cout << "Podaj tytuł: \n";
    cin >> title;
    
    if (option==1)
    {
        string text;
        cout << "Podaj treść: \n";
        getline(cin,text);
        string tmp2[1]={text};
        TextNote* td = new TextNote(title,tmp2);
        nd.addNote(td);
    }
    if (option==2)
    {
        cout << "Podaj treść: \n";
        string text[100];
        int i;
        for(i=0;i<100; i++){
            if(!getline(cin,text[i]))// end on eof
                break;
        }
        ListNote* td = new ListNote(title,text,i);
        nd.addNote(td);
    }
        cout << "Dodano notatke\n";
}

void NoteDel(NoteDirector nd){
    int index;
    cout << "Podaj index do usuniecia: \n";
    cin >> index;
    nd.deleteNote(index);
}

void NoteEdit(NoteDirector nd){
    int index;
    cout << "Podaj index do zmiany: \n";
    cin >> index;

    int option;
    cout << "Typ 1 - jednoliniowa" << endl;
    cout << "Typ 2 - wieloliniowa" << endl;
    cout << "Podaj typ notatki: " << endl;
    cin >> option;
    cin.ignore(256, '\n');
    
    string title;
    cout << "Podaj tytuł: \n";
    cin >> title;
    cin.ignore(256, '\n');
    
    if (option==1)
    {
        string text;
        cout << "Podaj treść: \n";
        cin.ignore(256, '\n');
        getline(cin,text);
        string tmp2[1]={text};
        TextNote* td = new TextNote(title,tmp2);
        nd.editNote(td,index);
    }
    if (option==2)
    {
        cout << "Podaj treść: \n";
        string text[100];
        int i;
        for(i=0;i<100; i++){
            if(!getline(cin,text[i]))// end on eof
                break;
        }
        ListNote* td = new ListNote(title,text,i);
        nd.editNote(td,index);
    }
        cin.ignore(256, '\n');
        cout << "Dodano notatke\n";
}


int main()
{
    while (true)
    {
        NoteDirector nd = NoteDirector();
        string ddd[]={"cccc"};
        TextNote* td = new TextNote("ddd",ddd);
        nd.addNote(td);
        unsigned int option;
        printHelp();
        cin >> option;
        cin.ignore(256, '\n');
        switch (option)
        {
        case 1:
            NoteAdd(nd);
            break;
        case 2:
            nd.clearNotesList();
            break;
        case 3:
            NoteDel(nd);
            break;
        case 4:
            nd.printAllTitles();
            break;
        case 5:
            NoteEdit(nd);
            break;
        }
        sleep(1);
        cout << endl << endl;
        nd.printAllTitles();
    }
    return 0;
}
