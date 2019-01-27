// Author: Matt Grabara
// Year: 2009

// Demo for graf.h header
// Program creates a directed graph with 4 vertices and 3 edges.
// Then Dijkstra algorithm is executed for vertex 1 and length of optimal paths between vertex 1 and 0, 1, 2, 3 are displayed.

// "no connection" means there is no way to access the vertex from a given vertex.

// Watch out: Vertex numbering starts at 0

#include <iostream>
#include <string>
#include <vector>
#include "graf.h"

using namespace std;

int main() {
	graf G(4);
	G.setEdge(0, 1, 5, true);
	G.setEdge(1, 2, 3, true);
	G.setEdge(2, 0, 1, true);	
	G.setEdge(3, 2, 3, true);

	std::vector <long double> a;
	a=G.dijkstra(1);
	for (unsigned int i=0; i<a.size(); ++i)
		if (a[i] != std::numeric_limits<long double>::max())
			cout << a[i] << '\n';
		else cout << "no connection\n";
	return 0;
}
