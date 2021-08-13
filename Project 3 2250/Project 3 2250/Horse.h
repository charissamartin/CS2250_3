//  Horse.h
//  Project 3 2250


#ifndef Horse_h
#define Horse_h
#include <string>

using namespace std;

class Horse {
private:
    string name, rider;
    int maxRunningDistPerSecond, distanceTraveled, racesWon;
public:
    void runASecond();
    void sendToGate();
    void addToRacesWon();
    void displayStats(int numRaces);
    void displayHorse(int goalLength);
    Horse(string, string);
    Horse();
    int distance();
};

#endif /* Horse_h */

