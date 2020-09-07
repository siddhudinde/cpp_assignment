        #include<iostream>
    using namespace std;
    struct node
    {
        int data;
        node *next;
    };
    node *head;
    class LinkedList
    {
  public :
    void beginsert ();
    void lastinsert ();
    void randominsert();
    void begin_delete();
    void last_delete();
    void random_delete();
    void display();
    void search();
    };
   
    void LinkedList :: beginsert()
    {
        node *ptr;
        int item;
        ptr = new node;
        if(ptr == NULL)
        {
            cout<<"\nOVERFLOW";
        }
        else
        {
            cout<<"\nEnter value\n";
            cin>>item;
            ptr->data = item;
            ptr->next = head;
            head = ptr;
            cout<<"\nNode inserted";
        }

    }
    void LinkedList :: lastinsert()
    {
        node *ptr,*temp;
        int item;
        ptr = new node;
        if(ptr == NULL)
        {
            cout<<"\nOVERFLOW";
        }
        else
        {
            cout<<"\nEnter value?\n";
            cin>>item;
            ptr->data = item;
            if(head == NULL)
            {
                ptr -> next = NULL;
                head = ptr;
                cout<<"\nNode inserted";
            }
            else
            {
                temp = head;
                while (temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = ptr;
                ptr->next = NULL;
                cout<<"\nNode inserted";

            }
        }
    }
    void LinkedList :: randominsert()
    {
        int i,loc,item;
        node *ptr, *temp;
        ptr = new node;
        if(ptr == NULL)
        {
            cout<<"\nOVERFLOW";
        }
        else
        {
            cout<<"\nEnter element value";
            cin>>item;
            ptr->data = item;
            cout<<"\nEnter the location after which you want to insert ";
            cin>>loc;
            temp=head;
            for(i=0;i<loc;i++)
            {
                temp = temp->next;
                if(temp == NULL)
                {
                    cout<<"\ncan't insert\n";
                    return;
                }

            }
            ptr ->next = temp ->next;
            temp ->next = ptr;
            cout<<"\nNode inserted";
        }
    }
    void LinkedList :: begin_delete()
    {
        node *ptr;
        if(head == NULL)
        {
            cout<<"\nList is empty\n";
        }
        else
        {
            ptr = head;
            head = ptr->next;
            delete ptr;
            cout<<"\nNode deleted from the begining ...\n";
        }
    }
    void LinkedList :: last_delete()
    {
        node *ptr,*ptr1;
        if(head == NULL)
        {
            cout<<"\nlist is empty";
        }
        else if(head -> next == NULL)
        {
            head = NULL;
            delete head;
            cout<<"\nOnly node of the list deleted ...\n";
        }

        else
        {
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr1 = ptr;
                ptr = ptr ->next;
            }
            ptr1->next = NULL;
            delete ptr;
            cout<<"\nDeleted Node from the last ...\n";
        }
    }
    void LinkedList :: random_delete()
    {
        node *ptr,*ptr1;
        int loc,i;
        cout<<"\n Enter the location of the node after which you want to perform deletion \n";
        cin>>loc;
        ptr=head;
        for(i=0;i<loc;i++)
        {
            ptr1 = ptr;
            ptr = ptr->next;

            if(ptr == NULL)
            {
                cout<<"\nCan't delete";
                return;
            }
        }
        ptr1 ->next = ptr ->next;
        delete ptr;
        cout<<"\nDeleted node  "<<loc+1;
    }
    void LinkedList :: search()
    {
        node *ptr;
        int item,i=0,flag;
        ptr = head;
        if(ptr == NULL)
        {
            cout<<"\nEmpty List\n";
        }
        else
        {
            cout<<"\nEnter item which you want to search?\n";
            cin>>item;
            while (ptr!=NULL)
            {
                if(ptr->data == item)
                {
                    cout<<"item found at location  "<<i+1;
                    flag=0;
                }
                else
                {
                    flag=1;
                }
                i++;
                ptr = ptr -> next;
            }
            if(flag==1)
            {
                cout<<"Item not found\n";
            }
        }

    }

    void LinkedList :: display()
    {
        struct node *ptr;
        ptr = head;
        if(ptr == NULL)
        {
            cout<<"Nothing to print";
        }
        else
        {
            cout<<"\nprinting values . . . . .\n";
            while (ptr!=NULL)
            {
                cout<<"\n"<<ptr->data;
                ptr = ptr -> next;
            }
        }
    }
     int main ()
    {
        LinkedList L;
        int choice =0;
        while(choice != 9)
        {
            cout<<"\n\n*********Main Menu*********\n";
            cout<<"\nChoose one option from the following list ...\n";
            cout<<"\n===============================================\n";
            cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n";
            cout<<"\nEnter your choice?\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                L.beginsert();
                break;
                case 2:
                L.lastinsert();
                break;
                case 3:
                L.randominsert();
                break;
                case 4:
                L.begin_delete();
                break;
                case 5:
                L.last_delete();
                break;
                case 6:
                L.random_delete();
                break;
                case 7:
                L.search();
                break;
                case 8:
                L.display();
                break;
                case 9:
                exit(0);
                break;
                default:
                cout<<"Please enter valid choice..";
            }
        }
    }

