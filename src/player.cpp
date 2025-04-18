#include <string>
using namespace std;

//Merge Sort is Overrated, Quicksort better -Juan

class player{
private:
    //private variables holding each players name, age, points, assists, and rebounds
    string name;
    float points, assists, rebounds;

public:
    //default constructor used to create a plater
    player(){
        name = "";
        points = 0;
        assists = 0;
        rebounds = 0;
    }
    
    //parametrized constructor creating a player with a name and all 3 stats
    player(string nameIn, float pointsIn, float assistsIn, float reboundsIn){
        name = nameIn;
        points = pointsIn;
        assists = assistsIn;
        rebounds = reboundsIn;
    }

    //setter methods to modify the statistics of a player.
    void setPoints(float pointsIn){
        points = pointsIn;
    }

    void setAssists(float assistsIn){
        assists = assistsIn;
    }

    void setRebounds(float reboundsIn){
        rebounds = reboundsIn;
    }

    //accessor methods to return the values of a players statistics
    string getName(){
        return name;
    }

    float getPoints(){
        return points;
    }

    float getAssists(){
        return assists;
    }

    float getRebounds(){
        return rebounds;
    }
};