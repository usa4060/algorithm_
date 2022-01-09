#include <iostream>
using namespace std;

double A, B;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>A>>B;
    
    cout.precision(15);
    cout<<A/B<<'\n';
}

