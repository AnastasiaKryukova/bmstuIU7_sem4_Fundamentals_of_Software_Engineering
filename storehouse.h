#ifndef STOREHOUSE_H
#define STOREHOUSE_H

#include <vector>
#include "cells.h"
#include "const.h"


class Storehouse
{
public:

        std::vector <Cells> cell;

//        int num{0};
//        std::string input_detail = "shurup_" + std::to_string(num); //Код прибывшего товара
        std::string input_detail;
        int input_amount; //Количество прибывшего товара

        void input(); // Ввод новых данных

        void creation(); // Заполнение авто

        int size_vector(); // Размер

        void print(); // Печать на экран

        int addiction(std::string, int); // Добавление прибывшего товара

        int remove(std::string, int); // Удаление товара со склада

        void filtr_code(std::string, std::vector<Cells>&); // Фильтр по коду детали

        void sum_amount_code(std::string); // Суммарное количество по коду детали

        void sum_amount_each_code(); //Суммарное количество по каждому коду детали

        void sort_cell_adress(std::vector<Cells>&); // Сортировка по коду детали

};




#endif // STOREHOUSE_H
