#include <bits/stdc++.h>

void quick_sort(int* arr, int n){
    if (n <= 1){
        return;
    }

    int pivot = arr[n / 2];
    int i = 0, j = n - 1;

    while (i <= j){
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }

        if (i <= j){
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, j + 1);
    quick_sort(arr + i, n - i);
}

int main(){
    int n = 9;
    int arr[] = {10, 5, 8, 9, 3, 6, 3, 12, 16};
    quick_sort(arr, n);

    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}