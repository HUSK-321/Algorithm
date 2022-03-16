#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> firstAnswer = {1, 2, 3, 4, 5};
vector<int> secondAnswer = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thirdAnswer = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int first = 0, second = 0, third = 0;

    for(int i = 0; i < answer.size(); i++){
        if(firstAnswer[i%5] == answer[i])   first++;
        if(secondAnswer[i%8] == answer[i])  second++;
        if(thirdAnswer[i%10] == answer[i])  third++;
    }

    int highScore = max(first, max(second, third));

    if(first == highScore)  answer.push_back(1);
    if(second == highScore) answer.push_back(2);
    if(third == highScore)  answer.push_back(3);

    return answer;
}