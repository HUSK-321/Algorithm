#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int numX[10];
int numY[10];

string solution(string X, string Y) {
    string answer = "";
    
    for(int i = 0; i < X.size(); i++)
    {
        numX[X[i] - '0']++;
    }
    for(int i = 0; i < Y.size(); i++)
    {
        numY[Y[i] - '0']++;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        int minCount = min(numX[i], numY[i]);
        while(minCount--)
        {
            answer += static_cast<char>(i + '0');
        }
    }
    
    if(answer == "")
    {
        return "-1";
    }
    if(answer[0] == '0')
    {
        return "0";
    }
    return answer;
}