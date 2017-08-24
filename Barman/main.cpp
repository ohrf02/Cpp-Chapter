#include <iostream>
#include "RedWine.h"
#include "Beer.h"
#include "WhiteWine.h"

void printList(int n, Drink* arr[]);
void barLoop(int n, Drink* arr[]);

int main() {
    Drink* stock[12];

    stock[0] = new Beer("Budweiser");
    stock[1] = new Beer("Heineken");
    stock[2] = new Beer("Corona Extra");
    stock[3] = new Beer("Sam Adams");
    stock[4] = new WhiteWine(1968, "Emerald Rizling");
    stock[5] = new WhiteWine(1989, "Golan Smadar");
    stock[6] = new WhiteWine(1999, "Golan Smadar");
    stock[7] = new WhiteWine(1997, "Yarden Sarona");
    stock[8] = new RedWine(1994, "Yarden Mount Hermon");
    stock[9] = new RedWine(1997, "Chianti");
    stock[10] = new RedWine(1997, "Yarden Cabernet Sauvignon");
    stock[11] = new RedWine(1997, "Chadeau Margot");

    barLoop(12, stock);
    return 0;
}

//Prints the Drinks list
void printList(int n, Drink* arr[]){
    std::cout << "What can I get you, Sir? (0 - list options)" << std::endl;

    std::cout << "0)    list options" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << ")    " << arr[i]->getName() << std::endl;
    }

    std::cout << "99)    How did you prepare my last drink?" << std::endl;
    std::cout << "100)    Leave the bar" << std::endl;
}

//The Bar's loop.
void barLoop(int n, Drink* arr[]){
    bool flage = true;
    int choice;
    int last_choice = -1;

    while (flage) {

        std::cout << "What can I get you, Sir?(0 - list options)" << std::endl;
        std::cin >> choice;

        //If the input is a drink => updates the last choice of the user and prints the drink.
        if (choice > 0 && choice <= n) {
            std::cout << "One " << arr[choice - 1]->getName() << " coming up, Sir." << std::endl;
            last_choice = choice;
            continue;
        }

        //If the input is not a drink => Checks if the input is 0/99/100,
        // else => prints an error message.
        switch(choice){
            //If the number is 0 => prints the list options.
            case 0: {
                printList(n, arr);
                continue;
            }

            //If the number is 99 => prints the last drink.
            case 99: {
                if(last_choice != -1){
                    std::cout << "You ordered " << arr[last_choice - 1]->getName() << std::endl;
                    arr[last_choice - 1]->prepare();
                } else{
                    std::cout << "You ordered nothing..." << std::endl;
                }
                continue;
            }

            //If the number is 100 => exit!
            case 100:
            {
                std::cout << "The bar is closed. Good night" << std::endl;
                flage = false;
                continue;
            }

            //Else => prints an error message.
            default: {
                std::cout << "Please enter numbers from 0 to 100" << std::endl;
                continue;
            }
        }


    }

}