#include <iostream>
#include <unordered_map>
#include <string>

struct Symbol {
    std::string type;
    std::string scope;
};

int main()
{
    std::unordered_map<std::string, Symbol> symbolTable;

    std::cout << "Symbol Table\n";

    // Accept user input for symbol insertion
    while (true) {
        std::string name, type, scope;

        std::cout << "Enter symbol name (or 'exit' to finish): ";
        std::cin >> name;

        if (name == "exit") {
            break;
        }

        std::cout << "Enter symbol type: ";
        std::cin >> type;

        std::cout << "Enter symbol scope: ";
        std::cin >> scope;

        symbolTable[name] = { type, scope };
    }

    // Display the symbol table
    std::cout << "\nSymbol Table\n";
    std::cout << "Name \t\t Type \t\t Scope\n";
    for (const auto& entry : symbolTable) {
        std::cout << entry.first << " \t\t " << entry.second.type << " \t\t " << entry.second.scope << "\n";
    }

    return 0;
}


Enter symbol name (or 'exit' to finish): add
Enter symbol type: int
Enter symbol scope: global
Enter symbol name (or 'exit' to finish): a
Enter symbol type: int
Enter symbol scope: function parameter
Enter symbol name (or 'exit' to finish): b
Enter symbol type: int
Enter symbol scope: function parameter
Enter symbol name (or 'exit' to finish): sum
Enter symbol type: int
Enter symbol scope: local
Enter symbol name (or 'exit' to finish): exit
