#include "Webpage.h"

Webpage::Webpage() {
    // Default constructor
	webURL = "No web history./n";
	visitTime = NULL;
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    // Stores passed variables to Webpage private members
	webURL = webpageURL;
	visitTime = timeVisited;
}

string Webpage::getURL() {
    // Returns URL at requested node in the list
	return webURL;
}

time_t Webpage::getTime() {
    // Returns the time of visit at requested node in the list
	return visitTime;
}
