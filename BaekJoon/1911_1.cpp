#include <iostream>
using namespace std;

int n; // 노드의 갯수
char node[30][3];
int point[30];

void PreOrder(int root){
    // 노드 출력 - 0 > 왼자식 - 1 > 오른자식 - 2
    printf("%c", node[root][0]);
    if(node[root][1] != '.')
        PreOrder(point[node[root][1] - 'A']);
    if(node[root][2] != '.')
        PreOrder(point[node[root][2] - 'A']);
}

void InOrder(int root){
    // 왼자식 - 1 > 노드 출력 - 0 > 오른자식 - 2
    if(node[root][1] != '.')
        InOrder(point[node[root][1] - 'A']);
    printf("%c", node[root][0]);
    if(node[root][2] != '.')
        InOrder(point[node[root][2] - 'A']);
}

void PostOrder(int root){
    // 왼자식 - 1 >  오른자식 - 2 > 노드 출력 - 0
    if(node[root][1] != '.')
        PostOrder(point[node[root][1] - 'A']);
    if(node[root][2] != '.')
        PostOrder(point[node[root][2] - 'A']);
    printf("%c", node[root][0]);
}


int main(){
    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%c", node[i][j]);
        }
        point[node[i][0] - 'A'] = i;
    }
    // 출력 : 전위 / 중위 / 후위
    PreOrder(0);
    printf("\n");
    InOrder(0);
    printf("\n");
    PostOrder(0);
    printf("\n");
}