// C++ implementation of efficient algorithm to find
// smaller element on left side
#include <iostream>
#include <stack>
using namespace std;


void printPrevSmaller(int arr[], int n)
{
	stack<int> S;

	
	for (int i=0; i<n; i++)
	{
		
		while (!S.empty() && S.top() >= arr[i])
			S.pop();

		// If all elements in S were greater than arr[i]
		if (S.empty())
			cout << "-1 ";
		else //Else print the nearest smaller element
			cout << S.top() << ", ";

		
		S.push(arr[i]);
	}
}


int main()
{
	int arr[] = {1, 3, 0, 2, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printPrevSmaller(arr, n);
	return 0;
}
