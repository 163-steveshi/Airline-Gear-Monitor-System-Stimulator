#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"
#include <iomanip>
using namespace std;

class Part{
    
    //overload << operator for easier print purpose
    friend ostream& operator<<(ostream& os, const Part& p);

    public:

        //constructor
        Part(const string& nam);
        //virtual destructor for not over free object
        virtual ~Part();
        //getter 
        const string& getName() const;
        //member functions
        void addFlightHours(int h);
        void install(const Date& d);
        const Date& getInstallationDate() const;
        int getFlighthours() const;
        //for dynamical binding using ostream for print
        virtual void print(ostream& os) const;
        
    
        //pure virtual member function
        virtual bool inspection(const Date& d) const = 0;
    protected:
        
        //member variables
        string name;
        Date installationDate;
        int flighthours;

};

class FH_Part : virtual public Part{

    public:
        //constructor
        FH_Part(const string& nam, int fh);
        //virtual destructor for not over free object
        virtual ~FH_Part();
        //virtual Function
        virtual bool inspection(const Date& d) const;
        virtual void print(ostream& os) const; //for dynamical binding using ostream for print
        //getter
        int getFHinspect() const;

    protected:

        //the number of flight hours  until inspection is required
        int fh_inspect;

};


class IT_Part : virtual public Part{

    public:
        //constructor
        IT_Part(const string& nam, int it);
        //virtual destructor for not over free object
        virtual ~IT_Part();
        //getter
        int getITinspect() const;
        //virtual Function
        virtual bool inspection(const Date& d) const;
        virtual void print(ostream& os) const; //for dynamical binding using ostream for print

    protected:

        //the number of days installed until inspection is required
        int it_inspect;

};

class FHIT_Part : virtual public FH_Part , virtual public IT_Part{

    public:
        //constructor
        FHIT_Part(const string& nam, int fh, int it);
        //virtual destructor for not over free object
        virtual ~FHIT_Part();
        //virtual Function
        virtual bool inspection(const Date& d) const;
        virtual void print(ostream& os) const; //for dynamical binding using ostream for print

    protected:


};
#endif