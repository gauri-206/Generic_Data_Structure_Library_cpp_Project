#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
    struct NodeS *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    public:
        struct NodeS<T> *first;
        int iCount;

        SinglyLL();
        void Display();
        int count();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);

};

template<class T>
SinglyLL <T>:: SinglyLL()
{
    first = NULL;
    iCount =0;
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked List: " <<"\n";

    NodeS<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyLL <T>::count()
{
    return iCount;
}

template<class T>
void SinglyLL <T>::InsertFirst(T no)
{

    NodeS<T> * newn = new NodeS<T>;

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
    iCount++;
    
}

template<class T>
void SinglyLL <T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL <T>::InsertAtPosition(T no, int ipos)
{

    if((ipos < 1) || (ipos > iCount+1 ))
    {
        cout<<"Invalid Position...\n";
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T> ;

        newn ->data = no;
        newn->next = NULL;

        for(int iCnt=1; iCnt < ipos-1; iCnt++ )
        {
            temp = temp->next;
        }
        newn ->next = temp ->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;   
}

template<class T>
void SinglyLL <T>::DeleteLast()
{
    if(first == NULL)

    {
        return;
    }     
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL <T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount ))
    {
        cout<<"Invalid Position...\n";
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for(int iCnt =1; iCnt<ipos -1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCL
{
    public:
        struct NodeS<T> *first;
        struct NodeS<T> *last;
        int iCount;

        SinglyCL();
    void Display();
    int count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);

};

template<class T>
SinglyCL <T>:: SinglyCL()
{
    first = NULL;
    iCount =0;
}

template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked List: " <<"\n";

    NodeS<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"->| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SinglyCL <T>::count()
{
    return iCount;
}

template<class T>
void SinglyCL <T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template<class T>
void SinglyCL <T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }

    last -> next = first;
    first -> prev = last;
    
    iCount++;
}

template<class T>
void SinglyCL <T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        NodeS<T> *newn = new NodeS<T>;

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void SinglyCL <T>::DeleteFirst()
{
     if(iCount == 0)         
    {
        return; 
    }
    else if(iCount == 1)        
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else       
    {
        first = first->next;
        delete last->next;     

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCL <T>::DeleteLast()
{
     if(iCount == 0)         
    {
        return; 
    }
    else if(iCount == 1)        
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else       
    {
        last = last -> prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCL <T>::DeleteAtPosition(int ipos)
{
        if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = first;
        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    public:
        struct NodeD<T> *first;
        int iCount;

         DoublyLL();
    void Display();
    int count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
};

template<class T>
DoublyLL <T>:: DoublyLL()
{
    first = NULL;
    iCount =0;
}

template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of Doubly Linear Linked List: " <<"\n";

    NodeD<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int DoublyLL <T>::count()
{
    return iCount;
}

template<class T>
void DoublyLL <T>::InsertFirst(T no)
{

    NodeD<T> * newn = new NodeD<T>;

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
    iCount++;
    
}

template<class T>
void DoublyLL <T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL <T>::InsertAtPosition(T no, int ipos)
{

    if((ipos < 1) || (ipos > iCount+1 ))
    {
        cout<<"Invalid Position...\n";
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T> ;

        newn ->data = no;
        newn->next = NULL;

        for(int iCnt=1; iCnt < ipos-1; iCnt++ )
        {
            temp = temp->next;
        }
        newn ->next = temp ->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;   
}

template<class T>
void DoublyLL <T>::DeleteLast()
{
    if(first == NULL)

    {
        return;
    }     
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL <T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount ))
    {
        cout<<"Invalid Position...\n";
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for(int iCnt =1; iCnt<ipos -1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
    public:
        struct NodeD<T> *first;
        struct NodeD<T> *last;
        int iCount;

         DoublyCL();
    void Display();
    int count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
};

template<class T>
DoublyCL <T>:: DoublyCL()
{
    last = NULL;
    iCount =0;
}

template<class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Doubly Circular Linked List: " <<"\n";

    NodeD<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"=>| "<<temp->data<<" |=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int DoublyCL <T>::count()
{
    return iCount;
}

template<class T>
void DoublyCL <T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template<class T>
void DoublyCL <T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }

    last -> next = first;
    first -> prev = last;
    
    iCount++;
}

template<class T>
void DoublyCL <T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        NodeD<T> *newn = new NodeD<T>;
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyCL <T>::DeleteFirst()
{
     if(iCount == 0)         
    {
        return; 
    }
    else if(iCount == 1)        
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else       
    {
        first = first->next;
        delete last->next;     

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template<class T>
void DoublyCL <T>::DeleteLast()
{
     if(iCount == 0)         
    {
        return; 
    }
    else if(iCount == 1)        
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else       
    {
        last = last -> prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template<class T>
void DoublyCL <T>::DeleteAtPosition(int ipos)
{
        if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;
        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////
// Entry point function
///////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL<int> obj1;
    SinglyCL<int> obj2;
    DoublyLL<int> obj3;
    DoublyCL<int> obj4;

    cout<<"Singly Linear Linked List.....\n";
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();
    cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    obj1.InsertAtPosition(55, 4);
    obj1.Display();
    cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    obj1.DeleteAtPosition(4);
    obj1.Display();
    cout<<"Number of elements are: "<<obj1.count()<<"\n\n";
   
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    cout<<"Doubly Linear Linked List.....\n";
    obj3.InsertFirst(50);
    obj3.InsertFirst(20);
    obj3.InsertFirst(10);

    obj3.InsertLast(100);
    obj3.InsertLast(110);

    obj3.InsertAtPosition(60, 4);
    obj3.Display();
    cout<<"Number of elements are: "<<obj3.count()<<"\n\n";

    obj3.DeleteAtPosition(4);
       
    obj3.DeleteFirst();
    obj3.DeleteLast();

    obj3.Display();
    cout<<"Number of elements are: "<<obj3.count()<<"\n\n";

    // cout<<"Singly Circular Linked List.....\n";
    // obj2.InsertFirst(50);
    // obj2.InsertFirst(20);
    // obj2.InsertFirst(10);

    // obj2.InsertLast(100);
    // obj2.InsertLast(110);

    // obj2.InsertAtPosition(60, 4);
    // obj2.Display();
    // cout<<"Number of elements are: "<<obj2.count()<<"\n\n";

    // obj2.DeleteAtPosition(4);
    // obj2.Display();
    // cout<<"Number of elements are: "<<obj2.count()<<"\n\n";
   
    // obj4.DeleteFirst();
    // obj4.DeleteLast();

    // obj2.Display();
    // cout<<"Number of elements are: "<<obj2.count()<<"\n\n";
    // return 0;
}

///////////////////////////////////////////////////////////////////////////
