#include <iostream>
#include "structures/stack.h"
#include "structures/queue.h"
#include "sort/BubbleSort.h"
#include "structures/LinkedList.h"
#include <random>

#define LOG(x) std::cout<<x<<std::endl

/* 
    The classes are Header only because their are templates, 
    for now it's more easy go in this way
*/

int main()
{
    using namespace structures;
    using namespace sort;
    
    /* The LinkedList is not working properly yet (memory leak :P) */

    // 'Pause' the application
    std::cin.get();
}
