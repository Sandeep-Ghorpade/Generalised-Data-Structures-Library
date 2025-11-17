#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void QueueX<T> :: Enqueue(T no) // InsertLast
{
    struct Queuenode<T> *temp = NULL;
    struct Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
T QueueX<T> :: Dequeue()         // DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int QueueX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: Push(T no) // InsertFirst
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of singly circular linked list
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of doubly cirular Linked List
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLLL 
//  Description :   Generic implementation of singly linear Linked List
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////


template <class T>
struct SinglyLLLnode
{   
    T data;
    struct SinglyLLLnode<T> * next;
};

template <class T>
class SinglyLLL
{
    private : 
        int iCount;
        struct SinglyLLLnode<T> * first;
    public :
        SinglyLLL();
        void Display();
        int Count();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    iCount = 0;
    first = NULL;
}

template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    else
    {
        temp = first;

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
}

template <class T>
int SinglyLLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * newn = NULL;

    if((pos < 1) || (pos > iCount + 1))
    {
        cout<<"Invaild input\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>;

        newn -> data = no;
        newn -> next = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Linked list is empty.\n";
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        first = first -> next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Linked list is empty.\n";
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp -> next = NULL;
        iCount--;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invaild input\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete target;
        iCount--;
    }
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLLL 
//  Description :   Generic implementation of doubly linear Linked List
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////


template <class T>
struct DoublyLLLnode
{   
    T data;
    struct DoublyLLLnode<T> * next;
    struct DoublyLLLnode<T> * prev;
};

template <class T>
class DoublyLLL
{
    private : 
        int iCount;
        struct DoublyLLLnode<T> * first;
    public :
        DoublyLLL();
        void Display();
        int Count();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    iCount = 0;
    first = NULL;
}

template <class T>
void DoublyLLL<T> :: Display()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    else
    {
        temp = first;

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }
}

template <class T>
int DoublyLLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new DoublyLLLnode<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new DoublyLLLnode<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * newn = NULL;

    if((pos < 1) || (pos > iCount + 1))
    {
        cout<<"Invaild input\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"Linked list is empty.\n";
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;
        delete first->prev;
        first -> prev = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Linked list is empty.\n";
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp -> next = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invaild input\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete temp-> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         BST 
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////


template <class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *lchild;
    struct BSTnode<T> *rchild;
};

template <class T>
void Insert(struct BSTnode<T> ** first, T no)
{
    struct BSTnode<T> * newn = NULL;
    struct BSTnode<T> * temp = NULL;

    newn = (struct BSTnode<T> *)malloc(sizeof(BSTnode<T>));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)  // BST is empty
    {
        *first = newn;
    }
    else                // BST contains atleast 1 node
    {
        temp = *first;

        while(1)
        {
            if(no == temp->data)
            {
                printf("Duplicate element : Unable to insert node\n");
                free(newn);
                break;
            }
            else if(no > temp->data)    // rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)    // lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template <class T>
void Inorder(struct BSTnode<T> * first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\t",first->data);
        Inorder(first->rchild);
    }
}

template <class T>
void Preorder(struct BSTnode<T> * first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

template <class T>
void Postorder(struct BSTnode<T> * first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\t",first->data);
    }
}

template <class T>
bool Search(struct BSTnode<T> * first, T no)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {   
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }

    return bFlag;
}

template <class T>
int Count(struct BSTnode<T> * first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->rchild);   // Importanat
        Count(first->lchild);
    }
    return iCount;
}

template <class T>
int CountLeafNodes(struct BSTnode<T> * first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->lchild == NULL && first->rchild ==NULL)
        {
            iCount++;
        }

        CountLeafNodes(first->rchild);   // Importanat
        CountLeafNodes(first->lchild);
    }
    return iCount;
}

template <class T>
int CountParentNodes(struct BSTnode<T> * first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->lchild != NULL || first->rchild != NULL)
        {
            iCount++;
        }

        CountParentNodes(first->rchild);   // Importanat
        CountParentNodes(first->lchild);
    }
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting 
//  Description :   Generic implementation of sorting algorithms
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template <class T>
class Sorting        // Increasing
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        Sorting(int no);
        ~Sorting();
        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
Sorting<T> :: Sorting(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
Sorting<T> :: ~Sorting()
{
    delete []Arr;
}

template <class T>
void Sorting<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i =0;                   // 11       

    for(i = 0; i < iSize;i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))     // IMP
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void Sorting<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void Sorting<T> :: BubbleSort()
{
    int i = 0, j = 0, temp = 0;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; i < iSize ; i++)         // Outer loop
    {
        for(j = 0; j < iSize - 1; j++)      // Inner loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"Data after Pass : "<<i+1<<"\n";

        Display();
    }
}

template <class T>
void Sorting<T> :: BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; (i < iSize && bFlag == true) ; i++)         // Outer loop
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i; j++)      // Inner loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout<<"Data after Pass : "<<i+1<<"\n";

        Display();
    }
}

template <class T>
void Sorting<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0 ; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template <class T>
void Sorting<T> :: InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching (program587.cpp) -> generic
//  Description :   Generic implementation of searching algorithms
//  Author :        Sandeep Sanjay Ghorpade
///////////////////////////////////////////////////////////////////////

template <class T>
class Searching        // Increasing
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        Searching(int no);
        ~Searching();
        void Accept();
        void Display();        
        bool LinearSearch(int no);       // N
        bool BiDirectionalSearch(int no);    // N/2
        bool BinarySearchInc(int no);
        bool BinarySearchDec(int no);
        bool BinarySearchEfficientInc(int no);
        bool BinarySearchEfficientDec(int no);
        bool CheckSortedInc();
        bool CheckSortedDec();

};

template <class T>
Searching<T> :: Searching(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
Searching<T> :: ~Searching()
{
    delete []Arr;
}

template <class T>
void Searching<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i =0;                   // 11       

    for(i = 0; i < iSize;i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))     // IMP
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void Searching<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool Searching<T> :: LinearSearch(int no)       // N
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)                  // IMP
    {
        cout<<"Data is sorted\n";

        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template <class T>
bool Searching<T> :: BiDirectionalSearch(int no)    // N/2
{
    int iStrat = 0;
    int iEnd = 0;

    bool bFlag = false;

    for(iStrat = 0, iEnd = iSize-1 ; iStrat <= iEnd; iStrat++, iEnd--)
    {
        if(Arr[iStrat] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template <class T>
bool Searching<T> :: BinarySearchInc(int no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // First half (Left window)
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])     // Second half (Right window)
        {
            iStart = iMid + 1;
        }
    }   // End of while

    return bFlag;
}

template <class T>
bool Searching<T> :: BinarySearchDec(int no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])     // First half (Left window)
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])     // Second half (Right window)
        {
            iStart = iMid + 1;
        }
    }   // End of while

    return bFlag;
}

template <class T>
bool Searching<T> :: BinarySearchEfficientInc(int no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)       // New
    {
        cout<<"Data is not sorted\n";
        
        return LinearSearch(no);    // Important
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    //Change
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // First half (Left window)
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])     // Second half (Right window)
        {
            iStart = iMid + 1;
        }
    }   // End of while

    return bFlag;
}

template <class T>
bool Searching<T> :: BinarySearchEfficientDec(int no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    //Change
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])     // First half (Left window)
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])     // Second half (Right window)
        {
            iStart = iMid + 1;
        }
    }   // End of while

    return bFlag;
}

template <class T>
bool Searching<T> :: CheckSortedInc()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])   // Change kela ahe
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

template <class T>
bool Searching<T> :: CheckSortedDec()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i+1])   // Change kela ahe
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

int main()
{
    
    return 0;
}