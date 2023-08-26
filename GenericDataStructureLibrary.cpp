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
    cout<<"Elements of Singly Circular Linked List: " <<"\n";

    NodeS<T> *temp = first;

    for(int iCnt =1; iCnt<= iCount; iCnt++)
    {
        cout<<"->|"<<temp->data<<"|";
        temp = temp->next;
    }
    cout<<"->NULL"<<"\n";
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
    newn->data = no;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last -> next = newn;

    iCount++;
}

template<class T>
void SinglyCL <T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;

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
        newn->data = no;

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

    for(int iCnt=1; iCnt <= iCount; iCnt++)
    {
        cout<<"=>|"<<temp->data<<"|";
        temp = temp->next;
    }
    cout<<"=> NULL"<<"\n";
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
    newn->data = no;

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
    newn->data = no;

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
        newn ->data = no;

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
// Class of ArrayX
///////////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectinalSearch(T);
        bool BinarySearch(T);

        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}


///////////////////////////////////////////////////////////////////////////
//           Linear Search
///////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag  = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}


///////////////////////////////////////////////////////////////////////////
//          Bidirectional Search
///////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BidirectinalSearch(T No)
{
    bool flag  = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}


///////////////////////////////////////////////////////////////////////////
//          Binary Search
///////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;
    
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if(Arr[iMid] == No)
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////
//          Bubble Sort
///////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

///////////////////////////////////////////////////////////////////////////
//          Bubble sort Efficient
///////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

///////////////////////////////////////////////////////////////////////////
//          Selection Sort
///////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

///////////////////////////////////////////////////////////////////////////
//          Insertion Sort
///////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
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

    // cout<<"Singly Linear Linked List.....\n";
    // obj1.InsertFirst(51);
    // obj1.InsertFirst(21);
    // obj1.InsertFirst(11);

    // obj1.InsertLast(101);
    // obj1.InsertLast(111);

    // obj1.Display();
    // cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    // obj1.InsertAtPosition(55, 4);
    // obj1.Display();
    // cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    // obj1.DeleteAtPosition(4);
    // obj1.Display();
    // cout<<"Number of elements are: "<<obj1.count()<<"\n\n";
   
    // obj1.DeleteFirst();
    // obj1.DeleteLast();

    // obj1.Display();
    // cout<<"Number of elements are: "<<obj1.count()<<"\n\n";

    // cout<<"Doubly Linear Linked List.....\n";
    // obj3.InsertFirst(50);
    // obj3.InsertFirst(20);
    // obj3.InsertFirst(10);

    // obj3.InsertLast(100);
    // obj3.InsertLast(110);

    // obj3.InsertAtPosition(60, 4);
    // obj3.Display();
    // cout<<"Number of elements are: "<<obj3.count()<<"\n\n";

    // obj3.DeleteAtPosition(4);
       
    // obj3.DeleteFirst();
    // obj3.DeleteLast();

    // obj3.Display();
    // cout<<"Number of elements are: "<<obj3.count()<<"\n\n";

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
   
    // obj2.DeleteFirst();
    // obj2.DeleteLast();

    // obj2.Display();
    // cout<<"Number of elements are: "<<obj2.count()<<"\n\n";

    // cout<<"Doubly Circular Linked List.....\n";
    // obj4.InsertFirst(50);
    // obj4.InsertFirst(20);
    // obj4.InsertFirst(10);

    // obj4.InsertLast(100);
    // obj4.InsertLast(110);

    // obj4.InsertAtPosition(60, 4);
    // obj4.Display();
    // cout<<"Number of elements are: "<<obj4.count()<<"\n\n";

    // obj4.DeleteAtPosition(4);
    // obj4.Display();
    // cout<<"Number of elements are: "<<obj4.count()<<"\n\n";
   
    // obj4.DeleteFirst();
    // obj4.DeleteLast();

    // obj4.Display();
    // cout<<"Number of elements are: "<<obj4.count()<<"\n\n";

    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iValue;

    ArrayX <int>*obj = new ArrayX<int>(iValue);

    obj->Accept();
    obj->Display();

    cout<<"Enter the element that you want to search\n";
    cin>>iValue;

   // bRet = obj->LinearSearch(iValue);
    //bRet = obj->BidirectinalSearch(iValue);

    bRet = obj->BinarySearch(iValue);
    if(bRet == true)
    {
        cout<<iValue<<" is present in the array\n";
    }
    else
    {
        cout<<iValue<<" is not present in the array\n";
    }
    delete obj;
    return 0;

}
///////////////////////////////////////////////////////////////////////////
