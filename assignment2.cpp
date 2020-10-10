#include "GameOfLife.cpp"
#include "Simulation.cpp"
#include <fstream>    // file I/O
#include <iostream>
#include <array>
using namespace std;

int main(int argc, char  **argv) {
    int a = 0, b = 0, c = 0,x = 0,y = 0;
    char choiceA,choiceB,inFileChar;
    string userPath = "";
    string mapLines = "";
    string inFileLine = "";
    string pause = "";
    int wow = 0;
    double popDensity ;

    cout  << "Would you like to (a) use a map file or (b) generate a random assignment?" << endl;
    cin >> choiceA;

    if (choiceA == 'a') {
      // USER PROVIDES MAP FILE
      cout << "Enter map file name..."<< endl;
      cin >> userPath;

      cout << "Map File Selected....'" << userPath << "'" << endl;
      ifstream inFile(userPath);
      while(inFile >> inFileChar){

          mapLines += inFileChar;
          cout << mapLines << endl;

      }
      cout << "mapLines: ";
      cout << mapLines;

    } else if ( choiceA == 'b'){
      cout << "Enter Size Dimensions...." << endl;
      cout << "Width : " ;
      cin >> x;
      cout << "Height : " ;
      cin >> y;
      cout << "Width : " << x << ", Height : " << y << endl;
      cout << "Enter initial population density (Enter a decimal value 0.0 - 1.0)" << endl;
      cin >> popDensity;

      GameOfLife userGen(x,y,popDensity);
      userGen.initializeMapBoard();
      userGen.initializeNextMapBoard();
      userGen.populateBoard();
      userGen.printMapBoard();

      //while (userGen.hasWorldEnded()==false) {
      userGen.simulateLife();
      //userGen.clearMapBoard();
      //userGen.simulateLife();

        //userGen.printNextMapBoard();
        //getchar();
      //userGen.printNextMapBoard();
      //}




      //userGen.clearMapBoard();
      //userGen.clearNextMapBoard();
      cout<<"done"<<endl;
    }

  return 0;
}
