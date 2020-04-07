#include "String.cpp"
int main()
{

    String s1("hello");
    String s2("hc");
    char c = 'h';
    // s2 += c;
    // s2 += c;
    // s2 += c;
    // s2 += c;
    // s2 -= c;
    // //std::cout<<s2.getString();
    // s2 -= 'c';
    // //std::cout << s2.getString() << std::endl;
    // s2 += s1;
    // std::cout << s2.getString() << std::endl;
    String c3;
   c3 = c + s1;
   c3-=c;
    // c3.print();
    //c3 = s1+s2;
    // String s3 = s2 - c;
    // std::cout << c3.getString() << std::endl;

    // std::cout<<(c3>=c3);
    // c3.print();
    //unsigned x = 13;
    //std::cout<<toString(x)<<std::endl;
    // toString(x).print();
    //std::cout<<c3<<c3<<std::endl;
     //reverse(c3).print();
    //toUpper(c3).print();
     c3.print();

    return 0;
}
