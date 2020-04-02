#ifndef SONG_H
#define SONG_H

class Song
{
private:
    char *name;
    char *author;
    char *albumName;
    size_t time;

public:
    Song();
    Song(const char*,const char*,const char*,size_t);
    Song(const Song&);
    ~Song();
    Song& operator=(const Song&);
    char* getName()const;
    char* getAuthor()const;
    char* getAlbumName()const;
    size_t getTime()const;
    void setSong(const char*,const char*,const char*,size_t);
    void setName(const char*);
    void setAuthor(const char*);
    void setAlbum(const char*);
    void setTime(size_t);
    bool operator<(const Song&)const;
    bool smaller(const Song&)const;
    void print();
};

#endif