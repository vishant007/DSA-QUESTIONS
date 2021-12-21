// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum profit
// that can be made after buying and
// selling the given stocks
int maxProfit(int price[], int start, int end)
{

	// If the stocks can't be bought
	if (end <= start)
		return 0;

	// Initialise the profit
	int profit = 0;

	// The day at which the stock
	// must be bought
	for (int i = start; i < end; i++) {

		// The day at which the
		// stock must be sold
		for (int j = i + 1; j <= end; j++) {

			// If buying the stock at ith day and
			// selling it at jth day is profitable
			if (price[j] > price[i]) {

				// Update the current profit
				int curr_profit = price[j] - price[i];

				// Update the maximum profit so far
				profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}

// Driver code
int main()
{
	int price[] = { 100, 180, 260, 310,
					40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	cout << maxProfit(price, 0, n - 1);

	return 0;
}
// Valley Peak Approach:

// In this approach, we just need to find the next greater element and subtract it from the current element so that the difference keeps increasing until we reach a minimum. If the sequence is a decreasing sequence so the maximum profit possible is 0.


// #include <iostream>
// using namespace std;
 
// // Preprocessing helps the code run faster
// #define fl(i, a, b) for (int i = a; i < b; i++)
 
// // Function that return
// int maxProfit(int* prices, int size)
// {
//     // maxProfit adds up the difference between
//     // adjacent elements if they are in increasing order
//     int maxProfit = 0;
//     // The loop starts from 1
//     // as its comparing with the previous
//     fl(i, 1, size) if (prices[i] > prices[i - 1]) maxProfit
//         += prices[i] - prices[i - 1];
//     return maxProfit;
// }
 
// // Driver Function
// int main()
// {
//     int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
//     int N = sizeof(prices) / sizeof(prices[0]);
//     cout << maxProfit(prices, N) << endl;
//     return 0;
// }