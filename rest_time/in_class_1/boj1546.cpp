#include <iostream>
using namespace std;

int main(){
    double N[1000];
    double M = 0;
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>N[i];
        if(M < N[i])M = N[i];
    }
    double sum = 0;
    for(int i = 0; i <T; i++){
        sum+=N[i]/M*100;
    }
    cout<< sum/T<<'\n';
}
