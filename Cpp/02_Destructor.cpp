#include <iostream>
using namespace std;

class myList
{
public:
    myList(int);
    ~myList(); // destructor
    int *elements;

private:
    int size;
};

myList::myList(int s)
{
    cout << " --> constructor called <-- \n";
    size = s;
    elements = new int[s];
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
    delete[] elements;
}

int main()
{
    cout << "Hello" << endl;
    myList u(5);
    cout << "Bye" << endl;
}

// g++ -g 01_DynamicMemory.cpp -o 01_DynamicMemory
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01_DynamicMemory