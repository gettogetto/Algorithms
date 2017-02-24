#include "Graph.h"
#include<iostream>
#include<functional>
#include<stack>
#include<algorithm>
using std::queue;
using std::cout;
using std::endl;
using std::priority_queue;
using std::greater;
using std::stack;
using std::pair;
Graph::Graph()
{
}

Graph::Graph(bool isDirect , const vector<Vertex >& vertexes,const vector<Edge >& edges)
{
	this->m_direct = isDirect;

	int num = edges.size();

	this->m_adj.resize(num);
	this->m_vertexes = vertexes;
	this->m_edges = edges;

	for (auto edge : edges) {
		m_adj[edge.m_begin].push_back(edge.m_end);
		if (!m_direct) m_adj[edge.m_end].push_back(edge.m_begin);
	}


	this->m_vertex_count = vertexes.size();
}

Graph::~Graph()
{
}


//全局函数
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
//列出联通分量
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
/*
对一个有向无环图(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，使
得图中任意一对顶点u和v，若边(u,v)∈E(G)，则u在线性序列中出现在v之前。通常，这样的线性序列称为满足拓扑次序
(Topological Order)的序列，简称拓扑序列。简单的说，由某个集合上的一个偏序得到该集合上的一个全序，这个操作称之为拓扑排序。
*/
vector<int> topSort(const Graph& graph) {
	if (graph.m_direct == false) {
		cout << "error:graph should be directed!" << endl;
		return vector<int>();
	}
	int num = graph.m_vertex_count;
	vector<int>res;
	vector<int> indegree(num, 0);
	for (auto edge : graph.m_edges) {
		indegree[edge.m_end]++;
	}

	queue<int> q;
	for (Vertex i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res.push_back(i);
		}
	}

	while (!q.empty()) {
		Vertex v = q.front();
		q.pop();
		for (Vertex j = 0; j < graph.m_adj[v].size(); j++) {
			Vertex w = graph.m_adj[v][j];
			if (--indegree[w] == 0) {
				q.push(w);
				res.push_back(w);
			}
		}
	}
	if (int(res.size() ) != num) {
		cout << "error:graph has circle!" << endl;
		return vector<int>();
	}
	return res;
}


//单源最短路径dijkstra,不能有负边
void dijkstra(const Graph& graph, Vertex source, vector<Vertex>& path) {
	int num = graph.m_vertex_count;
	path.resize(num);
	vector<vector<Vertex> > weight(num, vector<Vertex>(num,INT32_MAX));
	//初始化
	for (Vertex i = 0; i < num; i++) {
		weight[i][i] = 0;
	}
	for (auto edge : graph.m_edges) {
		Vertex i = edge.m_begin;
		Vertex j = edge.m_end;
		if (edge.m_weight < 0) {
			cout << "error:graph has negative weight" << endl;
			return ;
		}
		weight[i][j] = edge.m_weight;
	}
	vector<Vertex> dist(num,INT32_MAX);//dist[i]值source到i的最小路径

	vector<bool> collected(num,false);//是否已收入
	priority_queue < pair<Vertex, int>, vector< pair<Vertex, int> >, compare> pq;//最小堆

	for (Vertex i = 0; i < num; i++) {
		dist[i] = weight[source][i];
		pq.push({ i,dist[i] });
		if (dist[i] == INT32_MAX) path[i] = -1;
		else path[i] = source;
	}
	collected[source] = true;
	pq.pop();

	while (!pq.empty()) {
		Vertex v = pq.top().first;
		pq.pop();
		if (collected[v] == true) continue;//碰到已收录的点，直接跳过
		else collected[v] = true;
		for (auto w : graph.m_adj[v]) {
			if (collected[w] == false) {
				if (dist[v]<INT32_MAX&&weight[v][w] < INT32_MAX&&long(dist[v] + weight[v][w]) <INT32_MAX&&dist[v] + weight[v][w] < dist[w]) {
					dist[w] = dist[v] + weight[v][w];
					pq.push({ w,dist[w] });//!!!!!更新堆中相应的{w,dist[w]}，更新只是把新的键值对放入堆中，并没有删掉旧的对，但是新的一定在旧的之前被pop，并会将其标志为已收录，当旧的被pop出来，会发现此点已收录，所以上面直接continue
					path[w] = v;
				}
			}
		}
	}
}
void showPath(const vector<Vertex>& path,Vertex source,Vertex destination) {
	stack<int>s;
	while (source != destination) {
		if (destination == -1) return;
		s.push(destination);
		destination = path[destination];
	}
	s.push(source);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

//Floyd多源最短路径
void floyd(const Graph& graph, Vertex source, vector<vector<Vertex >>& path) {
	int num = graph.m_vertex_count;
	path.resize(num);
	for (int i = 0; i < num; i++) path[i].resize(num);

	vector<vector<Vertex> > weight(num, vector<Vertex>(num, INT32_MAX));
	//初始化
	for (Vertex i = 0; i < num; i++) {
		weight[i][i] = 0;
		path[i][i] = i;
	}
	for (auto edge : graph.m_edges) {
		Vertex i = edge.m_begin;
		Vertex j = edge.m_end;
		if (edge.m_weight < 0) {
			cout << "error:graph has negative weight" << endl;
			return;
		}
		weight[i][j] = edge.m_weight;
		path[i][j] = i;
	}

	for (Vertex k = 0; k < num; k++) {
		for (Vertex i = 0; i < num; i++) {
			for (Vertex j = 0; j < num; j++) {
				if (weight[i][k] < INT32_MAX&&weight[k][j] < INT32_MAX&&long(weight[i][k] + weight[k][j])<INT32_MAX&&weight[i][k] + weight[k][j] < weight[i][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

}

void showPath(const vector<vector<Vertex> >&path, Vertex source, Vertex destination) {
	stack<int>s;
	if (destination == -1) return;
	while (source != destination) {
		s.push(destination);
		destination = path[source][destination];
	}
	s.push(source);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
