###############################################################
# Program:
#     Assignment 09, Binary Search Tree
#     Brother Kirby, CS235
# Author:
#     Aiden/Garrett/Ian
# Summary:
#     This is a Binary Search Tree. This structure will take
#     any kind of data and keep all of it in order. The data
#     needs to support comparison but it also. This implemetation
#     also keeps the tree balanced using red-black logic.
# Time:
#     Aiden:   2 hours
#     Garrett: 12 hours
#     Ian:     2 hours
#     Group:   2 hours
# The most difficult part:
#     Aiden: Rotation is a very difficult concept to wrap
#            my head around....
#     Garrett: Optimizing the code so that there were less
#              boolean checks and getting rid of most of The
#              redundant code. The red-black balancing was also
#              fairly challenging until I was able to find 
#              a set of possible circumstances and just 
#              created a case for each of them. I had to make
#              it so that the tree was validated and fixed 
#              after insertion. I could probably come up with
#              a way to insert while balancing.
#     Ian: I was having some issues with operator overloading
#          this week and figuring out the nested node. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment09.o
	g++ -o a.out assignment09.o -g -std=c++11
	tar -cf assignment09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment09.o     : the driver program
##############################################################
assignment09.o: bst.h assignment09.cpp
	g++ -c assignment09.cpp -g -std=c++11


