// Class Name : Graph
// Namespace  : COMP2230_Assignment
//
// This class store the graph adjacents and find cut vertices by using
// Depth First Search (DFS)
//
// Author : kelvin Yin (contact@kelvinyin.com)

#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <vector>		// Dynamic array

namespace COMP2230_Assignment {
	class Graph {
		public :
			// Constructor
			//
			// This constructor initialise all the member variables.
			//
			// Precondition  : One parameter argument: vector < vector<int> > type.
			// Postcondition : Initialise vertex with parameter argument and other
			//				   member variables.
			Graph(std::vector< std::vector<int> > _vertex);

			// Method : getCutVertex
			//
			// This method is to get the number of cut vertices that this graph
			// have. This method call cutVertex method recursively using DFS.
			//
			// Precondition  : No parameter argument. The object has been instantiated.
			// Postcondition : Label the vertices and call cutVertex recursively.
			//				   Print all the cut vertices found.
			std::vector<int> getCutVertex();

			// Method : cutVertex
			//
			// This method is to find the number of cut vertices by using DFS.
			//
			// Precondition  : One parameter argument: int type, as the vertex number.
			//				   The object has been instantiated.
			// Postcondition : Find the cut vertices recursively.
			void cutVertex(int v);

		private :
			// A matrix for vertices and adjacents
			std::vector< std::vector<int> > vertex;

			// Label for visited vertices
			std::vector<int> visit;

			// Label for cut vertices
			std::vector<int> cut;

			// To store the smallest visit label of each vertex
			std::vector<int> low;

			// The parrent of the vertex
			std::vector<int> parent;

			// The number of the child of the root
			int root_child_count;

			// Label
			int count;
	};
}

#endif