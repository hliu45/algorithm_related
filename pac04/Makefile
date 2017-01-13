#  CS101-Abstract Data Type and Algorithm
#    4th Programming Assignment_pa04
#  Name:Hsin-Liang Liu  CruzID:hliu45  ID:1446091



CC = gcc
CFLAGS = -g -Wall -O0 

edgeList.o:	edgeList.c edgeList.h
	${CC} -c ${CFLAGS} edgeList.c

minPQ.o:	minPQ.c minPQ.h
	${CC} -c ${CFLAGS} minPQ.c

graph04.o:	graph04.c edgeList.h minPQ.h
	${CC} -c ${CFLAGS} graph04.c

graph04: 	edgeList.o minPQ.o graph04.o
	${CC} -o graph04 ${CFLAGS} edgeList.o minPQ.o graph04.o



