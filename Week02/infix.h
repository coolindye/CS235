/***********************************************************************
* Header:
*    INFIX      
* Summary:
*    This will contain just the prototype for the convertInfixToPostfix()
*    function
* Author
*    Aiden and Garrett
************************************************************************/

#ifndef INFIX_H
#define INFIX_H

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK


string convertInfixToPostfix();

string convertPostfixToAssembly(const string & postfix);

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix();

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly();

#endif // INFIX_H

