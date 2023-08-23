#include <iostream>
#include <chrono>
#include <string>
using namespace std;

string GenerateRandomString() {
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string resultString;
    resultString.reserve(1000000000);

    for (int i = 0; i < 1000000000; ++i) {
        resultString += alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    
    return resultString;
}

void BranchConverter(string& s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
}

void BranchlessConverter(string& s)
{
    for(int i = 0; i < s.size(); i++)
    {
        s[i] -= 32 * (s[i] >= 'a' && s[i] <= 'z');
    }
}

int main()
{
    {
        cout << "1. Convert with Branch\n";
        string testString = GenerateRandomString();
        auto start = chrono::system_clock::now();

        BranchConverter(testString);

        auto end = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << duration.count() << "\n ============================\n";
    }

    {
        cout << "2. Convert with Branchless\n";
        string testString = GenerateRandomString();
        auto start = chrono::system_clock::now();

        BranchlessConverter(testString);

        auto end = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << duration.count() << "\n ============================\n";
    }
}