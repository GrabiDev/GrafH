// graf.h version 1.0
// author: Matt Grabara     year: 2009

// Most successful and optimised version of C++ header to handle graphs.
// It uses overloading setEdge function to allow for defining complex edges.
// Contains successful implementation of Dijkstra algorithm.

#include <vector>
#include <algorithm>
#include <limits>

class graf {
	private:
	unsigned int V;
	std::vector < std::vector<bool> > directions;
	std::vector < std::vector<long double> > weight;
	std::vector <long double> weightV;
	std::vector <bool> isWeightV;
	std::vector < std::vector<bool> > edges;
	std::vector < std::vector<bool> > isWeight;
	class vertex {
		public:
		unsigned int no; long double distance;
		friend bool operator < (const vertex &a, const vertex &b) {
				return(a.distance<b.distance);
		}
	};
	public:
	unsigned int vertexCount();
	graf(unsigned int vv);
	void setEdge(unsigned int a, unsigned int b, bool directed);
	void setEdge(unsigned int a, unsigned int b, unsigned int w, bool directed);
	void setWeightV(unsigned int vertex, long double w);
	long double showWeight(unsigned int a, unsigned int b);
	long double showWeightV(unsigned int a);
	std::vector <long double> dijkstra(unsigned int vertex);
};

graf::graf(unsigned int vv) {
	V=vv;
	edges.resize(V);
	weight.resize(V);
	weightV.resize(V);
	isWeightV.resize(V);
	isWeight.resize(V);
	directions.resize(V);
	for (unsigned int i=0; i<V; ++i) {
		weight[i].resize(V);
		isWeight[i].resize(V);
		edges[i].resize(V);
		directions[i].resize(V);
	}
}

unsigned int graf::vertexCount() {
	return V;
}

void graf::setEdge(unsigned int a, unsigned int b, bool directed) {
	edges[a][b]=true;
	isWeight[a][b]=false;
	switch (directed) {
		case 0: directions[a][b]=false;
		case 1: directions[a][b]=true;
	}
}

void graf::setEdge(unsigned int a, unsigned int b, unsigned int w, bool directed) {
	edges[a][b]=true;
	isWeight[a][b]=true;
	weight[a][b]=w;
	switch (directed) {
		case 0: directions[a][b]=false;
		case 1: directions[a][b]=true;
	}
}

void graf::setWeightV(unsigned int vtx, long double w) {
	isWeightV[vtx]=true;
	weightV[vtx]=w;
}

long double graf::showWeight(unsigned int a, unsigned int b) {
	return weight[a][b];
}

long double graf::showWeightV(unsigned int a) {
	return weightV[a];
}

std::vector <long double> graf::dijkstra(unsigned int vtx) {
	std::vector <vertex> Q (V);
	std::vector <long double> d (V, std::numeric_limits<long double>::max());
	d[vtx]=0;
	for (unsigned int i=0; i<V; ++i)
		Q[i].no=i;
	while (!Q.empty()) {
		for (unsigned int i=0; i<Q.size(); ++i)
			Q[i].distance=d[Q[i].no];
		sort (Q.begin(), Q.end(), std::less<vertex>());
		unsigned int u=Q.front().no;
		Q.erase(Q.begin());
		for (unsigned int i=0; i<V; ++i)
			if (edges[u][i] && d[i]>d[u]+weight[u][i]) d[i]=d[u]+weight[u][i];
	}
	return d;
}
