#ifndef AICRAFT_H
#define AICRAFT_H

#include <iostream>
#include <string>
using namespace std;
#include "Array.h"
#include "Part.h"
#include "defs.h"

class Aircraft{



    public:
        //overload os
        friend ostream& operator<<(ostream& os, const Aircraft& p);
        //constructor
        Aircraft(const string& ty, const string& regi);
        
        //getter
        const string& getRegistration() const;

        //other functions
        void install(Part* p, const Date& d);
        void takeFlight(int hours);
        void inspectionReport(const Date& d, Array<Part*>& p);

    private:

        //variables
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts; //an array of part pointer


};
#endif