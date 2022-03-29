#include <iostream>
#include <vector>
using namespace std;

const int MAX = 301;
const int MAXDIST = 2000001;
int friends[MAX][MAX];
pair<int, int> line[MAX];
int n, q;

bool SameLine(const pair<int, int>& a, const pair<int, int> b){
    if(a.first > b.second || a.second < b.first)
        return false;
    return true;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            friends[i][j] = MAXDIST;
    
    for(int i = 1; i <= n; i++){
        int left, right;    cin >> left >> right;
        line[i] = {left, right};
        friends[i][i] = 0;
    }

    // make friend
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == j)  continue;

            if(SameLine(line[i], line[j])){
                friends[i][j] = 1;
                friends[j][i] = 1;
            }
        }
    }

    // floyid
    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            if(friends[from][via] == MAXDIST)   continue;

            for(int to = 1; to <= n; to++){
                if(friends[from][to] > friends[from][via] + friends[via][to])
                    friends[from][to] = friends[from][via] + friends[via][to];
            }
        }
    }

    // make answer vector
    vector<int> answers;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;   cin >> a >> b;

        if(friends[a][b] == MAXDIST)
            answers.push_back(-1);
        else
            answers.push_back(friends[a][b]);
    }

    // print
    for(int i = 0; i < q; i++){
        cout << answers[i] << '\n';
    }
    
}