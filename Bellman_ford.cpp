/*
[Bellman Ford Algorithm]
1. 
*/

#include <bits/stdc++.h>


/*
* 
*/
int main(int argc, char **argv){
    
    int num_nodes = 7;

    int adjacency_matrix[num_nodes][num_nodes] = {{0, 6, 5, 5, 0, 0, 0},
                                                  {0, 0, 0, 0, -1, 0, 0},
                                                  {0, -2, 0, 0, 1, 0, 0},
                                                  {0, 0, -2, 0, 0, -1, 0},
                                                  {0, 0, 0, 0, 0, 0, 3},
                                                  {0, 0, 0, 0, 0, 0, 3},
                                                  {0, 0, 0, 0, 0, 0, 0}};
    
    int cost[num_nodes];
    cost[0] = 0;
    for(int i = 1; i < num_nodes; ++i){
        cost[i] = INT_MAX;
    }

    for (int k = 0; k < num_nodes - 1; ++k){
        for (int i = 0; i < num_nodes; ++i){
            for(int j = 0; j < num_nodes; ++j){
                if (adjacency_matrix[i][j] != 0){
                    if (cost[i] + adjacency_matrix[i][j] < cost[j]){
                        cost[j] = cost[i] + adjacency_matrix[i][j];
                    }
                }
            }
        }

        std::cout << "Iteration" << k << ":" << std::endl;
        for(int i = 0; i < num_nodes; ++i){
            std::cout << "node" << i+1 << " = " << cost[i] << ", ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "========================================================" <<std::endl;
    std::cout << "Final" << std::endl;
    for(int i = 0; i < num_nodes; ++i){
        std::cout << "node" << i+1 << " = " << cost[i] << ", ";
    }
    std::cout << "\n";
    
    return 0;
}