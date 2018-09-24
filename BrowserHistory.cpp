#include "BrowserHistory.h"

BrowserHistory::BrowserHistory() {
	counter = 0; // Tracks our position within the list after back/forward operation.
}

BrowserHistory::~BrowserHistory() {
    // COMPLETED
}

void BrowserHistory::visitSite(Webpage newSite) {
	// COMPLETED
	// If counter > 0, we are not at front of list. We pop the front until we reach the front of the list.
	// If we are going back and visiting a different website, whatever is in front needs to be popped.
	if (counter > 0) {
		for (int pop = 0; pop < counter; pop++) {
			history.pop_front();
		}
		counter = 0;
	}
	// Adds new Webpage node to front lists
	history.push_front(newSite); 
	full_history.push_front(newSite); 
}

string BrowserHistory::getURL() {
	// COMPLETED
	// Empty list error check.
	if(history.empty())
		throw length_error("No History\n");
	urlIterator = history.begin(); // Places iterator at beginning of history list.
	// Increment until the counter variable; then urlIterator will be incremented to the current place in the web history.
	for (int i = 1; i <= counter; i++){
		urlIterator++;
	}
	return urlIterator->getURL();
}

size_t BrowserHistory::getNavSize() {
    // COMPLETED
	return history.size();
}

string BrowserHistory::back() {
	// COMPLETED
	if(history.empty())
		throw length_error("No History\n");
	it = history.begin();
	counter++; // Since we added new sites to the front, older sites would be to the right; thus, we increment counter.
	// Increments iterator to current location in web history.
	for (int iter = 1; iter <= counter; iter++) {
		it++;
	}
	return it->getURL();
}

string BrowserHistory::forward() {
    // COMPLETED
	if(history.empty())
		throw length_error("No History\n");
	counter--; // Newer sites are to the left of the list, so decrement counter.
	it--; 
	return it->getURL();
}

void BrowserHistory::readHistory(string fileName) {
    // COMPLETED
	ifstream myfile(fileName);
	// Opens and reads in from text file.
	if (myfile.is_open()) {
		cout << "Successfully opened file " << fileName << endl;
		string status, site; // Variables to hold information from text file.
		time_t time;
		while (myfile >> status) {
			// If the web page is a new site, we add it to the front.
			if (status == "new") {
				myfile >> site >> time;
				Webpage file(site, time); // Creates a Webpage object to hold site and time in order to pass via visitSite funciton.
				visitSite(file);
				//cout << "Added " << file.getURL() << " to front\n";
			}
			if (status == "back") {
				back();
				// If text file says to go back, simply call back function.
				//cout << getURL() << " back" << endl;
			}
			if (status == "forward") {
				forward();
				// Calls forward function if text file says to go forward.
				//cout << getURL() << " forward" << endl;
			}
		}
		myfile.close();
	}

}

void BrowserHistory::printBackSites() {
    // COMPLETED
	if(history.empty())
		throw length_error("No History\n");
	it = history.end(); // Put iterator at the end of list since that is where the older sites are. 
	for (int i = 1; i < history.size() - counter; i++) {
		// (history.size() - counter) will give us all the sites that are in the back history but not the current page we are at.
		it--; // Continue to go left as for loop iterates. Oldest site will be printed first.
		cout << it->getURL() << endl;
	}
}

void BrowserHistory::printForwardSites() {
    // COMPLETED
	if(history.empty())
		throw length_error("No History\n");
	it = history.begin(); 
	// First for loop places the iterator at the current place in web history.
	for (int j = 0; j <= counter; j++) {
		it++;
	}
	// Second for loop prints the web history beginning at the current page and until there are no more forward pages.
	for (int i = 0; i <= counter; i++) {		
		it--;
		cout << it->getURL() << endl;
	}
}

void BrowserHistory::printFullHistory() {
    // COMPLETED
	if(history.empty())
		throw length_error("No History\n");
	full_history.reverse(); // Reverses history in order to print full history from oldest to newest
	it = full_history.begin();
	// Prints out full web history.
	for (int i = 1; i <= full_history.size() ; i++)  {
		cout << it->getURL() << endl;
		it++;
	}
	full_history.reverse(); // Puts list back in its original order
}
