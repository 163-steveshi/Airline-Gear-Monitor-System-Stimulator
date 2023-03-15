
#include "Date.h"
//default constructor
Date::Date(){
	setDate(1901,1,1);
}

//constructor
Date::Date(int y, int m, int d){
	setDate(y,m,d);
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

void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(const Date& d){
	setDate(d.year, d.month, d.day);
}


//getters
int Date::getDay()const{ return day; }
int Date::getMonth()const{ return month; }
int Date::getYear()const{ return year; }
const char* Date::getMonthName()const{return months[month-1];}


//other
//overload < for compare if date is earlier than date d
bool Date::operator<(const Date& d) const{
	if (year == d.year){
		if (month == d.month){
			return day < d.day;
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}	
}
//overload == for check date 
bool Date::operator==(const Date& d) const{
	if (year == d.year){
		if (month == d.month){
			return day == d.day;
		}else{
			return false;
		}
	}
	else{
		return false;
	}	
}

//convert a specfic date that earlier than 1901, 01, 01
//to days
int Date::toDays() const{
	int days = (year-1901)*365 + day;
	for (int i = 1; i < month; ++i){
		days += getDaysIn(i);
	}
	return days;
}

//overload ostream for easy print
ostream& operator<<(ostream& out, const Date& d){
	return out << d.getMonthName()<<" "<<d.getDay()<<", "<<d.getYear()<<endl;
}

//get the last day based on date's month
int Date::getMaxDay() const{
	return getDaysIn(getMonth());
}

//helper function to return the last day in specific month
int Date::getDaysIn(int month) const{
	switch(month){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

//print function
void Date:: print() const{


	cout<<"Year: "<<year<<" Month: "<<month<<"Days: "<<day<<endl;
}
