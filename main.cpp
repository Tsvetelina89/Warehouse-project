#include <iostream>
#include <string>
#include "warehouse.h"

using namespace std;
const int N = 15;
int main()
{
    Items products[N] = {
    {"Samsung", "Galaxy S25", 1354.56, 10, 12},
    {"Apple", "Iphone 17", 1599.98, 25, 10},
    {"Samsung", "Galaxy A17", 159.99, 45, 30},
    {"Samsung", "Galaxy A26", 347.26, 50, 65},
    {"Realme", "16 Pro", 599.98, 15, 10},
    {"Apple", "Iphone 17 Pro", 2554.56, 15, 20},
    {"Apple", "Iphone 17 Pro Max", 3599.98, 25, 35},
    {"Realme", "Note 70T", 459.99, 20, 25},
    {"Realme", "GT8 Pro", 1048.14, 10, 15},
    {"Motorola", "Signature", 999.98, 12, 15},
    {"Samsung", "S25 Ultra", 3303.78, 10, 22},
    {"Samsung", "A76", 508.88, 20, 21},
    {"Samsung", "A36", 678.99, 15, 25},
    {"Samsung", "A56", 599.98, 15, 25},
    {"Motorola", "Razr", 511.28, 20, 22}
    };
    show_menu(products, N);


    return 0;
}
