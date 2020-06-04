//cd.cpp -- 
#include "cd.h"
#include <iostream>
#include<cstring>

Cd::Cd (char * s1, char * s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections=n;
    playtime=x;
}

Cd::Cd (const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections=d.selections;
    playtime=d.playtime;
}

Cd::Cd ()
{
    strcpy(performers, "");
    strcpy(label, "");
    selections=0;
    playtime=0;
}

Cd::~Cd()
{

}

void Cd::Report() const
{
    cout<<"Attention, this is basice class!"<<endl
     << "performers: "<<performers<<endl
        <<"label: "<<label<<endl
        <<"labels:"<<selections<<endl
        <<"playtime: "<<playtime<<endl<<endl;
}

 Cd& Cd::operator=(const Cd & d)
 {
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections=d.selections;
    playtime=d.playtime;
 }

Classic::Classic(char* name, char* s1, char* s2, int n, double x)  :  Cd(s1, s2,n,x)
{
    strcpy(name_, name);
}

Classic::Classic(char* name, const Cd & cd) : Cd(cd)
{
    strcpy(name_, "");
}

Classic::Classic() : Cd()
{
    strcpy(name_, "");
}

Classic::~Classic() 
{
}

void Classic::Report() const
{
    cout<<"Attention, this is Derived Class!"<<endl;
    cout<<name_<<endl;
    Cd::Report();
}
