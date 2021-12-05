
#include "Date.h"

Date::Date(){
	setDate(1,1,1901,1,1);
}

Date::Date(int y, int m, int d,int h,int dur){
	setDate(y,m,d,h,dur);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}
void Date::setHour(int h){
	if (h <24){
		hour = h;
	}
	else if (h==24){
		hour = 0;
	}
}
void Date::setDur(int dur){
	if((0<=dur)&&(dur<=max_allowable_duration)){
		duration = dur;
	}
    else{
        duration = max_allowable_duration;
    }
}
void Date::setDate(int y, int m, int d, int h , int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDur(dur);
}

void Date::setDate(Date& d){
	setDate(d.day, d.month, d.year,d.hour,d.duration);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour(){return hour;}
int Date:: getDuration(){return duration;}

const string& Date::getMonthName(){return months[month-1];}


//other
bool Date:: overlaps(Date& s){
    if ((this->day==s.day)&&(this->month==s.month)&&(this->year==s.year)&&(this->hour != s.hour)){
		if((this->hour+this->duration>s.hour)&&(s.hour+s.duration>this->hour)){
				 return true;
    		}
			else{
				return false;
			}
    }
	else if((this->day==s.day)&(this->month==s.month)&(this->year==s.year)&&(this->hour == s.hour)){
			if((this->hour+this->duration>s.hour)&&(s.hour+s.duration>this->hour)){
				 return true;
    		}
			else{
				return false;
			}
	}
    else if((this->day==s.day)||(this->month==s.month)||(this->year==s.year)&&(this->hour == s.hour)){
            return false;   
    } 
	return false;
}

bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
            if(day==d.day){   
                if(hour == d.hour){
                    return false;
                }else{
                    return hour < d.hour;
                }
            }else{
                return day < d.day;
            }
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}	
}


void Date::print(){
	cout <<" (MM-DD-YY HOUR DURATION) " <<getMonthName()<<" "<<getDay()<<","<<getYear()<<" ("<<getHour()<<" "<<getDuration()<<") "<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

