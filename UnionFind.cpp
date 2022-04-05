// From Leetcode graph section, Practice


#include <iostream>
#include <vector>

class UnionFind {
    public:
    UnionFind(int size) : root(size), rank(size) { //O(N): N = # of nodes
        for(int i=0; i<size; ++i) {
            root[i] = i;
            rank[i] = 1; //Needed for Union by Rank: choose tree with greater rank(height) as root
        }
    }

    // Finds and returns the root of x
    // O(α(N)), where α = Inverse Ackermann Function, assumed as O(1)
    // hence avg find time = O(1)
    int find(int x) {          
        if(x == root[x]) {    
            return x;
        }
        return root[x] = find(root[x]); //Key: Recursion until root(not parent) is found
    }

    // Merges two nodes/connected componse by doing a Union by Rank
    // Key --> choose tree with the greater rank(height)
    // Total time = O(α(N)) => O(1)
    void unionSet(int x, int y){                        
        int rootX = find(x); //O(α(N)) => O(1)
        int rootY = find(y); //O(α(N)) => O(1)
        if (rootX != rootY) {
            // KEY: choose tree with the greater rank(height)
            //1. LHS(tree) height > RHS(tree) height ==> LHS root becomes RHS root
            if(rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            }
            //2. LHS(tree) height < RHS(tree) height ==> RHS root becomes LHS root
            else if(rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            }
            //3. LHS(tree) height == RHS(tree) height then  
            else {
                root[rootY] = rootX; //a. LHS root becomes RHS root
                rank[rootX] += 1; //b) LHS(height)++
            }
        }
    }

    //Determines if two nodes are connected or connected components
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    private:
    std::vector<int> root;
    std::vector<int> rank;
};



int main() {
    std::cout << "Hello world" << std::endl;

    //test cases
    int N = 10;
    UnionFind uf(N); 
    // 1-2-5-6-7    3-8-9    4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);

    uf.unionSet(3, 8);
    uf.unionSet(8, 9);

    std::cout << "Connected 1, 5: " << uf.connected(1, 5) << std::endl;
    std::cout << "Connected 5, 7: " << uf.connected(5, 7) << std::endl;
    std::cout << "Connected 4, 9: " << uf.connected(4, 9) << std::endl;

    // 1-2-5-6-7   3-8-9-4
    uf.unionSet(9, 4);
    std::cout << "Connected 4, 9: " << uf.connected(4, 9) << std::endl;

    return  0;
}