#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> wantMap;
    for(int i = 0; i < number.size(); i++)
        wantMap.insert({want[i], number[i]});
    
    for(int i = 0; i <= discount.size() - 10; i++){
        unordered_map<string, int> martDiscount;
        for(int j = i; j < i + 10; j++){
            martDiscount[discount[j]] += 1;
        }
        if(martDiscount == wantMap)
            answer++;
    }

    return answer;
}