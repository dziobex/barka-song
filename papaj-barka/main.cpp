#include <windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>

bool question(std::string question, std::string option) {
    std::string answ = "";

    std::cout << question << '\n';

    std::cin >> answ;
    std::transform(answ.begin(), answ.end(), answ.begin(), ::tolower);

    return answ == option;
}
int main() {
    SetConsoleTitle(TEXT("poczekalnia"));

    if (question("Chcesz zaczac symulacje? Wszystkie odpowiedzi oprocz n/N beda brane za jednoznaczna zgode.", "n"))
        return std::cout << "Zegnaj zatem.", 1;

    SetConsoleTitle(TEXT("papaj polak 3 barke w c++ kreci"));

    std::ifstream papaj("papaj.txt");
    std::string line = "";

    while (papaj >> line)
    {
        std::cout << line << '\n';
    }

    papaj.close();

    float sound = 0, duration = 0;


    while (1)
    {
        std::ifstream read("nuty.txt");
        bool right = true;

        while (read >> sound >> duration)
        {
            Beep(sound, duration);
        }
        read.close();

        if (!question("Czy chcesz kontynuowac symulacje? Wszystkie odpowiedzi oprocz y/Y beda brane za \"NIE\".", "y"))
            return std::cout << "Szkoda, bylo milo.", 1;
    }

    return 0;
}
