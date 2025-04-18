#include <string>
#include <vector>
#include "player.cpp"
using namespace std;
//PLEASE PLEASE PLEASE WORK

class playerList{
private:
    vector<player> players;
    int numberOfPlayers = 0;

public:
  //default constructor
  playerList(){}  

  //adds a new player to the list of players
  void addPlayer(string name, float points, float assists, float rebounds){
    player newPlayer = player(name, points, assists, rebounds);
    players.push_back(newPlayer);
    numberOfPlayers++;
  }

  //Function that sorts all players and returns the 25 with the least points
  vector<player> lowestPoints(){
    vector<player> toReturn;
    return toReturn;
  }

  //Function that sorts all players and returns the 25 with the least assists
  vector<player> lowestAssists(){
    vector<player> toReturn;
    return toReturn;
  }

  //Function that sorts all players and returns the 25 with the least rebounds
  vector<player> lowestRebounds(){
    vector<player> toReturn;
    return toReturn;
  }

  //Function that sorts all players and returns the 25 with the lowest overall statistics
  vector<player> lowestOverall(){
    vector<player> toReturn;
    return toReturn;
  }

  //Function to return a string of all player names
  string allPlayerNames(){
    string toReturn = "";
    for(int i = 0; i < numberOfPlayers; i++){
        if(i == 0){
            toReturn = "\n" + players[i].getName();
        } else{
            toReturn += "\n" + players[i].getName();
        }
    }
    return toReturn;
  }

  string allPlayerStats(){
    string toReturn = "";
    for(int i = 0; i < numberOfPlayers; i++){
        if(i == 0){
            toReturn = "\n" + players[i].getName();
            toReturn += " points are: " + to_string(players[i].getPoints());
            toReturn += " assists are: " + to_string(players[i].getAssists());
            toReturn += " rebounds are: " + to_string(players[i].getRebounds());
        } else{
            toReturn += "\n" + players[i].getName();
            toReturn += " points are: " + to_string(players[i].getPoints());
            toReturn += " assists are: " + to_string(players[i].getAssists());
            toReturn += " rebounds are: " + to_string(players[i].getRebounds());
        }
    }
    return toReturn;
  }
};