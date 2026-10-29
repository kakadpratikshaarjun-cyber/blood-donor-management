## Algorithm

Step 1: Start the program.

Step 2: Input the number of airports and flight connections.

Step 3: Represent the airport network using a weighted adjacency matrix.

Step 4: Input the source airport and destination airport.

Step 5: Initialize the source distance to 0 and all other distances to infinity. Mark all airports as unvisited.

Step 6: Select the unvisited airport having the minimum distance.

Step 7: Update the distances of adjacent airports if a shorter route is found and store their parent vertices.

Step 8: Mark the selected airport as visited.

Step 9: Repeat Steps 6–8 until all reachable airports are processed.

Step 10: Display the minimum travel costs from the source airport to all reachable airports.

Step 11: Reconstruct and display the complete shortest route to the selected destination using parent vertices.

Step 12: Provide options to:
   a) Change the source airport.
   b) Update flight connection costs.
   c) Display the shortest paths again.
   d) Exit the program.

Step 13: If the source is changed or flight costs are updated, run Dijkstra's algorithm again using the updated information.

Step 14: Repeat until the user selects Exit.

Step 15: Stop the program.
