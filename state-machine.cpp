/*** Daipayans State Machine ***/
/**** Copyright reserved by Daipayan ***/
/*** Licensed under GNU ***/


#include <bits/stdc++.h> 
using namespace std; 
  
class StateMachine 
{
public: 
    int signal;
    void print () 
    { cout<< "print base class" <<endl; } 
   
    virtual void run () 
    { cout<< "show base class" <<endl; } 
}; 
   
class Init_State:public StateMachine 
{ 
public: 
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
    { cout<< "print derived class" <<endl; } 
   
    void run () 
    { cout<< "We are in init state" <<endl; } 
}; 
class Run_State:public StateMachine 
{ 
public: 
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
    { cout<< "print derived class" <<endl; } 
   
    void run ()  
    { cout<< "we are in running state" <<endl; } 
};
class DeInit_State:public StateMachine   
{
public:
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
    { cout<< "print derived class" <<endl; }
  
    void run ()
    { cout<< "we are in deinit state" <<endl; }
};
 
 
//run the State Machine function 
void runStateMachine(void *p) 
{ 
    StateMachine *ptr = (StateMachine *)p; 
      switch(ptr->signal)
     {
       case 0:
       ptr = new Init_State;
       break;
       case 1:
       ptr = new Run_State;
       break;
       case 2:
       ptr = new DeInit_State; 
       break;
     } 
    //Non-virtual function, binded at compile time 
    ptr->print();  
       
    // virtual function, binded at runtime (Runtime polymorphism) 
    ptr->run();  
  
    return; 
} 

int main()
{
   StateMachine *ptr = new StateMachine;
   ptr->signal = 0;
   runStateMachine((void*)ptr);
} 
