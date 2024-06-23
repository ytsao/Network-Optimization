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