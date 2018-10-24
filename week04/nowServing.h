/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Garrett Smith and Aiden Reid
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include <string>      // for STRING
#include "deque.h"     // for DEQUE

// the interactive nowServing program
void nowServing();

class request
{
public:
	//Constructors
	request(): section(""), name(""), minutes(0){}
	request(string c, string n, int m) : section(c), name(n), minutes(m){}
	request(const request & rhs)
	{
		section = rhs.section;
		name = rhs.name;
		minutes = rhs.minutes;
		emergency = rhs.emergency;
	}

	//Getters
	string getClass() { return section; }
	string getName() { return name; }
	int getMin() { return minutes; }

	void setEmergency(bool tf)
	{
		this->emergency = tf;
	}

	void reduceTime() 
	{  
		this->minutes -= 1; 
	}

	void display()
	{
		if (emergency) {
			cout << "\tEmergency for " << getName() << " for class " << getClass() << ". Time left: " << getMin() << endl;
			reduceTime();
		}
		else
		{
			cout << "\tCurrently serving " << getName() << " for class " << getClass() << ". Time left: " << getMin() << endl;
			reduceTime();
		}
	}

private:
	string section, name;
	int minutes;
	bool emergency = false;
};

#endif // NOW_SERVING_H

