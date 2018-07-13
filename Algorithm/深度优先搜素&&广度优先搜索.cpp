// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdafx.h"
#include <stdarg.h>
#include <iostream>

#include <string>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <memory.h>

using namespace std;

class graph {
public :
	graph(int v) :vertex(v) { adj = new list<int>[v]; };
	void addEdge(int v, int w);
	void DFS();
	void DFS(int v);
	void BFS(int v);
private :
	int vertex;
	list<int> * adj;
	void DFSUtils(int v, bool visited[]);
};

void graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void graph::DFSUtils(int v, bool visited[]) {
	visited[v] = true;//置位
	cout << v << " ";
	list<int>::iterator iter;
	for (iter = adj[v].begin(); iter != adj[v].end(); iter++) {
		if (!visited[*iter]) {
			DFSUtils(*iter, visited);
		}
	}
}

void graph::DFS() {
	bool * visited = new bool[vertex];
	memset(visited,false,vertex);
	for (int i = 0; i < vertex; i++) {
		if(!visited[i])
			DFSUtils(i,visited);
	}

}

void graph::DFS(int v) {
	bool * visited = new bool[vertex];
	memset(visited, false, vertex);

	DFSUtils(v, visited);
}

void graph::BFS(int v) {
	bool * visited = new bool[vertex];
	memset(visited,false,vertex);
	list<int> q;
	visited[v] = true;
	q.push_back(v);
	list<int>::iterator iter;
	while (!q.empty()) {
		v = q.front();

		cout << v << " ";
		q.pop_front();

		for (iter = adj[v].begin(); iter != adj[v].end(); iter++) {
			if (!visited[*iter]) {
				visited[*iter] = true;
				q.push_back(*iter);
			}
		}
	}
}

int main(int argc, char** argv)
{
	graph g(5);
	g.addEdge(0, 1);//生成无向图  
	g.addEdge(0, 4);
	g.addEdge(1, 0);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 0);
	g.addEdge(4, 1);

	g.BFS(0);

	std::cin.get();
	return 0;
}