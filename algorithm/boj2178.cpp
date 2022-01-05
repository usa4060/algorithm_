#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
const int MAX = 102;

bool visit[MAX+2][MAX];
int map[MAX+2][MAX];
int dis[MAX+2][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y){
    queue<pair<int, int>>q;
    q.push(make_pair(x, y));    // 좌표 자체를 pair로 만들어서 queue에 넣어준다
    visit[x][y] = true;
    dis[x][y] = 1;
    
    while(!q.empty()){
        int new_x = q.front().first;
        int new_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int X = new_x+dx[i];
            int Y = new_y+dy[i];
            if(map[X][Y] == 1 && !visit[X][Y]){
                visit[X][Y] = true;
                dis[X][Y] = dis[new_x][new_y]+1;
                q.push(make_pair(X, Y));
            }
        }
    }
    cout<<dis[N][M]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char temp;
            cin>>temp;
            map[i][j] = temp - '0';
        }
    }
    bfs(1, 1);
}
