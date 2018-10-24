/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Garrett Smith & Aiden Reid
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>	   // for STRING
#include <sstream>     // for STRINGSTREAM
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;
using namespace custom;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
	// instructions
	cout << "This program will allow you to buy and sell stocks. "
		<< "The actions are:\n";
	cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
	cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
	cout << "  display         - Display your current stock portfolio\n";
	cout << "  quit            - Display a final report and quit the program\n";

	queue <stocks> boughtStocks(100);
	queue <stocks> soldStocks(100);

	while (true) 
	{
		//Get input from user and use stringstreams to parse information
		string option, answer;
		getline(cin, option);
		stringstream ss(option);
		ss >> answer;

		//Buy Logic
		if (answer == "buy")
		{
			Dollars money;
			int amount;
			ss >> amount >> money;
			stocks order(amount, money);
			boughtStocks.push(order);
		}

		//Sell Logic
		else if (answer == "sell")
		{
			queue <stocks> tempS(100);
			Dollars money;
			int amount;
			ss >> amount >> money;

			//Make sure negative buys are impossible
			if (amount < 0) { amount = 0; }

			while (amount > 0)
			{
				if (boughtStocks.front().getNumStock() > amount)
				{
					//queue :: pfront() necessary to keep this code concise
					Dollars profitTotal = boughtStocks.pfront()->sellStock(amount, money);
					stocks order(amount, money, profitTotal);
					soldStocks.push(order);

					//Reduce order amount to zero to exit loop
					amount = 0;
				}

				else
				{
					int temp = boughtStocks.front().getNumStock();

					//queue :: pfront necessary to keep this code concise
					Dollars profitTotal = boughtStocks.pfront()->sellStock(temp, money);
					stocks order(temp, money, profitTotal);
					soldStocks.push(order);

					//Remove empty bought stocks
					boughtStocks.pop();

					//Reduce the order amount by the size of the bought stock
					amount -= temp;
				}
			}
		}

		//Display Logic
		else if (answer == "display")
		{
			queue <stocks> temp(100);
			Dollars total;

			//If boughtStocks isn't empty then print off Title and each stocks
			if (!boughtStocks.empty())
				cout << "Currently held:" << endl;
			while (!boughtStocks.empty())
			{
				temp.push(boughtStocks.front());
				boughtStocks.pfront()->display();
				boughtStocks.pop();
			}

			//Fill boughtStocks back up
			while (!temp.empty())
			{
				boughtStocks.push(temp.front());
				temp.pop();
			}

			//If soldStocks isn't empty print it and keep a total of the profits
			if (!soldStocks.empty())
				cout << "Sell History:" << endl;
			while (!soldStocks.empty())
			{
				temp.push(soldStocks.front());
				soldStocks.front().display();
				total += soldStocks.front().getProfit();
				soldStocks.pop();
			}

			//Fill soldStocks back up
			while (!temp.empty())
			{
				soldStocks.push(temp.front());
				temp.pop();
			}

			//Print out profits
			cout << "Proceeds: " << total << endl;

		}


		else if (answer == "quit")
		{
			break;
		}
		cout << "> ";
	}
}