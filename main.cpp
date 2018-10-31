// This program is to get all the cut vertices in the graph.
// The graph adjacents are read from the input file.
//
// Author : Kelvin Yin (contact@kelvinyin.com)

#include <iostream>
#include <vector>
#include <fstream>

#include "Graph.h"

using namespace std;
using namespace COMP2230_Assignment;

int main() {
	// Variables
	string inputFile;				// Input file
	vector< vector<int> > vertex;	// Vertex of the graph
	vector<int> adjacent;			// Adjacent of the vertex 
	vector<int> cutVertices;		// Cut vertices
	char inputValue;				// To read input value from the file
	int count;						// Number of input value

	// Greeting
	cout << "Hello and welcome to Cut Vertex algorithm!" << endl;

	// Enter input file
	cout << endl << "Please enter the name of the input file containing the input graph." << endl;
	cin >> inputFile;

	// When the keyboard input is not "Q"
	while (inputFile != "Q" && inputFile != "q") {
		// Initialise variables
		vertex.clear();
		adjacent.clear();
		cutVertices.clear();
		inputValue = char();
		count = 0;

		// Read file
		ifstream iFile(inputFile);

		// Get input from the input file with the valid format
		if (iFile.good()) {
			while(iFile >> inputValue) {
				if (inputValue == ',') {
					iFile >> inputValue;
				} else {
					if (count > 0) {
						vertex.push_back(adjacent);
						adjacent.clear();
					}
				}

				int v = inputValue - 48;
				adjacent.push_back(v);

				count++;
			}

			vertex.push_back(adjacent);
			adjacent.clear();

			// Get the cut vertices of the graph
			Graph graph(vertex);
			cutVertices = graph.getCutVertex();

			// Print the cut vertices
			cout << "The cut vertices of the graph given in file " << inputFile << " are ";
			for(int i = 0; i < cutVertices.size(); i++) {
				if (i == cutVertices.size() - 2) {
					cout << cutVertices[i] << " and ";
				} else if (i == cutVertices.size() - 1) {
					cout << cutVertices[i] << ".";
				} else {
					cout << cutVertices[i] << ", ";
				}
			}

			cout << endl;
		} else {
			cout << "Error reading the file. File might not exist." << endl;
		}

		// Enter input file
		cout << endl << "Please enter another input file name, or type Q to quit the program" << endl;
		cin >> inputFile;
	}

	cout << endl << "Thank you for using Cut Vertex algorithm. Bye." << endl;

	return 0;
}