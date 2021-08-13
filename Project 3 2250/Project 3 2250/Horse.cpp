//
//  Horse.cpp
//  Project 3 2250
//


#include "Horse.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void Horse :: runASecond(){distanceTraveled += rand()%(maxRunningDistPerSecond + 1);} //
void Horse :: sendToGate(){distanceTraveled = 0;}
void Horse :: addToRacesWon(){racesWon = racesWon +1;}
void Horse :: displayStats(int numRaces){
    cout << name << " has won " << racesWon << "/" << numRaces << " races.\n";
}

//Creates "track" and scales it to be viewable on most screens.
void Horse :: displayHorse(int goalLength){
    double screenWidth = 80, trackScale = (screenWidth - 2)/ goalLength;
    cout << "\n|";
    if (distanceTraveled >= goalLength){
        int count = 0;
        for (int i = 0; i < (screenWidth - 2); i++){
            cout << "-";
            count++;
            }
        cout << "|> ";
        cout << name << ", ridden by: " << rider;
    }
    else {
        int count = 0;
        for (int i = 0; i < floor(trackScale * distanceTraveled) - 1; i++){
            cout << "-";
            count++;
        }
        cout << ">";
        while (count < (screenWidth - 3)){
            cout << "-";
            count++;
        }
        cout << "| ";
        cout << name << ", ridden by: " << rider;
    }
}
//Constructors
Horse :: Horse(string horsey, string jockey){name = horsey; rider = jockey; distanceTraveled = 0; maxRunningDistPerSecond = (rand()%100) + 1;}
Horse :: Horse(){} //overloaded to make it easier to put into array.

int Horse :: distance(){
    return distanceTraveled;
}

