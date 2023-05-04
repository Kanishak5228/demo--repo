#include <iostream>
#include <string>

class Player {
private:
    int playerNo;
    std::string name;
    int numMatches;
    int* goals;

public:
    Player(int pNo, std::string pname, int numM) {
        playerNo = pNo;
        name = pname;
        numMatches = numM;
        goals = new int[numMatches];

        std::cout << "Enter the number of goals scored in each match for player " << playerNo << ": " << std::endl;
        for(int i = 0; i < numMatches; i++) {
            std::cout << "Match " << i+1 << ": ";
            std::cin >> goals[i];
        }
    }

    ~Player() {
        delete[] goals;
    }

    void displayInfo() {
        std::cout << "Player Number: " << playerNo << std::endl;
        std::cout << "Player Name: " << name << std::endl;
        std::cout << "Number of Matches: " << numMatches << std::endl;
        std::cout << "Goals Scored in Each Match: " << std::endl;
        for(int i = 0; i < numMatches; i++) {
            std::cout << "Match " << i+1 << ": " << goals[i] << std::endl;
        }
    }
};

int main() {
    Player player1(1, "John Doe", 5);
    player1.displayInfo();
    return 0;
}
