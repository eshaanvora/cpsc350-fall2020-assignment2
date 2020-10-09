#include "GameOfLife.h"
#include <iostream>
#include <string>
using namespace std;



GameOfLife::GameOfLife(){
    mapWidth = 0;
    mapHeight = 0;
    mapPopDensity = 0;
    aliveCounter = 0;

}

GameOfLife::GameOfLife(int width, int height, double popDensity){
    mapWidth = width;
    mapHeight = height;
    mapPopDensity = popDensity;
    aliveCounter = 0;

}
GameOfLife::~GameOfLife(){

}

void GameOfLife::initializeBoard(){
    mapBoard = new int*[mapWidth];
    for(int i = 0; i < mapWidth; i++){
      mapBoard[i] = new int[mapHeight];
    }
}
// void GameOfLife::initializeNextMapBoard(){
//
// }

void GameOfLife::populateBoard(){
  srand(time(NULL));
  for (int i =0;i < mapWidth;++i) {
    for (int j =0;j < mapHeight;++j) {
        double randVal = rand() / double(RAND_MAX);
        if(randVal < mapPopDensity){
          mapBoard[i][j] = 1;
        }else{
          mapBoard[i][j] = 0;
        }
      }
    }
  }


void GameOfLife::printMapBoard(){
    cout << "Board is : " << endl;
    cout << mapHeight << endl;
    cout << mapWidth << endl;
    //print GOL mapBoard
    for(int i = 0; i < mapHeight; i++){
      for(int j = 0; j < mapWidth; j++){
        cout << " "<< mapBoard[i][j] << " ";
      }
      cout << endl;
    }
}


void GameOfLife::clearMapBoard(){
    for(int i = 0; i < mapWidth; i++){
        delete [] mapBoard[i];
    }
    delete [] mapBoard;
}

void GameOfLife::simulateLife(){
    nextMapBoard = new int*[mapWidth];
    for(int i = 0; i < mapWidth; i++)
        mapBoard[i] = new int[mapHeight];

    // Loop through every spot in our 2D array and check spots neighbors
    for (int x = 0; x < mapHeight; x++) {
      for (int y = 0; y < mapWidth; y++) {

        // Add up all the states in a 3x3 surrounding grid
        int neighbors = 0;
        for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
              // if x + i == negative then break
              if((x+i || y+j) < 0){
                cout<< "out of bounds";
                break;
              }else{
                neighbors += mapBoard[(x+i+mapHeight)%mapHeight][(y+j+mapWidth)%mapWidth];
              }

          }
        }
        // A little trick to subtract the current cell's state since
        // we added it in the above loop
        neighbors -= mapBoard[x][y];

        if((mapBoard[x][y] == 1) && (neighbors <  2)){
          nextMapBoard[x][y] = 0;
        }else if ((mapBoard[x][y] == 1) && (neighbors >  3)){
          nextMapBoard[x][y] = 0;
        }else if ((mapBoard[x][y] == 0) && (neighbors == 3)){
          nextMapBoard[x][y] = 1;
        }else{
          nextMapBoard[x][y] = mapBoard[x][y];
        }
      }
    }

    // Next is now our mapBoard

    mapBoard = nextMapBoard;


}

bool GameOfLife::hasWorldEnded(){
    for(int i = 1; i < mapHeight; i++){
      for(int j = 1; j < mapWidth; j++){
        if(nextMapBoard[i][j] == 1){
            aliveCounter++;
        }
      }
    }
    return worldEnd;
}
