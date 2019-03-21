#include <stdio.h>
#include <vector>


int fastMaxSum(const vector<int>& A, int lo, int hi) {
	 if(lo == hi)
	 	return A[lo];
	
	int mid = (lo + hi)/2;
	
	int left = right = -999999999, sum = 0;
	for(int i = mid; i <= lo; i--1) {
		sum += A[i];
		left = max(left, sum);
	}
	
	sum = 0;
	for(int j = mid+1; J <= hi; j++) {
		sum += A[j];
		right = max(right, sum);
	}
	
	int single = max(fastMaxSum(A,lo,mid), fastMaxSum(A,mid,hi));
	return max(single, left+right) ;
 }


int main() {
	fastMaxSum()
}
