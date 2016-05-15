#include<iostream>
#include"Graph.h"
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	vector<Vertex> vertexes{0,1,2,3,4,5,6,7};
	vector<Edge> edges;

	edges.push_back(Edge(0,1));
	edges.push_back(Edge(0,2));
	edges.push_back(Edge(1,3));
	edges.push_back(Edge(1,4));
	edges.push_back(Edge(2,5));
	edges.push_back(Edge(2,6));
	edges.push_back(Edge(3,7));
	edges.push_back(Edge(4,7));
	edges.push_back(Edge(5,6));

	Graph graph(false,vertexes, edges);//no direct
	//cout << "DFS" << endl;
	//for (int i : vertexes) {
	//	vector<Vertex> res;
	//	std::unordered_map<Vertex, bool> visited;
	//	DSF(graph, i,res,visited);
	//	cout << "start from " << char(i + 'A') << " : ";
	//	for (auto ii : res) cout << char(ii + 'A');
	//	cout << endl;
	//}

	//cout << "BFS" << endl;
	//for (int i : vertexes) {
	//	vector<Vertex> res;
	//	std::unordered_map<Vertex, bool> visited;
	//	BSF(graph, i, res, visited);
	//	cout << "start from " << char(i + 'A') << " : ";
	//	for (auto ii : res) cout << char(ii + 'A');
	//	cout << endl;
	//}
	ListComponents(graph,0);

	ListComponents(graph, 1);
	system("pause");
}