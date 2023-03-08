 // In this assignment, we implement an undirected graph class 
// of five nodes (numbered as 0, 1, 2, 3, 4) and two graph 
// traverse algorithms. 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Graph {
private:
int adjacencyMatrix[5][5] = {{0}};
bool visitedList[5];
public:
    void BuildGraph(vector<int> link);
    vector<int> DepthFirstTraverse(int input);
    vector<int> BreadthFirstTraverse(int input);
    bool isVisited(int input);

};

void Graph::BuildGraph(vector<int> link) {
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
