// Encryption and Decryption
#include <bits/stdc++.h>
using namespace std;
string encryptRailFence(string text, int key)
{
    char rail[key][(text.length())];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++)
    {
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        rail[row][col++] = text[i];
        dir_down ? row++ : row--;
    }
    string result;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);

    return result;
}

string decryptRailFence(string cipher, int key)
{
    char rail[key][cipher.length()];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            rail[i][j] = '\n';
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;
        rail[row][col++] = '*';
        dir_down ? row++ : row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];
    string result;
    row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
        dir_down ? row++ : row--;
    }
    return result;
}
string stringToBinaryAscii(string const &str)
{
    string binary = "";
    for (char const &c : str)
    {
        binary += bitset<8>(c).to_string();
    }
    return binary;
}
int binaryToDecimal(string n)
{
    string num = n;

    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

string setStringtoASCII(string str)
{
    int N = int(str.size());
    if (N % 8 != 0)
    {
        return "Not Possible!";
    }
    string res = "";
    for (int i = 0; i < N; i += 8)
    {
        int decimal_value = binaryToDecimal((str.substr(i, 8)));
        res += char(decimal_value);
    }

    return res;
}
int main()
{
    string s;
    cout << "Enter the text" << endl;
    getline(cin, s);
    int k = s.length();
    k = k * 8;
    k = sqrt(k);
    string e = stringToBinaryAscii(s);
    string s1 = encryptRailFence(e, k);
    string s3 = setStringtoASCII(s1);
    cout << "Encrypted text: ";
    cout << s3 << endl;

    string d = stringToBinaryAscii(s3);
    string s2 = decryptRailFence(d, k);
    cout << "Decrypted text: ";
    cout << setStringtoASCII(s2);

    return 0;
}