#include <iostream>
#include <string>

using namespace std;

string xorString(const string& a, const string& b)
{
    string result = "";
    int n = b.length();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string calculateCRC(const string& dividend, const string& divisor)
{
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    int n = dividend.length();
    while (pick < n)
    {
        if (tmp[0] == '1')
            tmp = xorString(divisor, tmp) + dividend[pick];
        else
            tmp = xorString(string(pick, '0'), tmp) + dividend[pick];
        pick += 1;
    }
    if (tmp[0] == '1')
        tmp = xorString(divisor, tmp);
    else
        tmp = xorString(string(pick, '0'), tmp);
    return tmp;
}

void encodeData(const string& data, const string& key)
{
    int l_key = key.length();
    string appended_data = (data + string(l_key - 1, '0'));
    string remainder = calculateCRC(appended_data, key);
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder): " << codeword << "\n";
}

int main()
{
    string data = "100100";
    string key = "1101";
    cout << "Sender side...\n";
    encodeData(data, key);
    return 0;
}