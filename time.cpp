
// C++ program to find Current Day, Date 
// and Local Time 
#include<iostream> 
#include<ctime> 
using namespace std; 
int main() 
{ 
    // Declaring argument for time() 
    time_t tt; 
  
    // Declaring variable to store return value of 
    // localtime() 
    struct tm * ti; 
  
    // Applying time() 
    time (&tt); 
  
    // Using localtime() 
    ti = localtime(&tt); 
  
    cout << "Current Day, Date and Time is = " 
         //<< ti->
         //asctime(ti):

   /*ascitime-> It is used to convert the contents in the structure filled by localtime into a human-readable version which finally returns day, date and time in the given format: */
         ;
//          tm {   ti->
//    int tm_sec;   // seconds of minutes from 0 to 61
//    int tm_min;   // minutes of hour from 0 to 59
//    int tm_hour;  // hours of day from 0 to 24
//    int tm_mday;  // day of month from 1 to 31
//    int tm_mon;   // month of year from 0 to 11
//    int tm_year;  // year since 1900
//    int tm_wday;  // days since sunday
//    int tm_yday;  // days since January 1st
//    int tm_isdst; // hours of daylight savings time
//
  
  return 0; 
} 
