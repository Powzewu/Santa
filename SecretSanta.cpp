#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
//There is no exception handling. Don't be silly
void shuffleNames(std::vector<std::string>& names) 
{

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(names.begin(), names.end(), generator);
}

int main() 
{
    int count;
    std::cout << "How many people will be participating: ";
    std::cin >> count;

    std::vector<std::string> participants(count);

    for (int i = 0; i < count; i++) {
        std::cout << "Enter the name of participant " << i + 1 << ": ";
        std::cin >> participants[i];
    }

    shuffleNames(participants);

    for (const auto& name : participants) {
        std::cout << name << " --> ";
    }
    std::cout << participants[0] << std::endl;

    return 0;
}
