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

GameOfLife::GameOfLife(int height, int width, double popDensity){
    mapWidth = width;
    mapHeight = height;
    mapPopDensity = popDensity;
    aliveCounter = 0;
    mapNeighbors = 0;
    worldEnd = false;



}
GameOfLife::~GameOfLife(){

}

void GameOfLife::initializeMapBoard(){
    mapBoard = new int*[mapHeight];
    for(int i = 0; i < mapHeight; i++){
      mapBoard[i] = new int[mapWidth];
    }
}
void GameOfLife::initializeNextMapBoard(){
    nextMapBoard = new int*[mapHeight];
    for(int i = 0; i < mapHeight; i++)
        nextMapBoard[i] = new int[mapWidth];
}

void GameOfLife::populateBoard(){
  srand(time(NULL));
  for (int i =0;i < mapHeight;i++) {
    for (int j =0;j < mapWidth;j++) {
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
    cout << "Gen 0 : " << endl;
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

void GameOfLife:: printNextMapBoard(){
  //print GOL mapBoard
  for(int i = 0; i < mapHeight; i++){
    for(int j = 0; j < mapWidth; j++){
      cout << " "<< nextMapBoard[i][j] << " ";
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
void GameOfLife::clearNextMapBoard(){
    for(int i = 0; i < mapWidth; i++){
        delete [] nextMapBoard[i];
    }
    delete [] nextMapBoard;
}

void GameOfLife::simulateLife(){
    // Loop through every spot in our 2D array and check spots neighbors
    for (int x = 0; x < mapHeight; x++) {
      for (int y = 0; y < mapWidth; y++) {
        //Add up all the states in a 3x3 surrounding grid
        for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
            if ((i+x) == -1 || (j+y) == -1 || (i+x) == mapWidth || (j+y) == mapHeight){
                break;
            } else{
                cout << i << ":" << j << endl;
                mapNeighbors += mapBoard[(x+i)][(y+j)];
            }
            }
          }

        mapNeighbors -= mapBoard[x][y];

        if((mapBoard[x][y] == 1) && (mapNeighbors <  2)){
          nextMapBoard[x][y] = 0;
        }else if ((mapBoard[x][y] == 1) && (mapNeighbors >  3)){
          nextMapBoard[x][y] = 0;
        }else if ((mapBoard[x][y] == 0) && (mapNeighbors == 3)){
          nextMapBoard[x][y] = 1;
        }else{
          nextMapBoard[x][y] = mapBoard[x][y];
        }
      }
    }
    mapBoard = nextMapBoard;

}

bool GameOfLife::hasWorldEnded(){
    for(int i = 1; i < mapHeight; i++){
      for(int j = 1; j < mapWidth; j++){
        if(mapBoard[i][j] == 1){
          aliveCounter++;
        }
      }
    }
    if(aliveCounter < 1){
      return true;
    }
}
