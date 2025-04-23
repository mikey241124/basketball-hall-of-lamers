#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class playerGenerator{
private:
    vector<string> allNames;

public:
    playerGenerator(){}

    void loadNames(){
        string line;
        ifstream myFile("names.txt");

        if (myFile.is_open()) {
            while (getline(myFile, line)) {
                allNames.push_back(line);
            }
            myFile.close();
        }
    }
    //Int to float changes
    //https://stackoverflow.com/questions/42138421/why-the-static-cast-on-time0-on-this-code
    playerList generateRandom(playerList inputtedList, int numberToGenerate){
        srand(static_cast<unsigned>(time(0)));

        for(int i = 0; i < numberToGenerate; i++){
            string name;
            float points, assists, rebounds;

            int randomNumber = rand() % allNames.size();
            name = allNames[randomNumber];
            allNames.erase(allNames.begin() + randomNumber);

            //float randomNum = (rand() % 45 + 1);
            //randomNum = (rand() % 18 + 1);
            //randomNum = (rand() % 25 + 1);
            //https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

            points = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (45.0f - 1.0f)));
            assists = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (18.0f - 1.0f)));
            rebounds = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (25.0f - 1.0f)));

            inputtedList.addPlayer(name, points, assists, rebounds);
        }
        return inputtedList;
    }
};