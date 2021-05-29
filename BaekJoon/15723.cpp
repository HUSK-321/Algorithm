#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
char inputFrom, inputTo;
bool alphabet[27][27];
string isTemp;

void Floyd(){
    for(int via = 1; via <= 26; via++){
        for(int to = 1; to <= 26; to++){
            if(!alphabet[via][to])
                continue;

            for(int from = 1; from <= 26; from++){
                if(!alphabet[from][via])
                    continue;
                
                if(alphabet[via][to] == true && alphabet[from][via] == true)
                    alphabet[from][to] = true;
                if(alphabet[via][to] == false && alphabet[from][via] == false)
                    alphabet[from][to] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    // a - 97
    while(n--){
        cin >> inputFrom >> isTemp >> inputTo;
        alphabet[inputFrom - 96][inputTo - 96] = true;
        alphabet[inputTo - 96][inputFrom - 96] = false;
    }

    Floyd();

    cin >> m;
    while (m--){
        cin >> inputFrom >> isTemp >> inputTo;
        if(alphabet[inputFrom - 96][inputTo - 96])
            printf("T\n");
        else
            printf("F\n");
    }
    
    
}