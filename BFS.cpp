#include <bits/stdc++.h>

int main(){
    int num_nodes = 5;
    int node_list[num_nodes] = {0, 0, 0, 0, 0};
    int adjacency_matrix[num_nodes][num_nodes] = {{0, 5, 2, 0, 0},
                                                  {5, 0, 0, 2, 4},
                                                  {2, 0, 0, 0, 10},
                                                  {0, 2, 0, 0, 1},
                                                  {0, 4, 10, 1, 0}};
    
    int start_node = 0;
    std::queue<int> q;
    q.push(start_node);
    node_list[start_node] = 1;
    while(!q.empty()){
        int current_node = q.front();
        std::cout << current_node << "\n";
        q.pop();
        for (int j = 0; j < num_nodes; ++j){
            if (adjacency_matrix[current_node][j] != 0 && node_list[j] == 0){
                q.push(j);
                node_list[j] = 1;
            }
        }
    }

    return 0;
}