#include <iostream>
#include <string>

// Function that returns true if str is a valid identifier
bool isValid(const std::string& str)
{
    // If first character is invalid
    if (!((str[0] >= 'a' && str[0] <= 'z')
        || (str[0] >= 'A' && str[0] <= 'Z')
        || str[0] == '_'))
        return false;

    // Traverse the string for the rest of the characters
    for (size_t i = 1; i < str.length(); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || str[i] == '_'))
            return false;
    }

    // String is a valid identifier
    return true;
}

int main()
{
    std::cout << "Enter an identifier: ";
    std::string str;
    std::getline(std::cin, str);

    if (isValid(str))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}
