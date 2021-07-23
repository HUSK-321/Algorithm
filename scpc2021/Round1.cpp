#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int Answer;
int T, test_case, num;
int people[100001];
bool visit[100001];

void WhoIsFriend(int x){
    if(!visit[x]){
        // 방문 체크
        visit[x] = true;
        int next = people[x];
        // 다음이 자기 자신
        if(x == next){
            Answer++;
            return;
        }
        // 다음이 이미 방문한곳 -> 체크 되어있음

    } else {
        return;
    }
}

int main(){
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++){
		Answer = 0;
        // 사람 수
		cin >> num;
        memset(people, 0, (num + 2)*sizeof(int));
        memset(visit, false, (num + 2)*sizeof(bool));

        // 배열에 사람 저장
        for(int i = 1; i <= num; i++){
            cin >> people[i];
            // i + input = who is friend;
            people[i] += i;
            if(people[i] > num)
                people[i] = i;
        }
        // 친구 연결 알고리즘
        for(int i = 1; i <= num; i++)
            WhoIsFriend(i);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}