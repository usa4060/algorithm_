#include <iostream>
#include <queue>
#include <string.h>
#define MAX 301
bool visit[MAX][MAX];
int dis[MAX][MAX];
int T, I, s_x,s_y,f_x,f_y;
using namespace std;

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};


bool isInside(int y, int x){
    if(x >= 0 && y >= 0 && x < I && y < I)return true;
    return false;
}


void bfs(){
    queue<pair<int, int>>q;
    q.push(make_pair(s_y, s_x));
    if(q.front().first == f_y && q.front().second == f_x)return;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        for(int i = 0; i <8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(isInside(ny, nx)){
                if(!visit[ny][nx]){
                    q.push(make_pair(ny, nx));
                    visit[ny][nx] = true;
                    dis[ny][nx] = dis[y][x]+1;
                }
            }
        }
        q.pop();
    }
    
    
}


void init_all(){
    for(int i = 0; i < MAX; i++){
        memset(visit[i], false, sizeof(visit[i]));
        memset(dis[i], 0, sizeof(dis[i]));
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    while(T--){
        init_all();
        cin>>I;
        cin>>s_y>>s_x;
        cin>>f_y>>f_x;
        bfs();
        cout<<dis[f_y][f_x]<<'\n';
        
    }
}
