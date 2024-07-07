#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addedge(struct node *adjlist[], int u, int v)
{
    struct node *newnode = createnode(v);
    newnode->next = adjlist[u];
    adjlist[u] = newnode;
}

void bfs(struct node *adjlist[], int visited[], int startnode)
{
    int queue[10];
    int front = 0, rear = 0;
    queue[rear++] = startnode;
    visited[startnode] = 1;
    while (front != rear)
    {
        int currentnode = queue[front++];
        printf("%d", currentnode);
        struct node *temp = adjlist[currentnode];
        while (temp != NULL)
        {
            if (!(visited[temp->data]))
            {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

void dfs(struct node *adjlist[], int visited[], int vertex)
{
    struct node *temp = adjlist[vertex];
    // if (!visited[temp->data])
    {
        printf("%d ", vertex);
        visited[vertex] = 1;
    }
    while (temp != NULL)
    {
        if (visited[temp->data] == 0)
        {
            dfs(adjlist, visited, temp->data);
        }
        temp = temp->next;
    }
}
int main()
{
    int vertices;
    printf("Enter the number of vertices:");
    scanf("%d", &vertices);
    struct node *adjlist[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjlist[i] = NULL;
    }
    addedge(adjlist, 0, 1);
    addedge(adjlist, 0, 2);
    addedge(adjlist, 1, 3);
    addedge(adjlist, 1, 4);
    addedge(adjlist, 2, 4);
    int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;
    // bfs(adjlist, visited, 0);
    dfs(adjlist, visited, 0);
    return 0;
}