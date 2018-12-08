###############################################################
# Program:
#     Assignment 12, Hash
#     Brother Kirby, CS235
# Author:
#     Garrett Smith, Aiden Reid, Ian Stubbs
# Summary:
#     <put a description here>
# Hardest Parts:
#     Garrett: 
#
#     Ian: Hardest part was getting the iterator to properly go 
#          through the list of strings and make tolower. 
#
#     Aiden:
# Time:
#     Total time: 7
#     Garrett: 
#     Ian: 7
#     Aiden: 
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

