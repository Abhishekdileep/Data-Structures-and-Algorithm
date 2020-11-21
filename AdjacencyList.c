#include<stdio.h>
#include<stdlib.h>

struct NODE {
    int vertex;
    struct NODE* next;
};

typedef struct NODE* Node;

struct GRAPH {
    int numVertices ; 
    Node* adjList;
};

typedef struct GRAPH* Graph;

Node createNode(int val){
    Node temp = (Node)malloc(sizeof(struct NODE));
    temp->vertex = val;
    temp->next = NULL;
    return temp;
}

Graph createGraph(int vertices){
    Graph temp = (Graph ) malloc(sizeof(struct GRAPH));
    temp->numVertices = vertices;
    temp->adjList = (Node)malloc(vertices * sizeof(Node)); //Adjaceny list is just a list of Pointers and not acutal data is Stored hence Node is used not NODE 
    int i=0;
    while( i < vertices ){
        temp->adjList[i] = NULL;
        i++;
    }
    return temp;
}

Graph addEdge(int s , int d , Graph graph){
    // for edge d to s  
    Node temp = (Node)malloc(sizeof(struct NODE));
    temp->vertex = s;
    temp->next = graph->adjList[d];
    graph->adjList[d] = temp;

    // for edge s to d
    temp = (Node)malloc(sizeof(struct NODE));
    temp->vertex = d;
    temp->next = graph->adjList[s];
    graph->adjList[s] = temp;

    return graph;
}

void printGraph(Graph graph){
    Node temp ;
    int v; 
    for(v=0;v<graph->numVertices;v++){
        temp =  graph->adjList[v];
        printf("Vertex %d --> ",v);
        while(temp){
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}


int main(){

    Graph graph = createGraph(4);
    addEdge(0 , 1 ,graph);
    addEdge(0 , 2 ,graph);
    addEdge(0 , 3 ,graph);
    addEdge(1 , 2 ,graph);

    printGraph(graph);
    return 0;
}