#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"
#include <cstring>
#include <cassert>
String::String()
{
    this->str = nullptr;
    this->lenght = 0;
}
String::String(const char *str)
{
    assert(str && strlen(str) < 255);
    this->lenght = strlen(str);
    this->str = new char[lenght + 1];
    strcpy(this->str, str);
}
String::String(const String &other)
{
    assert(other.str && other.lenght < 255);
    this->lenght = other.lenght;
    this->str = new char[lenght + 1];
    strcpy(this->str, other.str);
}
String::~String()
{
    delete[] str;
}
void String::setString(const char *str)
{
    delete[] str;
    assert(str && strlen(str) < 255);
    this->lenght = strlen(str);
    this->str = new char[lenght + 1];
    strcpy(this->str, str);
}
void String::setSize(size_t size)
{
    this->lenght = size;
}
char *String::getString() const
{
    return this->str;
}
size_t String::getLenght() const
{
    return this->lenght;
}
bool String::operator==(String other) const
{
    return strcmp(this->str, other.str) == 0;
}
String &String::operator=(const String &other)
{
    if (this->str != other.str)
    {
        delete[] this->str;
        this->lenght = other.lenght;
        this->str = new char[lenght];
        strcpy(this->str, other.str);
    }
    return *this;
}
String &String::operator+=(const char &c)
{
    char *result;
    assert(this->lenght < 254);

    size_t len = this->lenght + 1;
    result = new char[lenght + 1];
    strcpy(result, this->str);
    result[len - 1] = c;
    delete[] this->str;
    this->lenght++;
    this->str = new char[lenght + 1];
    strcpy(this->str, result);
    this->str[lenght] = '\0';
    return *this;
}
String &String::operator-=(char c)
{
    char *result;
    bool flag = true;
    result = new char[this->lenght + 1];
    strcpy(result, this->str);
    for (size_t i = 0; i < this->lenght; i++)
    {

        if (result[i] == c)
        {
            flag = false;
            for (size_t j = i + 1; j < this->lenght; j++)
            {
                result[j - 1] = result[j];
            }
        }
    }
    if (flag)
    {
        return *this;
    }
    delete[] this->str;
    this->lenght--;
    this->str = new char[lenght + 1];
    strcpy(this->str, result);

    this->str[lenght] = '\0';
    return *this;
}
String &String::operator+=(const String &other)
{
    assert(other.str && this->lenght + other.lenght < 255);
    char *result;
    size_t len = this->lenght + other.lenght + 1;
    result = new char[len];
    strcpy(result, this->str);
    strcat(result, other.str);
    delete[] this->str;
    this->lenght += other.lenght;
    this->str = new char[this->lenght + 1];
    strcpy(this->str, result);
    this->str[this->lenght] = '\0';
    return *this;
}
String String::operator+(const String &other)
{
    String result;
    result = *(this);
    result += other;
    return result;
}
String String::operator+(const char c)
{
    String result;
    result = *(this);
    result += c;
    return result;
}
String String::operator-(const char c)
{
    bool flag = true;
    String result;
    result = *(this);
    for (size_t i = 0; i < this->lenght; i++)
    {
        if (c == this->str[i])
        {
            flag = false;
        }
    }
    if (flag)
    {
        return result;
    }
    result -= c;

    return result;
}
bool String::operator<(String other) const
{
    return strcmp(this->str, other.str) < 0;
}
bool String::operator<=(String other) const
{
    return strcmp(this->str, other.str) <= 0;
}
bool String::operator>(String other) const
{
    return strcmp(this->str, other.str) > 0;
}
bool String::operator>=(String other) const
{
    return strcmp(this->str, other.str) >= 0;
}
char String::operator[](size_t i) const
{
    return this->str[i];
}

char &String::operator[](size_t i)
{
    return this->str[i];
}
void String::print() const
{
    std::cout << this->str << std::endl;
}
String &String::operator=(const char &c)
{
    delete[] this->str;
    this->lenght = 1;
    this->str = new char[1];
    this->str[0] = c;
    this->str[1] = '\0';
    return *this;
}

String operator+(char c, String s)
{
    String result;
    result = c;
    result += s;
    return result;
}
std::ostream &operator<<(std::ostream &out, String s)
{
    out << s.getString();
    
    return out;
}

String toString(unsigned int &x)
{
    char c;
    String a("x");
    a -= 'x';
    if (x < 9)
    {
        a += ('0' + x);
    }
    else
    {
        while (x > 0)
        {
            //result = operator+ ('0' + x % 10,result);
            c = ('0' + x % 10);
            a = c + a; //най-дясна цифра
            x /= 10;
        }
    }
    return a;
}
String reverse(const String &s)
{
    String result;

    size_t count = s.getLenght();
    result = s[count - 1];
    //result += s[1];
    for (int i = count - 2; i >= 0; i--)
    {
        result += s[i];
    }
    // result+=s[0];

    return result;
}
String toUpper(const String &s)
{
    String result(s);
    result.setSize(s.getLenght());

    for (size_t i = 0; i < result.getLenght(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] += 'A' - 'a';
        }
    }
    return result;
}
#endif