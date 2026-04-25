#ifndef WAREHOUSE_H_INCLUDED
#define WAREHOUSE_H_INCLUDED
#include <string>

struct Items {
    std::string name;
    std::string model;
    double price_per_product;
    int number_of_stocks;
    int quantity;

};
void show_menu(Items products[], int N);
void products_to_order(Items products[], int N);
void in_stock(Items products[], int N);
double total_sum_of_warehouse(Items products[], int N);
void search_by_name_model(Items products[], int N);
void price_order (Items products[], int N);
void alphabetical_order (Items products[], int N);
void show_the_products(Items products[], int N);

#endif // WAREHOUSE_H_INCLUDED
