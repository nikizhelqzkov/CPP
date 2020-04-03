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
    while(inputFile)
    {
        if(currentEmployee.loadFromBin(inputFile))
        {
            if(currentEmployee.getWorktime() < 20.0)
            {
                currentEmployee.print(outputFile);
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return true;
}

int main()
{
    //calculateSalaries("m.txt", "BudgetForSalaries.txt");
    //convertTextToBin("m.txt", "Employees.bin");
    //filterFromBin("Employees.bin", "LessThan20Hours.txt");

    return 0;
}
