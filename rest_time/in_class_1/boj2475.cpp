#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char a;
    int n = 0;
    for(int i = 0;i < 5; i++){
        cin>>a;
        n+= ((a-'0')*(a-'0'));
    }
    cout<<n%10<<'\n';
}
