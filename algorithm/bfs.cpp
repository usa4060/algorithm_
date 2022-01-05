#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;
bool c[7];
vector<int>a[8];

void bfs(int start){
    queue<int>q;
    q.push(start);          // queue에 root를 집어넣음
    c[start] = true;        // 집어 넣는 즉시 방문처리를 한다.
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<' ';       // queue의 front는 항상 방문처리가 되어있으므로 pop해주고, 출력해준다.
        
        for(int i = 0; i < a[x].size(); i++){
            int y = a[x][i];
            if(!c[y]){      // for문을 통해 front에 해당하는 노드에 인접한 값들을 모두 확인 함
                q.push(y);
                c[y] = true;
                            // 방문 하지 않았다면 queue에 집어넣어주고, 방문처리를 해준다.
                        
            }
        }
    }
}
//


int main(){
    a[1].push_back(2);
    a[2].push_back(1);
    
    a[1].push_back(3);
    a[3].push_back(1);
    
    a[2].push_back(3);
    a[3].push_back(2);
    
    a[2].push_back(4);
    a[4].push_back(2);
    
    a[2].push_back(5);
    a[5].push_back(2);
    
    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);
    
    a[4].push_back(5);
    a[5].push_back(4);
    
    a[6].push_back(7);
    a[7].push_back(6);
    
    bfs(1);
}
