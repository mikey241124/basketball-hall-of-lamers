#include <string>
#include <vector>
#include "player.cpp"
using namespace std;
//"undefined ref to main", dont want main, compile error
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
    //call the quicksort with whichStat = 0; annd return vector
    vector<player> sorted = players;
    quickSort(sorted, 0, sorted.size()-1, 0); //vector size -> -1 always 
    return vector<player>(sorted.begin(), sorted.begin()+min(25, (int)sorted.size()));
    //formula above should give 25 players, ref for later:
    //https://www.geeksforgeeks.org/stdmin-in-cpp/   min requires x &y of same type
    //https://www.geeksforgeeks.org/type-casting-in-programming/ typecasting (the (int) above)
    //together make super clean line that avoids an if+for loop
  }

  //Function that sorts all players and returns the 25 with the least assists
  vector<player> lowestAssists(){
    //call the quicksort with whichStat = 1;
    vector<player> sorted = players;
    quickSort(sorted, 0, sorted.size()-1, 1);
    return vector<player>(sorted.begin(), sorted.begin()+min(25, (int)sorted.size()));
  }

  //Function that sorts all players and returns the 25 with the least rebounds
  vector<player> lowestRebounds(){
    //call the quicksort with whichStat = 2;
    vector<player> sorted = players;
    quickSort(sorted, 0, sorted.size()-1, 2);
    return vector<player>(sorted.begin(), sorted.begin()+min(25, (int)sorted.size()));
  }

  //Function that sorts all players and returns the 25 with the lowest overall statistics
  vector<player> lowestOverall(){
    //call the quicksort with whichStat = 3;
    vector<player> sorted = players;
    quickSort(sorted, 0, sorted.size()-1, 3);
    return vector<player>(sorted.begin(), sorted.begin()+min(25, (int)sorted.size()));
  }


  //Initiate Quicksort Main: Uses partitioning and low/high system
  //Pass actual vector of player to modify it, low and high are vector start/end
  //Update: need something to actually choose which player data we need (done)
  vector<player> quickSort(vector<player>& playerVec, int low, int high, int whichStat){
    if(low<high){
      //Last player in vector is always the pivot, move everything w/ Partition func
      int calledPartition = partition(playerVec, low, high, whichStat);
      //First one is left half partition, second one is right half, double checked spacing
      quickSort(playerVec, low, calledPartition-1, whichStat);
      quickSort(playerVec, calledPartition+1, high, whichStat);
      return playerVec;
    }
  }
  //Helper function Partition: everything less than pivot before, everything greater to the right!
  int partition(vector<player>& playerVec, int low, int high, int whichStat){
    float pivotPoint = getWhichStatSelect(playerVec[high], whichStat);
    //why does it say range error (fixed) Subtract by 1 for starting value:
    int truelow = low -1;

    for(int i=low; i<high; i++){
      //is this supposed to be playerVec[i]???? (had as vec[i]).
      if(getWhichStatSelect(playerVec[i], whichStat)<pivotPoint){
        truelow++;
        //Only when 
        //is this supposed to be playerVec[i]???? (had as vec[i]).
        swap(playerVec[truelow], playerVec[i]);
      }
    }
    swap(playerVec[truelow+1],playerVec[high]);
    return truelow+1;
  }

  //somwhow get number input into string , "points" "assist etc
  float getWhichStatSelect(player inputPlayer, int dataType){
    if(dataType == 0){
      return inputPlayer.getPoints();
    } else if(dataType == 1){
      return inputPlayer.getAssists();
    } else if(dataType == 2){
      return inputPlayer.getRebounds();
    } else{
      return inputPlayer.getOverall();
    }
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
