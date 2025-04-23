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

    playerList generateRandom(playerList inputtedList, int numberToGenerate){
        srand(time(0));

        for(int i = 0; i < numberToGenerate; i++){
            string name;
            float points, assists, rebounds;

            int randomNumber = (rand() % allNames.size()) + 1;
            name = allNames[randomNumber];
            allNames.erase(allNames.begin() + randomNumber);

            float randomNum = (rand() % 45 + 1);
            points = randomNum;

            randomNum = (rand() % 18 + 1);
            assists = randomNum;

            randomNum = (rand() % 25 + 1);
            rebounds = randomNum;

            inputtedList.addPlayer(name, points, assists, rebounds);
        }
        return inputtedList;
    }
};