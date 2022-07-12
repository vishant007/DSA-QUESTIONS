#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0)return 0;
        if(stones.size()==1)return stones[0];
        priority_queue<int>pq(stones.begin(),stones.end());
        while(!pq.empty()){
            if(pq.size()>1){
                int a=pq.top(),b=0;
                pq.pop();
                b=pq.top();
                pq.pop();
                b=abs(a-b);
                pq.push(b);
            }
            if(pq.size()==1){
                return pq.top();
            }
        }
        return 0;
    }
int main() {
    vector<int>v={2,7,4,1,8,1};
    int z=lastStoneWeight(v);
    cout<<z<<endl;
}