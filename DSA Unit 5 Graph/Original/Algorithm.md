## Algorithm

Step 1: Start the program.

Step 2: Input the number of airports (vertices) and flight connections (edges).

Step 3: Represent the airport network using a weighted graph.

Step 4: Input the source airport and destination airport.

Step 5: Initialize the distance of the source airport to 0 and all other airports to infinity.

Step 6: Mark all airports as unvisited.

Step 7: Select the unvisited airport having the minimum distance.

Step 8: Update the distances of its adjacent airports if a shorter route is found. Store their parent vertices.

Step 9: Mark the selected airport as visited.

Step 10: Repeat Steps 7–9 until all reachable airports are processed.

Step 11: Display the minimum travel cost from the source airport to all reachable airports.

Step 12: Reconstruct the shortest route to the selected destination using the parent vertices.

Step 13: Display the shortest route and its total cost. If the destination is unreachable, display an appropriate message.

Step 14: Stop the program.
