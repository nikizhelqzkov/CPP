#include "employ.cpp"
#include "manager.cpp"
#include "programmer.cpp"

Employ **RemoveViaExp(Employ **arr, size_t size)
{
    Employ **buffer = new Employ *[size];
    Employ **reserve;

    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = arr[i];
    }

    int sz = size;
    bool flag = false;
    for (size_t i = 0; i < size; i++)
    {
        if (buffer[i]->getWorkExp() < 3)
        {
            flag = true;
            reserve = buffer[i]->removeEmploy(arr, sz);
            sz--;
        }
    }

    if (flag)
    {
        return reserve;
    }
    else
    {
        return buffer;
    }
}

int main()
{
    Manager m("Nikolay Zhelyazkov", 33, 13);
    Manager n("kiki Zhelyazkov", 33, 13);
    //m.print();
    Programmer p("Nikolay Penkov", 1, true, false);
    // p.print();
    Employ **arr;
    // for (size_t i = 0; i < 2; i++)
    // {
    //     arr[i]->print();
    // }

    Programmer p2("Il Penkov", 1, true, false);
    arr = p.addEmploy(arr, 0);
    arr = p2.addEmploy(arr, 1);
    arr = n.addEmploy(arr, 2);

    arr = m.addEmploy(arr, 3);

    for (size_t i = 0; i < 4; i++)
    {
        arr[i]->print();
    }
    std::cout << "\n\n";
    //    // arr = p.removeEmploy(arr, 3);
    //     for (size_t i = 0; i < 2; i++)
    //     {
    //         arr[i]->print();
    //     }
    arr = RemoveViaExp(arr, 4);
    for (size_t i = 0; i < 4; i++)
    {
        arr[i]->print();
    }

    for (size_t i = 0; i < 4; i++)
    {
        delete[]arr[i];
    }
    
    delete arr;
}