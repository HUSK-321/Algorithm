#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
string pokemons[100001];
map<string, int> pokemon;
int main(){
    //init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string input;   cin >> input;
        pokemons[i] = input;
        pokemon[input] = i;
    }

    for(int i = 0; i < m; i++){
        string problem; cin >> problem;
        if(isdigit(problem[0])){
            cout << pokemons[stoi(problem)] << '\n';
        }
        else{
            cout << pokemon[problem] << '\n';
        }
    }
}