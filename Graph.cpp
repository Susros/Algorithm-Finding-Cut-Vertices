// Implementation Class : Graph 
//
// This is the implemntation for the class Graph.
//
// Author: Kelvin Yin (contact@kelvinyin.com)

#include "Graph.h"

namespace COMP2230_Assignment {
	// Implentation : Constructor
	Graph::Graph(std::vector< std::vector<int> > _vertex) {
		vertex 			 = _vertex;
		count  			 = 0;
		root_child_count = 0;

		for(int i = 0; i < vertex.size(); i++) {
			visit.push_back(0);
			cut.push_back(0);
			low.push_back(0);
			parent.push_back(0);
		}
	}

	// Implementation : getCutVertex
	std::vector<int> Graph::getCutVertex() {
		for(int i = 0; i < vertex.size(); i++) {
			if(visit[i] == 0) {
				parent[i] = i;			// parent of the vertex i
				root_child_count = 0;	// number of its child
				cutVertex(i);			// find cut vertex
			}
		}

		// Print all cut vertices
		std::vector<int> cutVertices;
		for(int i = 0; i < cut.size(); i++) {
			if (cut[i] == 1) {
				cutVertices.push_back(i + 1);
			}
		}

		return cutVertices;
	}

	void Graph::cutVertex(int v) {
		count++;										// label
		visit[v] = count;								// vertex v has been visited
		low[v] = visit[v];								// smallest visit label of vertex v

		// Get all the adjacents of vertex v
		for(int i = 0; i < vertex[v].size(); i++) {
			// oen of the adjacent of vertex v
			int w = vertex[v][i];
		
			if (visit[w - 1] == 0) {					// If that adjacent has not been yet visited
				parent[w - 1] = v;						// parent of that adjacent
				cutVertex(w - 1);						// Recursive method

				if (parent[v] == v) {					// There is child for this root
					root_child_count = root_child_count + 1;
				} else {
					if (low[w - 1] < low[v]) {			// The smaller visit lable is found; Spanning tree
						low[v] = low[w - 1];
					}

					if (low[w - 1] >= visit[v]) {		// Cut vertex is found
						cut[v] = 1;
					}
				}
			} else {
				if (parent[v] != (w - 1)) {				// Back edge
					if (visit[w - 1] < low[v]) {		// The smaller visit label is found
						low[v] = visit[w - 1];
					}
				}
			}
		}

		if (parent[v] == v && root_child_count > 1) {	// Cut vertex is found
			cut[v] = 1;
		}
	}
}