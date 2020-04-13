#include <iostream>
#include <cstring>
// #include "Person.h"
// #include "PersonArr.hpp"

char *addChar(char *name, const char s)
{
    char *result;

    result = new char[strlen(name) + 1];
    strcpy(result, name);
    result[strlen(name) - 1] = s;
    //delete[] name;
    result[strlen(name)] = '\0';
    return result;
}




int main()
{

    char* text;
    text  = new char[20];
    // while (std::cin && strlen(text)<20)
    // {
        
    //     std::cin>>text;

    //     std::cout<<text<<"\n";
    
    // }
    
    // char *name = new char[2];
    // name[0] = 'a';
    // name[1] = 'b';
    // char s = 's';
    // name = addChar(name,s);
    // //addChar(name,'a');
    
    // char *name2 = new char[4];

    // name2 = addChar(name, s);
    // // strcpy(name2,addChar(name,'s'));
    // for (size_t i = 0; i < strlen(name); i++)
    // {
    //     std::cout << name[i];
    // }

    //     Person a("Ivancho",20,"n@",20);
    //    // a.profile_info("Ivancho");
    //     Person* arr = new Person[1];
    //     arr[0] = a;
    //     PersonArr array(arr,1);
    //     array.printArr();
    //     delete[]arr;
}