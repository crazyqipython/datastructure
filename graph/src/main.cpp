#include <stdio.h>
#include <iostream>
#include "graph.h"


int main(int argc, const char *argv[])
{
//	int v=5;
//	struct Graph* graph = createGraph(v);
//	addEdge(graph, 0, 1);
//	addEdge(graph, 0, 4);
//	addEdge(graph, 1, 2);
//	addEdge(graph, 1, 3);
//	addEdge(graph, 1, 4);
//	addEdge(graph, 2, 3);
//	addEdge(graph, 3, 4);
//	printGraph(graph);
//	return 0;
//	Graph1 g(4);
//	g.addEdge(0, 1);
//	g.addEdge(0, 2);
//	g.addEdge(1, 2);
//	g.addEdge(2, 0);
//	g.addEdge(2, 3);
//	g.addEdge(3, 3);
//	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
////	g.DFS(2);
//	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
//	g.BFS(2);
//	printf("\n");
//	bool has;
//	printf("%d\n", has);
//	g.ExistPath(2,3, has);
//	printf("%d\n", has);

//	//²âÊÔfind a path
//	int path[13];
//	int l=0;
//	g.FindPath(0,1,path,l);
//	printf("%d ", l);
//	printf("%d",g.Maxdist(0));

	//test prime algorithm
//	{
//		int graph[V1][V1] = {{0, 2, 0, 6, 0},
//		                      {2, 0, 3, 8, 5},
//		                      {0, 3, 0, 0, 7},
//		                      {6, 8, 0, 0, 9},
//		                      {0, 5, 7, 9, 0},
//		                     };
//		primMST(graph);
//
//		return 0;
//
//	}
//	{
//	int V = 3;
//	int E = 3;
//	struct Graph *graph = createGraph(V, E);
//
//	graph->edge[0].src = 0;
//	graph->edge[0].dest = 1;
//	graph->edge[1].src = 1;
//	graph->edge[1].dest = 2;
//	graph->edge[2].src = 2;
//	graph->edge[2].dest = 0;
//
//	if (isCycle_opt(graph))
//		printf( "graph contains cycle" );
//	else
//		printf("graph not contains a cycle.");
//	}
//}

//	{
//		int V = 4;  // Number of vertices in graph
//		int E = 5;  // Number of edges in graph
//		struct Graph* graph = createGraph(V, E);
//		// add edge 0-1
//		graph->edge[0].src = 0;
//		graph->edge[0].dest = 1;
//		graph->edge[0].weight = 10;
//
//		// add edge 0-2
//		graph->edge[1].src = 0;
//		graph->edge[1].dest = 2;
//		graph->edge[1].weight = 6;
//
//		// add edge 0-3
//		graph->edge[2].src = 0;
//		graph->edge[2].dest = 3;
//		graph->edge[2].weight = 5;
//
//		// add edge 1-3
//		graph->edge[3].src = 1;
//		graph->edge[3].dest = 3;
//		graph->edge[3].weight = 15;
//
//		// add edge 2-3
//		graph->edge[4].src = 2;
//		graph->edge[4].dest = 3;
//		graph->edge[4].weight = 4;
//
//		KruskalMST(graph);
//
//		return 0;
//	}
	{
		int graph[V1][V1] = { {0,   5,  INF, 10},
		                      {INF, 0,   3, INF},
		                      {INF, INF, 0,   1},
		                      {INF, INF, INF, 0}
		                      };
		floydWarshall(graph);
		return 0;
	}
}
