#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int One=0,Zero=0;
        for(char c:s){
            if(c=='0') Zero++;
            else One++;
        }
        Zero-=(n/2-k);
        One-=(n/2-k);
        if(Zero<0 || One<0 || Zero%2!=0 || One%2!=0){
            cout<<"NO\n";
        }
        else{
            if(Zero/2+One/2==k  ){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

        
    }
}
//