// Adarsh Mandloi 
// 21105089 ECE 
// Assignment 1
// Family Linked List




#include<bits/stdc++.h>
using namespace std;



//Member is the node of our linked list containing data : Name and age of family members 

struct member
{
    string name;
    int age;
    member *previous;
    member *next;

};

class family
{ 
    
   member *tail=NULL;
   member *head=NULL;

   public:

 //Function to add new members from head 
    
    void new_member_front(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(tail==NULL)
            tail=person;
        if(head==NULL)
           person->previous=NULL;
        else
           {person->previous=head;
            head->next= person;}

        person->next=NULL;
        head=person;

    }




 //Function to add new members from  tail
        void new_member_back(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(head==NULL)
            head=person;
        if(tail==NULL)
           person->next=NULL;
        else
           {person->next=tail;
           tail->previous=person;}

        person->previous=NULL;
        tail=person;

    }




    
    void deleteFromTail(int n)//n is the number of members to be deleted
    {
        cout<<endl;

        if(head==NULL)
          { cout<<"no members left in the list.";
            return;
          }

        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
            member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            member *temp = tail;
            tail= tail->next;
            tail->previous=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }




    void deleteFromHead(int n)      //n is the number of members to be deleted
    {
        cout<<endl;
        if(head==NULL)
          { cout<<"no members left in the list.";
            return;
          }


        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
             member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        

        for(int i=0;i<n;i++)
        {
            member *temp = head;
            head=head->previous;
            head->next=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }



       //to simultaneously remove and store the member at head
    member* popHead()
    {   
        if(head==NULL)
           {cout<<"no members left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member *temp= head;
        head=head->previous;
        head->next=NULL;
        temp->previous=NULL;

        return temp;
    }



      //To simultaneously remove and store the member at tail

    member* popTail()
    {
        if(head==NULL)
           {cout<<"no members left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member* temp= tail;
        tail=tail->next;
        tail->previous=NULL;
        temp->next=NULL;
        
        return temp;
    }



    //to display family starting from tail
    void displayFromTail()
    {
        cout<<endl;
         if(head==NULL)
           {cout<<"no members left in the list."; 
           return;}
        
        member* temp = tail;
        cout<<"Tail <-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->next;
        }
        cout<<"Head";
    }


     //to display family starting from head

    void displayFromHead()
    {  cout<<endl;
         if(head==NULL)
           {cout<<"no members left in the list.";
           return;}
        member* temp = head;
        cout<<"Head<-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->previous;
        }
        cout<<"Tail";
    }

};





int main()
{ 
    family Rajput;
    Rajput.new_member_front("Adarsh",10);
    Rajput.new_member_front("Ridhima",18);
    Rajput.new_member_front("Kishan",26);
    Rajput.new_member_front("Maanak",40);
    Rajput.new_member_back("Rishabh",12);
    Rajput.displayFromHead();
    cout<<endl;
    Rajput.displayFromTail();
    cout<<endl;
    Rajput.deleteFromHead(2);
    Rajput.displayFromHead();
    Rajput.displayFromTail();
   
    cout<<endl<<Rajput.popTail()->name;
    Rajput.displayFromTail();
    return 0;
}

//Bonus Question:
//Since there are only two ways to transverse we can link different members in a family using linked list only accoring to their ages else there are many cases to be 
// considered .If we talk about relation having no relation with age ,it can't be possible to arrange.
