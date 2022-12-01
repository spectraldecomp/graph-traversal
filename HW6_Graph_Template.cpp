// 
// In this assignment, we implement an undirected graph class 
// of five nodes (numbered as 0, 1, 2, 3, 4) and two graph 
// traverse algorithms. The graph class is partially defined 
// for you, and we assume the graph is fully connected. 
// 
// You need to complete four tasks. 
// 
// 1. Define a private member to store the graph. 
//    You can use a matrix or a list. For list, you 
//    need to implement the table and associated lists 
//    yourself, and cannot use the list library. 
// 
// 2. Define the BuildGraph function. (You don't have to 
//    additionally declare a constructor. But you can.) 
// 
// 3. Define the Depth-First Traverse function. 
// 
// 4. Define the Breadth-First Traverse function. 
//
// Detailed instructions are given below.  
// 
// Remember: this program only tests a graph of five nodes.  
// 
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Graph {
private:
    // you should use a private member to store a graph 
    // you can use either a matrix or list to store it. 
public:
    void BuildGraph(vector<int> link);
    vector<int> DepthFirstTraverse(int i);
    vector<int> BreadthFirstTraverse(int i);
};

void Graph::BuildGraph(vector<int> link) {

    // This function constructs a graph using the 
    // input link vector. This vector contains all 
    // edges of the graph as follows: 
    // 1st edge is connecting node link[0] and link[1]
    // 2nd edge is connecting node link[2] and link[3]
    // 3rd edge is connecting node link[4] and link[5]
    // ...... 

};

vector<int> Graph::DepthFirstTraverse(int i) {

    // This function performs depth-first traverse 
    // on the graph, starting at node i, and returns 
    // the sequence of visited nodes stored in a vector.
    // For example, if DFS visits 3, 1, 0, 2, 4, then 
    // this function returns a vector {3,1,0,2,4}. 
    // 
    // Whether you are using matrix or list implementation, 
    // break ties based on the order of nodes. 
    // For example, if node i has multiple univisited 
    // neighbors 2, 1, 3, we should visit 1 first, then 2 
    // and finally 3. (If you are using list implementation, 
    // it may be easier to store neighbor nodes in order 
    // to facilitate the traverse implementation.) 
    // 

};

vector<int> Graph::BreadthFirstTraverse(int i) {

    // This function performs breadth-first traverse 
    // on the graph, starting at node i, and returns 
    // the sequence of visited nodes stored in a vector.
    // For example, if BFT visits 4, 2, 1, 0, 3, then 
    // this function returns a vector {4,2,1,0,3}. 
    // 
    // Whether you are using matrix or list implementation, 
    // break ties based on the order of nodes. 
    // For example, if node i has multiple univisited 
    // neighbors 2, 1, 3, we should visit 1 first, then 2 
    // and finally 3. (If you are using list implementation, 
    // it may be easier to store neighbor nodes in order 
    // to facilitate the traverse implementation.) 
    // 


};


int main()
{
    int mode, temp;
    vector<int> input;
    vector<int> output;
    Graph x;

    cin >> mode;
    while (cin >> temp) {
        input.push_back(temp);
    }

    switch(mode) {

    case 0:
        x.BuildGraph(input);
        output = x.DepthFirstTraverse(input.at(0));
        for (int i = 0; i < output.size(); i++) {
            cout << output.at(i) << endl;
        }
        break;
    case 1:
        x.BuildGraph(input);
        output = x.BreadthFirstTraverse(input.at(0));
        for (int i = 0; i < output.size(); i++) {
            cout << output.at(i) << endl;
        }
        break;
    }

    return 0;
}
