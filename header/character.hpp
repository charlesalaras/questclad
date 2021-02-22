#include<iostream>
#include<string>

class Character{
   
 protected:
   const std:: string name;
    int classType;  
    int gold;   
  
 public:
   Character(std::string name, int gold):name(name), gold(gold){}
   virtual ~Character() {}
   virtual int getGold()=0;
   
   virtual stirng getName()=0;

}
