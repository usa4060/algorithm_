#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, V;
stack<int>s;
vector<int>v[1001];
bool visit_dfs[1001];
bool visit_bfs[1001];
void bfs(int start){
    queue<int>q;
    q.push(start);
    visit_bfs[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<< x << ' ';
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(!visit_bfs[y]){
                q.push(y);
                visit_bfs[y]=true;
            }
        }
    }
}

void dfs(int start){
    if(visit_dfs[start])return;
    visit_dfs[start] = true;
    cout<<start<<' ';
    for(int i = 0; i <v[start].size(); i++){
        int y = v[start][i];
        dfs(y);
    }
}



int main(){
    cin>>N>>M>>V;
    for(int i = 0; i < M; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        sort(v[i].begin(), v[i].end());
    }
    dfs(V);
    cout<<'\n';
    bfs(V);
    return 0;
}
