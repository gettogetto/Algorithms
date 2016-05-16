#pragma once

class Edge
{
public:
	explicit Edge();
	explicit Edge(int begin, int end, int weight=1);
	~Edge();
	int m_begin;
	int m_end;
	int m_weight;
};

