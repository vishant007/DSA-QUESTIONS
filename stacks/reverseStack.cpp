#include<iostream>
using namespace std;

void insertAtbottom(stack<int> &st, int ele ){
     if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.pop();
    st.pop();
    insertAtbottom(st, ele);

    st.push(topele)
}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.pop();
    st.pop();
    reverse(st);
    insertAtbottom(st,ele)
    
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);
    while(!st.empty){
        cout<<st.top()<<" ";
        st.pop();
    }
}