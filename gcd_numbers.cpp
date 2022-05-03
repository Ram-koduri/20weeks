#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int n1,m1;
    n1=n;
    m1=m;
    int ans;
    while(n!=0 && m!=0){
        if(n<m){
            if(m%n==0){
                ans=n;
                break;
            }
            m = m%n;
        }
        else{
            if(n%m==0){
                ans = m;
                break;
            }
            n = n%m;
        }
    }
    cout<<ans;
}