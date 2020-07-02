#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "\nsecure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numebers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou Win!";
        return true;
    }
    else
    {
        std::cout << "\nYou Lose!";
        return false;
    }
}

    int main()
    {
        srand(time(NULL)); // create new random sequence based on time of day

        int LevelDifficulty = 1;
        int const MaxDifficulty = 5;

        while(LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
        {
            bool bLevelComplete = PlayGame(LevelDifficulty);
            std::cin.clear(); // Clears any errors
            std::cin.ignore(); // Discards the buffer

            if (bLevelComplete)
            {
                ++LevelDifficulty;
            }
        }
        std::cout << "\n*** Great work agent! You got all the files now RUN! ***\n";
    return 0;
}