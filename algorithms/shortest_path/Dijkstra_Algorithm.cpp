/*
[Dijkstra Algorithm]
1. node_0 為原點
2. 選擇 cost 最低的 node 去連接其adjacency nodes
3. 更新 cost
4. 重複 step 2 & step 3 直到所有 node 皆被拜訪過
*/

#include <bits/stdc++.h>


/*
* visited[num_nodes] : 有沒有走過 node i, default = false
* cost[num_nodes] : 從起點到 node i 的總成本, default = INF
* path[num_nodes] : previous node connect to node i, default = -1
*/
int main(int argc, char **argv){
    
    int num_nodes = 5;

    int adjacency_matrix[num_nodes][num_nodes] = {{0, 5, 2, 0, 0},
                                                  {5, 0, 0, 2, 4},
                                                  {2, 0, 0, 0, 10},
                                                  {0, 2, 0, 0, 1},
                                                  {0, 4, 10, 1, 0}};


    int visited[num_nodes];
    int cost[num_nodes];
    int path[num_nodes];
    for(int i = 0; i < num_nodes; ++i){
        visited[i] = false;
        cost[i] = INT_MAX;
        path[i] = -1;
    }

    int source_node = 0;
    cost[source_node] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.push(std::make_pair(cost[source_node], source_node));

    while(!pq.empty()){
        int current_node = pq.top().second;
        std::cout << "Pick node_" << current_node << std::endl;
        pq.pop();

        if (visited[current_node] == false){
            visited[current_node] = true;

            for(int j = 0; j < num_nodes; ++j){
                if (adjacency_matrix[current_node][j] != 0){
                    if (cost[j] > cost[current_node] + adjacency_matrix[current_node][j]){
                        path[j] = current_node;
                        cost[j] = cost[current_node] + adjacency_matrix[current_node][j];
                        pq.push(std::make_pair(cost[j], j));          
                    }          
                }
            }
        }

        std::cout << "===============================================================================" << std::endl;
        for(int i = 0; i < num_nodes; ++i){
            std::cout << "node_" << i << " = " << cost[i] << std::endl;
            std::cout << "visited_" << i << " = " << visited[i] << std::endl;
            std::cout << "path_" << i << " = " << path[i] << std::endl;
            std::cout << std::endl;
        }
        std::cout << "===============================================================================" << std::endl;
    }


    // Print the shortest path solution
    int terminate_node = 4;
    int current_node = terminate_node;
    std::cout << "Total cost = " << cost[terminate_node] << std::endl;
    while(current_node != source_node){
        std::cout << "node_" << current_node << " <- ";
        current_node = path[current_node];
    }
    std::cout << "node_" << source_node;


    return 0;
}