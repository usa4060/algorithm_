#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
# define MAX 1002
int map[MAX][MAX];
int dis[MAX][MAX][2];
int N,M;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
using namespace std;



int bfs(){
    queue<pair<pair<int, int>,int>>q;
    q.push(make_pair(make_pair(1, 1),1)); // 1 => 아직 벽 안뿌숨
    dis[1][1][1] = 1; // [][][1] ==> 벽뚫기 가능
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int canBreak = q.front().second;
        q.pop();
        
        if(x == N && y == M)return dis[x][y][canBreak];
        
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            
            // 벽을 만난다면?
            if(map[nx][ny] == 1 && canBreak){
                dis[nx][ny][canBreak-1] = dis[x][y][canBreak] + 1;
                q.push(make_pair(make_pair(nx, ny),canBreak - 1));
            }
            // 벽이 아닌 곳을 만난다면?
            else if(map[nx][ny] == 0 && dis[nx][ny][canBreak] == 0){
                dis[nx][ny][canBreak] = dis[x][y][canBreak] + 1;
                q.push(make_pair(make_pair(nx, ny),canBreak));
            }
        }
    }
    
    return -1;
}

void init(){
    for(int i = 0; i < MAX; i++){
            memset(map[i], -1, sizeof(map[i]));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    cin>>N>>M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char temp;
            cin>> temp;
            map[i][j] = temp-'0';
        }
    }   // map 구성
    int ans = bfs();
    
    cout<<ans<<'\n';
    return 0;
}
