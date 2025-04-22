#include <iostream>
#include <vector>
#include "playerList.cpp"
#include "playerGenerator.cpp"

using namespace std;

int main() {
    //print out introductory message
    cout << "Welcome to the Basketball hall of lamers, the sports stat tracking app to show you the worst of the worst!" << endl;

    playerList players;
    playerGenerator generator;
    generator.loadNames();
    bool running = true;

    //loop to run code until user decides to exit
    while(running){
        //print options
        cout << endl << "Please select one of the following options. Simply type the number for the function you would like to use and press the enter key." << endl;
        cout << "Option 0: Close program." << endl;
        cout << "Option 1: Insert player to list." << endl;
        cout << "Option 2: Print all player names." << endl;
        cout << "Option 3: Prins all player names and statistics." << endl;
        cout << "Option 4: Print the lowest 25 players sorted by points." << endl;
        cout << "Option 5: Print the lowest 25 players sorted by assists." << endl;
        cout << "Option 6: Print the lowest 25 players sorted by rebounds." << endl;
        cout << "Option 7: Print the lowest 25 players sorted overall." << endl;
        cout << "Option 8: Insert a number of randomly generated characters to list." << endl;

        //get input
        int input = 0;
        cin >> input;

        //if input == 0, close program
        if(input == 0){
            running = false;
            cout << "Exiting program. Thank you for using the Basketball hall of lamers!!!" << endl;
        }
        //if input == 1, add a new player to the roster
        else if(input == 1){
            string nameIn, pointsIn, assistsIn, reboundsIn;
            float points, assists, rebounds;
            cout << "Please enter the players name." << endl;
            cin >> nameIn;
            //this takes in the input as a string and attempts to convert it to an integer. it will continue asking for input until a valid number 0-9 is given.
            bool validInput = false;
            while(!validInput){
                cout << "Please enter the players number of Points Per Game (PPG)" << endl;
                cin >> pointsIn;
                try{
                    points = stof(pointsIn);
                    validInput = true;
                } catch(invalid_argument){
                    cout << "Sorry, that input seems to be incorrect, please enter a number between 0-9." << endl;
                }
            }
            //this takes in the input as a string and attempts to convert it to an integer. it will continue asking for input until a valid number 0-9 is given.
            validInput = false;
            while(!validInput){
                cout << "Please enter the players number of assists" << endl;
                cin >> assistsIn;
                try{
                    points = stof(pointsIn);
                    validInput = true;
                } catch(invalid_argument){
                    cout << "Sorry, that input seems to be incorrect, please enter a number between 0-9." << endl;
                }
            }
            //this takes in the input as a string and attempts to convert it to an integer. it will continue asking for input until a valid number 0-9 is given.            
            validInput = false;
            while(!validInput){
                cout << "Please enter the players number of Rebounds Per Game (RBG)" << endl;
                cin >> reboundsIn;
                try{
                    points = stof(pointsIn);
                    validInput = true;
                } catch(invalid_argument){
                    cout << "Sorry, that input seems to be incorrect, please enter a number between 0-9." << endl;
                }
            }
            //inserts a new player to the list of players.
            players.addPlayer(nameIn, points, assists, rebounds);
            cout << "Player added successfully." << endl;
        }
        else if(input == 2){
            //prints out all the names of the players in the order that they are entered into the list.
            string toPrint = players.allPlayerNames();
            cout << "All of the entered players are as follows:";
            cout << toPrint << endl;
        }
        else if(input == 3){
            //prints out all the names of the players in the order that they are entered into the list.
            string toPrint = players.allPlayerStats();
            cout << "All of the entered players are as follows:";
            cout << toPrint << endl;
        }
        else if(input == 4){
            //sort worst 25 players by points, need to make seperate implementation comparing merge sort and quick sort.
            vector<player> worstPoints = players.lowestPoints();
            if(worstPoints.size() <= 0){
                cout << "PlayerList is empty, please add players to the roster." << endl;
            } else{ 
                for(int i = 0; i < worstPoints.size(); i++){
                cout << worstPoints[i].getName() + "'s points is: " << worstPoints[i].getPoints() << endl;
                }
            }
        }
        else if(input == 5){
            //sort worst 25 players by assists, need to make seperate implementation comparing merge sort and quick sort.
            vector<player> worstPoints = players.lowestAssists();
            if(worstPoints.size() <= 0){
                cout << "PlayerList is empty, please add players to the roster." << endl;
            } else{ 
                for(int i = 0; i < worstPoints.size(); i++){
                cout << worstPoints[i].getName() + "'s assists is: " << worstPoints[i].getAssists() << endl;
                }
            }
        }
        else if(input == 6){
            //sort worst 25 players by rebounds, need to make seperate implementation comparing merge sort and quick sort.
            vector<player> worstPoints = players.lowestRebounds();
            if(worstPoints.size() <= 0){
                cout << "PlayerList is empty, please add players to the roster." << endl;
            } else{ 
                for(int i = 0; i < worstPoints.size(); i++){
                cout << worstPoints[i].getName() + "'s rebounds are: " << worstPoints[i].getRebounds() << endl;
                }
            }
        }
        else if(input == 7){
            //sort worst 25 players by overall stats, need to make seperate implementation comparing merge sort and quick sort.
            vector<player> worstPoints = players.lowestOverall();
            if(worstPoints.size() <= 0){
                cout << "PlayerList is empty, please add players to the roster." << endl;
            } else{ 
                for(int i = 0; i < worstPoints.size(); i++){
                cout << worstPoints[i].getName() + "'s overall stats are: " << worstPoints[i].getOverall() << endl;
                }
            }
        }
        else if(input == 8){
            string numberToGenerate;
            cout << "Please enter the number of players you would like to generate" << endl;
            bool validInput = false;
            while(!validInput){
                cin >> numberToGenerate;
                try{
                    int numberGenerating = stoi(numberToGenerate);
                    validInput = true;
                    players = generator.generateRandom(players, numberGenerating);
                } catch(invalid_argument){
                    cout << "Sorry, that input seems to be incorrect, please enter a number between 0-9." << endl;
                }
            }
        }
        else{
            //DO NOT FORGET TO REPLACE THE PLACEHOLDER
            cout << "sorry, your input seems to be invalid, please enter a number 0-placeholder." << endl;
        }
    }
}