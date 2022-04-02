#include <iostream>
#include <vector>
#include <unordered_set>

struct Node {
    int value;
    std::vector<Node*> adjList;

    // Constructors 
    Node() {
        value = 0;
        adjList = std::vector<Node*>();
    }
    Node(int _value) {
        value = _value;
        adjList = std::vector<Node*>();
    }
    Node(int _value, std::vector<Node*> _adjList) {
        value = _value;
        adjList = _adjList;
    }
};

struct Graph {
    std::unordered_set<Node*> nodes; 

    Graph() {
        nodes = std::unordered_set<Node*>();
    }

    //Adj list, makes it unidirectional
    void createEdge(Node* from, Node* to) {
        from->adjList.push_back(to);
        // to->adjList.push_back(from);
    }

    void addNode(Node* node) {
        nodes.insert(node);
    }

    void printGraph() {
        for(Node* curr : nodes) {  
            std::cout << "Node: " << curr->value << std::endl;
            auto currAdjList = curr->adjList;

            std::cout << "Edges: ";
            for(int i=0; i<currAdjList.size(); ++i) {
                std::cout << currAdjList[i]->value << ", ";
            }
            std::cout << std::endl;
        }

        std::cout << "EOG--(End of Graph)" << std::endl;
    }

};

//Testing

void testPrintGraph() {
    Graph test = Graph();

    Node node1 = Node(1);
    Node node2 = Node(2);
    Node node3 = Node(3);

    test.addNode(&node1);
    test.addNode(&node2);
    test.addNode(&node3);

    test.createEdge(&node1, &node2);
    test.createEdge(&node1, &node3);

    test.printGraph();
}

int main() {
   
    testPrintGraph();

    return 0;
}