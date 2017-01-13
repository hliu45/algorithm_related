
//////////////////////////////////////////////////////////////
/ CS101 - 2015 Spring - Abstract Data Type and Algorithm     /
/     4th Programming Assignment - ReadMe.txt                /
/  Name: Hsin-Liang Liu   CruzID:hliu45   ID:1446091         /  
//////////////////////////////////////////////////////////////


How to run program:

$ make graph04
$ ./graph04 -D/P s testfile.in 

******************************************
command "make graph04" will compile the file and constuct executable file graph04

command "./graph04 -D/P s testfile" to run the program

example:
$ ./graph04 -P 1 testfile1.in 
//it will run Prim's MST algorithm on file testfile1.in starting at vertex 1

$ ./graph04 -D 5 testfile2.in
//execute Dijkstra SSSP on file testfile2.in starting at vertex 5

*******************************************

Purpose:
This program will implement Prim's Algorithm and Dijkstra's Algorithm, user can choose between -P and -D to run Prim's MST or Dijkstra SSSP respectively, and choose which vertex to start.

Introduction:
In the main function, system will decite where to run, based on the input command line. Then it read the file and pass the file to parseN() and edgeWgtGraph() functions to allocate the information and store it in EdgeInfo element.(parseN functions will allocate the first number as total vertex). Information including from which vertex, to which vertex and their correspond weight, and pass the information to greedyTree() function to perform Prim's or Dijkstra's algorithm. greedyTree() will check the start vertex and what Prim/Dijkstra to run. If we choose Prim's MST. then system will load edge information in unidrected graph to EdgeList structure and call function updateFringe() to shortest weight between fringe and tree, if we choose Dijkstra we will do load 
the directed graph information to EdgeList sturcture and call the function shortestPath() to find the shortest path from the starter. And finally out put a four column table to show the information including vertex, parent, weight, status. In this program, we use unidrected graph for Prim' Algorithm and directed graph for Dijkstra's algorithm.


file:
graph04.c
intList.c
intList.h
edgeList.c
edgeList.h
minPQ.c
minPQ.h
Makefile
ReadMe.txt

2 testfile:
testfile1.in //make from the example in the book
testfile2.in //make from the example in the book
tesffile3.in


output:
It's a four column talbe to indicate vertex's parent, weight, status.
including the what algorithm to implement and information about the starting vertex.
for example:

Prim's Algorithm MST        starting from vertex 1
---------------------------------------------------
vertex	 parent	 fringeWgt	 status
1	 -1	 0.000000	 tree
2	 1	 1.000000	 tree
3	 2	 3.000000	 tree
4	 6	 2.000000	 tree
5	 4	 2.000000	 tree
6	 1	 2.000000	 tree
----------------------------------------------END

Prim Algorithm apply to undirected graph.
fringeWgt is the weight between parent and it's self for prim's algorithm

next example is Dijkstra SSSP 
Dijkstra SSSP               starting from vertex 1
---------------------------------------------------
vertex	 parent	 fringeWgt	 status
1	 -1	 0.000000	 tree
2	 1	 4.000000	 tree
3	 2	 7.000000	 tree
4	 6	 4.000000	 tree
5	 6	 5.000000	 tree
6	 1	 2.000000	 tree
----------------------------------------------END

fringeWgt denote the shortest path from the starter.
Dijkstra Algorithm apply to directed graph.
In the example above the staring vertex is 1. so 1's fringeWgt is zero. and
parent is -1(-1 denote the staring vertex). 
