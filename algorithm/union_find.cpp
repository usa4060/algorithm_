#include <iostream>
using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x)return x; // 노드의 부모가 자기 자신이면 최상위 라는 의미
    return parent[x] =getParent(parent, parent[x]); // 최상위 부모를 모든 자식 노드에 기록
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);   // a와 b의 최상위 부모값을 구한다.
    if(a < b)parent[b] = a;
    else parent[a] = b; // a와 b의 크기를 비교하여 더 작은값의 부모를 큰 값의 부모로 넣는다.
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b)return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int parent[11];
    for(int i = 1; i <= 10; i++){
        parent[i] = i;
    }
    
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 1, 2);
    unionParent(parent, 3, 5);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    cout<< "1과 5는 연결되어있나요? "<<findParent(parent, 1, 5)<<'\n';
}
