#include "grid.h"
#include "Graph.h"

int Grid::GetTheNumberOfCellsX() {
    return numofcellsX;
}
int Grid::GetTheNumberOfCellsY() {
    return numofcellsY;
}
int Grid::GetTheCellSizeX() {
    return cellsizeX;
}
int Grid::GetTheCellSizeY() {
    return cellsizeY;
}
Grid::Grid(int nocX, int nocY, int csX, int csY, Graph_lib::Color col) {
    this->numofcellsX = nocX;
    this->numofcellsY = nocY;
    this->cellsizeX = csX;
    this->cellsizeY = csY;
    this->set_color(col);
    this->set_style(Graph_lib::Line_style::solid);
    for (int i = 0; i < numofcellsY + 1; i++)
        this->add({0, i * cellsizeY}, { cellsizeY * numofcellsY, i * cellsizeY});
    for (int i = 0; i < numofcellsX + 1; i++)
        this->add({i * cellsizeX, 0}, {i * cellsizeX, cellsizeX * numofcellsX});
}