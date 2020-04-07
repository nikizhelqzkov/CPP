#ifndef STRING_H
#define STRING_H
#include <iostream>
class String
{
private:
    char *str;
    size_t lenght;

public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    void setString(const char *);
    char *getString() const;
    size_t getLenght() const;
    void setSize(size_t);
    String &operator=(const String &);
    
    String &operator=(const char &);

    String &operator+=(const char&);
    String &operator+=(const String &);
    String &operator-=( char);
    String operator+(const String &);
    String operator-(const char);
    String operator+(const char);

    bool operator<(String) const;
    bool operator>(String) const;
    bool operator<=(String) const;
    bool operator>=(String) const;
    bool operator==(String) const;

    char operator[](size_t) const;
    char& operator[](size_t) ;
    void print() const;
    void init(const char);
};

String operator+(char, String);
std::ostream &operator<<(std::ostream &, String);
String toString(unsigned int &);
String reverse(const String&);
String toUpper(const String&);

#endif