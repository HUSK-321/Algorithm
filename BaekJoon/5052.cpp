#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Trie
{
    bool bIsTerminal;
    Trie* Children[10];

    Trie()
    : bIsTerminal(false), Children()
    {}

    ~Trie()
    {
        delete [] Children;
    }

    void Insert(const string& InputNumber)
    {
        Trie* CurTrie = this;

        for(int i = 0; i < InputNumber.size(); i++)
        {
            if(CurTrie->Children[InputNumber[i] - '0'] == nullptr)
            {
                CurTrie->Children[InputNumber[i] - '0'] = new Trie();        
            }
            CurTrie = CurTrie->Children[InputNumber[i] - '0'];

            if(i == InputNumber.size() - 1)
            {
                CurTrie->bIsTerminal = true;
            }
        }
    }

    bool IsTherePrefix(const string& InputNumber)
    {
        Trie* CurTrie = this;

        for(int i = 0; i < InputNumber.size(); i++)
        {
            if(CurTrie->Children[InputNumber[i] - '0'] != nullptr)
            {
                CurTrie = CurTrie->Children[InputNumber[i] - '0'];
                if(CurTrie->bIsTerminal)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int TestCaseNum, PhoneNumberCount;

    cin >> TestCaseNum;

    while (TestCaseNum--)
    {
        cin >> PhoneNumberCount;
        vector<string> NumberList(PhoneNumberCount);
        for(int i = 0; i < PhoneNumberCount; i++)
        {
            cin >> NumberList[i];
        }

        sort(NumberList.begin(), NumberList.end());

        Trie* NumberTrie = new Trie();
        bool bNotConsistency = true;
        
        for(auto PhoneNumber : NumberList)
        {
            if(NumberTrie->IsTherePrefix(PhoneNumber))
            {
                bNotConsistency = false;
                break;
            }
            NumberTrie->Insert(PhoneNumber);
        }

        if(bNotConsistency)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
        delete NumberTrie;
    }
}