#pragma once
#include"Edge.h"
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
typedef int Vertex;
using std::vector;
using std::list;


class Graph
{
public:
	explicit Graph();
	explicit Graph(bool isDirect ,const vector<Vertex >& vertexes, const vector<Edge >& edges);
	~Graph();


	vector<vector<Vertex> >m_adj;

	vector<Vertex> m_vertexes;

	int m_vertex_count;

	bool m_direct;
};

void DSF(const Graph& graph,const Vertex &start,vector<Vertex> &res, std::unordered_map<Vertex, bool>&visited);
void BSF(const Graph& graph, const Vertex &start, vector<Vertex> &res, std::unordered_map<Vertex, bool>&visited);
void ListComponents(const Graph& graph , bool BFSorDFS);