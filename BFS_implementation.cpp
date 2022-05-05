#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<vector<int>> map;
    queue<int> q;
    int n,c;
    cin>>n;
    cin>>c;
    map.resize(n);
    int n1,n2;
    for(int i=0;i<c;i++){
        cin>>n1;
        cin>>n2;
        map[n1].push_back(n2);
        
    }

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    int start;
    cout<<"Input start node: ";
    cin>>start;
    
    //Tranversal
    q.push(start);
    int cr;
    vector<int> chk,srh;
    srh.push_back(start);
    while(q.size()!=0){
        cr = q.front();
        
        chk.push_back(cr);
        q.pop();
        int flag =1;
        for(int i=0;i<map[cr].size();i++){
            flag =1;
            for(int j=0;j<chk.size();j++){
               
                if(map[cr][i]==chk[j]){
                    flag =0;
                    
                }
            }
            
            if(flag !=0 ){
            q.push(map[cr][i]);
            srh.push_back(map[cr][i]);}
        }
    }

    for(int i=0;i<srh.size();i++){
        cout<<srh[i]<<' ';
    }

}