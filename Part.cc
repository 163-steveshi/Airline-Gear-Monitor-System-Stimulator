#include "Part.h"

//Part Class constructor
Part::Part(const string& nam): name(nam), flighthours(0){


}
//destructor for not over delete
Part::~Part(){

}
//getter 
const string& Part:: getName() const{

    return name;
}
const Date& Part:: getInstallationDate() const{

    return installationDate;
}
int Part:: getFlighthours() const{

    return flighthours;
}

//member functions
/*
	Funcation name: addFlightHours
	Function Purpose: add hour in parameter to this part's flighthours
    Return Value: None
*/
void Part:: addFlightHours(int h){

   
    flighthours = flighthours + h;
    

}


/*
	Funcation name: install
	Function Purpose: set the installationDate to the Date in the parameter
    Return Value: None
*/
void Part:: install(const Date& d){
    
  
    installationDate.setDate(d);
   

}
//global function overload os for easier print information
ostream& operator<<(ostream& os, const Part& p){

    
    p.print(os);
    return os;
}

//part helper function to use ostream
void Part:: print(ostream& os) const{
    
    os<< "Part: "<<name<<endl;
    os<< "FLightHour:  "<<flighthours<<endl;
    Date d; //create a default date
    os<< "Installation Date: ";

    //if the date is default 1901 print not install
    if(installationDate == d){
        os<<"Not Installed"<<endl;
    }
    else{
        os<<installationDate;
    }
    
    

}


//FH_Part Class constructor
FH_Part ::FH_Part(const string& nam, int fh): Part(nam), fh_inspect(fh){


}
//destructor for not over delete
FH_Part::~FH_Part(){
    
}

/*
	Funcation name: inspection
	Function Purpose: determine if flightHours is greater than or equal to fh_inspect or not
    Return Value: True: if flightHours is greater than or equal to fh_inspect
                  False: flightHour is less than fh_inspect
*/
bool FH_Part ::inspection(const Date& d) const{

    return (Part::getFlighthours() >= fh_inspect);

}
//use dynamical binding and use ostream to print
void FH_Part:: print(ostream& os) const{
    
    
    Part::print(os);

    os<<"Inspect every: "<<fh_inspect<<" flight hours"<<endl;


}
//getter 
int FH_Part::getFHinspect() const{

    return fh_inspect;
}



//IT_Part Class constructor
IT_Part ::IT_Part(const string& nam, int it):  it_inspect(it),Part(nam){


}
//destructor for not over delete
IT_Part:: ~IT_Part(){
    
}

/*
	Funcation name: inspection
	Function Purpose: determine if days between installed date and inspected date is greater 
    than or equal to it_inspect or not
    Return Value: True:  days between installed date and inspected date is greater 
    than or equal to it_inspect 
                  False:  days between installed date and inspected date is less 
    than to it_inspect
*/
bool IT_Part ::inspection(const Date& d) const {
     
    
    return (d.toDays() - (Part::getInstallationDate().toDays()) >= it_inspect);

}


//use dynamical binding and use ostream to print
void IT_Part:: print(ostream& os) const{
    
    
    Part::print(os);
    os<<"Inspect every: "<<it_inspect<<" days installed"<<endl;

}

//getter
int IT_Part:: getITinspect() const{

    return it_inspect;

}


//FHIT_Part Class constructor
FHIT_Part ::FHIT_Part(const string& nam, int fh, int it): FH_Part(nam,fh), IT_Part(nam,it), Part(nam){


}

//destrcutor for not over delete variable
FHIT_Part::~FHIT_Part(){
    
}

/*
	Funcation name: inspection
	Function Purpose: determine whether the return result of FH_Part's Inspection() or IT_Part()'s
    inspection is true or not
    Return Value: True:  return result of FH_Part's Inspection() and IT_Part()'s
    inspection is true
                  False: return result of FH_Part's Inspection() and IT_Part()'s
    inspection is differnt
*/
bool FHIT_Part ::inspection(const Date& d) const{
     
    
    return (FH_Part:: inspection(d) || IT_Part:: inspection(d));

}

//use dynamical binding and use ostream to print
void FHIT_Part:: print(ostream& os) const{
    
    
    Part::print(os);
    
    os<<"Inspect every: "<<FH_Part::getFHinspect()<<" flight hours"<<endl;
    os<<"Inspect every: "<<IT_Part::getITinspect()<<" days installed"<<endl;



}