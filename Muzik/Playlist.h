#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"
class Playlist
{
private:
    char *name;
    Song *arr;
    size_t count;

public:
    Playlist();
    Playlist(const char *, Song *, size_t);
    Playlist(const Playlist &);
    ~Playlist();
    Playlist &operator=(const Playlist &);
    Song operator[](size_t) const;
    Song &operator[](size_t);
    Song *getArr() const;
    friend void sortPlaylistViaName(Playlist &);
    friend void sortPlaylistViaTime(Playlist &);
    friend void sortPlaylistViaAuthor(Playlist &);
    friend void printWithLimit(Playlist, size_t);
};

#endif