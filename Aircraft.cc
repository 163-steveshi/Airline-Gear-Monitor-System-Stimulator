#include "Aircraft.h"

 //constructor
Aircraft::Aircraft(const string& ty, const string& regi): type(ty), registration(regi),flighthours(0){



}


//getter function
const string& Aircraft:: getRegistration() const{

    return registration;
}


/*
	Funcation name: intall
	Function Purpose: install the part p with give date d to the aircraft
    Return Value: None
*/
void Aircraft:: install(Part* p, const Date& d){
    
    //check whether there are enough space or not
    if(parts.isFull()){

        cout<<"Sorry the aircraft has not enough space to insert a another part"<<endl;
        return;
    }
    //first call the part function to set the date
    //then try to add into the part array
    p->install(d);
    parts.add(p);

     

}

/*
	Funcation name: takeFlight
	Function Purpose: update flighthours for all parts that is on the aircraft
    Return Value: None
*/
void Aircraft::takeFlight(int hours){

    //update airplant flight hour
    flighthours += hours;
    
    for (int i = 0; i < parts.getSize(); i++){
       
        //update all parts' flighthour on this plane
        parts[i]->addFlightHours(hours); 
       
    }
    

}


/*
	Funcation name: inspectionReport
	Function Purpose: do a inspection test for all parts on aircraft.
    If the aircraft require inspection, add it to the array P.
    Return Value: None
*/
void Aircraft::inspectionReport(const  Date& d, Array<Part*>& p){

    for (int i = 0; i < parts.getSize(); ++i){
       
       
        //if the part require check add to array p
        if(parts[i]->inspection(d)){

            p.add(parts[i]); //require check not sure is shallow copy or deep copy
        }
       
    }
}


//overload ostream for print purpose
ostream& operator<<(ostream& os, const Aircraft& p){

    cout<<"Aircraft:    "<<p.type<<endl;
    cout<<"Registration:  "<<p.getRegistration()<<endl;
    
    return os;
}