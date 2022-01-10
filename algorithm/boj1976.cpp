#include <iostream>
#include <vector>
#define MAX 201
using namespace std;
int city[MAX];
int N, M;
vector<int> v;
int getperent(int parent[], int x){
    if(parent[x] == x)return x;
    return parent[x] = getperent(parent, parent[x]);
}

void unionParent(int parent[], int x, int y){
    int a = getperent(parent, x);
    int b = getperent(parent, y);
    if(a < b)parent[b] = a;
    else parent[a] = b;
}

bool isTravel(){
    int check = city[v[0]];
    for(int i = 0; i < v.size(); i++){
        if(city[v[i]] != check)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>> N >> M;
    
    for(int i = 1; i <= N; i++){
        city[i] = i;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int temp;
            cin>>temp;
            if(temp == 1){
                unionParent(city, i, j);
            }
        }
    }
    for(int i = 0; i < M; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    if(isTravel())cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    
}
