#include "notes.h"

using namespace std;

string Note::getTitle() const{
    return title;
}

void Note::setTitle(const string title){
    this->title=title;
}


TextNote::TextNote(string title, string content[])
{
    this->title=title;
    this->content=content[0];
}

string TextNote::getContent() const{
    return content;
}

void TextNote::setContent(const string content[]){
    this->content=content[0];
}


ListNote::ListNote(string title, string content[], int size){
    this->title=title;
    this->size=size;
    for(int i=0;i<size;i++)
        this->content[i]=content[i];
}

string ListNote::getContent() const{
    string tmp;
    for(int i=0;i<size;i++)
        tmp+= "* " + content[i] + "\n";
    return tmp;
}

void ListNote::setContent(const string content[], int size){
    for(int i=0;i<size;i++)
        this->content[i]=content[i];
}


NoteDirector::NoteDirector(Note* notesList[], int used){
    this->used=used;
    for(int i=0;i<used;i++)
        this->notesList[i]=notesList[i];
}

void NoteDirector::addNote(Note* n){
    notesList[used++]=n;
}

void NoteDirector::deleteNote(int index){
    for(int i=index;i<used-1;i++)
        notesList[i]=notesList[i+1];
    notesList[used-1]=NULL;
    used--;
}

int NoteDirector::editNote(Note* n, int index){
    if(index>=used)
        return 1;

    notesList[index]=n;
    return 0;
}

void NoteDirector::clearNotesList(){
    for(int i=0;i<used;i++)
        notesList[i]=NULL;
    used=0;
}

void NoteDirector::printAllTitles(){
    for(int i=0;i<used;i++)
        cout << i << ": " << notesList[i]->getTitle() << endl;
    cout << "huj" << endl;
}