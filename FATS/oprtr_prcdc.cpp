#include <iostream>
#include <string>
#include <vector>

void f()
{
    std::cout << "Not operator grammar" << std::endl;
    exit(0);
}

int main()
{
    std::vector<std::string> grm;
    char c;
    int n, flag = 0;

    std::cout << "Enter the number of productions: ";
    std::cin >> n;
    std::cin.ignore();

    std::cout << "Enter the productions:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::string production;
        std::getline(std::cin, production);
        grm.push_back(production);
    }

    for (const std::string& production : grm)
    {
        c = production[2];

        int j = 3;
        while (c != '\0')
        {
            if (production[j] == '+' || production[j] == '-' || production[j] == '*' || production[j] == '/')
                flag = 1;
            else
            {
                flag = 0;
                f();
            }

            if (c == '$')
            {
                flag = 0;
                f();
            }

            c = production[++j];
        }
    }

    if (flag == 1)
        std::cout << "Operator grammar" << std::endl;

    return 0;
}
