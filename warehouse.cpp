#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include "warehouse.h"
using namespace std;


void show_menu(Items products[], int N){
    int choice;
    do{

        cout << "Please enter option from 1-7, for end please enter 0!" << " ";
        cin >> choice;


        switch (choice){
            case 0: cout << "Exiting...";
            break;
            case 1: cout << "Available items: " << '\n';
            show_the_products(products, N);
            break;
            case 2: cout << "Alphabetical order: " << '\n';
            alphabetical_order(products, N);
            show_the_products(products, N);
            break;
            case 3: cout << "Price order: " << '\n';
            price_order(products, N);
            show_the_products(products, N);
            break;
            case 4: cout << "Search product by name and model: " << '\n';
            search_by_name_model(products, N);
            break;
            case 5: cout << "Print items with stock below N: " << '\n';
            in_stock(products, N);
            break;
            case 6: cout << "Products to order: " << '\n';
            products_to_order(products, N);
            break;
            case 7: cout << "Total sum of warehouse: " << '\n';
            total_sum_of_warehouse(products, N);
            break;

            default: cout << "Invalid data! Please try again!" << '\n';
            break;
        };
    }while (choice != 0);
}


void products_to_order(Items products[], int N){

    for (int i=0; i<N; i++){
        int needed_orders = 0;
        if (products[i].quantity > products[i].number_of_stocks){
            needed_orders = products[i].quantity - products[i].number_of_stocks;
            cout << products[i].name << " " << products[i].model << ":" << " "
            << "Needed quantity:" << " " << needed_orders << '\n';
        }
    }
}


void in_stock(Items products[], int N){
    int needed_quantity;
    cout << "Enter needed quantity: ";
    cin >> needed_quantity;
    cout << '\n';

    for (int i=0; i<N; i++){
        if (needed_quantity > products[i].number_of_stocks){
            cout << products[i].name << " " << products[i].model << ":" << " "
            << products[i].number_of_stocks << " " << "pieces" << '\n';
            cout << '\n';
        }
    }

}

double total_sum_of_warehouse(Items products[], int N){

    double total_sum = 0;

    for (int i=0; i<N; i++){
        total_sum += products[i].price_per_product * products[i].number_of_stocks;

    }
    cout << fixed << setprecision(2);
    cout << "Total sum of warehouse is: " << " " << total_sum << " " << "euro" <<'\n';
    return total_sum;

}

void search_by_name_model(Items products[], int N){
    string name, model;
    cout << "Please enter name: " << '\n';
    cin.ignore();
    getline(cin, name);
    cout << "Please enter model: ";
    getline(cin, model);
    bool is_found = false;

    for (int i=0; i < name.size(); i++){
        name[i] = tolower(name[i]);
    }
    for (int i=0; i < model.size(); i++){
        model[i] = tolower(model[i]);
    }


    for (int i=0; i<N; i++){
        string current_name = products[i].name;
        string current_model = products[i].model;


        for (int j=0; j < current_name.size(); j++){
            current_name[j] = tolower(current_name[j]);
        }

        for (int j=0; j < current_model.size(); j++){
            current_model[j] = tolower(current_model[j]);
        }
        if (name == current_name && model == current_model){
            cout << "Your choice: " << " " <<products[i].name << " " <<products[i].model << " "<< '\n' << "price: "
            << products[i].price_per_product << " " << '\n' << "number of stocks: "
            << products[i].number_of_stocks << '\n' << "quantity: "
            << " " << products[i].quantity << endl;
            is_found = true;
            break;
        }

    }
    if (!is_found){
        cout << "The product you are looking for is not available!" << '\n';
    }
}
void price_order (Items products[], int N){
    Items price_copy;
    for (int i=0; i<N; i++){
        for (int j=0; j<N-i-1; j++){
            if (products[j].price_per_product > products[j+1].price_per_product){
                price_copy = products[j];
                products[j] = products[j+1];
                products[j+1] = price_copy;
            }
        }
    }
}
void alphabetical_order (Items products[], int N){
    Items name_copy;
    for (int i=0; i<N; i++){
        for (int j=0; j<N-i-1; j++){
            if (products[j].name > products[j+1].name){
                name_copy = products[j];
                products[j] = products[j+1];
                products[j+1] = name_copy;
            }

            else if (products[j].name == products[j+1].name){
                    if (products[j].model > products[j+1].model){
                    name_copy = products[j];
                    products[j] = products[j+1];
                    products[j+1] = name_copy;
                    }

                }
            }
    }
}
void show_the_products(Items products[], int N){

    for (int i=0; i<N; i++){
        cout << "Name: " << products[i].name << " " << '\n' << '\n'
        << "Model: " << products[i].model << " " << '\n'
        << "Single price: " << products[i].price_per_product << " " <<"euro" << " " << '\n'
        << "Available quantity: " << products[i].number_of_stocks << " " << '\n'
        << "Desired amount: " << products[i].quantity << '\n' << '\n';
    }
}

