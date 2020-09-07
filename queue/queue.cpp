#include <iostream>
using namespace std;
const int maxsize = 5;
int que[maxsize];

class Que
{
 private:
    int front = -1;
    int rear = -1;
    int choice =0;
public:

  void insert ()
  {
    int val;
      cout << "Enter the element you want" << "\n";
      cin >> val;
    if (rear == maxsize - 1)
      {
	cout << "overflow" << endl;
	return;
      }
    if (front == -1 && rear == -1)
      {
	front = 0;
	rear = 0;
      }
    else
      {
	rear = rear + 1;
      }
    que[rear] = val;
    cout << "value is Inserted" << endl;
  }

  void del ()
  {
    int item;
    if (front == -1 || front > rear)
      {
	cout << "underflow" << endl;
	return;
      }
    else
      {
	item = que[front];
	if (front == rear)
	  {
	    front = -1;
	    rear = -1;
	  }
	else
	  {
	    front = front + 1;
	  }
	cout << "value deleted" << endl;
      }
  }

  void display ()
  {
    int i;
    if (rear == -1)
      {
	cout << "empty queue" << endl;
      }
    else
      {
	cout << "printing values......" << endl;
	for (i = front; i <= rear; i++)
	  {
	    cout << que[i] << endl;
	  }
      }
  }
  void run ()
  {
    while (choice != 4)
      {
	cout << "1.insert an element" << endl << "2.delete the element" <<
	  endl << "3.didplay the queue" << endl << "4.exit" << endl;
	cout << "enter your choice ?" << endl;
	cin >> choice;
	switch (choice)
	  {
	  case 1:
	    {
	      insert ();
	      break;
	    }
	  case 2:
	    {
	      del ();
	      break;
	    }
	  case 3:
	    {
	      display ();
	      break;
	    }
	  case 4:
	    {
	      exit (0);
	      break;
	    }
	  default:
	    {
	      cout << " you Enter valid choice" << endl;
	    }
	  };
      }

  }
};


  int main ()
  {
    Que q;
    q.run ();
    return 0;
  }