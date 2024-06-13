#include <bits/stdc++.h>

template <class T1, class T2, class Pred = std::less<T2>>
struct sort_pair_second{
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right){
        Pred p;
        return p(left.second, right.second);
    }
};

int *tree;

int Find(int id){
    if (id == tree[id]){
        return id;
    }

    Find(tree[id]);
}

void Union(int from, int to){
    tree[to] = from;
}

int main(){

    int num_nodes = 5;
    tree = new int[num_nodes];
    for (int i = 0; i < num_nodes; ++i){
        tree[i] = i;
    }

    int adjacency_matrix[num_nodes][num_nodes] = {{0, 5, 2, 0, 0},
                                                  {5, 0, 0, 2, 4},
                                                  {2, 0, 0, 0, 10},
                                                  {0, 2, 0, 0, 1},
                                                  {0, 4, 10, 1, 0}};


    std::vector<std::pair<std::pair<int, int>, int>> edges;
    for(int i = 0; i < num_nodes; ++i){
        for (int j = 0; j < num_nodes; ++j){
            if (adjacency_matrix[i][j] != 0){
                edges.push_back(std::make_pair(std::make_pair(i,j), adjacency_matrix[i][j]));
            }
        }
    }

    // Sorting the edges
    sort(edges.begin(), edges.end(), sort_pair_second<std::pair<int,int>,int>());


    for(int i = 0; i < edges.size(); ++i){
        std::cout << edges[i].first.first << ", " << edges[i].first.second << " -> " << edges[i].second << std::endl;
    }


    // union-find 
    for (int i = 0; i < edges.size(); ++i){
        int from = Find(edges[i].first.first);
        int to = Find(edges[i].first.second);

        if (from != to){
            Union(from, to);
        }
    }
    

    // Show results
    for (int i = 0; i < num_nodes; ++i){
        std::cout << tree[i] << std::endl;
    }
    

    return 0;
}