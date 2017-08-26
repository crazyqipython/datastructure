#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include <iostream>
#include <string.h>
//#include <algorithm>
//
//struct AdjListNode * newAdjListNode(int dest){
//	struct AdjListNode * newNode=
//			(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
//	newNode->dest = dest;
//	newNode->next = NULL;
//	return newNode;
//}
//
//struct Graph* createGraph(int v){
//	struct Graph * graph = (struct Graph*)malloc(
//			sizeof(struct Graph));
//	graph->v = v;
//	graph->array = (struct AdjList*)malloc(
//			v*sizeof(struct AdjList));
//	int i;
//	for(i=0; i<v; ++i){
//		graph->array[i].head = NULL;
//	}
//	return graph;
//}
//
//void addEdge(struct Graph*g, int src, int dest){
//	struct AdjListNode *newNode = newAdjListNode(dest);
//	newNode->next = g->array[src].head;
//	g->array[src].head = newNode;
//
//	//add a edge from dest to src
//	newNode = newAdjListNode(src);
//	newNode->next = g->array[dest].head;
//	g->array[dest].head = newNode;
//}
//
//void printGraph(struct Graph *graph){
//	int v;
//	for(v=0; v<graph->v; v++){
//		struct AdjListNode *pCrawl = graph->array[v].head;
//		printf("\n Adjacency list of vertex %d\n head ", v);
//		while(pCrawl!=NULL){
//			printf("-> %d", pCrawl->dest);
//			pCrawl = pCrawl->next;
//		}
//		printf("\n");
//	}
//}

Graph1::Graph1(int v){
	this->V = V;
	adj = new list<int>[V];
}

void Graph1::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph1::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for(i=adj[v].begin(); i !=adj[v].end(); i++){
		if(!visited[*i]){
			DFSUtil(*i, visited);
		}
	}
}


void Graph1::DFS(int v){
//	bool *visited = new bool[V];
//	int i;
//	for(i=0; i<V; i++){
//		visited[i] = false;
//	}

	DFSUtil(v, visited);

}

void Graph1::BFS(int s){
//	bool *visited = new bool[V];
//	for(int i=0; i<V; i++){
//		visited[i] = false;
//	}
	visited[s] = true;

	list<int> queue;
	list<int>::iterator i;
	queue.push_back(s);
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}


void Graph1::ExistPath(int u, int v, bool&has){
	visited[u] = true;
	if(u==v){
		has = true;
		return;
	}
	list<int>::iterator i;
	for(i=adj[u].begin(); i!=adj[u].end(); i++){
		if(!visited[*i]){
			this->ExistPath(*i, v, has);
		}
	}
}

void Graph1::FindAPath(int u, int v, int path[], int &l){
	visited[u]=true;
	l++;
	path[l]=u;

	if(u==v){
		for(int i=1; i<=l; i++){
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	list<int>::iterator i;
	for(i=adj[u].begin(); i!=adj[u].end(); i++){
		if(!visited[*i]){
			this->FindAPath(*i, v, path,l);
		}
	}
}

void Graph1::FindPath(int u,int v,int path[],int &l){
	visited[u] = true;
	l++;
	path[l]=u;
	if(u==v&&l>=1){
		for(int i=1; i<=l; i++){
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	list<int>::iterator i;
	for(i=adj[u].begin(); i!=adj[u].end(); i++){
		if(!visited[*i]){
			this->FindPath(*i,v,path,l);
		}
	}
	visited[u] = false;
}

int Graph1::Maxdist(int s){

	visited[s]=true;
	list<int> queue;
	list<int>::iterator i;
	queue.push_back(s);
	while(!queue.empty()){
		s =queue.front();
		queue.pop_front();
		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return s;
}


int minKey(int key[V1],  bool mstSet[V1]){
	int min_index;
	int min = INT_MAX;
	for(int i = 0; i < V1; i++){
		if(mstSet[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}


void printMST(int parent[V1], int n, int graph[V1][V1]){

	printf("mst edges is: \n");
	for(int i = 1; i < V1; i++){
		printf("%d - %d %d\n", parent[i], i, graph[parent[i]][i]);
	}
}


void primMST(int graph[V1][V1]){
	int parent[V1];
	bool mstSet[V1];
	int key[V1];

	for(int i=0; i < V1; i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for(int count=0; count < V1-1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		//update key according the u
		for(int v = 0; v < V1; v++){
			if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
				key[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}
	printMST(parent, V1, graph);
}

struct Graph *createGraph(int V, int E){
	struct Graph* graph =
	           (struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->E = E;

	graph->edge =
	        (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
	return graph;
}

int find(int parent[], int i){
	if(parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
	int xroot = find(parent, x);
	int yroot = find(parent, y);

	if(xroot != yroot)
		parent[xroot] = yroot;
}

int isCycle( struct Graph* graph ){
	int *parent = (int*) malloc( graph->V * sizeof(int) );
	memset(parent, -1, sizeof(int) * graph->V);

	for(int i = 0; i < graph->E; i++){
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		//如果相等，那么图联通
		if(x == y)
			return 1;
		//如果不相等，将两个端点连起来来，如果所有的边连起来他们的root不相等，那么不联通
		Union(parent, x, y);
	}
	return 0;
}

int find_compression(struct subnet subnets[], int i){
	if(subnets[i].parent != i)
		subnets[i].parent = find_compression(subnets, subnets[i].parent);
	return subnets[i].parent;
}

void Union_by_rank(struct subnet subnets[], int x, int y){
	int xroot = find_compression(subnets, x);
	int yroot = find_compression(subnets, y);

	if (subnets[xroot].rank < subnets[yroot].rank)
		subnets[xroot].parent = yroot;
	else if (subnets[xroot].rank > subnets[yroot].rank)
		subnets[yroot].parent = xroot;

	else{
		subnets[xroot].parent = y;
		subnets[yroot].rank++;
	}
}

int isCycle_opt(struct Graph* graph){
	int V = graph->V;
	int E = graph->E;

	// Allocate memory for creating V sets
	struct subnet *subsets =
		(struct subnet*) malloc( V * sizeof(struct subnet) );

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for(int e = 0; e < E; ++e)
	{
		int x = find_compression(subsets, graph->edge[e].src);
		int y = find_compression(subsets, graph->edge[e].dest);

		if (x == y)
			return 1;

		Union_by_rank(subsets, x, y);
	}
	return 0;
}

int myComp(const void* a, const void* b){
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph){
	int V = graph->V;
	struct Edge results[V];
	int e = 0;
	int i = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	struct subnet *subsets =
	        (struct subnet*) malloc( V * sizeof(struct subnet) );

	for(int v = 0; v < V; v++){
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while(e < V - 1){
		struct Edge next_edge = graph->edge[i++];

		int x = find_compression(subsets, next_edge.src);
		int y = find_compression(subsets, next_edge.dest);

		if(x != y){
			results[e] = next_edge;
			e++;
			Union_by_rank(subsets, x, y);
		}
	}
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", results[i].src, results[i].dest,
									  results[i].weight);
	return;
}

void floydWarshall(int graph[][V1]){
	int dist[V1][V1], i, j, k;
	for (i = 0; i < V1; i++)
	        for (j = 0; j < V1; j++)
	            dist[i][j] = graph[i][j];

	for(k = 0; k < V1; k++){
		for(i = 0; i < V1; i++){
			for(j = 0; j < V1; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution1(dist);
}

void printSolution1(int dist[][V1]){

    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
	for(int i = 0; i < V1; i++){
		for(int j = 0; j < V1; j++){
			if(dist[i][j] == INF)
				printf("%7s", "INF");
			else{
				printf("%7d", dist[i][j]);
			}
		}
		printf("\n");
	}
}
