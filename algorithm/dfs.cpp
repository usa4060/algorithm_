#include <iostream>
#include <vector>

using namespace std;

int num = 7;
bool c[8];
vector<int> a[8];

void dfs(int x){
    if(c[x])return; // 해당 노드를 이미 방문했다는 의미미으로 바로 return
    c[x] = true;
    cout<<x<<' ';   // 해당 노드에는 아직 방문을 안했으므로, 해당 노드에 visit처리 해주고
                    // 이제는 방문을 했으므로 출력처리
    
    for(int i = 0; i < a[x].size(); i++){
        dfs(a[x][i]);
    }
                    // 위의 for문을 통해, 해당 노드에 인접해있는 node를 탐색해주는 과정
                    // 인접한 노드들을 모두 dfs에 집어넣어서, 이미 방문했는지를 확인해야함
                    // 만일 방문했으면 위에서 바로 return처리를 해줘서 돌아오게 됨
}
