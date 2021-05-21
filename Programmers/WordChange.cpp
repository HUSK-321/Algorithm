#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[51];
int ans = 100;

bool CanChange(string a, string b){
    int res = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
            res++;
    }
    
    if(res == 1)
        return true;
    else
        return false;
}

void DFS(string start, string end, int count, vector<string>& words){
    for(int i = 0; i < words.size(); i++){
        if(CanChange(start, words[i])){
            if(words[i] == end){
                ans = min(ans, count + 1);
                return;
            }
            
            if(!visit[i]){
                visit[i] = true;
                DFS(words[i], end, count + 1, words);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    DFS(begin, target, 0, words);
    
    if(ans == 100)
        ans = 0;
    return ans;
}