#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;

    vector<int> range(200); // index 0 -> -100

    for(int i = 0; i < lines.size(); i++){
        int start{ min(lines[i][0], lines[i][1]) };
        int end{ max(lines[i][0], lines[i][1]) };
        for(int j = start; j < end; j++){
            range[j + 100]++;
        }
    }

    for(int i = 0; i < range.size(); i++)
        if(range[i] > 1)
            answer++;

    return answer;
}