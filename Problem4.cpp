//
// Created by user on 02-Nov-22.
//

// A simple representation of graph using STL
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Graph { //interface for Graph
public:
    Graph(const vector<int> &starts, const vector<int> &ends);
    int numOutgoing(const int nodeID);
    const vector<int> * adjacent(const int nodeID);
    vector<int> starts, ends;
};

Graph::Graph(const vector<int> &starts, const vector<int> &ends) {
    if (starts.size() != ends.size()) {
        throw errc::invalid_argument; // throws invalid argument error if lengths are unequal
    }
    this->starts = starts;
    this->ends = ends;
}

int Graph::numOutgoing(const int nodeID) {
    int count = 0;
    for (int i = 0; i < starts.size(); i++) {
        if (starts[i] == nodeID) {
            count++; // counts all the nodes that have an incoming edge from nodeID
        }
    }
    return count;
}

const vector<int> * Graph::adjacent(const int nodeID) {
    vector<int>* temp; // initializes pointer
    for (int i = 0; i < starts.size(); i++) {
        if (starts[i] == nodeID) {
            temp->push_back(ends[i]); // adds edges of nodeID to vector
        }
    }
    return temp;
}

// Tested for error when starts and ends have unequal lengths
int main()
{
    int V = 5;
    vector<int> starts(6);
    starts = {0, 0, 0, 4, 4, 3};
    vector<int> ends(6);
    ends = {1, 2, 3, 3, 1, 1};

    Graph graph(starts, ends);

    cout << graph.numOutgoing(0) << endl; // prints the number of nodes that nodeID has edges to

    const vector<int> result = *graph.adjacent(4); // fills up a vector with the values of the pointer vector
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; // prints the vector of nodes that nodeID has edges to
    }

    return 0;
}

