#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
vector<string> word;

int get_sum(string a){
    int count = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] - '0' >= 0 && a[i] - '9' <= 0)
            count += a[i] - '0';
    }
    return count;
}


bool compare(string a, string b){
    
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        int A = get_sum(a);
        int B = get_sum(b);
        if(A != B)return A <B;
        else{
            return a < b;
        }
    }
}

int main(){
    ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    while(T--){
        string temp;
        cin>>temp;
        word.push_back(temp);
    }
    
    sort(word.begin(), word.end(), compare);
    
    for(int i = 0; i < word.size(); i++){
        cout<<word[i]<<'\n';
    }
}
// 1. length비교
// 2. 단어에 포함된 숫자 합 비교
// 3. 사전순 비교
