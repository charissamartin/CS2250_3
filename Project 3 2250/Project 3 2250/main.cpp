//
//  main.cpp
//  Project 3 2250
//


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Horse.h"

int furthestHorse(int, Horse*, int);


using namespace std;
int main() { 
    srand(time(NULL));
    char raceAgain;
    int numRaces = 0;
    
    //Asking for user input and does some error checking
    int goalLength, numHorsies;
    char x;
    cout << "How many horses are in the race: ";
    cin >> numHorsies;
    while (!numHorsies || numHorsies < 0){
        cout << "Please enter a valid number.";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> numHorsies;
    }
    Horse * name = new Horse[numHorsies];
    for (int i = 0; i < numHorsies; i++){
        string horseyName, jockeyName;
        cout << "Please give me the name of horse " << i + 1 << ": ";
        cin >> horseyName;
        cout << "Please give me the name of rider " << i + 1 << ": ";
        cin >> jockeyName;
        name[i] = Horse(horseyName, jockeyName);
    }
    cout << "Enter goal length: ";
    cin >> goalLength;
    while (!goalLength || goalLength < 100){
        cout << "Please enter a value of at least 100.";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> goalLength;
    }
    //Loops that asks for progress of "the next second" and for continuation of racing
    do{
        numRaces++;
        for (int i = 0; i < numHorsies; i++) name[i].sendToGate();
        cout << "The start!";
        for (int i = 0; i < numHorsies; i++) name[i].displayHorse(goalLength);
        
        cout << "\nReady for the next second? (y/n)";
        cin >> x;
        //Error Checking
        while (!x || (x != 'Y' && x != 'y' && x != 'N' && x != 'n')){
            cout << "Please enter y for yes or n for no.";
            cin.clear();
            cin.ignore(100,'\n');
            cin >> x;
        }
        while (x == 'Y' || x == 'y'){
            for (int i = 0; i < numHorsies; i++){
                name[i].runASecond();
                }
            for (int i = 0; i < numHorsies; i++){
                name[i].displayHorse(goalLength);
                }
            if (furthestHorse(numHorsies, name, goalLength) >= goalLength){
                // Determines that there is a winner
                break;
                }
            cout << "\nReady for the next second? (y/n)";
            cin >> x;
            //Error Checking
            while (!x || (x != 'Y' && x != 'y' && x != 'N' && x != 'n')){
                cout << "Please enter y for yes or n for no.";
                cin.clear();
                cin.ignore(100,'\n');
                cin >> x;
            }
            if (x == 'N' || x == 'n'){
                break;
                }
            }
        cout << endl;
        for (int i = 0; i < numHorsies; i++){
            name[i].displayStats(numRaces);
        }
        cout << "Do you want to race again? (y/n)";
        cin >> raceAgain;
        //Error Checking
        while (!raceAgain || (raceAgain != 'Y' && raceAgain != 'y' && raceAgain != 'N' && raceAgain != 'n')){
            cout << "Please enter y for yes or n for no.";
            cin.clear();
            cin.ignore(100,'\n');
            cin >> raceAgain;
        }
    } while (raceAgain == 'Y' || raceAgain == 'y');
    return 0;
}
// Keeps track of who is winning and how many races have been won.
int furthestHorse(int numHorsies, Horse*horseyptr, int goalLength){
    int maximumPos = 0, horseArray = 0;
    for (int i = 0; i < numHorsies; i++){
        if (horseyptr[i].distance() > maximumPos){
            maximumPos = horseyptr[i].distance();
            horseArray = i;
        }
        else if (horseyptr[i].distance() == maximumPos){
            if (rand()%2 == 0)
                horseArray = i;
        }
    }
    if (maximumPos >= goalLength){
    horseyptr[horseArray].addToRacesWon();
    }
    return maximumPos;
}
