/*
Describe the template class Set for representing a set. Elements
sets are stored in dynamic memory as a singly linked list.
Duplicate elements are not entered in the Set.
For objects of the Set class, define the operations check for adding an element to
a set (add), deleting an element (del), entering an element (in),
combining N sets.
Demonstrate working with a template class for different types of
information elements.
*/
#include <iostream>
using namespace std;

template<typename T>
class List{
public:
    List();
    ~List();

    //Check if the item exists in the list
    int check(T i);

    //List output
    void print();

    //Combining sets
    void union_queue(List<T> *obj);

    //deleting the first item in the list
    void del_front();

    //deleting an item in the list
    void del(T t);

    //Adding an item to the end of the list
    void push_back(T data);

    //Clearing the list
    void clear();

    //Getting the number of items in the list
    int get_size(){return Size;}

    //Getting start and end addresses
    void get_pointer();

private:
    template<typename U>
    class Node{
    public:
        Node *pNext;
        U data;
        Node(U data=U(),Node *pNext=nullptr){
            this->data=data;
            this->pNext=pNext;
        }
    };
    int Size;
    Node<T> *start;
};

template<typename T>
List<T>::List(){
    Size=0;
    start=nullptr;
}

template<typename T>
List<T>::~List(){
    clear();
}

template<typename T>
void List<T>::get_pointer(){
    cout<<"\n Начало ";
    cout<<this->start;
}

template<typename T>
void List<T>::union_queue(List<T> *obj){
    List<T> *l=obj;
    while(l->start!=nullptr){
        push_back(l->start->data);
        l->start=l->start->pNext;
        Size++;
    }
}

template<typename T>
void List<T>::clear(){
    while(Size){
        del_front();
    }
}

template<typename T>
void List<T>::del(T t){
    int i=0;
    Node<T> *tp=this->start;
    Node<T> *temp=tp;
    while(temp!=nullptr){
        if((temp->data==t)&&(i==0)){
            start=start->pNext;
            delete tp;
            Size--;
        }else{
            if(temp->data==t){
                Node<T> *del=tp->pNext;
                tp->pNext=del->pNext;
                //temp=temp->pNext;
                delete del;
                Size--;
            }
        }
        tp=temp;
        temp=temp->pNext;
        i++;
    };
}

template<typename T>
void List<T>::del_front(){
    Node<T> *temp=this->start;
    start=start->pNext;
    delete temp;
    Size--;
}

template<typename T>
int List<T>::check(T i){
    Node<T> *temp=this->start;
    while(temp!=nullptr){
        if(temp->data==i)
            return 1;
        temp=temp->pNext;
    }
}

template<typename T>
void List<T>::push_back(T data){
    if(check(data)!=1){
        if(start==nullptr){
            start=new Node<T>(data);
        }else{
            Node<T> *push=this->start;
            while(push->pNext!=nullptr){
                push=push->pNext;
            }
            push->pNext=new Node<T>(data);
        }
        Size++;
    }
}

template<typename T>
void List<T>::print(){
    Node<T> *l=this->start;
    int i=0;
    while(l!=nullptr){
        cout<<"\n"<<i<<" - "<<l->data<<"\n";
        i++;
        l=l->pNext;
    }
}

int main(){
    setlocale(LC_ALL,"rus");

                                       cout<<"\n\tWorking with the data type int\n";
    List<int> obj1_int;
    List<int> obj2_int;

    obj1_int.push_back(5);
    obj1_int.push_back(10);
    obj1_int.push_back(100);
    cout<<"\nМножество \n\n";
    obj1_int.print();
    cout<<"\nAdding elements 6, 54 и 4567 in the set\n\n";
    obj1_int.push_back(6);
    obj1_int.push_back(54);
    obj1_int.push_back(4567);
    cout<<"\nМножество после\n\n";
    obj1_int.print();
    cout<<"\nAdding the element again 6 in the set\n\n";
    obj1_int.push_back(6);
    cout<<"\nМножество после\n\n";
    obj1_int.print();
    cout<<"\nElement 6 was not added to the set, since it already exists\n\n";
    cout<<"\nDelete elements 5, 100 and 54\n\n";
    obj1_int.del(5);
    obj1_int.del(100);
    obj1_int.del(54);
    cout<<"\nThe set after\n\n";
    obj1_int.print();
    cout<<"\nCreating a new set\n\n";
    obj2_int.push_back(4634);
    obj2_int.push_back(1045);
    obj2_int.push_back(145);
    cout<<"\nAnother set \n\n";
    obj2_int.print();
    cout<<"\nLet's combine the sets\n\n";
    obj1_int.union_queue(&obj2_int);
    cout<<"\nThe combined set  \n\n";
    obj1_int.print();
    obj1_int.clear();
    obj2_int.clear();

    return 0;
}

