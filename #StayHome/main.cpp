#include <iostream>
#include "Person.h"
#include"PersonArr.hpp"

int main(){
    Person a("Ivancho",20,"n@",20);
   // a.profile_info("Ivancho");
    Person* arr = new Person[1];
    arr[0] = a;
    PersonArr array(arr,1);
    array.printArr();
    delete[]arr;
    
}