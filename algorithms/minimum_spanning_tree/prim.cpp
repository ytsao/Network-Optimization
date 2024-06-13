#include <bits/stdc++.h>

int main(){
    int num_nodes = 5;
    std::vector<int> adjacency_nodes(num_nodes, -1);
    int adjacency_matrix[num_nodes][num_nodes] = {{0, 5, 2, 0, 0},
                                                  {5, 0, 0, 2, 4},
                                                  {2, 0, 0, 0, 10},
                                                  {0, 2, 0, 0, 1},
                                                  {0, 4, 10, 1, 0}};

    int count = 0;
    int results = 0;
    adjacency_nodes[0] = -1;
    while (count < num_nodes) {
        int min_value = INT_MAX;
        int start_node = 0;
        int next_node = 0;
        for (int i = 0; i < num_nodes; ++i){
            for (int j = i + 1; j < num_nodes; ++j){
                if (adjacency_matrix[i][j] > 0 
                && adjacency_matrix[i][j] < min_value 
                && adjacency_nodes[i] != -1
                && adjacency_nodes[j] == -1){
                    min_value = adjacency_matrix[i][j];
                    start_node = i;
                    next_node = j;
                }
            }
        }
        adjacency_nodes[next_node] = start_node;
        std::cout << "start node:" << start_node << "\n";
        std::cout << "next node:" << next_node << "\n";
        if (min_value != INT_MAX) results += min_value;
        count++;
    }

    for (int i = 0; i < num_nodes; ++i){
        std::cout << adjacency_nodes[i] << "\n";
    }
    std::cout << results << "\n";

    return 0;
}