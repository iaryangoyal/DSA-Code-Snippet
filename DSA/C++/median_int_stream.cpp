/**
 * This algorithm returns the median of a running 
 * stream of integers
 * reference: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
**/
#include <bits/stdc++.h>
using namespace std;


void print_median(double arr[], int n){
	cout << "Running the program" << endl;
	
	// median. Initialize to 0
	double med = 0;
	int i;

	// max and min heaps to store upper and lower half of integer stream
	// sort the upper heap to be in descending order
	priority_queue<double> lower;
	priority_queue<double,vector<double>,greater<double>> upper;


	for (i = 0; i < n; i++){
		double current_int = arr[i];
		// case1: upper and lower heaps are currently of same size
		if (upper.size() == lower.size()){
			if (current_int < med){
				//if current int is less than current median
				// push it to lower heap and return the new top
				// element as the median
				lower.push(current_int);
				med = lower.top();
			}
			else{
				//case where current int is greater than current median
				upper.push(current_int);
				med = upper.top();
			}
		}
		// case2: upper heap larger than lower heap
		else if (upper.size() > lower.size()){
			if (current_int < med){
				// if current item less than median
				lower.push(current_int);
				
			}
			else{
				lower.push(upper.top());
				upper.pop();
				upper.push(current_int);
			}
			med = (lower.top() + upper.top())/2.0;
		}
		// case3: lower heap larger than upper heap
		else{
			if (current_int > med){
				// if current item larger than median
				upper.push(current_int);
			}
			else{
				upper.push(lower.top());
				lower.pop();
				lower.push(current_int);
			}
			med = (lower.top() + upper.top())/2.0;
		}
		cout << med << endl;
	}
	
}



// test function
int main(){
	// test stream of integers
	double arr [] = {25, -30, 10, 20, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "About to run the program" << endl;
	print_median(arr, n);
	return 0;
}