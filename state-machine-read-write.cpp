/***** Licensed under GNU *****/
/**** Copyright reserved by Daipayan ****/

#include <bits/stdc++.h> 
using namespace std; 
  
int *ptr;
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
    void print ()  
    { cout<< "print derived class" <<endl; } 
   
    void run () 
    {
        ptr = (int*)malloc(sizeof(int)); 
        cout<< "We are in init state" <<endl; 
    } 
}; 
class Write_State:public StateMachine 
{ 
public: 
    void print ()  
    { cout<< "print derived class" <<endl; } 
   
    void run ()  
    {   *ptr = 5; 
        cout<< "we are in writing state" <<endl; } 
};
class Read_State:public StateMachine 
{ 
public: 
    void print ()  
    { cout<< "print derived class" <<endl; } 
   
    void run ()  
    {   cout << *ptr <<endl;
        cout<< "we are in read state" <<endl; } 
};
class Delete_State:public StateMachine   
{
public:
    void print ()  
    { cout<< "print derived class" <<endl; }
  
    void run ()
    {   free(ptr);
        cout<< "we are in delete state" <<endl; }
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
       ptr = new Write_State;
       break;
       case 2:
       ptr = new Read_State; 
       break;
       case 3:
       ptr = new Delete_State;
       break;
     } 
    ptr->run();  
  
    return; 
} 

int main()
{
   StateMachine *ptr = new StateMachine;
   for(int i=0; i<4;i++)
   {
     ptr->signal = i;
     runStateMachine((void*)ptr);
   }
} 
