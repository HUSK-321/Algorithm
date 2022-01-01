#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int change_cost[1001][1001];

int main(){
    string from_string, to_string;
    cin >> from_string >> to_string;

    for(int i = 0; i <= from_string.length(); i++)
        change_cost[i][0] = i;
    for(int i = 0; i <= to_string.length(); i++)
        change_cost[0][i] = i;
    
    for(int from = 1; from <= from_string.length(); from++){
        for(int to = 1; to <= to_string.length(); to++){

            if(from_string[from-1] == to_string[to-1]){
                change_cost[from][to] = change_cost[from-1][to-1];
            }
            else{
                change_cost[from][to] = 
                    min(change_cost[from-1][to-1], min(change_cost[from-1][to], change_cost[from][to-1])) + 1;

            }

        }
    }

    cout << change_cost[from_string.length()][to_string.length()] << endl;
    
}