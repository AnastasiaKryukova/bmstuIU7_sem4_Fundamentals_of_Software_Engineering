#include <iostream>
#include "storehouse.h"

using namespace std;

int main()
{
    int x;

    cout << "Введите значение выполняемой операции" << endl;
    cout << "1 - Вывод базы данных товаров на экран" << endl << "2 - Приёмка товара: внесение данных в БД"<< endl;
    cout << "3 - Отгрузка товара: удаление данных из БД" << endl << "4 - Фильтраци по заданному коду детали"<< endl;
    cout << "5 - Поиск суммарного количества по заданному коду детали" << endl << "6 - Поиск суммарного количества по каждому из кодов деталей"<< endl;
    cout << "7 - Сортировка по полю «адрес ячейки»" << endl;
    cout << "\vВведите номер операции = ";

    Storehouse item;
    item.creation();

    while(cin >> x)
    {
        switch(x)
        {
            case 1:
            {

                item.print();
                cout << "\vВведите номер операции = ";

                break;
            }


            case 2:
            {
                //item.newborn();

                string numer;
                cout << "<Ввод shurup_X>  numer = ";
                cin >> numer;
                cout << endl << endl;

                int kol;
                cout << "kol = ";
                cin >> kol;
                cout << endl << endl;

                item.input_detail = numer;
                item.input_amount = kol;

                item.addiction(numer, kol);

                cout << "\vВведите номер операции = ";

                break;
            }

            case 3:
            {

                //item.newborn();


                string numer;
                cout << "<Ввод shurup_X>  numer = ";
                cin >> numer;
                cout << endl << endl;

                int kol;
                cout << "kol = ";
                cin >> kol;
                cout << endl << endl;

                item.input_detail = numer;
                item.input_amount = kol;

                item.remove(numer, kol);

                cout << "\vВведите номер операции = ";

                break;
            }

            case 4:
            {
                //item.newborn();

                string numer;
                cout << "<Ввод shurup_X>  numer = ";
                cin >> numer;
                cout << endl << endl;

                item.input_detail = numer;

                std::vector<Cells>vec;

                item.filtr_code(numer,vec);

                cout << "\vВведите номер операции = ";

                break;
            }

            case 5:
            {
                //item.newborn();

                string numer;
                cout << "<Ввод shurup_X>  numer = ";
                cin >> numer;
                cout << endl << endl;

                item.input_detail = numer;

                item.sum_amount_code(numer);

                cout << "\vВведите номер операции = ";

                break;
            }

            case 6:
            {
                //item.newborn();

                item.sum_amount_each_code();
                cout << "\vВведите номер операции = ";

                break;
            }

            case 7:
            {
                //item.newborn();

                std::vector<Cells> help;
                item.sort_cell_adress(help);

                cout << "\vВведите номер операции = ";

                break;
            }

            case 8:
            {
                break;

                default:
                    cout << "\vНеверно введен операции" << endl;
                    cout << "Введите номер операции = ";

                    break;

            }


        }





    }






    return 0;
}
