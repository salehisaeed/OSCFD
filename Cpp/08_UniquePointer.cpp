#include <iostream>
#include <memory>
using namespace std;

class myList
{
public:
    myList(int);
    ~myList();
    unique_ptr<int[]> elements;

private:
    int size;
};

myList::myList(int s)
{
    cout << " --> constructor called <-- \n";
    size = s;
    elements = unique_ptr<int[]>(new int[size]); // with new
    // elements = make_unique<int[]>(size);      // with make_unique
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
}

int main()
{
    cout << "Hello" << endl;
    myList u(5);
    // myList v = u; // error due to unique_ptr (no copy constructor)
    
    cout << "Bye" << endl;
}