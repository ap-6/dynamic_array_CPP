
#include <vector> 
#include <string>
using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();						//default constructor
	vlist(const vlist&);			//copy constructor
	~vlist();					//destructor
	bool isEmpty() const;		//returns true if DB vector is empty, false if not empty
	vector<string>::iterator search(const string&); //
	void insert(const string&);	//inserts a string value alphabetically into vector
	void remove(const string&); //removes a string value from vector
	void print() const;			//prints all values in vector
private:
	vector<string> DB;			//vector containing strings in alphabetical order
	int count;					//number of elements stored in vector DB
};

#endif


