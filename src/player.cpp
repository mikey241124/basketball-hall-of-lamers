#include <string>
using namespace std;

class player{
private:
    //private variables holding each players name, age, points, assists, and rebounds
    string name;
    int points, assists, rebounds;

public:
    //default constructor used to create a plater
    player(){
        name = "";
        points = 0;
        assists = 0;
        rebounds = 0;
    }
    
    //parametrized constructor creating a player with a name and all 3 stats
    player(string nameIn, int pointsIn, int assistsIn, int reboundsIn){
        name = nameIn;
        points = pointsIn;
        assists = assistsIn;
        rebounds = reboundsIn;
    }

    //setter methods to modify the statistics of a player.
    void setPoints(int pointsIn){
        points = pointsIn;
    }

    void setAssists(int assistsIn){
        assists = assistsIn;
    }

    void setRebounds(int reboundsIn){
        rebounds = reboundsIn;
    }

    //accessor methods to return the values of a players statistics
    string getName(){
        return name;
    }

    int getPoints(){
        return points;
    }

    int getAssists(){
        return assists;
    }

    int getRebounds(){
        return rebounds;
    }
};