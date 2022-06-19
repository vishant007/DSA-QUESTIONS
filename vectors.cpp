#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // traversal using simple for loop
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    } //1 2 3

    // traversal using iterator
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<endl;
    }// 1 2 3


    // traversal using auto keyword
    for(auto element:v){
        cout<<element<<endl;
    }// 1 2 3

    v.pop_back(); // 1 2

    vector<int> v2 (3,20);
    // 20 20 20 

    //swap() is used to swap the elements 
    swap(v,v2);
    for(auto element:v){
        cout<<element<<endl;
    }
    for(auto element:v2){
        cout<<element<<endl;
    }
    // 20 20 20 1 2

    //sorting of the vectors
    sort(v.begin(),v.end());


//pairs in vectors which will allow to store pair of objects

    pair<int, char> p;
    p.first = 3;
    p.second = 'f';

}