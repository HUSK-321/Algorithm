#include <iostream>
using namespace std;

int n, m;
int cityGroup[201];

int FindGroup(int x){
    if(cityGroup[x] == x)
        return x;
    else return cityGroup[x] = FindGroup(cityGroup[x]);
}

void MergeGroup(int x, int y){
    x = FindGroup(x);
    y = FindGroup(y);

    if(x == y)    return;

    cityGroup[x] = y;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 201; i++)
        cityGroup[i] = i;

    // input
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int isConnect;
            cin >> isConnect;

            if(i == j)  continue;

            if(isConnect)
                MergeGroup(i, j);
        }
    }

    // search trip
    int group, country;

    cin >> country;
    group = FindGroup(country);
    for(int i = 1; i < m; i++){
        int nextCountry;
        cin >> nextCountry; 

        if(group != FindGroup(nextCountry)){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}