#include "Song.cpp"
#include "Playlist.h"

Playlist::Playlist()
{
    strcpy(this->name, "New playlist");
    this->arr = nullptr;
    this->count = 0;
}
Playlist::Playlist(const char *name, Song *arr, size_t count)
{
    assert(name && strlen(name) > 0 );
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    assert(count > 0);
    this->count = count;
    assert(arr != nullptr);
    this->arr = new Song[this->count];
    for (size_t i = 0; i < this->count; i++)
    {
        this->arr[i] = arr[i];
    }
    
}
Playlist::~Playlist()
{
    delete[] this->name;
    delete[] this->arr;
}
Playlist::Playlist(const Playlist &other)
{

    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->count = other.count;
    this->arr = new Song[this->count];
    for (size_t i = 0; i < this->count; i++)
    {
        this->arr[i] = other.arr[i];
    }
}
Playlist &Playlist::operator=(const Playlist &other)
{
    assert(other.name && strlen(other.name) > 0);
    delete[] name;
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    assert(other.count > 0);
    this->count = other.count;
    assert(other.arr != nullptr);
    this->arr = new Song[this->count];
    for (size_t i = 0; i < this->count; i++)
    {
        this->arr[i] = other.arr[i];
    }
    return *this;
}
Song Playlist::operator[](size_t i) const
{
    return this->arr[i];
}
Song &Playlist::operator[](size_t i)
{
    return this->arr[i];
}

Song *Playlist::getArr() const
{
    return this->arr;
}
template <class T>
void swap(T &a, T &b)
{
    T c = b;
    b = a;
    a = c;
}
void sortPlaylistViaName(Playlist &p)
{
    for (size_t i = 0; i < p.count - 1; i++)
    {
        for (size_t j = i + 1; j < p.count; j++)
        {
            if (p[j] < p[i])
            {
                swap(p[i], p[j]);
            }
        }
    }
}
void sortPlaylistViaAuthor(Playlist &p)
{
    for (size_t i = 0; i < p.count - 1; i++)
    {
        for (size_t j = i + 1; j < p.count; j++)
        {
            if (p[j].smaller(p[i]))
            {
                swap(p[i], p[j]);
            }
        }
    }
}
void sortPlaylistViaTime(Playlist &p)
{
    for (size_t i = 0; i < p.count - 1; i++)
    {
        for (size_t j = i + 1; j < p.count; j++)
        {
            if (p.arr[j].getTime() < p.arr[i].getTime())
            {
                swap(p[i], p[j]);
            }
        }
    }
}
void printWithLimit(Playlist p, size_t time)
{
    std::cout << "\nPlaylist: " << p.name << "\n";
    std::cout << "Time limit: " << time << " seconds"
              << "\n\n";

    size_t count = 0;
    size_t sum = p[count].getTime();

    while (sum <= time && count < p.count)
    {
        std::cout << count + 1 << " song:"
                  << "\n";

        p[count].print();
        std::cout << "----------------------------\n\n";
        sum += p[count + 1].getTime();

        count++;
    }
}