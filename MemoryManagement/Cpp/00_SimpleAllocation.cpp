#include <iostream>
int main()
{
    int var = 42;

    int* ptr = new int; // Allocates memory for an integer
    *ptr = 42;          // Assigns a value to the allocated memory

    return 0;
}

// g++ -g 00_SimpleAllocation.cpp -o 00_SimpleAllocation
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./00_SimpleAllocation
// g++ -S -o 00_SimpleAllocation.s 00_SimpleAllocation.cpp //See the compiled machine language in ASCII format