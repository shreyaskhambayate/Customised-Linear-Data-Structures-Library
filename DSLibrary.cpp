#include<iostream>
using namespace std;
//////////////////////////////////////////////
//Structure Declarations
//////////////////////////////////////////////


// node is for Singly Linked Lists
template <typename T>
struct node
{
    T data;
    struct node *next;
};

// node2 for   Doubly Linked Lists
template <typename T>
struct node2
{
    T data2;
    struct node2 *next2;
    struct node2 *prev2;
};   


////////////////////////////////////////////////
// End of structure declaration 
////////////////////////////////////////////////


//////////////////////////////////////////////////////
//Class Declarations
// 1. Singly Linear Linked List
// 2. Doubly Linear Linked List
// 3. Singly Circular Linked List
// 4. Doubly Circular Linked List
// 5. Stack 
// 6. Queue
// Author: Shreyas Khambayate
//////////////////////////////////////////////////////

//  1. Singly Linear Linked List
template <class T>
class SinglyLL 
{
private:
    node <T>* first;
    int size;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};
/////////////////////////////////////////////////////////
// 2. Doubly Linear Linked List
template <class T>
class DoublyLL
{
private:    
    int size;
    node2 <T>* first;

public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteFirstX();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();

};
//////////////////////////////////////////////////////////
//  3. Singly Circular Linked List
template <class T>
class SinglyCLL 
{
private:
    node <T>* first;
    node <T>* last;
    int size;
    
public:
    SinglyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};
/////////////////////////////////////////////////////////
// 4. Doubly Circular Linked List
template <class T>
class DoublyCLL
{
private:    
    int size;
    node2 <T>* first;
    node2 <T>* last;

public:
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteFirstX();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();

};
///////////////////////////////////////////
// 5. Stack
template <class T>
class Stack
{
private:
    node <T>* first;
    int size;
public:
    Stack();
    void push(T);
    T pop();
    int Count();
    void Display();
};
/////////////////////////////////////////////
// 6. Queue
template <class T>
class Queue
{
private:
    node<T>* first;
    int size;
public:
    Queue();
    void Enqueue(T);
    T Dequeue();
    int Count();
    void Display();
};
//////////////////////////////////////////////////////////
// End of class declarations
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Inline functions for classes
///////////////////////////////////////////////////////////

// 1. SinglyLLL
template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    size = 0;
}
   
template <class T>
    void SinglyLL<T>::InsertFirst(T no)
    {
        node <T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
        newn->data = no;
        newn->next = NULL;
       
        if(first == NULL)
        {
           first = newn;
        }
        else
        {
           newn->next = first;
           first = newn;
        }
       size++;
    }
   
template <class T>
    void SinglyLL<T>::InsertLast(T no)
    {
        node <T> * newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
       
        newn->data = no;
        newn->next = NULL;
       
        if(first == NULL)
        {
           first = newn;
        }
        else
        {
            node <T>* temp = first;
           
            while(temp->next != NULL)
            {
               temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
   
template <class T>
    void SinglyLL<T>::InsertAtPos(T no, int ipos)
    {
        node <T>* temp = first;

        if( (ipos<1) || (ipos>size+1))
        {
            return;
        }

        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            node <T> * newn = new node<T>;
            newn->data = no;
            newn->next = NULL;

            for(int i = 1; i < ipos - 1; i++)
            {
               temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            size++;
        }
    }
   
template <class T>
    void SinglyLL<T>::DeleteFirst()
    {
        node <T> * temp = first;
       
        if(first != NULL)
        {
           first = first->next;
           delete temp;
           
           size--;
        }
    }

template <class T>
    void SinglyLL<T>::DeleteLast()
    {
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
           size--;
       }
       else
       {
           node <T>* temp = first;
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           
           delete temp->next;
           temp->next = NULL;
           size--;
       }
    }
   
template <class T>
   void SinglyLL<T>::DeleteAtPos(int ipos)
   {
        if( (ipos<1) || (ipos>size))
        {
            return;
        }

        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == size+1)
        {
            DeleteLast();
        }
        else
        {
            node <T>* temp = first;
            for(int i = 1; i<ipos-1;i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;

            size--;
        }
   }
   
template <class T>
    void SinglyLL<T>::Display()
    {
        node <T> * temp = first;
       
        while(temp!= NULL)
        {
           cout<<temp->data<<"\t";
           temp = temp->next;
        }
       cout<<"\n";
    }
   
template <class T>
    int SinglyLL<T>::Count()
    {
       return size;
    }

//////////////////////////////////////////////////////////////////////////
//End of Singly Linear Linked List
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
//2. Doubly Linear Linked List

template <class T>
DoublyLL<T>::DoublyLL()
{
    size = 0;
    first = NULL;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    node2 <T> * newn = new node2<T>;
  
    newn->data2 = no;
    newn->next2 = NULL;
    newn->prev2 = NULL;

    if(first == NULL)
    {
        first = newn;
    }   
    else
    {
        newn -> next2 = first;
        first -> prev2 = newn;

        first = newn;
    }
    size++;
}
template <class T>
void DoublyLL<T>::InsertLast( T no)
{
    node2 <T> * newn = new node2<T>;
    node2 <T> * temp = first;

    newn->data2 = no;
    newn->next2 = NULL;
    newn->prev2 = NULL;

    if(first == NULL)
    {
        first = newn;
    }   
    else
    {
        while(temp->next2 != NULL)
        {
            temp = temp -> next2;
        }
        temp->next2 = newn;
        newn->prev2 = temp;
    }
    size++;
}
template <class T>
void DoublyLL<T>::Display()
{
    node2 <T> * temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp ->data2<<"| ->";
        temp = temp ->next2;
    }   
    cout<<"\n";
}
template <class T>
int DoublyLL<T>::Count()
{
    return size;
}
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    node2 <T> * temp = first;

    if(first != NULL)
    {
        first = first -> next2;
        free(temp);  // temp jithe point kartoy toh free/delete hoil
        if(first != NULL)
        {
            first->prev2 = NULL;
        }
    }
    size--;
}
template <class T>
void DoublyLL<T>::DeleteFirstX()  // add this in declaration
{
    if(first == NULL)
    {
        return;
    }
    else if( first ->next2 == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        node2 <T> * temp = first;
        temp = temp -> next2;
        free(temp-> prev2 );
        temp -> prev2 = NULL;
    }
    size--;
}
template <class T>
void DoublyLL<T>::DeleteLast()  
{
    node2 <T> * temp = first;
    if(first == NULL)
    {
        return;
    }
    else if( first ->next2 == NULL)
    {
        delete(first);
        first = NULL;
    }
    else  
    {
        while(temp->next2 != NULL)
        {
            temp = temp->next2;
        }
        temp->prev2->next2 = NULL;
        delete(temp);
    }
    size--;
}
template <class T>
void DoublyLL<T>::InsertAtPos( T no, int iPos)
{
    int i = 0; // for loop counter
    node2 <T> * temp = first;

    if( (iPos<1)  || (iPos>size+1) )  // filter
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == size + 1)
    {
        InsertLast( no);
    }
    else
    {
        node2 <T> * newn = new node2<T>;
        newn->next2 = NULL;
        newn->prev2 = NULL;
        newn->data2 = no;

        for( i = 1; i <iPos - 1;i++)
        {
            temp = temp ->next2;
        }
        newn->next2 = temp -> next2;
        newn->next2 ->prev2 = newn;
        temp->next2 = newn;
        newn->prev2 = temp;
        size++;
    }
}
template <class T>
void DoublyLL<T>::DeleteAtPos( int iPos)  //check pk code i think this is incomplete last line
{
    int i = 0; // for loop counter
    node2 <T> * temp = first;

    if( (iPos<1)  || (iPos>size) )  // filter
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == size )
    {
        DeleteLast();
    }
    else
    {
        for( i = 1; i <iPos - 1;i++)
        {
            temp = temp ->next2;
        }
        temp->next2 = temp ->next2 ->next2;
        delete(temp->next2->prev2);
        size--;
    }
}


//////////////////////////////////////////////////////////////////////////
//End of Doubly Linear Linked List
//////////////////////////////////////////////////////////////////////////
 

//////////////////////////////////////////////////////////////////////////
//3. Singly Circular Linked List

template <class T>
 SinglyCLL<T>::SinglyCLL()
{
    size = 0;
    first = NULL;
    last = NULL;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    node<T>* newn = new node<T>;
    newn->data = no;
    newn->next = NULL;    

    if((first == NULL) && (last == NULL) ) //empty LL
    { //size == 0
        first = newn;
        last = newn;
    } 
    else 
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    size++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    node<T>* newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    if( size == 0)  // if( (first == NULL) && (last == NULL) )
    {
        first = newn;
        last = newn;
    }
    else if(size == 1) 
    {
        first->next = newn;
        last = newn;
    } 
    else 
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    size++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()  // bug
{
    if(size == 0)
    {
        return;
    }
    else if( size == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = first->next;
        free(last->next);
        last->next = first; 
    }
    
    size--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if( first == last)
    {
        delete first;
        first == NULL;
        last == NULL;
        size--;
        return;
    }
    else 
    {
        node<T>* temp = first;
        while( temp->next != last )
        {
            temp = temp->next;
        }
        delete last; 
        last = temp; 
        
    }
    last->next = first;
    size--;
}

template<class T>
void SinglyCLL<T>::Display()
{
    do
    {
        cout<<"|"<<first->data<<"|\t";
        first = first->next;
    }while(first != last->next);
    cout<<"\n";
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
    if( (ipos < 1)  || (ipos > size+1) )
    {
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
        return;
    }
    else if(ipos == size+1)
    {
        InsertLast(no);
        return;
    }
    else 
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        node<T>* temp = first;
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
    }
    last->next = first;
    size++;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    if( (ipos < 1) || (ipos > size) )
    {
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
        return;
    }
    else if(ipos == size)
    {
        DeleteLast();
        return;
    }
    else 
    {
        for(int i = 1; i < ipos - 1 ; i++)
        {
            first = first->next;
        }
        node<T>* targetted = first->next;
        first->next = first->next->next;
        delete targetted;
    }
    first = last->next;
    size--;
}

////////////////////////////////////////////////////////////////////////
// End of Singly Circular LinkedList
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// 4. DoublyCLL

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    size = 0;
    first = NULL;
    last = NULL;
}

template <class T>
void DoublyCLL<T>::Display()
        {
            if( (first == NULL) && (last == NULL) )   //size == 0
            {
                return;
            }
            do 
            {
                cout<<"|"<<first->data2<<"|";
                first = first->next2;
            }while(first != last->next2);
            cout<<"\n";
            last->next2 = first;
            first->prev2 = last;
        }
    
template <class T>
int DoublyCLL<T>::Count()
{
    return size;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
        {
            node2<T>* newn = new node2<T>;
            newn->data2 = no;
            newn->next2 = NULL;
            newn->prev2 = NULL;

            if( (first == NULL) && (last == NULL) )  // LL empty 
            {
                first = newn;
                last = newn;
                newn->next2 = last;
                newn->prev2 = first;
            }
            else
            {
                newn->next2 = first;
                newn->prev2 = last;
                first = newn;
                last->next2 = newn;
            }
            last->next2 = first;  
            first->prev2 = last; // ye bhi decide kar lo in case of doubly circular
            size++;             
        }
template <class T>
void DoublyCLL<T>::InsertLast(T no)
        {
            if( (first == NULL) && (last == NULL)  ) // size == 0 
            {
                InsertFirst(no);
                return;
            }
            else 
            {
                node2<T>* newn = new node2<T>;
                newn->data2 = no;

                newn->next2 = first;
                newn->prev2 = last;
                first->prev2 = newn;
                last->next2 = newn;
                last = newn;
            }
            size++;
            last->next2 = first;
            first->prev2 = last;
        }
template <class T>
void DoublyCLL<T>::DeleteFirst()  // problem in else
        {
            if( (first == NULL) && (last == NULL)  ) // size == 0 
            {
                return;
            }

            else if(size == 1)
            {
                delete first;
                first = NULL;
                last  = NULL;
            }
            else 
            {
                first = first->next2;
                //delete last->next; // working
                delete first->prev2;  
                last->next2 = first;
                first->prev2 = last;
            }
            size--;
        }
template <class T>
        void DoublyCLL<T>::DeleteLast()
        {
            if(size == 0) // (first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last) // size == 1
            {
                free(first);
                first = NULL;
                last = NULL;
            }
            else
            {
                last = last->prev2;
                last->next2 = first;
                delete first->prev2;
                first->prev2 = last;
            }
            size--;
        }
template <class T>
        void DoublyCLL<T>::InsertAtPos(T no, int ipos)
        {
            if( (ipos < 0) || (ipos > size+1) )
            {
                return;
            }

            if(ipos == 1)
            {
                InsertFirst(no);
                return;
            }
            else if(ipos == size+1)
            {
                InsertLast(no);
                return;
            }
            else 
            {
                node2<T>* temp = first;
                node2<T>* newn = new node2<T>;
                newn->data2 = no;
                newn->next2 = NULL;
                newn->prev2 = NULL;

                for(int i = 1; i < ipos - 1; i++)
                {
                    temp = temp->next2;
                }
                
                newn->prev2 = temp;
                newn->next2 = temp->next2;
                temp->next2 = newn;
                newn->next2->prev2 = newn; 

                size++;
            }
        }
template <class T>
        void DoublyCLL<T>::DeleteAtPos(int ipos)
        {
             if( (ipos < 0) || (ipos > size) )
            {
                return;
            }

            if(ipos == 1)
            {
                DeleteFirst();
                return;
            }
            else if(ipos == size)
            {
                DeleteLast();
                return;
            }  
            else
            {
                node2<T>* temp = first;
                for(int i = 1; i < ipos - 1; i++)
                {
                    temp = temp->next2;
                }
                temp->next2 = temp->next2->next2;
                delete temp->next2->prev2;
                temp->next2->prev2 = temp;

                size--;
            } 
        }

////////////////////////////////////////////////////////////////////////
// End of Doubly Circular LinkedList
////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Inline functions for class Stack
template <class T>
    Stack<T>::Stack()
    {
        first = NULL;
        size = 0;
    }

template <class T>
    void Stack<T>::push(T no)  //InsertFirst
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
            newn->next = NULL;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
template <class T>
    T Stack<T>::pop()  //DeleteFirst
    {
        if(first == NULL)
        {
            return 0;
        }
        else if(size == 1)  // first->next == NULL
        {
            T ret = first->data;
            delete first;
            first = NULL;
            size--;
            return ret;
        }
        else
        {
            node<T>* temp = first;
            T ret = first->data;
            first = first->next;
            delete temp;
            size--;
            return ret;
        }
    } 
template <class T>
    int Stack<T>::Count()
    {
        return size;
    }
template <class T>
    void Stack<T>::Display()
    {
        node<T>* temp = first;
        if(first == NULL)
        {
            return;
        }
        while( temp != NULL )
        {
            cout<<"|"<<temp->data<<"|\n";
            temp = temp->next;
        }
    }

//////////////////////////////////////////////////////////////////////////
//End of Function Definations for Stack
//////////////////////////////////////////////////////////////////////////
 
////////////////////////////////////////////////////
// Inline Functions for Queue
template <class T>
    Queue<T>::Queue()
    {
        first = NULL;
        size = 0;
    }
template <class T>
    void Queue<T>::Enqueue(T no)  //InsertFirst
    {
        node<T>* newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)  // size == 0
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
template <class T>
    T Queue<T>::Dequeue()  //DeleteFirst
    {
        if( size == 0)  // first == NULL
        {
            return 0;
        }
        else if( size == 1) // first->next == NULL
        {
            T ret = first->data;
            delete first;
            first = NULL;
            --size;  // size = 0
            return ret;
        }

        else
        {
            node<T>* temp = first;
            while(temp->next->next != NULL) 
            {
                temp = temp->next;
            }

            T ret = temp->next->data;
            delete temp->next; 
            temp->next = NULL; 

            size--;
            return ret;
        }
    }
template <class T>
    int Queue<T>::Count()
    {
        return size;
    }
template <class T>
    void Queue<T>::Display()
    {
        node<T>* temp = first;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|";
            temp = temp->next;
        }   
        cout<<"\n";
    }
////////////////////////////////////////////////////
//End of Function Definations for Queue
//////////////////////////////////////////////////////////////////////////