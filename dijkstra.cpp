// dijkstra.cpp : Defines the entry point for the console application.
//

// remove // if using MVS
/*//*/#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main() {			
	int nodeCount, connectionCount, root;
	cin >> nodeCount >> connectionCount;
	cin >> root;

	vector<vector<ii>> nodeConns(nodeCount, vector<ii>(0, make_pair(0, -1))); 
	vector<int> nodeWeight(nodeCount, -1); 

	for (int i = 0; i < connectionCount; i++) {
		int startNode, endNode, weight;
		cin >> startNode >> endNode >> weight;

		nodeConns[startNode].push_back(make_pair(weight, endNode));
	}
	
	priority_queue<ii> toVisit; // holds -weight total, node to visit (-weight first because pq arranges from highest to lowest by default)
	nodeWeight[root] = 0;

	toVisit.push(make_pair(0, root)); 

	while (!toVisit.empty()) {
		int currNodeId = toVisit.top().second;

		toVisit.pop();

		for (int i = 0; i < nodeConns[currNodeId].size(); i++) {
			ii currConn = nodeConns[currNodeId][i];
			
			
			if (nodeWeight[currConn.second] == -1 || nodeWeight[currNodeId] /*weight of parent node*/ + currConn.first /*weight of connection*/ < nodeWeight[currConn.second] /*child weight*/) {
				nodeWeight[currConn.second] = nodeWeight[currNodeId] + currConn.first;
				toVisit.push(make_pair(-1 * nodeWeight[currConn.second], currConn.second));
			}
		}
	}

	int endingNode;
	while (cin >> endingNode) {
		cout << nodeWeight[endingNode] << endl;
	}
	
	return 0;
}

