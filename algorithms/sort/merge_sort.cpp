<<<<<<< HEAD
#include <bits/stdc++.h>

void merge_sort(int* arr, int n){

    if (n <= 1){
        return;
    }
    int m = n / 2;
    int* left = new int[m];
    int* right = new int[n - m];

    for (int i = 0; i < m; ++i){
        left[i] = arr[i];
    }
    for (int i = m; i < n; ++i){
        right[i - m] = arr[i];
    }

    merge_sort(left, m);
    merge_sort(right, n - m);

    int i = 0, j = 0, k = 0;
    while (i < m && j < n - m){
        if (left[i] < right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < m){
        arr[k++] = left[i++];
    }

    while (j < n - m){
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

int main(){

    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};
    merge_sort(arr, n);

    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
=======
/*
Developer: YN

Merge sort 
	A  sorting algorithm that follows the divide-and-conquer approach.
	Recursively dividing the input array into small subarrays and sorting those subarrays then merging them back together to obtain the sorted array.

	
	Step 1: Divide: 
	Step 2: Conquer:
	Step 3: Merge:

*/

#include <iostream>


void merge_sort(int* input_array){


}

void print_array(const int* input_array, const int size){
	for (int i = 0; i < size; ++i){
		std::cout << input_array[i] << std::endl;
	}
}


int main(){
	
	int input_array[] = {4, 2, 8, 1};
	int size = sizeof(input_array)/sizeof(int);

	print_array(input_array, size);
	merge_sort(input_array);
	print_array(input_array, size);


	return 0;
}
>>>>>>> d132c63 (add track sort folder)
