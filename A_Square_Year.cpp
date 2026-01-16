#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(int(sqrt(stoi(s)))*int(sqrt(stoi(s)))==stoi(s)){
            cout<<"0 "<<int(sqrt(stoi(s)))<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
}