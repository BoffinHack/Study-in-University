#include <iostream>

using namespace std;
//#include <iomanip>

template <typename T>
class Stack{
private:
    T *prt;                  //Pointer to the beginning of the stack
    int amount,cam;          //Number of elements
public:
    Stack(int amount);
    ~Stack();
    void push(T el);
    void pop();
    void print();
};

template<typename T>
Stack<T>::Stack(int amount){         //Constructor
    cam=this->amount=(amount-1);      // -1, since we start counting from 0
    prt=new T[(amount-1)];         //We allocate memory for the stack
}

template<typename T> //Deconstructor
Stack<T>::~Stack(){
    delete prt;
}

template<typename T>             //Putting the elements on the stack
void Stack<T>::push(T el){
    if(amount>=0){                 //If there is still room
        prt[amount]=el;         //Putting the element
        amount--;           //Reducing the stack size
    }else{
        cout<<"\n\tСтек полон!\n";
    }
}

template<typename T>
void Stack<T>::print(){       //Output the stack
    for(int i=0;i<=cam;i++){
        cout<<"\n\t"<<prt[i]<<"\n";
    }
}

template<typename T>
void Stack<T>::pop(){
    if(amount!=cam){               //If there are still elements in the stack
        amount++;                   //Approaching the end of the stack
        prt[amount]=0;          //Deleting the last element

    }else{
        cout<<"\n\tСтек пуст!\n";
    }
}

int main(){
    setlocale(LC_ALL,"rus");
    Stack<int> R(5);
    R.push(5);
    R.push(54);
    R.push(24);
    R.push(43);
    R.push(5466);
    R.print();
    cout<<"\n\n";
    R.pop();
    R.pop();
    R.print();
    return 0;
}
