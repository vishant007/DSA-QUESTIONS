#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top(); //popping the first element of stack and keeping it in side so that after insertion at bottom we can again add it later
    s.pop();

    // recursive call
    solve(s, x);
    s.push(num);

}


stack<int> pushBottom(stack<int>& mystack,int x){
    solve(mystack, x);
}

