
// https://www.geeksforgeeks.org/the-celebrity-problem/
#include<iostream>
#include<stack>
using namespace std;

class solution{

    private:
       bool knows(vector<vector<int> >& M, int a,int b, int n){
            if(M[a][b] == 1){
                return true;
            }
            else{
                return false;
            }
       }
    public:
    int celebrity(vector<vector<int> >& M,int n){
        stack<int> s;
        for(int i = 0; i<n; i++){
            s.push(i);
        }

        while(s.size() > 1){
            int a = s.top();
            s.pop();

            int b=s.top();
            s.pop();
        }
          if(knows(a,b)){
            s.push(b);
        }

          else{
            s.push(a);
        }
        int candidate = s.top();
        // to verify whether that person is celebrity or not
        bool rowcheck = false;
        int zerocount = 0;

        for(int i =0; i<n; i++){
            if(M[candidate][i] == 0){
                zerocount++;
            }

        }

        bool colcheck = false;
        int onecount = 0;

        for(int i=0; i<n; i++){
            if(M[i][candidate] == 1){
                onecount++;
            }
        }
        if(onecount=n-1){
            colcheck = true;
        }

        if(rowcheck == true && colcheck == true){
            return candidate;
        }
        else{
            return -1;
        }
    }

};