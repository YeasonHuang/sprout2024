#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T,op,x;
    priority_queue<int,vector<int>,greater<int>> PQ;
    cin>>T;
    while(T--){
        cin>>op;
        if(op==1){
            cin>>x;
            PQ.push(x);
        }
        else{
            if(PQ.size()) cout<<PQ.top()<<'\n',PQ.pop();
            else cout<<"empty!\n";
        }
    }
}