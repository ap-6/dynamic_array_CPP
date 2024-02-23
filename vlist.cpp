#include <iostream>
#include <vector>
#include <string>
#include "vlist.h" 

using namespace std;

/**************************************************************************************************
Name:           vlist
Pre-Conditon:   Constructor has not been invoked.
Post-Condition: count = 0; vector size is 9.
Description:    Constructs an instance of a vlist object.
**************************************************************************************************/
vlist::vlist()
{
	cout << "Default Constructor Invoked" << endl;

	count = 0;
	DB.reserve(9);
}


/**************************************************************************************************
Name:           vlist
Pre-Conditon:   A vlist object is being passed by reference.
Post-Condition: A hard copy of a vlist object has been created.
Description:    Creates a hard copy of a vlist object.
**************************************************************************************************/
vlist::vlist(const vlist & Org)
{
	cout << "Copy Constructor Invoked" << endl;
	
	count = 0;
	vector<string>::const_iterator orgIt;

	//loop traverses Org and uses push_back to copy each value to current object
	for (orgIt = Org.DB.begin(); orgIt != Org.DB.end(); orgIt++)
	{
		DB.push_back(*orgIt);
		count++;
	}

	Org.print();
	print();
}


/**************************************************************************************************
Name:		    ~vlist
Pre-condition:	Destructor has not been invoked.
Post-condition: array DB deleted.
Description:		Deallocates memory of a vlist object.
**************************************************************************************************/
vlist::~vlist()
{
	cout << "Destructor Invoked" << endl;

	DB.clear();			//removes all elements from vector
	DB.shrink_to_fit();	//reduces capacity to equal the size
}

/**************************************************************************************************
Name:		    isEmpty()
Pre-condition:	It is not known whether DB vector is empty or not
Post-condition: It is known whether DB vector is empty or not
Description:		isEmpty() returns true if DB vector is empty or returns false if DB vector 
				is not empty
**************************************************************************************************/
bool vlist::isEmpty() const
{ 
	return DB.empty(); 
}

/**************************************************************************************************
Name:			search()
Pre-condition:	The address of key in DB vector is not known
Post-condition: An iterator pointing to the address of key in DB vector is returned 
				or an iterator pointing to the address after the final value in DB vector
				(that is, DB.end()) is returned if key is not in DB vector. Also a message
				saying whether key is found in DB vector is sent to cout stream.
Description:		search function looks for key in DB vector. If it is found, a message saying
				so is sent to cout and an iterator pointing to its address is returned.
				If not found, a message saying so is sent to cout and an iterator pointing to
				the address after the final value in DB vector (DB.end()) is returned.
**************************************************************************************************/
vector<string>::iterator vlist::search(const string& key)
{
	cout << "search invoked to find \"" << key << "\"" << endl;

	vector<string>::iterator it = DB.begin();
	while (it != DB.end() && *it != key) //iterate through DB until either the end is reached or
	{									 //key is found
		it++;
	}

	if (it == DB.end())	//if key is not found
	{
		cout << "Item Not Found" << endl;
		return it;
	}
	else					//if key is found
	{
		cout << "Item Found" << endl;
		return it;
	}
}

/**************************************************************************************************
Name:			insert()
Pre-condition:	key is not in DB vector
Post-condition: key is inserted into DB vector in alphabetical order
Description:		insert() takes string key as an input parameter and inserts it in
				the vector DB wherever it fits alphabetically
**************************************************************************************************/
void vlist::insert(const string & key)
{	
	vector<string>::iterator it = DB.begin(); //points to first element of DB	

	while (it != DB.end() && key > *it) //find position where key should be placed alphabetically 
	{									
		it++;
	}
		
	if (it == DB.end()) //if at end, append to end
	{
		DB.push_back(key);
		count++;
	}
	else					//if somewhere before end, insert at alphabetical location
	{
		DB.insert(it, key);
		count++;
	}
}

/**************************************************************************************************
Name:			remove()
Pre-condition:	key may or may not be in vector DB
Post-condition: key is not in vector DB
Description:		remove() uses the search() function to find key's position in vector DB 
				(if it is in vector DB) and then uses .erase() to remove key from vector DB.
				If key is not found in vector DB, a message saying so is sent to cout.
**************************************************************************************************/
void vlist::remove(const string& key) 
{
	vector<string>::iterator it = search(key);
	
	if (it == DB.end()) //key is not in DB
	{
		cout << "\"" << key << "\"" << " is not in vector" << endl;
	}
	else					//key is in DB
	{
		DB.erase(it);
		count--;
	}
}

/**************************************************************************************************
Name:			print()
Pre-condition:	The values of vlist's vector DB are not displayed through cout
Post-condition: The values of vlist's vector DB are displayed through cout in order from
				the first value to the last value
Description:		print() loops through vector DB and outputs each value along the way
				to cout, going from the first element to the last element. 
				If vector DB is empty, a message saying so is sent to cout.
**************************************************************************************************/
void vlist::print() const
{
	if (isEmpty())
	{
		cout << "vlist object is empty." << endl;
	}
	else
	{
		int size = DB.size();

		for (int i = 0; i < size; i++)
		{
			cout << DB[i] << " ";
		}
		cout << endl;
	}
}