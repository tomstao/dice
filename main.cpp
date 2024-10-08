#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    char replay = 'Y';
    srand(time(NULL));
    rand();
    int totalRolls = 0;
    int num = 0;
    int results[] = {0,0,0,0,0,0};
    const int SIZE = sizeof(results) / sizeof(results[0]);

    do
    {std::cout << "Enter the number of rolls you would like to play: ";
        while (!(std::cin >> totalRolls))
        {
            std::cout << "Please input an integer!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        for (int i = 0; i < totalRolls; i++)
        {
            num =( rand() % SIZE) + 1;
            results[num - 1] ++;
        }
        for (int k = 0; k < SIZE; k++)
        {   std::cout << "The dice of "<< k + 1 << ": ";
            for (int l = 0; l < results[k]; l++)
            {
                std::cout << "X";
            }
            std::cout <<' '<<results[k]<< std::endl;
        }

        std::cout <<"Do you want to press y to play one more time?"<<std::endl;
        std::cin >> replay;
        for (int j = 0; j < std::size(results); j++)
        {
            results[j] = 0;
        }
        replay = toupper(replay);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

        while (replay == 'Y');

    return 0;
}
