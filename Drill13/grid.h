#include "Graph.h"

struct Grid : Graph_lib::Lines {
    private:
        int numofcellsX;
        int numofcellsY;
        int cellsizeX;
        int cellsizeY;
    public:
        int GetTheNumberOfCellsX();
        int GetTheNumberOfCellsY();
        int GetTheCellSizeX();
        int GetTheCellSizeY();
        Grid(int nocX, int nocY, int csX, int csY, Graph_lib::Color col);
};