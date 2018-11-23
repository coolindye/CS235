###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Author:
#     Garrett, Ian, Aiden
# Summary:
#     This program creates an abstract data type that is fairly
#     equivalent to the map data structure in the standard 
#     library. There is also an implementation of a wordCount
#     that is able to count the frequency of a word appearing
#     within any block of text. Due to the red-black balancing
#     of the tree system, the searching for a word is very fast
#     and the program itself is able to analyze a document of 
#     270000+ words in less than 15 seconds on standard 
#     computing hardware. The finding of the word that is being
#     looked for takes at worst O(logn) time to find.
# Hardest Parts:
#     Garrett: The hardest part for me was trying to figure out
#             an error that kept saying that I couldn't convert
#             one type to another, even though both types in 
#             the error code were the same. Turns out that I 
#             had forgotten to make one of the copy constructors
#             use a reference value and so the compiler kept 
#             trying to use the only other copy constructor.
#             After 3-4 hours of testing everything, I finally
#             figured out that I needed to add a '&' and the
#             rest started working. I know to be careful about
#             that in the future.
#     Ian:
#
#     Aiden:
# Time:
#     Total time: 7 hrs (4 of those trying to fix one problem)
#     Garrett: 7 hrs
#     Ian: 
#     Aiden: 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g -std=c++11
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g -std=c++11

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g  -std=c++11
