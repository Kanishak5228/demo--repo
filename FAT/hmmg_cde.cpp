#include <iostream>
#include <vector>

std::vector<int> hammingEncode(const std::vector<int>& data)
{
    std::vector<int> encodedData(7);
    encodedData[0] = data[0];
    encodedData[1] = data[1];
    encodedData[2] = data[2];
    encodedData[4] = data[3];
    encodedData[5] = data[4];
    encodedData[6] = data[5];
    encodedData[3] = encodedData[0] ^ encodedData[1] ^ encodedData[2];
    encodedData[4] ^= encodedData[0] ^ encodedData[2] ^ encodedData[6];
    encodedData[5] ^= encodedData[0] ^ encodedData[1] ^ encodedData[6];
    encodedData[6] ^= encodedData[1] ^ encodedData[2] ^ encodedData[6];
    return encodedData;
}

int hammingDecode(const std::vector<int>& receivedData)
{
    int c1 = receivedData[0] ^ receivedData[2] ^ receivedData[4] ^ receivedData[6];
    int c2 = receivedData[1] ^ receivedData[2] ^ receivedData[5] ^ receivedData[6];
    int c3 = receivedData[3] ^ receivedData[4] ^ receivedData[5] ^ receivedData[6];
    int c = c3 * 4 + c2 * 2 + c1;
    return c;
}

int main()
{
    std::cout << "Enter 4 bits of data one by one\n";
    std::vector<int> data(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> data[i];
    }

    std::vector<int> encodedData = hammingEncode(data);

    std::cout << "\nEncoded data is\n";
    for (int i = 0; i < 7; i++) {
        std::cout << encodedData[i];
    }

    std::cout << "\n\nEnter received data bits one by one\n";
    std::vector<int> receivedData(7);
    for (int i = 0; i < 7; i++) {
        std::cin >> receivedData[i];
    }

    int errorPosition = hammingDecode(receivedData);

    if (errorPosition == 0) {
        std::cout << "\nNo error while transmission of data\n";
    } else {
        std::cout << "\nError on position " << errorPosition;
        std::cout << "\nData sent: ";
        for (int i = 0; i < 7; i++) {
            std::cout << encodedData[i];
        }

        std::cout << "\nData received: ";
        for (int i = 0; i < 7; i++) {
            std::cout << receivedData[i];
        }

        std::cout << "\nCorrect message is\n";
        if (receivedData[7 - errorPosition] == 0) {
            receivedData[7 - errorPosition] = 1;
        } else {
            receivedData[7 - errorPosition] = 0;
        }

        for (int i = 0; i < 7; i++) {
            std::cout << receivedData[i];
        }
    }

    return 0;
}