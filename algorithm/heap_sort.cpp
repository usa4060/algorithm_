#include <iostream>
using namespace std;

int num = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
// 1 3 5 5 6 6 7 8 9
int main(){
    for(int i = 1; i < num; i++){
        int c = i;
        do {
            int root = (c - 1) / 2;
            if(heap[root] < heap[c]){
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            // parent와 child2개의 값을 비교해서 parent의 값이 가장 큰 값을 갖게 하는 과정
            c = root; // 계속 위의 heap으로 올라가는 과정
        } while (c != 0);
    }
    for(int i = 0; i < num; i++){
        cout << heap[i] << " ";
    }
    cout<<"\n";
    for(int i = num - 1; i >= 0; i--){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        // 현재 root의 위치에는 heap의 최댓값이 있는 상황.
        // 따라서 root의 값을 heap[마지막위치]의 값과 교체를 하고,
        // size를 1 줄이고, root에 다시 최댓값이 오는 과정을 실행해서, 이를 반복해야 함
        int root = 0;
        int c = 1;
        do {
            c = 2*root + 1;
            if(c < i-1 && heap[c] < heap[c + 1]) // child 중에서 큰 값을 찾는 과정
                c++; // -> child중 큰 값의 heap을 고를 수 있도록 index를 조정하는 과정
            if(c < i && heap[root] < heap[c]){
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
                // root의 값과 child중 큰 값을 비교하여 큰 값이 root에 오도록 이동
            }
            // 이렇게 할 수 있는 이유는, node3개로 이루어진 sub-heap에서는 항상
            // 큰 값이 root의 값임을 보장하기 때문이다.
            root = c;
            // heap[c]의 값이 변경 되었기 때문에, 해당 c를 root로 하는 sub-heap의 값을
            // 다시 확인해 줘야하므로 root의 값에 변경된 c의 값을 넣어서
            // 해당 값을 root로 하여 다시 확인한다.
        } while (c < i);
    }
    
    for(int i = 0; i < num; i++){
        cout << heap[i] << " ";
    }
    cout<<"\n";
}
