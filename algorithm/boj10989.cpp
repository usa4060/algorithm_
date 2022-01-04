#include <iostream>
#include <string>
#include <vector>
using namespace std;

int num[10001] = {0, };
int T;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    while(T--){
        int a;
        cin>>a;
        num[a]++;
    }
    
    for(int i = 1; i < 10001; i++){
        while(num[i] != 0){
            cout<<i<<'\n';
            num[i]--;
        }
    }
    return 0;
}
