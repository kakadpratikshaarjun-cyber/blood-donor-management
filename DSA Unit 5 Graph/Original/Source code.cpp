#include <iostream>
#include <climits>
using namespace std;

#define MAX 20

int main()
{
    int n, graph[MAX][MAX];
    int dist[MAX], visited[MAX], parent[MAX];
    int i, j, u, v, src, dest;
    int minDist;

    cout << "Enter number of airports: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";
    cout << "(Enter 0 if no direct route exists)\n";

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    cout << "Enter source airport (0 to " << n-1 << "): ";
    cin >> src;

    for(i = 0; i < n; i++)
    {
        dist[i] = graph[src][i];
        visited[i] = 0;

        if(i != src && graph[src][i] != INT_MAX)
            parent[i] = src;
        else
            parent[i] = -1;
    }

    dist[src] = 0;

    for(i = 0; i < n; i++)
    {
        minDist = INT_MAX;
        u = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] &&
               graph[u][v] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nMinimum Flight Costs:\n";

    for(i = 0; i < n; i++)
    {
        cout << src << " to " << i << " = ";

        if(dist[i] == INT_MAX)
            cout << "Not Reachable\n";
        else
            cout << dist[i] << endl;
    }

    cout << "\nEnter destination airport: ";
    cin >> dest;

    if(dest < 0 || dest >= n)
    {
        cout << "Invalid destination!";
    }
    else if(dist[dest] == INT_MAX)
    {
        cout << "No route available!";
    }
    else
    {
        int path[MAX], count = 0;
        int temp = dest;

        while(temp != -1)
        {
            path[count++] = temp;
            temp = parent[temp];
        }

        cout << "\nShortest Route: ";

        for(i = count - 1; i >= 0; i--)
        {
            cout << path[i];

            if(i != 0)
                cout << " -> ";
        }

        cout << "\nMinimum Cost: " << dist[dest];
    }

    return 0;
}
