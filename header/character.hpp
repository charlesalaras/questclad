#include<iostream>
#include<string>

class character{
 protected:
    string character;
    int class;    
  
 public:
   character(string character):character(){}
   virtual ~character() {}
   
   
   virtual stirng getName()=0;

}
