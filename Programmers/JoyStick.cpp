#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


/*
알파벳은 65~90, 총 26개
처음에는 A로만 되어 있다
J = 74
A 에서 양 끝을 이동

하는 동작
위 : 다음 알차벳
아래 : 이전 알파벳 (A에서 아래로 가면 Z)
왼 : 커서를 왼쪽으로 이동 (처음 위치에서 커서시 마지막으로)
오 : 커서를 오른쪽으로 이동

- 현재 커서에서 글자를 왼성
- 왼, 오른쪽 중 이 문자와 더 근접합걸 찾기
- 이후 해당 글자를 맞추기


AㅁㅁㅁBㅁㅁㅁ
해당 글자가 있을 때 글자의 움직임은 쉽게 구할 수 있다 (해당 글자 -65 or 26 - (해당 글자 - 65))
좌우 움직임을 따로 구해주면 된다 (A가 많은 방향이 이득)


*/
int solution(string name) {
    int answer = 0;

    int length = name.length();

    // 각 글자별 상하 움직임
    for(int i = 0; i < length; i++)
        answer += min(name[i] - 65, 91 - name[i]);

    // 각 글자까지 가는데 좌우 움직임
    // 첫 글자는 움직이지 않는다
    int moveStick = length - 1;
    for(int i = 0; i < length; i++){
        int nextAlp = i + 1;
        while(nextAlp < length && name[nextAlp] == 'A'){
            nextAlp++;
        }
        moveStick = min(moveStick, i + (length - nextAlp) + min(i, length - nextAlp)); 
    }
    answer += moveStick;

    return answer;
}

int main(){
    cout << solution("ABBAAAABA");
}