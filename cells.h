#ifndef CELLS_H
#define CELLS_H

#include <string>

struct Cells
{
    std::string detail_code; // код детали
    std::string cell_adress; // адрес ячейки
    int amount; // количество
    int size; // размер ячейки, вместимость ячейки
};


#endif // CELLS_H
