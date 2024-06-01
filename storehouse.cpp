#include "storehouse.h"
#include <iostream>
#include <map>
using namespace std;



void Storehouse::creation()
{
    cell.push_back({"shurup_0", "cell_090",20,volume});
    cell.push_back({"shurup_3", "cell_091",10,volume});
    cell.push_back({"shurup_2", "cell_092",15,volume});

    // Заполняем вектор cell типа Cells
    for(unsigned int i = 0; i < number_cells - 3; i++)
    {
        string A = "shurup_" + to_string(0+i);
        string B = "cell_" + to_string(100+i);
        int C = 10 + i;

        cell.push_back({A, B, C, volume});
    }
}


int Storehouse::size_vector()
{
   cout << "size " << cell.size() << endl << endl;
   return 0;
}


void Storehouse::print()
{
    cout << endl;
    cout << "Код" << "\t\t" << "Адрес" << "\t\t" << "Количество" << "\t" << "Вместимость" << endl <<  "детали" << "\t\t" << "ячейки" << "\t\t" << "деталей" << "\t\t" << "ячейки";
    cout << endl << endl;

    for (size_t i = 0; i < number_cells; i++)
    {
        cout << cell[i].detail_code << "\t";
        cout << cell[i].cell_adress << "\t";
        cout << cell[i].amount << "\t\t";
        cout << cell[i].size << "\t";
        cout << endl << endl;
    }
}


void Storehouse::input()
{
    cout << "Код прибывшего товара = ";
    cout << input_detail;
    cout << endl;

    cout << "Количество прибывшего товара = ";
    cout << input_amount;
    cout << endl;

}


int Storehouse::addiction(string input_detail, int input_amount)
{
    if(input_detail == "")
    {
        cout << "Код товара не заполнен" << endl;
    }
else cout << "Данные заполнены" << endl;


    if(input_amount == 0)
    {
        cout << "Ошибка в количестве товара" << endl;
    }


    int sum = 0; //Количество свободного места для данной детали на складе
    for(unsigned int i = 0; i < number_cells; i++)
    {
         if(cell[i].amount == 0 || cell[i].detail_code == input_detail)
                    sum+= cell[i].size - cell[i].amount;
    }

    if(sum < input_amount)
        {
            cout << "Недостаточно места на складе" << endl;;
        }
    else cout << "Место на складе есть" << endl;;



    // Добавление к деталям имеющимся на складе
        for(unsigned int i = 0; i < number_cells; i++)
        {
            if(cell[i].detail_code == input_detail && cell[i].size - cell[i].amount < volume)
            {
                int differ = cell[i].size - cell[i].amount;
                if(input_amount > differ)
                {
                    input_amount -= differ;
                    cell[i].amount += differ;
                    continue;
                }
                if(input_amount <= differ)
                {
                    cell[i].amount += input_amount;
                    //input_amount = 0;

                    break;
                }
            }
        }

        // Добавление деталей в пустые ящики без наклейки типа товара
            if(input_amount > 0)
            {
                for(unsigned int i = 0; i < number_cells; i++)
                {
                    if((cell[i].size - cell[i].amount) == volume)
                    {
                        int differ = cell[i].size - cell[i].amount;
                        if(input_amount > differ)
                        {
                            input_amount -= differ;
                            cell[i].amount += differ;
                            cell[i].detail_code = input_detail;
                            continue;
                        }
                        if(input_amount <= differ)
                        {
                            cell[i].amount += input_amount;
                            //input_amount = 0;
                            cell[i].detail_code = input_detail;

                            break;
                        }
                     }
                 }

            }

return 0;
}


int Storehouse::remove(string input_detail, int input_amount)
{
    if(input_detail == "")
    {
        cout << "Код товара не заполнен" << endl;
    }
else cout << "Данные заполнены" << endl;


    if(input_amount == 0)
    {
        cout << "Ошибка в количестве товара" << endl;
    }

    int sum {0}; //количество штук для данной детали на складе
        for(unsigned int i = 0; i < number_cells; i++)
            if(cell[i].detail_code == input_detail)
                sum+= cell[i].amount;

    if(sum < input_amount && sum != 0)
        {
            cout << "Недостаточно товара на складе" << endl;
        }
    else cout << "Товара на скаладе достаточно" << endl;

    if(sum == 0) cout << "Данного типа товара на складе нет" << endl;


    // Удаление деталей имеющихся на складе
        for(unsigned int i = 0; i < number_cells; i++)
        {
            if(cell[i].detail_code == input_detail)
            {
                int differ = cell[i].amount;
                if(input_amount > differ)
                {
                    cell[i].amount = 0;
                    input_amount -= differ;
                    cell[i].detail_code.clear();
                    continue;
                }
                if(input_amount <= differ)
                {
                    if(input_amount == differ) cell[i].detail_code.clear();
                    cell[i].amount -= input_amount;
                   //input_amount=0;
                    break;
                }
            }
        }
        return 0;



}


void Storehouse::filtr_code(string input_detail, std::vector<Cells>& filtr)
{
    cout << endl;
    cout << "Код" << "\t\t" << "Адрес" << "\t\t" << "Количество" << "\t" << "Вместимость" << endl <<  "детали" << "\t\t" << "ячейки" << "\t\t" << "деталей" << "\t\t" << "ячейки";
    cout << endl << endl;
    for(unsigned int i = 0; i < cell.size(); i++)
        {
            if(cell[i].detail_code == input_detail)
            {
                filtr.push_back(cell[i]);
            }
        }

    for(unsigned int i = 0; i < filtr.size(); i++)
    {
        cout << filtr[i].detail_code << "\t";
        cout << filtr[i].cell_adress << "\t";
        cout << filtr[i].amount << "\t\t";
        cout << filtr[i].size << "\t";
        cout << endl << endl;
    }
}


void Storehouse::sum_amount_code(string input_detail)
{
    cout << endl;
    cout << "Код" << "\t\t" << "Адрес" << "\t\t" << "Количество" << "\t" << "Вместимость" << endl <<  "детали" << "\t\t" << "ячейки" << "\t\t" << "деталей" << "\t\t" << "ячейки";
    cout << endl << endl;

    int sum {0};
    for(unsigned int i = 0; i < cell.size(); i++)
    {
        if(cell[i].detail_code == input_detail)
        {
            sum+= cell[i].amount;
        }
    }
    cout << input_detail << "\t" << 0 << "\t\t" << sum << "\t\t" << 0 << endl;

}


void Storehouse::sum_amount_each_code()
{

//    std::vector<Cells>renew;
//    int sum {0};

//    for(unsigned int i = 0; i < cell.size(); i++)
//    {
//        std::map<std::string, int> check;
//        check[cell[i].detail_code] = cell[i].amount;

//        if(check[cell[i].detail_code])
//        {
//            sum += check[cell[i].detail_code];
//        }

//        if(sum != 0) renew.push_back({cell[i].detail_code, "0", sum, 0});

//    }


    // 1 - вход был; 0 - входа не было.
    std::vector<Cells> new_vec;
    std::vector <bool> check_in(cell.size(), 0);

    for(unsigned int n = 0; n < cell.size(); n++)
    {
        int sum = 0;

        if(check_in[n] == 1) // если было вхождение, то продолжаем дальше пробегать по вектору
        {
            continue;
        }

        for(unsigned int i = n; i < cell.size(); i++)
        {
            if(cell[i].detail_code == cell[n].detail_code && check_in[i] == 0)
            {
                sum += cell[i].amount;
                check_in[i] = 1;
            }
        }

        if(sum != 0)
        {
            new_vec.push_back({cell[n].detail_code, "0", sum, 0});
        }
    }

    cout << endl;
    cout << "Код" << "\t\t" << "Адрес" << "\t\t" << "Количество" << "\t" << "Вместимость" << endl <<  "детали" << "\t\t" << "ячейки" << "\t\t" << "деталей" << "\t\t" << "ячейки";
    cout << endl << endl;

    for(unsigned int i = 0; i < new_vec.size(); i++)
    {
        cout << new_vec[i].detail_code << "\t";
        cout << new_vec[i].cell_adress << "\t\t";
        cout << new_vec[i].amount << "\t\t";
        cout << new_vec[i].size << "\t";
        cout << endl << endl;
    }

//    cout << "size new_vec " << new_vec.size() << endl << endl;

}


void Storehouse::sort_cell_adress(std::vector<Cells>& sec)
{
    for(unsigned int i = 0; i < cell.size(); i++)
    {
        sec.push_back(cell[i]);
    }

    Cells buff;

    for(unsigned long int i = 0; i < cell.size()-1; i++)
    {
        for(unsigned long int j = i + 1; j < cell.size(); j++)
        {
            if(sec[i].detail_code > sec[j].detail_code)
            {
                buff = sec[i];
                sec[i] = sec[j];
                sec[j] = buff;
            }

        }
    }

    cout << endl;
    cout << "Код" << "\t\t" << "Адрес" << "\t\t" << "Количество" << "\t" << "Вместимость" << endl <<  "детали" << "\t\t" << "ячейки" << "\t\t" << "деталей" << "\t\t" << "ячейки";
    cout << endl << endl;

    for (size_t i = 0; i < sec.size(); i++)
    {
        cout << sec[i].detail_code << "\t";
        cout << sec[i].cell_adress << "\t";
        cout << sec[i].amount << "\t\t";
        cout << sec[i].size << "\t";
        cout << endl << endl;
    }
}



