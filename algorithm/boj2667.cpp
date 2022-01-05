#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char map [26][26];
bool visit [26][26];
int cnt = 0;
vector<int>v;
void dfs(int x, int y){
    if(visit[x][y] == true || map[x][y] == '0')return;
    visit[x][y] = true;
    cnt++;
    if(map[x+1][y] == '1')dfs(x+1, y);
    if(map[x][y+1] == '1')dfs(x, y+1);
    if(map[x-1][y] == '1')dfs(x-1, y);
    if(map[x][y-1] == '1')dfs(x, y-1);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dfs(i, j);
            if(cnt != 0)
            v.push_back(cnt);
            cnt = 0;
        }
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<'\n';
}
