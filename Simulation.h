#include <iostream>
#include <string>


class Simulation{
    public:
      Simulation();
      Simulation(string mapFile);
      ~Simulation();

      std::string mapFile;
      int** mapGrid;

      



};
