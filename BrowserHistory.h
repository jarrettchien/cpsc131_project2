#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();

    void visitSite(Webpage newSite);
    string back();
    string forward();

    void readHistory(string fileName);

    string getURL();
    size_t getNavSize();

    void printBackSites();
    void printForwardSites();
    void printFullHistory();

private:
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // COMPLETED
	list<Webpage> history; // We pushed new sites to the front; for forward and backward navigation. Most recent site at front
	list<Webpage> full_history; // Keeps entire web history
	list<Webpage>::iterator it; // Iterator for the back/forward functions
	list<Webpage>::iterator urlIterator; // Iterator for the getURL function
	int counter;
};
