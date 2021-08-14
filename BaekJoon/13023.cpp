#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> relation[2001];
bool visit[2001];
bool haveAnswer = false;

void Search(int cur, int count){
    visit[cur] = true;

    if(count == 4){
        haveAnswer = true;
        return;
    }

    for(int i = 0; i < relation[cur].size(); i++){
        if(!visit[relation[cur][i]])
            Search(relation[cur][i], count + 1);
            
    }
    
    visit[cur] = false;
}

int main(){
    // init 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        Search(i, 0);

        if(haveAnswer){
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}