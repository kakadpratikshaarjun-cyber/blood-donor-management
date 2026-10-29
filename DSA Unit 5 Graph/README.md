##Airport Route Optimization Using Dijkstra's Algorithm

1. Problem Statement

Develop a C++ program to represent airports as vertices and flight connections as weighted edges, where weights represent route costs. Apply Dijkstra's algorithm from a selected airport, display minimum costs to reachable airports, and reconstruct the shortest route to a selected destination.

2. Objectives

1. To represent airport connections using a weighted graph.
2. To implement Dijkstra's shortest path algorithm.
3. To calculate minimum flight costs.
4. To identify the shortest route between airports.
5. To display the shortest path and its total cost.
6. To handle unreachable destinations.

3. Concept Used

- Data Structure: Weighted Graph
- Graph Representation: Adjacency Matrix
- Algorithm: Dijkstra's Algorithm
- Programming Language: C++
- Approach: Greedy Method

4. Algorithm

Step 1: Start the program.

Step 2: Input the number of airports and cost adjacency matrix.

Step 3: Input the source airport.

Step 4: Initialize the source distance to 0 and all other distances to infinity.

Step 5: Mark all airports as unvisited.

Step 6: Select the unvisited airport having the minimum distance.

Step 7: Update the distances of adjacent airports if a shorter route is found. Store their parent vertices.

Step 8: Mark the selected airport as visited.

Step 9: Repeat Steps 6–8 until all reachable airports are processed.

Step 10: Display minimum flight costs from the source airport.

Step 11: Input the destination airport.

Step 12: Check whether the destination is valid and reachable.

Step 13: Reconstruct the shortest route using parent vertices.

Step 14: Display the shortest route and minimum cost, or an appropriate error message.

Step 15: Stop the program.

5. Sample Output

Enter number of airports: 5

Enter cost adjacency matrix:
(Enter 0 if no direct route exists)

0 10 0 5 0
10 0 1 2 0
0 1 0 9 4
5 2 9 0 2
0 0 4 2 0

Enter source airport (0 to 4): 0

Minimum Flight Costs:
0 to 0 = 0
0 to 1 = 7
0 to 2 = 8
0 to 3 = 5
0 to 4 = 7

Enter destination airport: 2

Shortest Route: 0 -> 3 -> 1 -> 2
Minimum Cost: 8

6. Time and Space Complexity

- Time Complexity: O(V²)
- Space Complexity: O(V²)
- V represents the number of airports.

7. Applications

1. Airline route optimization.
2. Transportation network planning.
3. GPS navigation systems.
4. Minimum-cost path identification.
5. Network routing applications.

8. Advantages

1. Finds minimum-cost routes efficiently.
2. Easy to implement using an adjacency matrix.
3. Supports multiple airport connections.
4. Identifies unreachable destinations.
5. Displays the complete shortest route.

9. Limitations

1. Does not support negative edge weights.
2. Maximum 20 airports in the given implementation.
3. Uses a static adjacency matrix.
4. Does not consider real-time flight availability.

10. Conclusion

The program successfully implements Dijkstra's algorithm to determine minimum flight costs and find the shortest route between selected airports using a weighted graph.









###Airport Route Optimization Using Dijkstra's Algorithm (Modified)

1. Problem Statement

Develop a C++ program to represent airports as vertices and flight connections as weighted edges, where weights indicate route costs. Implement Dijkstra's algorithm to calculate minimum travel costs from a selected source airport to all reachable airports and display the complete shortest path to a chosen destination. The program should allow users to change the source airport, update flight connection costs, and recalculate the shortest paths accordingly.

2. Objectives

1. To represent airports and flight connections using a weighted graph.
2. To implement Dijkstra's shortest path algorithm in C++.
3. To calculate minimum travel costs from a selected source airport.
4. To display the complete shortest route to a chosen destination.
5. To allow users to change the source airport dynamically.
6. To update flight connection costs and recalculate shortest paths.
7. To identify unreachable airports.

3. Concept Used

- Data Structure: Weighted Graph
- Representation: Adjacency Matrix
- Algorithm: Dijkstra's Algorithm
- Technique: Greedy Approach
- Programming Language: C++
- Modification: Dynamic source selection and flight cost updates.

4. Algorithm

Step 1: Start the program.

Step 2: Input the number of airports and flight connections.

Step 3: Create a weighted adjacency matrix to store route costs.

Step 4: Input the source airport and destination airport.

Step 5: Initialize all distances to infinity, source distance to 0, and mark all airports as unvisited.

Step 6: Select the unvisited airport having the minimum distance.

Step 7: Update the distances of adjacent airports if a shorter route is found.

Step 8: Store the parent vertex whenever a shorter route is identified.

Step 9: Mark the selected airport as visited.

Step 10: Repeat Steps 6–9 until all reachable airports are processed.

Step 11: Display minimum travel costs from the source airport.

Step 12: Reconstruct and display the shortest route to the selected destination.

Step 13: Display the following menu:

1. Change Source Airport
2. Update Flight Connection Cost
3. Recalculate Shortest Paths
4. Exit

Step 14: If the source airport is changed, accept the new source and run Dijkstra's algorithm again.

Step 15: If a flight cost is updated, modify the adjacency matrix and recalculate the shortest paths.

Step 16: Repeat the process until the user selects Exit.

Step 17: Stop the program.

5. Modifications Made

The original program calculates the shortest path from a fixed source airport.

The modified program introduces additional features:

1. Allows users to change the source airport.
2. Allows modification of existing flight connection costs.
3. Recalculates shortest paths after changes.
4. Provides a menu-driven interface.
5. Displays updated minimum travel costs and routes.

6. Time and Space Complexity

- Time Complexity: O(V²) per Dijkstra execution.
- Space Complexity: O(V²).
- V represents the number of airports.

7. Applications

1. Airline route optimization.
2. Transportation network planning.
3. Flight cost comparison.
4. GPS navigation systems.
5. Shortest-path calculation in weighted networks.

8. Advantages

1. Calculates minimum travel costs efficiently.
2. Allows flexible source airport selection.
3. Supports flight cost modifications.
4. Displays complete shortest routes.
5. Provides updated results after network changes.

9. Limitations

1. Dijkstra's algorithm does not support negative edge weights.
2. An adjacency matrix requires O(V²) memory.
3. Route costs must be entered manually.
4. The program does not consider real-time flight delays or availability.

10. Conclusion

The modified program successfully implements Dijkstra's algorithm for airport route optimization. It allows users to change the source airport, update flight costs, and recalculate the shortest paths, making the system more flexible and useful for route planning.
