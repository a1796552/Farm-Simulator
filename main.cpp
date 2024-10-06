#include <iostream>
using namespace std;

// main menu function
void displayMenu() {
    cout << "Welcome to Farm Management Simulator!\n";
    cout << "1. Farm\n";
    cout << "2. Market\n";
    cout << "3. Save game\n";
    cout << "4. Load game\n";
    cout << "5. Exit\n";
}

// farm menu function
void displayFarmMenu() {
    cout << "\n--- Farm Management ---\n";
    cout << "1. Plant Crops\n";
    cout << "2. Harvest Crops\n";
    cout << "3. Feed Animals\n";
    cout << "4. Collect Animal Produce\n";
    cout << "5. Return to Main Menu\n";
}

// market menu function
void displayMarketMenu() {
    cout << "\n--- Market ---\n";
    cout << "1. Buy Crops\n";
    cout << "2. Sell Produce\n";
    cout << "3. Check Market Prices\n";
    cout << "4. Return to Main Menu\n";
}

int main() {
    int choice;

    Farm myFarm;  // will have to change based on the name decided for the class

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int farmChoice;
                do {
                    displayFarmMenu();
                    cout << "Enter your choice: ";
                    cin >> farmChoice;

                    switch (farmChoice) {
                        case 1:
                            myFarm.plantCrops();
                            break;
                        case 2:
                            myFarm.harvestCrops();
                            break;
                        case 3:
                            myFarm.feedAnimals();
                            break;
                        case 4:
                            myFarm.collectProduce();
                            break;
                        case 5:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (farmChoice != 5);
                break;

            case 2:
                int marketChoice;
                do {
                    displayMarketMenu();
                    cout << "Enter your choice: ";
                    cin >> marketChoice;

                    switch (marketChoice) {
                        case 1:
                            myFarm.buyCrops();
                            break;
                        case 2:
                            myFarm.sellProduce();
                            break;
                        case 3:
                            myFarm.checkMarketPrices();
                            break;
                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (marketChoice != 4);
                break;

            case 3:
                myFarm.saveGame();
                break;

            case 4:
                myFarm.loadGame();
                break;

            case 5:
                cout << "Exiting the game. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}