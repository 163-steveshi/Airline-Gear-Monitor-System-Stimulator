#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
using namespace std;
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

class Airline{

   
    public:

        //constructor
        Airline(const string& nam);
        //destructor

        ~Airline();
        //other functions
        void addAircraft(const string& ty, const string& regi);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(const string& reg, int hours);
        void printAircraft()const;
        void printParts() const;
        void inspectionReport(const string& reg, const Date& date);
        bool install(const string& regi, const string& p_name, const Date& d);
        void print() const; 
        

    private:

        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;
        //private getter
        Aircraft* getAircraft(const string& regi) const;
        Part* getPart(const string& name) const;

};
#endif

