/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include <sstream>      // for STRINGSTREAM
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;
using namespace custom;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
	// instructions
	cout << "Every prompt is one minute.  The following input is accepted:\n";
	cout << "\t<class> <name> <#minutes>    : a normal help request\n";
	cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
	cout << "\tnone                         : no new request this minute\n";
	cout << "\tfinished                     : end simulation\n";

	deque <request> requests;
	bool oneTime = false;
	cin.clear();
	cin.ignore();

	for (int i = 0; true; ++i)
	{
		cout << "<" << i << "> ";

		//Get input from user and use stringstreams to parse information
		string option, answer;
		getline(cin, option);
		stringstream ss(option);
		ss >> answer;

		//Emergency request
		if (answer == "!!")
		{
			oneTime = true;
			string sec, name;
			int minutes;
			ss >> sec >> name >> minutes;
			request req(sec, name, minutes);
			req.setEmergency(true);


			//requests.pfront()->display();
			request temp(requests.front());
			temp.display();
			requests.pop_front();
			requests.push_front(temp);
			if (requests.front().getMin() <= 0)
				requests.pop_front();

			requests.push_front(req);
		}

		//finished Logic
		else if (answer == "finished")
		{
			break;
		}

		//none Logic
		else if (answer == "none") {}

		else if (answer != "")
		{
			string name;
			int minutes;
			ss >> name >> minutes;
			request req(answer, name, minutes);
			requests.push_back(req);
		}

		//Print out new minute
		if (!requests.empty() && oneTime == false)
		{
			//requests.pfront()->display();
			request temp(requests.front());
			temp.display();
			requests.pop_front();
			requests.push_front(temp);
			if (requests.front().getMin() <= 0)
				requests.pop_front();
		}

		oneTime = false;
		cerr << requests.size();
	}

   // end
   cout << "End of simulation\n";
}


