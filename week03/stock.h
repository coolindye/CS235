/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Garrett Smith & Aiden Reid
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <cassert>     // for ASSERT
#include <iostream>    // for ISTREAM and OSTREAM

 // the interactive stock buy/sell function
void stocksBuySell();

class stocks
{
public:
	//Constructors
	stocks()                                 : numStock(0) { d = 0;  profit = 0; soldStock = false; }
	stocks(int ns, Dollars &d2)              : numStock(ns) { d = d2; profit = 0; soldStock = false; }
	stocks(int ns, Dollars &d2, Dollars &pr) : numStock(ns) { d = d2; profit = pr; soldStock = true; }

	//Getters
	int getNumStock()   { return numStock; }
	Dollars getDollar() { return d; }
	Dollars getProfit() { return profit; }

	//Only method that modifies values
	Dollars sellStock(const int ns, Dollars & d2)
	{
		assert(numStock >= ns);
		numStock -= ns;
		return ((d2 * ns) - (d * ns));
	}

	void display()
	{
		if (soldStock)
			cout << "\tSold " << getNumStock() << " shares at " << getDollar() << " for a profit of " << getProfit() << endl;
		else
			cout << "\tBought " << getNumStock() << " shares at " << getDollar() << endl;
	}

private:
	bool soldStock;
	int numStock;
	Dollars d;
	Dollars profit;
};

#endif // STOCK_H

