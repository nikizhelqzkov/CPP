#include "Employee.cpp"
#include <fstream>
#include <iostream>

void test()
{
    Employee me("Me", 40, 20.50);

    std::ofstream outputFile("Employees.txt", std::ios::out);
    if(!outputFile.is_open())
    {
        std::cout << "Error! The file cannot be opened!" << std::endl;
        return;
    }

    me.print(outputFile);

    outputFile.close();
}

double calculateSalaries(const char* inputFileName, const char* outputFileName)
{
    std::ifstream inputFile(inputFileName, std::ios::in);
    if(!inputFile.is_open())
    {
        std::cout << "The input file " << inputFileName << " cannot be opened!" << std::endl;
        return 0;
    }

    std::ofstream outputFile(outputFileName, std::ios::out);
    if(!outputFile.is_open())
    {
        std::cout << "The output file " << outputFileName << " cannot be opened!" << std::endl;
        return 0;
    }

    double totalSalaries = 0;

    Employee currentEmployee;
    while(inputFile)
    {
        if(currentEmployee.read(inputFile))
        {
            double salary =
                currentEmployee.getWorktime() * currentEmployee.getHourSalary();

                outputFile << std::setiosflags(std::ios::fixed) << std::setprecision(2);
                outputFile << currentEmployee.getName() << '\t' << salary << std::endl;

                totalSalaries += salary;
        }
    }

    inputFile.close();
    outputFile.close();

    return totalSalaries;
}

bool convertTextToBin(const char* inputFileName, const char* outputFileName)
{
    std::ifstream inputFile(inputFileName, std::ios::in);
    if(!inputFile.is_open())
    {
        std::cout << "The input file " << inputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    std::ofstream outputFile(outputFileName, std::ios::out | std::ios::binary);
    if(!outputFile.is_open())
    {
        std::cout << "The output file " << outputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    Employee currentEmployee;
    while(inputFile)
    {
        if(currentEmployee.read(inputFile))
        {
            currentEmployee.storeInBin(outputFile);
        }
    }

    inputFile.close();
    outputFile.close();

    return true;
}

bool filterFromBin(const char* inputFileName, const char* outputFileName)
{
    std::ifstream inputFile(inputFileName, std::ios::in | std::ios::binary);
    if(!inputFile.is_open())
    {
        std::cout << "The input file " << inputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    std::ofstream outputFile(outputFileName, std::ios::out);
    if(!outputFile.is_open())
    {
        std::cout << "The output file " << outputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    Employee currentEmployee;
    std::cout<<"\n----------filtered salary < 20 lv---------\n";
    while(inputFile)
    {
        
        if(currentEmployee.loadFromBin(inputFile))
        {
            if(currentEmployee.getWorktime() < 20.0)
            {
                currentEmployee.print();
                currentEmployee.print(outputFile);
            }
           
        }
        
    }

    inputFile.close();
    outputFile.close();

    return true;
}
bool binToText(const char* inputFileName, const char* outputFileName)
{
    std::ifstream inputFile(inputFileName, std::ios::in | std::ios::binary);
    if(!inputFile.is_open())
    {
        std::cout << "The input file " << inputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    std::ofstream outputFile(outputFileName, std::ios::out);
    if(!outputFile.is_open())
    {
        std::cout << "The output file " << outputFileName << " cannot be opened!" << std::endl;
        return false;
    }

    Employee currentEmployee; std::cout<<"----------normal salary Text File---------\n";   
    while(inputFile)
    {
        
        if(currentEmployee.loadFromBin(inputFile))
        {
                        
                currentEmployee.print();
                currentEmployee.print(outputFile);
            
           
        }
        
    }
    std::cout<<"-------------------------------------\n";

    inputFile.close();
    
    outputFile.close();

    return true;
}
int main()
{
    calculateSalaries("m.txt", "BudgetForSalaries.txt");
    convertTextToBin("Employee.txt", "a.bin");
    convertTextToBin("m.txt","less.bin");
    binToText("a.bin","salaries.txt");
    filterFromBin("less.bin", "LessThan20Hours.txt");

    return 0;
}
