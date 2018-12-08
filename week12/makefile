###############################################################
# Program:
#     Assignment 12, Hash
#     Brother Kirby, CS235
# Author:
#     Garrett Smith, Aiden Reid, Ian Stubbs
# Summary:
#     Hash class 
# Hardest Parts:
#     Garrett: 
#
#     Ian:
#
#     Aiden: Making the array of lists for the hash work with still
#            allowing relavent usage of buckets
# Time:
#     Total time: 
#     Garrett: 
#     Ian: 
#     Aiden: 8
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment12.o spellCheck.o
	g++ -o a.out assignment12.o spellCheck.o -g -std=c++11
	tar -cf assignment12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment12.o     : the driver program
#      spellCheck.o       : the spell-check program and driver
##############################################################
assignment12.o: hash.h assignment12.cpp list.h
	g++ -c assignment12.cpp -g -std=c++11

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g -std=c++11

