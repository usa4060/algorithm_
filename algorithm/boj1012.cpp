#include <iostream>
#include <vector>
using namespace std;
const int MAX = 52;

int T, M, N, K;
int map[MAX][MAX];
bool visit[MAX][MAX];
bool ji = false;

void dfs(int x, int y){
    if(visit[x][y] || !map[x][y])return;
    ji = true;
    visit[x][y] = true;
    if(map[x+1][y] == 1)dfs(x+1,y);
    if(map[x][y+1] == 1)dfs(x,y+1);
    if(map[x-1][y] == 1)dfs(x-1,y);
    if(map[x][y-1] == 1)dfs(x,y-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    while(T--){
        cin>>M>>N>>K;
        int cnt = 0;
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                map[i][j] = 0;
                visit[i][j] = 0;
            }
        }
        // 초기화
        while(K--){
            int x, y;
            cin>>x>>y;
            map[y+1][x+1] = 1;
        }
        // map구성
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(map[i][j] == 1)
                dfs(i,j); // 세로 , 가로
                if(ji)cnt++;
                ji = false;
            }
        }
        // 지렁이 갯수 확인
        cout<<cnt<<'\n';
        cnt = 0;
    }
}
