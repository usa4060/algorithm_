#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 100001;

int N, M;
int dis[MAX];
bool visit[MAX];

int dx[3] = {-1, 1, 0};


bool isInclude(int x){
    if(x > MAX - 1 || x < 0)return false;
    return true;
}


void bfs(int start, int dest){
    
    if(start == dest)return;
    
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(isInclude(x-1) && !visit[x-1]){
            q.push(x-1);
            visit[x-1] = true;
            dis[x-1] = dis[x]+1;
        }
        
        if(isInclude(x+1) && !visit[x+1]){
            q.push(x+1);
            visit[x+1] = true;
            dis[x+1] = dis[x]+1;
        }
        
        if(isInclude(x*2) && !visit[x*2]){
            q.push(x*2);
            visit[x*2] = true;
            dis[x*2] = dis[x]+1;
        }
    }
    
}

void init(){
    for(int i = 0; i < MAX; i++){
        memset(dis, 0, sizeof(dis));
        memset(visit, false, sizeof(visit));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    
    cin>>N>>M;
    bfs(N, M);
    cout<<dis[M]<<'\n';
    
    return 0;
}
