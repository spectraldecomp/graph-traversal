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
int adjacencyMatrix[5][5] = {{0}};
    // you should use a private member to store a graph 
    // you can use either a matrix or list to store it. 
bool visitedList[5];
public:
    void BuildGraph(vector<int> link);
    vector<int> DepthFirstTraverse(int input);
    vector<int> BreadthFirstTraverse(int input);
    bool isVisited(int input);

};

void Graph::BuildGraph(vector<int> link) {
    // This function constructs a graph using the 
    // input link vector. This vector contains all 
    // edges of the graph as follows: 
    // 1st edge is connecting node link[0] and link[1]
    // 2nd edge is connecting node link[2] and link[3]
    // 3rd edge is connecting node link[4] and link[5]
    // ...... 
    for (int i = 0; i < link.size(); i+=2){
        // matrix[link[0]][link[1]] = 1 and vice versa
        adjacencyMatrix[link[i]][link[i+1]] = 1;
        adjacencyMatrix[link[i+1]][link[i]] = 1;  
    }
};

bool Graph::isVisited(int input){
    return visitedList[input];
}

vector<int> Graph::DepthFirstTraverse(int input) {
 
      visitedList[input] = true;
      vector<int> sequence;
      sequence.push_back(input);
    for (int i = 0; i < 5; i++){
        if ((adjacencyMatrix[input][i] == 1) && (isVisited(i) == false)){
            vector<int> subsequence = DepthFirstTraverse(i);
            sequence.insert(sequence.end(), subsequence.begin(), subsequence.end());
        }
    }
    return sequence;
};

vector<int> Graph::BreadthFirstTraverse(int i) {
vector<int> sequence;
queue<int> next;

  visitedList[i] = true;
  next.push(i);

  while (next.size() != 0) {
    int currNode = next.front();
    next.pop();
    sequence.push_back(currNode);

    for (int i = 0; i < 5; i++){
        if ((adjacencyMatrix[currNode][i] == 1) && (isVisited(i) == false)){
            next.push(i);
            visitedList[i] = true;
        }
     }
  }
  return sequence;
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
