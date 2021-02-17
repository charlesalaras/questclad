#include<iostream>
#include<string>

class character{
 protected:
    string character;
    
    double strength;
 public:
   character(string character, double health, double strength):character(){}
   virtual ~character() {}
   
   
   virtual stirng getName()=0;

   virtual double getStrength()=0.0;
}
