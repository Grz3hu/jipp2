#ifndef NOTES_H
#define NOTES_H

#include <iostream>
#include <string>

using namespace std;


class Note
{
protected:
    string title;
    int size;

public:
    Note() {};
    Note(string title) : title(title) {};
    string getTitle() const;
    void setTitle(const string title);
    string getContent() const {return "";};
    void setContent(const string content[]) {};
};


class TextNote : public Note
{
private:
    string content;
    int size=0;

public:
    TextNote() {};
    TextNote(string title, string content[]);
    string getContent() const;
    void setContent(const string content[]);
};


class ListNote : public Note
{
private:
    string content[100];
    int size = 1;

public:
    ListNote() {};
    ListNote(string title, string content[], int size);
    string getContent() const;
    void setContent(const string content[], int size);
};


class NoteDirector
{
private:
    Note* notesList[100];
    int used=0;

public:
    NoteDirector() {};
    NoteDirector(Note* notesList[], int used);
    void addNote(Note* n);
    void deleteNote(int index);
    int editNote(Note* n, int index);
    void clearNotesList();
    void printAllTitles();
};


#endif