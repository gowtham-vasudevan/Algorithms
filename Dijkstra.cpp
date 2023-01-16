#include <bits/stdc++.h>

/* Dijsktra's Algorithm is a greedy algorithm which was originally for finding the shortest path between two nodes in a graph. But a more common variant is used which
    is to find the shortest path of all the other nodes from a source node.
*/
int dijkstra(const std::vector<std::vector<int>>& adj, int& n)
{
    /* Create a distance matrix to keep record of the minimum distance of each node with the required node (first node in this example) and initialize all the 
       values to INT_MAX  except for the node from which we're trying to calculate the minimum distance.
           
    */
  
    std::vector<int> distance(n, INT_MAX);
    distance[0] = 0; // Initializing the distance of the node itself to 0.
    int i = 0, count = 0;
  
    /*count is the variable that tells us the number of nodes for which we've calculated the shortest distance to, from the source node.
      Initially count will be 0 since we have not found the shortest path to any node. For each iteration we increment the count. 
    */

  /* Iterate through the input vector to and check if the distance present in the distance vector is less than the value in the 'adj' vector plus the distance to
     the vector from the current node. If the value is lesser, then update the current value to the distance vectorand continue the iteration.
  */
    while(i < n && count < n)
    {
        int minimum = INT_MAX, ind = -1;
        for(int j=0; j<adj[i].size(); j++)
        {
            if(adj[i][j])
            {
                if(distance[i] + adj[i][j] < distance[j])
                {
                    distance[j] = distance[i] + adj[i][j];
                    if(distance[j] < minimum) ind = j, minimum = distance[j];
                }
            }
        }
        count++;
        if(ind >= 0) i = ind;
        else break;
    }
    for(int i:distance) std::cout<<i<<"  ";
    return distance[n-1];
}

int main()
{
    std::vector<std::vector<int>> adj =  {{0,2,4,0,0,0},{0,0,1,7,0,0},{0,0,0,0,3,0}, {0,0,0,0,0,1},{0,0,0,2,0,5},{0,0,0,0,0,0}};

    int n = 6;

    std::cout << dijkstra(adj, n);

    return 0;
}
