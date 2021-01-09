#include <iostream>
#include <algorithm>
using namespace std;
string st;
bool isball[3] = {true, false, false};
int main(){
    cin >> st;
    // 문자열이 배열인 것을 이용해 풀이
    // 입력받은 값 전부 스캔해서 하나하나 실행
    // 따로 함수를 만드는 것보다 편할 것 같다
    for(int i = 0; i < st.size(); i++){
        switch (st[i]){
            case 'A':
                swap(isball[0], isball[1]);
                break;
            case 'B':
                swap(isball[1], isball[2]);
                break;
            case 'C':
                swap(isball[0], isball[2]);
                break;
        }
    }

    for(int i = 0; i < 3; i++){
        if(isball[i] == true)
            printf("%d\n", i+1);
    }

}