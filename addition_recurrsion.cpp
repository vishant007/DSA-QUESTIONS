#include<iostream>
using namespace std;
int add(int n){
if ( n==0)
    return 1;
    return ( n % 10 + add(n/10));

}
int main(){
    int n = 16789;
    cout<<"sum of the given numbers is" << add(n);
    return 0;
}