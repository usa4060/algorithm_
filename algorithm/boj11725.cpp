#include<iostream>
#include<vector>
#define MAX 100001
using namespace std;
int N;
int arr[MAX];
bool visit[MAX];
vector<int>v[MAX];

void dfs(int start){
    if(visit[start])return;
    visit[start] = true;
    for(int i = 0; i < v[start].size(); i++){
        if(!visit[v[start][i]]){
            arr[v[start][i]] = start;
            dfs(v[start][i]);
        }
    }
}

int main(){
    ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int x,y;
    cin>>N;
    for(int i = 1; i < N; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i = 2; i <= N; i++){
        cout<<arr[i]<<'\n';
    }
    
}
