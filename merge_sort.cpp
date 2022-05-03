#include<iostream>
#include<chrono>
#include<ctime>
#include<cstdlib>
using namespace std;

void merge(int* arr, int left,int mi,int right){
    int leftsize = mi - left +1;
    int rightsize = right - mi;
    int leftemp[100000];
    int rightemp[100000];

    for(int i=0;i<leftsize;i++){
        leftemp[i]= arr[left+i];
    }
    for(int i=0;i<rightsize;i++){
        rightemp[i]=arr[mi+ 1+ i];
    }

    int i=0,j=0,k=left;
    while(i<leftsize && j<rightsize){
        if(leftemp[i]<=rightemp[j]){
            arr[k]=leftemp[i];
            i++;
        }
        else{
            arr[k]=rightemp[j];
            j++;
        }
        k++;
    }
    while(i<leftsize){
        arr[k]=leftemp[i];
        i++;
        k++;
    }
    while(j<rightsize){
        arr[k]=rightemp[j];
        j++;
        k++;
    }
}

void recur(int* arr,int st,int end){
    if(st>=end){
        return;
    }
    int mid = st+ (end-st)/2;
    recur(arr,st,mid);
    recur(arr,mid+1,end);
    merge(arr,st,mid,end);
}


int main(){
    int n;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++){
        arr[i] = rand() % 10000;
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
    recur(arr,0,n-1);
    end = std::chrono::system_clock::now();
  
    std::chrono::duration<double> elapsed_seconds = end - start;
   
    cout<<'\n';
    for(int i=0;i<n;i++){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
    cout<<"time: "<<elapsed_seconds.count()<<"time end";


}
