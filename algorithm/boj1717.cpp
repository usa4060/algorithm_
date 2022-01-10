#include <iostream>
#include <string.h>
#define MAX 1000001
using namespace std;
int N, M;
int node[MAX];



int getParent(int parent[], int x){
    if(parent[x] ==  x)return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    int x = getParent(parent, a);
    int y = getParent(parent, b);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

void findParent(int parent[],int a, int b){
    int x = getParent(parent, a);
    int y = getParent(parent, b);
    if(x == y)cout<< "YES"<<'\n';
    else cout<<"NO"<<'\n';
}


int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++){
        node[i] = i;
    }
    cin>> N >> M;
    while(M--){
        
        int x, y ,z;
        cin>> x >> y >> z;
        if(x == 0){
            unionParent(node, y, z);
        }
        else{
            findParent(node, y, z);
        }
    }
}
