// Wow its Event.cc
#include "Event.h"
#include "translate.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <fstream>

using namespace std;
Event::Event(const char* str) : Event(string(str)){}

Event::Event(const string &str){
	string strx = str;
	strx = decipher(strx);
	try{
		dy = stoi(strx.substr(8, 10));
		mth = stoi(strx.substr(5, 7));
		yr = stoi(strx.substr(0, 4));
	}catch(const std::exception& e){
		throw runtime_error("Error: invalid Event with this time stamp -> " + strx);
	}
	
}
void Event::set(int year, int month, int day){
	if(month > 12 || month < 1){
                throw runtime_error("ERROR: invalid(month out of range) trying to set value to -> " + month);
        }
        if(year > 9999 || year < 1){
                throw runtime_error("ERROR: invalid(year out of range) trying to set value to -> " + year);
        }
	int leap = 0;
        if(isLepYr(year)){leap = 1;}
        int mnthNum[] = {31,28+leap,31,30,31,30,31,31,30,31,30,31};
        if(mnthNum[month - 1] < day || day < 0){
                throw runtime_error("ERROR: invalid(day out of range for month) format in this line -> " + day);
        }
	yr = year;
	dy = day;
	mth = month;
}

int Event::year()  const{
	return yr;
}
int Event::month()  const{
	return mth;
}
int Event::day() const{
	return dy;
}
