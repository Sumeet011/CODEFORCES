#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> b;
        int c=a[0];
        int i=0;
        while(i<n){
            while(i<n && a[i]==c){
                i++;
            }
            b.push_back(c);
            if(i<n) c=a[i];
        }
        vector<int> res;
        int j=0;
        res.push_back(1);
        for(int i=1;i<(int)b.size();i++){
            if(b[i]==1+b[i-1]){
                res[j]++;
            }
            else{
                res.push_back(1);
                j++;
            }
        }
        int Ans=0;
        for(int i=0;i<(int)res.size();i++){
            if(res[i]%2==1){
                Ans+=(res[i]/2)+1;
            }
            else{
                Ans+=res[i]/2;
            }
        }
        cout<<Ans<<"\n";

    }}