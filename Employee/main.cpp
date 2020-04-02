#include "Employee.cpp"

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
        return;
    }
    std::
    if (!output.is_open())
    {
        std::cout << "The output file: " << outputFile << " can't be openen!\n";
        return;
    }
 
}

int main()
{
    Employee e;

    return 0;
}