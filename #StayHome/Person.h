#ifndef PERSON_H
#define PERSON_H

class Person
{
protected:
    char *name;
    int years;   //max 90
    char *email; //max 100 symbols
    int id;
public:
    Person();
    Person(const char *, int, const char *, int); 
    Person(const char *, int, int);
    Person(const char *, const char *, int);
    Person(const char *, int);
    Person(const Person &);
    ~Person();
    Person &operator=(const Person &);
    void setPerson(const char *, int, const char *, int);
    void setYears(int);
    void setEmail(const char *);
    void setName(const char *);
    void setId(int);
    bool operator==(const Person &);
    const char *getName() const;
    const char *getEmail() const;
    int getId() const;
    int getYears() const;
    void profile_info(const char *) const;
    void print(std::ostream &);
    bool read(std::istream &);
};


#endif
