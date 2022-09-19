// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half-2/

#include<bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q){
    queue<int> q1,q2;
    int n= q.size();
    for(int i=0;i<n/2;i++){
        q1.push(q.front());
        q.pop();
        
    }
    for(int i=0;i<n/2;i++){
        q2.push(q.front());
        q.pop();
        
    }
    for (int i = 0; i < n/2; i++) {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}


int main()
{
   
    queue<int> q;
    for (int i = 1; i <= 10; i++)
        q.push(i); 
 
    interleave(q);
 
    
    int n = q.size();
    for (int i = 0; i < n; i++) {
        cout << q.front() << " ";
        q.pop();
    }
}
