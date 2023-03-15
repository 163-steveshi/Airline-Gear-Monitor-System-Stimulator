#include "Airline.h"
//constructor
Airline::Airline(const string& nam): name(nam){


}
//destructor
Airline::~Airline(){

    //deallocate parts and aircraft
    for(int i = 0; i < aircrafts.getSize(); i++){

        delete aircrafts[i];
    }

    for(int j = 0 ; j < parts.getSize(); j++){

        delete parts[j];
    }

}


//get the aircraft with speecific registration 
Aircraft* Airline:: getAircraft(const string& regi) const{


    for(int i = 0; i < aircrafts.getSize(); i++){
        
        //find the aircraft 
        if(aircrafts[i]->getRegistration() ==regi){
            
            
            return aircrafts[i];
        }
    }

    //fail  to find the aircraft
    return NULL;

}

//get the part with matched name
Part* Airline::getPart(const string& name) const{

    for(int j = 0 ; j < parts.getSize(); j++){
        
        //find the part with matched name
        if(parts[j]->getName() == name){

            return parts[j];
        }
    }
    //fail to find the part
    return NULL;

}

/*
	Funcation name: addAircraft
	Function Purpose: add a aircraft with given name and registration to the Airline
    Return Value: None
*/
void Airline::addAircraft(const string& ty, const string& regi){
    
    //first check is enough space
    if(aircrafts.isFull()){

        return;
    }
    //make a new aircraft and insert to the array
    Aircraft* a = new Aircraft(ty, regi);
    aircrafts.add(a);
}

/*
	Funcation name: addPart
	Function Purpose: add a aircraft with given name and registration to the Airline
    Return Value: None
*/
void Airline::addPart(const string& part, int fh_inspect, int it_inspect){

    //check is enough space
    if(parts.isFull()){

        return;
    }
    

    //if fh_inspect or it_inspect is less than 0
    //make it zero
    if(fh_inspect < 0){

        fh_inspect = 0;
    }
    if(it_inspect < 0){

        it_inspect = 0;
    }

    //make a new Part and insert to the array
    //make IT_part if no fh_inspect value
    Part* p;
    if(fh_inspect == 0){
        p = new IT_Part(part, it_inspect);
    }
    //make FH_part if no it_inspect value
    else if(it_inspect ==0){

        p = new FH_Part(part, fh_inspect);
        
    }
    //if we have fh_inspect and it_inspect make a FH_IT part
    else{
        p = new FHIT_Part(part,fh_inspect, it_inspect);
    }
   
    parts.add(p);
}


/*
	Funcation name: takeFlight
	Function Purpose: update the flight hour for a specific aircraft
    in the airline if it exists
    Return Value: None
*/
void Airline::takeFlight(const string& reg, int hours){

    Aircraft* craft = getAircraft(reg);
    //if fail to find the aircraft
    if(craft == NULL){

        cout<<"Sorry the aircraft: "<<reg<<"is not exist"<<endl;
        return;
    }
    //if the aircraft is exits
    //update the aircraft flighthour
    craft->takeFlight(hours);
}

/*
	Funcation name: printAircraft
	Function Purpose: print all aircraft in the airline
    Return Value: None
*/
void Airline::printAircraft() const{

    for(int i = 0; i< aircrafts.getSize(); i++){

        cout<<*(aircrafts[i])<<endl;
    }
  
    
}

/*
	Funcation name: printParts
	Function Purpose: print all parts in the airline
    Return Value: None
*/
void Airline::printParts() const{

    
    for(int i = 0; i< parts.getSize(); i++){

        cout<<*(parts[i])<<endl;
    }
   
}

/*
	Funcation name: inspectionReport
	Function Purpose: print the aircraft and parts on the aircraft
    which needs to be inspected
    Return Value: None
*/
void Airline:: inspectionReport(const string& reg, const Date& date){

    //find the aircraft
    Aircraft* craft = getAircraft(reg);
    if(craft == NULL){

        cout<<"Sorry the aircraft: "<<reg<<"is not exist"<<endl;
        return;
    }
    //allocate a array to allocate the parts that need inpsection
    Array<Part*> p;
    craft->inspectionReport(date,p);
    //print the aircraft with the regisration
    cout<<"The following parts from "<<craft->getRegistration()<<" require inspection:"<<endl;
     for(int i = 0; i< p.getSize(); i++){

        cout<<*(p[i])<<endl;
    }
    cout<<endl<<endl;
}

/*
	Funcation name: install
	Function Purpose: install a specific part to the specific aircraft 
    if the part or aircraft is existed
    Return Value: True: SUccessful install
                  False: fail to add the aircraft
*/
bool Airline:: install(const string& regi, const string& p_name, const Date& d){

    //first try to search for the aircraft
    Part* p = getPart(p_name);
    if(p == NULL){

        cout<<"Sorry the part: "<<p_name<<"is not available"<<endl;
        return false;
    }
    //then try to find the airplane
    Aircraft* craft = getAircraft(regi);
    if(craft == NULL){

        cout<<"Sorry the aircraft: "<<regi<<"is not exist"<<endl;
        return false;
    }

    //if it exits now try to install part on the aircraft
    craft->install(p, d);

    return true;
}
//print function for testing purpose
void Airline::print() const{

    cout<<"Airline: "<<name<<endl;
}

