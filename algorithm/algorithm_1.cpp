#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int>member[50000];       // 정방향 그래프
vector<int>member_inv[50000];   // 역방향 그래프
stack<int>num;
int N, M;           // N은 사용자의 수 , M은 팔로워의 수
int user, follow;   // user가 node역할, follow가 edge의 역할을 한다.
int numValue = 0;   // 역방향 그래프를 민들기 위한 stack구조
bool visit[50000];  // 방문 여부를 결정하는 배열

void dfs(int x){
    if(visit[x]){       // 해당 노드를 이미 방문했다는 의미미으로 바로 return
        num.push(x);    // return하기 전에 stack에 push해서 역방향 그래프의 순회 순서 준비
        return;
    }
    visit[x] = true;    // 해당 노드에는 아직 방문을 안했으므로, 해당 노드에 visit처리

    for(int i = 0; i < member[x].size(); i++){
        dfs(member[x][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    while(M--){
        cin>>user>>follow;
        member[user].push_back(follow);     // 정방향 그래프 생성
        member_inv[follow].push_back(user); // 역방향 그래프 생성
    }
    
    visit[1] = true;
    dfs(1);
}
