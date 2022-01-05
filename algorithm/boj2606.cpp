#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int cnt = 0;
bool visit[101];
vector<int>v[101];
void bfs(int start){
    queue<int>q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y] = true;
                cnt++;
        }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    while(M--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    cout<<cnt<<'\n';
}
