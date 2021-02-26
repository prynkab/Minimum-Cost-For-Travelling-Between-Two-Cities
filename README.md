# Shortest Path Between Two Cities And Minimum Cost 
This project calculates the minimum cost requuired to travel from any starting city to the rest of the city and the path required.  

Objectives:  
  - Implement a data structure to meet given specifications
  - Design, implement, and use djikstra's algorithm to code  

Aim: To implement djikstra's algorithm to find the minimum cost required to travel between two cities and the required path.  

Procedure:  
  - Create cost matrix C[][] from the adjacency matrix adj[][]. C[i][j] is the cost to go from city i to j. If there is no edge between i and j and C[i][j] is infinity.
  - Array visited[] is initialized to zero.
  - If the vertex 0 is the source vertex then visited is initialized to 1.
  -  Create and distance matrix, by storing the cost of vertices from vertex no. 0 to n-1 from the source vertex 0. Initially, distance of source vertex is taken is as 0, i.e distance[0]=0;
  - for (i=1;i<n;i++)
    - Choose a vertex w, such that distance[w] is minimum and visited[w] is 0. Mark visited[w] as 1.
    - Recalculate the shortest distance of the remaining vertices from the source.
    - Only the vertices not marked as 1 in array visited[] should be considered for recalculation of distance i.e for each vertex v if(visited[v]==0) distance[v]=min(distance[v],distance[w]+cost[w][v]
  - This function is initialised in the main program with predefined values for cost between cities. Example program operation:
          
          Select the starting city from:
              0-> Pune
              1->Kolkata
              2->Bangalore
              3->Delhi
              4->Mumbai
              5->Vizag
              6->Ahmedabad
              7->Puri
              8->Indore
              9->Goa
              10->Lucknow
              11->Hyderabad
              12->Chennai
              13->Guwahati

          Enter the starting city:10

          Cost of travelling to the city Pune=Rs 1188
          Path=Pune<-Lucknow

          Cost of travelling to the city Kolkata=Rs 2328
          Path=Kolkata<-Pune<-Lucknow

          Cost of travelling to the city Bangalore=Rs 3548
          Path=Bangalore<-Ahmedabad<-Pune<-Lucknow

          Cost of travelling to the city Delhi=Rs 3458
          Path=Delhi<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Mumbai=Rs 2298
          Path=Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Vizag=Rs 3418
          Path=Vizag<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Ahmedabad=Rs 2338
          Path=Ahmedabad<-Pune<-Lucknow

          Cost of travelling to the city Puri=Rs 4548
          Path=Puri<-Vizag<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Indore=Rs 3498
          Path=Indore<-Ahmedabad<-Pune<-Lucknow

          Cost of travelling to the city Goa=Rs 3438
          Path=Goa<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Hyderabad=Rs 3588
          Path=Hyderabad<-Delhi<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Chennai=Rs 4708
          Path=Chennai<-Hyderabad<-Delhi<-Mumbai<-Pune<-Lucknow

          Cost of travelling to the city Guwahati=Rs 4713
          Path=Guwahati<-Bangalore<-Ahmedabad<-Pune<-Lucknow
          
