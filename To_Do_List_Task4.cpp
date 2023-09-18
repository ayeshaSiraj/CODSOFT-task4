#include <iostream>
#include <cstring>
using namespace std;

class node
{  public:
    string task;
    node*next;
    node*previous;
    bool status;
node()
{}
    node(string name)
    {
        status=false;
        task=name;
        next=NULL;
        previous=NULL;
    }
};


class ToDoList
{
     private:
   node *head;
   int length;
   
   public:

   void AddTask(string val,int pos)
   {

        if(pos<0 || pos>length+1)
        return;
        if(pos==1)
        {        node*n=new node(val);

            n->next=head;
            
            if(head!=NULL)
            head->previous=n;

             head=n;
        }

        else{
                    node*n=new node(val);

        node *curr=head;

             for(int i=1 ; i<pos-1 ; i++)
             {
                curr=curr->next;
             }
               // n->previous=curr;
                n->next=curr->next;
                if(curr->next!=NULL)
                curr->next->previous=n;
                //if(curr->next!=NULL)
                curr->next=n;
                n->previous=curr;
             

        }
           length++;
   }

     void DisplayListOrder()
     {
         if(length==0)
         cout<<"No Tasks to print"<<endl;
int c;

         node*curr=head;
         cout<<"Display Task in forward or reverse order?\n1.Forward\n2.Reverse"<<endl;
         cin>>c;
         if(c==1)
         { cout<<"______________TO-DO-LIST______________"<<endl;
          for(int i=1 ; i<=length ; i++)//forward
          {
            cout<<"Task "<<i<<" : "<<curr->task<<"-------------Status : ";
            if(curr->status==false)
            cout<<"Pending"<<endl;
            else if(curr->status==true)
            cout<<"Completed"<<endl;
            curr=curr->next;

          }
         }


else if(c==2)
{

                  while(curr->next!=NULL)
                  {
                    curr=curr->next;
                  }
 cout<<"______________TO-DO-LIST______________"<<endl;
              for(int i=1 ;i<=length ; i++)//reverse
          {
            cout<<i<<"). "<<curr->task<<"-------------Status : ";
            if(curr->status==false)
            cout<<"Pending"<<endl;
            else if(curr->status==true)
            cout<<"Completed"<<endl;
            curr=curr->previous;

          }    

}



     }


     void display()
     {
        if(length==0)
         cout<<"No Tasks to print"<<endl;

         node*curr=head;
         cout<<"______________TO-DO-LIST______________"<<endl;
          for(int i=1 ; i<=length ; i++)//forward
          {
            cout<<"Task "<<i<<" : "<<curr->task<<"-------------Status : ";
            if(curr->status==false)
            cout<<"Pending"<<endl;
            else if(curr->status==true)
            cout<<"Completed"<<endl;
            curr=curr->next;

          
         }
     }


     void MarkTaskComplete(int pos)
     {
        node*curr=head;
        for(int i=1 ; i<pos ; i++)
        {
            curr=curr->next;
        }

        curr->status=true;
     }

     void RemoveCompletedTasks(int pos)
     {
        node*curr=head;
         if(pos==1)
         {
            head=head->next;
            delete curr;
            if(head!=NULL)
            head->previous=NULL;
         }
         else
         {
           node*slow=NULL;
           for(int i=1;i<pos;i++)
           {
            slow=curr;
            curr=curr->next;
           }
           slow->next=curr->next;
           delete curr;
         }
         length--;
         
        
     }

ToDoList()
{
    head=NULL;
    length=0;
}
    
~ToDoList()
{
     node*curr=head;
        for(int i=0 ;i<=length ; i++)
        {
            curr=head;
            head=head->next;
            delete curr;
        }
}    
     int getlength()
     {
        return length;
     }

  
   int find()
   {   node*curr=head;
   int pos=1;
       for(int i=1 ; i<=length ; i++)
       {
            if(curr->status==true)
            RemoveCompletedTasks(pos);
            curr=curr->next;
            pos++;
       }
   }





};



int main()
{
    ToDoList l;
    int choice;

    while(1)
    {
        cout<<"________________MENU________________"<<endl;
        cout<<"1).Add Task\n2).Mark Task as Completed\n3).Remove all Completed Tasks\n4).Display Task\n5).Exit"<<endl;
cin>>choice;

        if(choice==1)
        {
            string name;
            cout<<"Enter task name "<<endl;
            getwchar();
            getline(cin,name);
            cout<<"Enter the priority level of the task on the scale of 1 onwards"<<endl;
            int p;
            cin>>p;
            l.AddTask(name,p);
        }
        else if(choice==2)
        {  l.display();
        int num;
            cout<<"Enter task number you want to Mark Complete"<<endl;
            cin>>num;
            l.MarkTaskComplete(num);
        }
        else if(choice==3)
        {
            l.find();
        }
        else if(choice==4)
        {
            l.DisplayListOrder();
        }
        else if(choice==5)
        break;
    }


}
