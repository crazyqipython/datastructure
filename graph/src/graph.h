#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <limits.h>

#define V1 4
#define INF INT_MAX
using namespace std;

static bool visited[4] = {false, false, false, false};
struct AdjListNode{
	int dest;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Edge{
	int src, dest, weight;
};

struct Graph{
	int V,E;
	struct Edge* edge;
};

struct Graph *createGraph(int V, int E);

//并查集
int find(int parent[], int i);
void Union(int parent[], int x, int y);
int isCycle(struct Graph *graph);

//使用rank和路径压缩实现并查集
struct subnet{
	int parent;
	int rank;
};

int find_compression(struct subnet subnets[], int i);
void Union_by_rank(struct subnet subnets[], int, int);
int isCycle_opt(struct Graph* graph);

struct AdjListNode * newAdjListNode(int dest);
struct Graph* createGraph(int v);
void addEdge(struct Graph*g, int src, int dest);
void printGraph(struct Graph *graph);


class Graph1{
	private:
		int V;
		list<int>* adj;
		void DFSUtil(int v, bool visited[]);
	public:
		Graph1(int V);
		void addEdge(int v, int w);
		void DFS(int v);
		void BFS(int s);
		//判断是否有简单路径
		void ExistPath(int u, int v, bool&has);
		//输出u->v的简单路径
		void FindAPath(int u, int v, int path[], int &l);
		void FindPath(int u,int v,int path[],int &l);
		int Maxdist(int v);
};

//prime algorithm
int minKey(int [], bool []);
void printMST(int [], int n, int graph[V1][V1]);
void primMST(int graph[V1][V1]);
void KruskalMST(struct Graph* graph);

//dynamic programing floyd
void floydWarshall(int graph[][V1]);
void printSolution1(int dist[][V1]);
#endif /* GRAPH_H_ */
