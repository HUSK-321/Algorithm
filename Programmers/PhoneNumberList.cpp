#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> numbers;

    for(int i = 0; i < phone_book.size(); i++){
        numbers[phone_book[i]] = 1;
    }

    for(int i = 0; i < phone_book.size(); i++){
        string prefix = "";
        for(int j = 0; j < phone_book[i].size(); j++){
            prefix += phone_book[i][j];
            if(numbers[prefix] && prefix != phone_book[i])
                return false;
        }
    }

    return true;
}