#include <string>
#include <vector>
#include "player.cpp"
using namespace std;

class playerList{
private:
    vector<player> players;
    int numberOfPlayers = 0;

    //Initiate Quicksort Main: Uses partitioning and low/high system
    //Pass actual vector of player to modify it, low and high are vector start/end
    //Update: need something to actually choose which player data we need (done)
    void quickSort(vector<player>& playerVec, int low, int high, string whichStat){
      if(low<high){
        //Last player in vector is always the pivot, move everything w/ Partition func
        int calledPartition = partition(playerVec, low, high, whichStat);
        //First one is left half partition, second one is right half, double checked spacing
        quickSort(playerVec, low, calledPartition-1, whichStat);
        quickSort(playerVec, calledPartition+1, high, whichStat);
      }
    }
    //Helper function Partition: everything less than pivot before, everything greater to the right!
    int partition(vector<player>& playerVec, int low, int high, string whichStat){
      float pivotPoint = getWhichStatSelect(playerVec[high], whichStat);
      //why does it say range error (fixed) Subtract by 1 for starting value:
      int truelow = low -1;


      for(int i=low; i<high; i++){
        if(getWhichStatSelect(vec[i], whichStat)<pivotPoint){
          truelow++;
          //Only when 
          swap(vec[truelow], vec[i]);
        }
      }
    swap(playervec[truelow+1],playervec[high]);
    return truelow+1;
    }
    //somwhow get number input into string , "points" "assist etc
    float getWhichStatSelect
    //....cant decide how
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