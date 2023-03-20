//this is for user info so I dont have to put it on everyfile
#ifndef _USER_
#define _USER_

#include <iostream>
#include <string>
using namespace std;

class User{

  private: 		//User info that should be hidden unless (pro...)called
    string Username;		//Username
    string Pawd;		//Password
    string em;			//email
    int bday;			//Birthday
    string fN;			//First name
    string lN;			//last name

  public:
    bool init( const string&, int);
    void display();

};

#endif  //dont forget this. 


