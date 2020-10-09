#include <iostream>
#include <string>

class GameOfLife{

    public:
        GameOfLife();
        GameOfLife(int width, int height, double popDensity);
        ~GameOfLife();



        int** mapBoard;
        int** nextMapBoard;
        int** temp;

        int mapHeight;
        int mapWidth;
        double mapPopDensity;
        bool worldEnd;
        int aliveCounter;

        void populateBoard();
        void initializeBoard();
        //void initializeNextMapBoard();
        void printMapBoard();
        void clearMapBoard();
        void simulateLife();
        void printNextMapBoard();

        bool hasWorldEnded();


};
