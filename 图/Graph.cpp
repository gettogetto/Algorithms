#include "Graph.h"
#include<iostream>
using std::queue;
using std::cout;
using std::endl;

Graph::Graph()
{
}

Graph::Graph(bool isDirect , const vector<Vertex >& vertexes,const vector<Edge >& edges)
{
	this->m_direct = isDirect;

	int num = edges.size();

	this->m_adj.resize(num);
	this->m_vertexes = vertexes;

	for (auto edge : edges) {
		m_adj[edge.m_begin].push_back(edge.m_end);
		if (!m_direct) m_adj[edge.m_end].push_back(edge.m_begin);
	}


	this->m_vertex_count = vertexes.size();
}

Graph::~Graph()
{
}

void DSF(const Graph& graphy, const Vertex &start, vector<Vertex> &res, std::unordered_map<Vertex,bool>&visited) {
	visited[start] = true;
	res.push_back(start);
	for (auto point : graphy.m_adj[start]) {
		if (!visited[point]) {
			DSF(graphy,point,res,visited);
		}
	}
}

void BSF(const Graph& graphy, const Vertex &start, vector<Vertex> &res, std::unordered_map<Vertex, bool>&visited) {
	visited[start] = true;
	res.push_back(start);
	queue<Vertex> q;
	q.push(start);
	while (!q.empty()) {
		Vertex tmp = q.front();
		q.pop();
		for (auto point : graphy.m_adj[tmp]) {
			if (!visited[point]) {
				visited[point] = true;
				q.push(point);
				res.push_back(point);
			}
		}
	}
}

void ListComponents(const Graph& graph , bool BFSorDFS) {
	/*BFS:1 DFS:0*/
	BFSorDFS ? cout << "BFS"<<endl :cout<< "DFS"<<endl;
	for (int i : graph.m_vertexes) {
		vector<Vertex> res;
		std::unordered_map<Vertex, bool> visited;
		BFSorDFS? DSF(graph, i, res, visited): BSF(graph, i, res, visited);
		cout << "start from " << char(i + 'A') << " : ";
		for (auto ii : res) cout << char(ii + 'A');
		cout << endl;
	}
	
}