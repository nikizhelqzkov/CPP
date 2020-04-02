#include <iostream>
#include <cstring>
#include <cassert>
#include "Song.h"

Song::Song()
{
    this->name = nullptr;
    this->author = nullptr;
    this->albumName = nullptr;
    this->time = 0;
}
Song::Song(const char *name, const char *author, const char *albumName, size_t time)
{
    assert(name && strlen(name) > 0);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(author && strlen(author) > 0);
    this->author = new char[strlen(author)] + 1;
    strcpy(this->author, author);
    assert(albumName && strlen(albumName) > 0);
    this->albumName = new char[strlen(albumName) + 1];
    strcpy(this->albumName, albumName);
    assert(time > 0);
    this->time = time;
}
Song::Song(const Song &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->author = new char[strlen(other.author) + 1];
    strcpy(this->author, other.author);
    this->albumName = new char[strlen(other.albumName) + 1];
    strcpy(this->albumName, other.albumName);
    this->time = other.time;
}
Song::~Song()
{
    delete[] this->name;
    delete[] this->author;
    delete[] albumName;
}
Song &Song::operator=(const Song &other)
{
    if (this->name != other.name)
    {

        delete[] name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    if (this->author != other.author)
    {
        delete[] author;
        this->author = new char[strlen(other.author) + 1];
        strcpy(this->author, other.author);
    }
    if (this->albumName != other.albumName)
    {
        delete[] albumName;
        this->albumName = new char[strlen(other.albumName) + 1];
        strcpy(this->albumName, other.albumName);
    }
    this->time = other.time;
    return *this;
}
char *Song::getName() const
{
    return this->name;
}
char *Song::getAuthor() const
{
    return this->author;
}
char *Song::getAlbumName() const
{
    return this->albumName;
}
size_t Song::getTime() const
{
    return this->time;
}
void Song::setSong(const char *name, const char *author, const char *albumName, size_t time)
{
    delete[] this->name;
    delete[] this->author;
    delete[] this->albumName;
    assert(name && strlen(name) > 0);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(author && strlen(author) > 0);
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
    assert(albumName && strlen(albumName) > 0);
    this->albumName = new char[strlen(albumName) + 1];
    strcpy(this->albumName, albumName);
    assert(time > 0);
    this->time = time;
}
bool Song::operator<(const Song &other) const
{
    if (strlen(this->name) <= strlen(other.name))
    {
        for (size_t i = 0; i < strlen(this->name); i++)
        {
            if (this->name[i] > other.name[i])
            {
                return false;
            }
            else if (this->name[i] < other.name[i])
            {
                return true;
            }
        }
        if (strlen(this->name) == strlen(other.name))
        {
            return false;
        }
        return true;
    }
    else
    {
        for (size_t i = 0; i < strlen(other.name); i++)
        {
            if (this->name[i] > other.name[i])
            {
                return false;
            }
            else if (this->name[i] < other.name[i])
            {
                return true;
            }
        }

        return false;
    }
}
bool Song::smaller(const Song &other) const
{
    if (strlen(this->author) <= strlen(other.author))
    {
        for (size_t i = 0; i < strlen(this->author); i++)
        {
            if (this->author[i] > other.author[i])
            {
                return false;
            }
            else if (this->author[i] < other.author[i])
            {
                return true;
            }
        }
        if (strlen(this->author) == strlen(other.author))
        {
            return false;
        }
        return true;
    }
    else
    {
        for (size_t i = 0; i < strlen(other.author); i++)
        {
            if (this->author[i] > other.author[i])
            {
                return false;
            }
            else if (this->author[i] < other.author[i])
            {
                return true;
            }
        }

        return false;
    }
}
void Song::print()
{
    std::cout << "Name: " << this->name << "\n";
    std::cout << "Author: " << this->author << "\n";
    std::cout << "Album: " << this->albumName << "\n";
    std::cout << "Time: " << this->time << " seconds"
              << "\n";
}
