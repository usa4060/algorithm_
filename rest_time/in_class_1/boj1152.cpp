#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string str;
    int cnt = 0;
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' ')cnt++;
    }
    
    if(str[0] == ' ')cnt--;
    if(str[str.size()-1] == ' ')cnt--;
    cout<<cnt + 1<<'\n';
    
}
