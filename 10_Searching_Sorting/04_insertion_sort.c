#include <stdio.h>


/*
Insertion Sort is a simple comparison-based sorting algorithm that builds
the final sorted array one element at a time. It works much like how you
might sort playing cards in your hands:
	- It starts from the second element, assuming the first is already sorted.
	- It picks each element and inserts it into its correct position among the previously sorted elements by shifting larger elements one position to the right.

Key Characteristics
-Time complexity:
	- Best case: O(n) when the array is already sorted
	- Worst case: O(n²) when the array is sorted in reverse
-Space complexity:
	 O(1) – it's an in-place algorithm
-Stable: 
	Yes – equal elements retain their original relative positions
-Adaptive:
	Efficient for nearly sorted data
*/



int main(){
	int array[] = {70, 16, 12, 40, 20, 50, 26}, i, j, temp, arr_len;
	arr_len = sizeof(array)/sizeof(array[0]);
	
	// insertion sort
	for (i=1;i<arr_len;i++){
		temp = array[i];
		j=i-1;
		while (j>=0 && array[j]>temp){
			array[j+1] = array[j];
			j--;
		}
		array[j+1]=temp;
	}
	
	for (i=0;i<arr_len;i++){
		printf("%d\t", array[i]);
	}
	return 0;
}
