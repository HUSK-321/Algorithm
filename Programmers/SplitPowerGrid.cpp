#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;
bool edges[MAX][MAX];
bool visit[MAX];

void ClearVisit(int _totalNum)
{
    for(int i = 1; i <= _totalNum; i++)
    {
        visit[i] = false;
    }
}

int GetConnectedCityNum(int _start, int _totalNum)
{
    if(visit[_start])   return 0;
    
    int cityCount = 1;
    visit[_start] = true;
    
    for(int i = 1; i <= _totalNum; i++)
    {
        if(!edges[_start][i])    continue;
        
        cityCount += GetConnectedCityNum(i, _totalNum);
    }
    return cityCount;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n + 1;
    
    for(int i = 0; i < wires.size(); i++)
    {
        const int from = wires[i][0];
        const int to = wires[i][1];
        
        edges[from][to] = true;
        edges[to][from] = true;
    }
    
    for(int i = 0; i < wires.size(); i++)
    {
        ClearVisit(n);
        const int from = wires[i][0];
        const int to = wires[i][1];
        
        edges[from][to] = false;
        edges[to][from] = false;
        
        // from city's number
        int firstSide = GetConnectedCityNum(from, n);
        
        if(visit[to])   continue;   // if still one tree
        // to city's number
        int otherSide = n - firstSide;
        
        // calculate the difference
        answer = min(answer, abs(firstSide - otherSide));
        
        edges[from][to] = true;
        edges[to][from] = true;
    }
    
    return answer;
}