#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 20001
using namespace std;
int K, V, E, u, v;
vector<int>graph[MAX];
bool visit[MAX];
bool save_color[MAX];

void bfs(int start){
    queue<pair<int, bool>>q; // 연결된 노드와, 해당 노드의 노드색 지정
    q.push(make_pair(start, save_color[start]));
    visit[q.front().first] = true;
    while(!q.empty()){
        int x = q.front().first;
        bool color = q.front().second;
        for(int i = 0; i < graph[x].size(); i++){
            if(!visit[graph[x][i]]){
                visit[graph[x][i]] = true;
                q.push(make_pair(graph[x][i], !color));
                save_color[graph[x][i]] = !color;
            }
        }
        q.pop();
    }
    
    
}

bool isBiparit(){
    for(int i = 1; i <= V; i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(save_color[i] == save_color[graph[i][j]]){
                return false;
            }
        }
    }
    return true;
}

void init(){
    for(int i = 0; i < MAX; i++){
        memset(visit, false, sizeof(visit));
        memset(save_color, false, sizeof(save_color));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>K;
    while(K--){
        
        init();
        cin>>V>>E;
        while(E--){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i <= V; i++){
            bfs(i);
        }
        if(isBiparit())cout<<"YES"<<'\n';
        else cout<< "NO"<<'\n';
        
        
        for(int i = 0; i < MAX; i++){
            graph[i].clear();
        }
    }
}
