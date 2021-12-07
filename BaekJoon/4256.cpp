#include <iostream>
using namespace std;

int t, n;
int pre_order[1010];
int in_order[1010];
int in_order_index[1010];


void Find_PostOrder(int inorder_start, int inorder_end, int root_index){
    for(int i = inorder_start; i <= inorder_end; i++){
        if(in_order[i] == pre_order[root_index]){
            // search tree's left side
            Find_PostOrder(inorder_start, i-1, root_index+1);
            // seatch tree's right side
            Find_PostOrder(i+1, inorder_end, root_index + i + 1 - inorder_start);
            // print root
            cout << pre_order[root_index] << " ";
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        // input
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> pre_order[i];
        for(int i = 0; i < n; i++)
            cin >> in_order[i];

        Find_PostOrder(0, n-1, 0);
        cout << '\n';
    }
    
}