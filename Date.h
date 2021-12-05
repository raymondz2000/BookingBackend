
#ifndef DATE_H
#define DATE_H
/*
This header is include constructor of date and all necessary properties and 
comparing date function 
*/
#include <iostream>
#include <string>
const int max_allowable_duration = 3;
using namespace std;

class Date {
		
	public:
		//constructor
		Date();
		Date(int year, int month, int day , int hour, int duration);
		Date(const Date&);
		
				
		/* -------------------------------- //setters ------------------------------- */
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setHour(int);
		void setDur(int);
		
		void setDate(int, int, int,int,int);
		void setDate(Date&);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getDuration();

		const string& getMonthName();
		
		//other
		bool lessThan(Date& d);
		void print();
        bool overlaps(Date& s);
	
	private:
		//functions
		int getMaxDay();
	
	
		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;
		
		
		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
};
#endif
