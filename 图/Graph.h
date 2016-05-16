#pragma once
#include"Edge.h"
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
typedef int Vertex;
using std::vector;

using std::pair;


class Graph
{
public:
	explicit Graph();
	explicit Graph(bool isDirect ,const vector<Vertex >& vertexes, const vector<Edge >& edges);
	~Graph();


	vector<vector<Vertex> >m_adj;//�ڽӾ���

	vector<Vertex> m_vertexes;//���ж���

	vector<Edge> m_edges;//���б�

	int m_vertex_count;//������

	bool m_direct;//������
};
//������С�ѵĺ�������
class compare {
public:
	bool operator()(pair<Vertex, int>& p1, pair<Vertex, int>& p2) {
		return p1.second > p2.second;
	}
};

void DSF(const Graph& graph,const Vertex &start,vector<Vertex> &res, std::unordered_map<Vertex, bool>&visited);
void BSF(const Graph& graph, const Vertex &start, vector<Vertex> &res, std::unordered_map<Vertex, bool>&visited);
void ListComponents(const Graph& graph , bool BFSorDFS);//�г���ͨ����

vector<int> topSort(const Graph& graph);//��������

void dijkstra(const Graph& graph, Vertex source, vector<Vertex>& path);
void showPath(const vector<Vertex>& path, Vertex source, Vertex destination);
void showPath(const vector<vector<Vertex> >&path, Vertex source, Vertex destination);
void floyd(const Graph& graph, Vertex source, vector<vector<Vertex> >& path);