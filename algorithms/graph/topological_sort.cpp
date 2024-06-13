#include <bits/stdc++.h>

int id;
const int NUM_NODES = 6;

void dfs(const int adjacency_matrix[][NUM_NODES], int *is_visited, int *topological_results, int current_node){
    if(is_visited[current_node] == 0){
        for (int j = 0; j < NUM_NODES; ++j){
            if (adjacency_matrix[current_node][j] != 0){
                dfs(adjacency_matrix, is_visited, topological_results, j);
            }
        }
        is_visited[current_node] = 1;
        topological_results[current_node] = id + 1;
        id--;
    }
    return;
}

int main(){
    id = NUM_NODES - 1;

    int adjacency_matrix[NUM_NODES][NUM_NODES] = {  {0, 1, 1, 0, 0, 0},
                                                    {0, 0, 0, 1, 1, 0},
                                                    {0, 0, 0, 1, 0, 1},
                                                    {0, 0, 0, 0, 1, 1},
                                                    {0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0}
                                                };

    // Initialization
    int *topological_results = new int[NUM_NODES];
    int *is_visited = new int[NUM_NODES];
    for(int i = 0; i < NUM_NODES; ++i){
        topological_results[i] = 0;
        is_visited[i] = 0;
    }

    // DFS
    for (int i = 0; i < NUM_NODES; ++i){
        if (is_visited[i] == 0){
            dfs(adjacency_matrix, is_visited, topological_results, i);
        }
    }

    // Show one of the results of topological ordering
    for(int i = 0; i < NUM_NODES; ++i){
        if (i != NUM_NODES - 1)
            std::cout << topological_results[i] << ", ";
        else 
            std::cout << topological_results[i] << "\n";
    }

    return 0;
}