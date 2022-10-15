#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
int numberOfComputer, numberOfEdge;
vector<int> edge[MAX];
bool visit[MAX];
int count = 0;

void SearchComputer(int curCom){
    visit[curCom] = true;

    for(int i = 0; i < edge[curCom].size(); i++){
        auto nextCom = edge[curCom][i];
        
        if(visit[nextCom])  continue;
        SearchComputer(nextCom);
        count++;
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> numberOfComputer;
    cin >> numberOfEdge;
    for(int i = 0; i < numberOfEdge; i++){
        int from, to;
        cin >> from >> to;

        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    SearchComputer(1);
    cout << count << '\n';
}