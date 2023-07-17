#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Instruction {
 string result;
 string op;
 string arg1;
 string arg2;
};
vector<Instruction> generateInstructions(const string& expr) {
 vector<Instruction> code;
 int tempCount = 1;
 int index = 0;
 auto generateTemp = [&]() {
 return "t" + to_string(tempCount++);
 };
 auto getNextToken = [&](string& token) {
 token = expr.substr(index, 1);
 index++;
 };
 auto generateInstruction = [&](const string& res, const string& oper, const string& arg1, const
string& arg2) {
 code.push_back({ res, oper, arg1, arg2 });
 };
 string token;
 getNextToken(token);
 auto processTerm = [&]() {
 string termToken = token;
 getNextToken(token);
 while (token == "*" || token == "/") {
 string opToken = token;
 getNextToken(token);
 string factorToken = token;
 getNextToken(token);
 string tempRes = generateTemp();
 generateInstruction(tempRes, opToken, termToken, factorToken);
 termToken = tempRes;
 }
 return termToken;
 };
 string factorToken = processTerm();
 while (token == "+" || token == "-") {
 string opToken = token;
 getNextToken(token);
 string termToken = processTerm();
 string tempRes = generateTemp();
 generateInstruction(tempRes, opToken, factorToken, termToken);
 factorToken = tempRes;
 }
 return code;
}
void printInstructions(const vector<Instruction>& code) {
 cout << "Three Address Code:" << endl;
 for (const auto& inst : code) {
 cout << inst.result << " = ";
 if (inst.arg2.empty()) {
 cout << inst.op << " " << inst.arg1 << endl;
 } else {
 cout << inst.arg1 << " " << inst.op << " " << inst.arg2 << endl;
 }
 }
}
int main() {
 string expr;
 cout << "Enter the expression: ";
 getline(cin, expr);
 vector<Instruction> code = generateInstructions(expr);
 printInstructions(code);
 return 0;
}
