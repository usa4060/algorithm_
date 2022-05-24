#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int>member[50000];       // 정방향 그래프
vector<int>member_inv[50000];   // 역방향 그래프
stack<int>num;
int followers[50000] = {0,}; // 팔로워의 값을 저장하기 위한 변수
int N, M;           // N은 사용자의 수 , M은 팔로워의 수
int user, follow;   // user가 node역할, follow가 edge의 역할을 한다.
int numValue = 0;   // 역방향 그래프를 민들기 위한 stack구조
bool visit[50000];  // 방문 여부를 결정하는 배열

bool comp(pair<int, int> a, pair<int, int>b){   // DFS1에서 탐색하는 순서를 정해줌
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void dfs(int x){
    visit[x] = true;    // 해당 노드에는 아직 방문을 안했으므로, 해당 노드에 visit처리
    
    // 여기서 탐색 순서를 일반적으로 순서대로 하는 것이 아니라,
    // 1) 팔로워 크기 큰 순서 (follower[member[x][i]]의 크기)
    // 2) 번호가 작은 순서 (member[x][i]값의 크기)
    // 이 조건의 순서대로 비교해서 탐색을 진행한다.
    
    vector<pair<int, int>>expSeq; // 비교를 위해 팔로워 크기와, 번호 순서를 담을 임시 벡터 생성
    for(int i = 0; i < member[x].size(); i++){
        expSeq.push_back(make_pair(followers[member[x][i]], member[x][i]));
    }
    sort(expSeq.begin(), expSeq.end(), comp);   // dfs 탐색의 순서를 정함
    
    for(int i = 0; i < expSeq.size(); i++){
    if(visit[expSeq[i].second]) continue; // 마지막 정점에서 다시 cycle로 연결되는 것을 방지
    dfs(expSeq[i].second);
    }
    num.push(x);        // 해당 정점을 stack에 삽입
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    
    while(M--){
        cin>>user>>follow;
        followers[follow]++;
        member[user].push_back(follow);     // 정방향 그래프 생성
        member_inv[follow].push_back(user); // 역방향 그래프 생성
    }
    
    // 탐색을 최초 시작할 때에도, 팔로워 숫자 및 작은 넘버를 기준으로 탐색을 시작 해야한다.
    vector<pair<int, int>>expSeq; // 비교를 위해 팔로워 크기와, 번호 순서를 담을 임시 벡터 생성
    for(int i = 0; i < N; i++){
        expSeq.push_back(make_pair(followers[i], i));
    }
    sort(expSeq.begin(), expSeq.end(), comp);   // dfs 탐색의 순서를 정함
    
    for(int i = 0; i < expSeq.size(); i++){
        if(visit[i])continue;
        dfs(expSeq[i].second);
        // 조건에 맞춰서 dfs 탐색을 하며 stack에 쌓이게된다.
        // 이 때, 이미 방문했으면 continue를 통해 건너뛰기한다
        // 이후 stack의 top부터 하나씩 pop하면서 역방향 그래프 탐색
        // 대신, 탐색 전에 visit[]을 false로 모두 초기화 해 주어야 한다.
    }
    
    memset(visit, false, sizeof(visit));    // visit[]을 false로 초기화
    
    int temp[50000];                // stack에 쌓인 값을 출력하기 위한 임시 배열
    int size = (int)num.size();     // stack에 쌓인 크기를 저장하기 위한 임시 변수
    for(int i = 0; i < size; i++){
        temp[i] = num.top();        // 임시 배열 temp에 stack값 저장
        num.pop();
    }
    reverse(temp, temp+size);       // 배열의 값을 뒤집어준다.
    for(int i = 0; i < size; i++){
        cout<<temp[i] << " ";       // stack에 저장된 순서로 출력
    }
    for(int i = 0; i < size; i++){
        num.push(temp[i]);          // stack값 재 정리
    }
}












//
//void dfs(int v) {
//    visited[v] = true;
//    for (int next : vt[v]) {
//        if (visited[next])
//            continue;
//        dfs(next);
//    }
//    st.push(v);
//}
//
//
//
//void func(int v, int c) {
//    visited[v] = true;
//    scc[c].push_back(v);
//    for (int next : rvt[v]) {
//        if (visited[next])
//            continue;
//        func(next, c);
//    }
//}

























