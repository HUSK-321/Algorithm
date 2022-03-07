#include <iostream>
#include <vector>
using namespace std;

int n, m;  // number of people, partys
int truthCount;
int group[51];  // 2 : know truth, 1 : heard lie, 0 : first party
vector<int> partyList[51];
vector<int> truthList;

int FindGroup(int x){
    if(group[x] == x)
        return x;
    return group[x] = FindGroup(group[x]);
}

bool isSameGroup(int x, int y){
    x = FindGroup(x);
    y = FindGroup(y);

    if(x == y)
        return true;
    return false;
}

void Merge(int x, int y){
    x = FindGroup(x);
    y = FindGroup(y);

    group[x] = y;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 51; i++)
        group[i] = i;

    // input
    cin >> n >> m;
    cin >> truthCount;
    for(int i = 0; i < truthCount; i++){
        int input;  cin >> input;
        truthList.push_back(input);
    }

    // input party
    for(int party = 0; party < m; party++){
        int peopleCount;    cin >> peopleCount;

        for(int i = 0; i < peopleCount; i++){
            int people; cin >> people;

            partyList[party].push_back(people);
        }
    }

    // Union Group
    
    for(int i = 0; i < m; i++){
        int firstMan = partyList[i][0];
        for(int j = 1; j < partyList[i].size(); j++){
            int secondMan = partyList[i][j];
            Merge(firstMan, secondMan);
        }
    }

    // solve
    int answer = m;
    for(int i = 0; i < m; i++){
        bool isTruthParty = false;

        for(int j = 0; j < partyList[i].size(); j++){
            if(isTruthParty)
                break;

            int present = partyList[i][j];
            for(int k = 0; k < truthList.size(); k++){
                if(isSameGroup(present, truthList[k])){
                    isTruthParty = true;
                    break;
                }
            }
        }

        if(isTruthParty)    
            answer--;
    }

    // output
    cout << answer << '\n';
}