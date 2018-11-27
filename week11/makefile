###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother Kirby, CS235
# Author:
#     Garrett Smith, Aiden Reid, Ian Stubbs
# Summary:
#     <put a description here>
# Hardest Parts:
#     Garrett: 
#
#     Ian:
#
#     Aiden:
# Time:
#     Total time: 
#     Garrett: 
#     Ian: 
#     Aiden: 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g -std=c++11
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c assignment11.cpp -g -std=c++11

