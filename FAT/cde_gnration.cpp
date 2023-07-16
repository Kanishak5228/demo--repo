#include <iostream>
#include <string>

std::string generateCode(const std::string& expression) {
    std::string code = "int main() {\n";
    code += "    int result = " + expression + ";\n";
    code += "    std::cout << \"Result: \" << result << std::endl;\n";
    code += "    return 0;\n";
    code += "}\n";
    return code;
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    std::string code = generateCode(expression);
    std::cout << "Generated code:\n" << code << std::endl;

    return 0;
}
