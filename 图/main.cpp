#include<iostream>
#include"Graph.h"
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
int main() {
	//±éÀú
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
	Graph graph(false,vertexes, edges);//true: direct
	ListComponents(graph,0);
	ListComponents(graph, 1);

	//ÍØÆËÅÅĞò
	cout << "ÍØÆËÅÅĞò : " << endl;
	vector<Vertex> vertexes2{0,1,2,3,4,5,6,7,8,9,10,11,12};
	vector<Edge> edges2;
	edges2.push_back(Edge(0,1));
	edges2.push_back(Edge(0,5));
	edges2.push_back(Edge(0,6));
	edges2.push_back(Edge(2,0));
	edges2.push_back(Edge(2,3));
	edges2.push_back(Edge(3,5));
	edges2.push_back(Edge(5,4));
	edges2.push_back(Edge(6,4));
	edges2.push_back(Edge(6,9));
	edges2.push_back(Edge(7,6));
	edges2.push_back(Edge(8,7));
	edges2.push_back(Edge(9,10));
	edges2.push_back(Edge(9,11));
	edges2.push_back(Edge(9,12));
	edges2.push_back(Edge(11,12));
	Graph graph2(true, vertexes2, edges2);//ÓĞÏòÎŞ»·Í¼
	vector<int> topsort = topSort(graph2);
	for (auto t : topsort) cout << t << " ";
	cout << endl;

	ListComponents(graph2, 0);
	ListComponents(graph2, 1);


	
	vector<Vertex> vertexes3{ 0,1,2,3,4};
	vector<Edge> edges3;
	edges3.push_back(Edge(0,1,100));
	edges3.push_back(Edge(0,2,30));
	edges3.push_back(Edge(0,4,10));
	edges3.push_back(Edge(2,1,60));
	edges3.push_back(Edge(2,3,60));
	edges3.push_back(Edge(3,1,10));
	edges3.push_back(Edge(4,3,50));
	Graph graph3(true, vertexes3, edges3);
	vector<int>path;
	Vertex source = 0;
	cout << "dijkstra :" << endl;
	dijkstra(graph3, source, path);
	for (auto destination : vertexes3) {
		if(destination!=source) showPath(path, source, destination);
	}


	cout << "floyd :" << endl;
	vector<vector<Vertex> >path2;
	floyd(graph3, source, path2);
	for (auto destination : vertexes3) {
		if (destination != source) showPath(path2, source, destination);
	}
	system("pause");
}