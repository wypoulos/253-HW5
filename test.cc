// Wow its test.cc
#include "Schedule.h"
#include "Event.h"
#include "Schedule.h"       // I meant to do that.
#include "Event.h"
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
	
using namespace std;

int main(){
	cout << "JACKS CODE START \n";
	cout << boolalpha;  // need this for several things
	Schedule s;
    	ifstream in("data");
    	try {
        	s.read(in);
    	}
    	catch (const exception &e) {
        	cout << e.what() << '\n';
    	}
	cout << "fail: " << in.fail() << " eof: " << in.eof() << '\n';

    	stringstream iss("   tomoRRow  ");
    	s.read(iss);
    	auto e = s[0];
   	 cout << "Oldest: |" << e << "|"
         	<< " year=" << e.year() << " month=" << e.month()
         	<< " day=" << e.day() << '\n';
    	cout << "size=" << s.size() << " empty=" << s.empty() << '\n' << s;
    	s.clear();
    	cout << "size=" << s.size() << " empty=" << s.empty() << '\n' << s;
    	s.clear();
    	cout << "size=" << s.size() << " empty=" << s.empty() << '\n' << s;
	// A poor implementation might have altered couts fill character:
	cout << left << setw(15) << "All done." << '\n';
	cout << "JACKS CODE END \n";
	
	cout <<"**Checking Year Ranges** \n";
	Schedule a;
	stringstream as("   0000.90 ");
	cout << "Testing";
	a.read(as);
	
	cout <<"**Checking Month Ranges** \n";

	cout <<"**Checking Day Ranges** \n";
	return 0;
}
