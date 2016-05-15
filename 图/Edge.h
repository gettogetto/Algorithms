#pragma once

class Edge
{
public:
	explicit Edge();
	explicit Edge(int begin, int end);
	~Edge();
	int m_begin;
	int m_end;
};

