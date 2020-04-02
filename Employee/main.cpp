#include "Employee.cpp"
#include<fstream>
#include<iostream>

void textToBin(const char *inputFile, const char *outputFile)
{
    std::ifstream input(inputFile, std::ios::in);
    if (!input.is_open())
    {
        std::cout << "The input file: " << inputFile << " can't be openen!\n";
        return;
    }
    std::ofstream output(outputFile, std::ios::out | std::ios::binary);
    if (!output.is_open())
    {
        std::cout << "The output file: " << outputFile << " can't be openen!\n";
        return;
    }
    while (input)
    {
        Employee currentEmployee;
        if (currentEmployee.read(input))
        {
            currentEmployee.print();
            currentEmployee.storeInBin(output);
        }
    }
    input.close();
    output.close();
}

double generateSalaries(const char *inputFile, const char *outputFile)
{
    std::ifstream input(inputFile, std::ios::in | std::ios::binary);
    if (!input.is_open())
    {
        std::cout << "The input file: " << inputFile << " can't be openen!\n";
        return 0;
    }
    std::ofstream output(outputFile, std::ios::out);
    if (!output.is_open())
    {
        std::cout << "The output file: " << outputFile << " can't be openen!\n";
        return 0;
    }
    double totalSalaries = 0;
    while (input)
    {
        Employee currentEmploy;
        if (currentEmploy.loadFromBin(input))
        {
            double currentSalary = currentEmploy.getHourSalary() * currentEmploy.getWorktime();
            output << currentEmploy.getName() << '\t' << currentSalary << '\n';
            totalSalaries += currentSalary;
        }
    }

    return totalSalaries;
}

int main()
{
    textToBin("m.txt","Employ.txt");

    return 0;
}