###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Author:
#     Garrett Smith & Aiden Reid & Ian Stubbs
# Summary:
#     Created a Binary tree node that contains Nodes. Also 
#     inplemented huffamn code. 
# Coding Time:
#     Pair: 8
#     Garrett: 9
#     Ian: 3
#     Aiden: 9
#
# The most difficult part:
#     Aiden: adding the nodes to a sorted tree and comparing
#            them to get there
#     Garrett: Getting the recursive functions of the BNode 
#              code to work correctly.
#     Ian: figuring out how to store values from the read file. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o 
	g++ -o a.out assignment08.o huffman.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g -std=c++11