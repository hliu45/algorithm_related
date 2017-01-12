#  CS101-Abstract Data Type and Algorithm
#    3th Programming Assignment_pa03
#  Name:Hsin-Liang Liu  CruzID:hliu45  ID:1446091

CSOURCE = intList.c loadGraph.c dStack.c biComp.c graph05.c
CHEADER = intList.h loadGraph.h dStack.h biComp.h
OBJECTS = intList.o loadGraph.o dStack.o biComp.o graph05.o

%.o : %.c
	gcc -g -Wall -O0 -c $<
graph05: ${OBJECTS}
	gcc -g -Wall -O0 -o $@ ${OBJECTS}

clean:
	- rm ${OBJECTS}
