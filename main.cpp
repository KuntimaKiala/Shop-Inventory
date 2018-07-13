/*
Author : Kuntima
Description : A shop 
Date : 13/7/2018
g++ -std=c++11 main.cpp -o main
*/

// importing the necessary libraries
#include <iostream>
#include <string>

using namespace std ;


// Initializing the lists
const int nbItems = 9 ; // number of item in the shop
const string Items[nbItems] ={"Meat", "Rice", "Beans", "Fish", "Brocolis", "Fruits", "Juice", "Snacks", "Cockies"} ; // the items
int BuyerInventory [nbItems] ={0,0,0,0,0,0,0,0,0} ; // the inventory, stock of each person
const float price[nbItems] = {10.35 ,1.20 ,0.57 ,4.1 ,40.15 ,5.07 ,2.0, 5.53 ,3.5 }; // the price of each item

void purchasedItems( int BuyerInventory [nbItems]) ; // a function that returns the final cost
void printBuyerInventory( int BuyerInventory[nbItems]) ; // a function that prints the client inventory
void printShoping() ; // a function that show what being purchased in the shop
// Array are passed by value, never by value
bool Shoping(int BuyerInventory[nbItems]) ;  // a function that controls what is being purchased

// main function
int main() {
    bool isDone = false ; // variable to control to keep or quit shoping

    // while the client is not done shoping keep going
    while (isDone == false){
        printShoping();
        printBuyerInventory(BuyerInventory);
        isDone = Shoping(BuyerInventory) ;
        if (isDone == true ){
            purchasedItems (BuyerInventory ) ;
        }
    }
    return 0 ;
}

void printShoping(){
    cout << "Welcome to the Kuntima Shop \n\n" ;
    cout << "Here the list of what we have available : \n" ;
    cout << "________________________" << endl ;
    cout << " | nb |" << " Item - " << "Price " << endl ;
    cout << "________________________" << endl ;

    for (int i = 0; i < nbItems; i++ ){
    cout << " | " << i+1 << " | "<< Items[i] << " - " << price[i] << endl  ;

    }
   cout << "________________________" << endl ;

}

void printBuyerInventory(int BuyerInventory[nbItems]) {

    cout << "Your inventory is :\n";
    for (int j = 0; j < nbItems; j++){
        if (BuyerInventory[j] > 0 ) {
            cout << BuyerInventory[j] << " x " << Items[j]  << endl;
        }

    }
    cout << endl ;
}


bool Shoping(int BuyerInventory[nbItems]) {

    int itemNb ;
    cout << " ********************** \n\n" ;
    cout << "Enter (" << 1 <<"-"<<nbItems <<") to choose the Item and Enter -1 to Stop shopping\n" ;
    cout << "What would you buy ? :" ;
    cin >> itemNb ;

    if (itemNb == -1 ) { // to quit purchasing 
    cout << "Thanks for the visit" ; // 
    return  true ;

    }

    if (itemNb < 1 || itemNb > nbItems ) { // controling that the person chooses the right numbers
        cout << "BAD INPUT ! \n\n" ;
        return  false ;
    }


    BuyerInventory[itemNb -1]++; // increment the number of items taken ==>  BuyerInventory[itemNb -1] = BuyerInventory[itemNb -1] +1 
    return false ;


}

void purchasedItems (int BuyerInventory[nbItems] ) {

    float totalvalue = 0.0 ;
    int i = 0 ;
    cout << endl ;
    for ( int k = 0; k < nbItems; k++) {
        totalvalue = totalvalue + price[k]*BuyerInventory[k] ;

        if (price[k]*BuyerInventory[k] > 0.0) {
            cout << i+1 <<"- " <<  Items[k] << ": " << price[k]*BuyerInventory[k] << " $"<< "\n" ;
            i++ ;
        }
    }

    cout << "Total Cost: " << totalvalue << "$\n\n" ;



}
