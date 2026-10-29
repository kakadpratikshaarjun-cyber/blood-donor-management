#include <iostream>
using namespace std;

#define MAX 20
#define INF 999999999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

int n, source;

// Dijkstra Algorithm
void dijkstra()
{
    int i, j, u, minDist;

    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for(i = 0; i < n; i++)
    {
        minDist = INF;
        u = -1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(graph[u][j] > 0 && visited[j] == 0)
            {
                if(dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                    parent[j] = u;
                }
            }
        }
    }
}

// Display Minimum Costs
void displayCosts()
{
    int i;

    cout << "\nMinimum Travel Costs:\n";

    for(i = 0; i < n; i++)
    {
        cout << source << " to " << i << " = ";

        if(dist[i] == INF)
            cout << "Not Reachable";
        else
            cout << dist[i];

        cout << endl;
    }
}

// Display Shortest Path
void displayPath(int destination)
{
    int path[MAX];
    int count = 0;
    int i;
    int temp = destination;

    while(temp != -1)
    {
        path[count] = temp;
        count++;
        temp = parent[temp];
    }

    cout << "\nShortest Route: ";

    for(i = count - 1; i >= 0; i--)
    {
        cout << path[i];

        if(i > 0)
            cout << " -> ";
    }
}

int main()
{
    int i, j;
    int choice, destination;
    int u, v, cost;

    cout << "Enter number of airports (1-20): ";
    cin >> n;

    if(n < 1 || n > MAX)
    {
        cout << "Invalid number of airports!";
        return 0;
    }

    cout << "\nEnter Cost Adjacency Matrix:\n";
    cout << "(Enter 0 for no direct flight)\n";

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if(graph[i][j] < 0 || graph[i][j] > 1000000)
            {
                cout << "Invalid flight cost!";
                return 0;
            }
        }
    }

    cout << "\nEnter Source Airport (0 to " << n-1 << "): ";
    cin >> source;

    if(source < 0 || source >= n)
    {
        cout << "Invalid Source Airport!";
        return 0;
    }

    do
    {
        cout << "\n\n===== AIRPORT ROUTE OPTIMIZATION =====";
        cout << "\n1. Calculate Minimum Travel Costs";
        cout << "\n2. Display Shortest Route";
        cout << "\n3. Change Source Airport";
        cout << "\n4. Update Flight Cost";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                dijkstra();
                displayCosts();
                break;
            }

            case 2:
            {
                cout << "\nEnter Destination Airport: ";
                cin >> destination;

                if(destination < 0 || destination >= n)
                {
                    cout << "Invalid Destination!";
                    break;
                }

                dijkstra();

                if(dist[destination] == INF)
                {
                    cout << "No Route Available!";
                }
                else
                {
                    displayPath(destination);
                    cout << "\nMinimum Cost: "
                         << dist[destination] << endl;
                }

                break;
            }

            case 3:
            {
                cout << "\nEnter New Source Airport: ";
                cin >> u;

                if(u >= 0 && u < n)
                {
                    source = u;
                    dijkstra();
                    displayCosts();
                }
                else
                {
                    cout << "Invalid Airport!";
                }

                break;
            }

            case 4:
            {
                cout << "\nEnter Two Airports: ";
                cin >> u >> v;

                if(u < 0 || u >= n || v < 0 || v >= n || u == v)
                {
                    cout << "Invalid Airports!";
                    break;
                }

                cout << "Enter New Flight Cost: ";
                cin >> cost;

                if(cost < 0 || cost > 1000000)
                {
                    cout << "Invalid Cost!";
                    break;
                }

                graph[u][v] = cost;
                graph[v][u] = cost;

                cout << "\nFlight Cost Updated Successfully!";

                dijkstra();
                displayCosts();

                break;
            }

            case 5:
            {
                cout << "\nProgram Ended Successfully!";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!";
            }
        }

    } while(choice != 5);

    return 0;
}
