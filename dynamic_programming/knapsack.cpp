#include <bits/stdc++.h>


int main(int argc, char** argv) {
    int C = 100;
    int num_items = 10;
    int weights[num_items] = { 0 };
    int profits[num_items] = { 0 };
    for (int i = 0; i < num_items;++i) {
        weights[i] = 10;
        profits[i] = 100;
    }

    // start 
    int dp[num_items][num_items] = { 0 };
    for (int i = 0; i < num_items; ++i) {
        for (int j = 0; j < num_items; ++j) {
            if (i == 0) {
                //
            }
            else {
                //
            }
        }
    }


    return 0;
}