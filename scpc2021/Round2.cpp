#include <iostream>
#include <vector>
using namespace std;

int Answer;
bool node[501];
vector<pair<int, int>> edge; // first -> second 라는 뜻
vector<pair<int, int>> NDedge; // 방향이 없음

int n, m, k;

void Solution(){
    
}

int main(int argc, char** argv){
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
        cin >> n >> m >> k;
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            edge.push_back(make_pair(x, y));
        }
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            NDedge.push_back(make_pair(x, y));
        }
		Answer = 0;
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}