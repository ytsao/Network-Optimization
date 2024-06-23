#include <bits/stdc++.h>

int main(){
    int n = 5;

    int arr[] = {5, 4, 3, 2, 1};
    for(int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (arr[i] > arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}