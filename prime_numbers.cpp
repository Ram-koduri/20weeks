#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[10000];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    for(int i=1;i<n;i++){
        if(arr[i]!=0){
            cout<<arr[i]<<endl;
            for(int j=i+arr[i];j<n;j+=arr[i]){
                arr[j]=0;
            }
        }
    }
}