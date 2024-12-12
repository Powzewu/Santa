#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


void shufflePointers(void* arr[], size_t size) {
    // Create a random number generator
    std::random_device rd;
    std::mt19937 generator(rd());             

    std::shuffle(arr, arr + size, generator);
}

int main()
{
    int count;
    std::cout<<"How many people will be participating: ";

    std::cin>>count;

    std::string *ptr = new std::string[count];

    for (int i = 0; i < count; i++)
    {
        std::string name;
        std::cout<<"Enter the name of the "<<i+1<<" participant: ";
        std::cin>>name;

        ptr[i] = name;
    }

    shufflePointers(reinterpret_cast<void**>(ptr), count);

    for (int i = 0; i < count; i++)
    {
        if((i<count-1))
        std::cout<<ptr[i]<<"-->";
        else
        std::cout<<ptr[i];
    }
    
    return 0;
}