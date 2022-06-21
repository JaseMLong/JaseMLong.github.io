/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

// Did my program with some functions just for fun/practice


// Function to get the item number from the menu of the chosen restaurant
int menuFunction(int n);

// Little function that fetches the # of items the customer wants
int numberOf();

int main()
{
    int restaurantNum;
    int menuNum;
    int number;
    float price;
    int restaurant;
    
    cout << "Welcome to the Fast Food Delivery Company..." << endl << endl << endl;
    cout << "____________________________________________" << endl << endl;
    cout << "Please Select a Restaurant:" << endl << endl;
    cout << "1. Sonic" << endl << "2. Burger King" << endl << "3. Chick-fil-A"; 
    cout << endl << endl << "Please select a restaurant (1, 2, or 3): ";
    cin >> restaurantNum;
    cout << endl << endl;
    
    // Error checking restaurant selection
    if ((restaurantNum != 1) && (restaurantNum != 2) && (restaurantNum != 3)){
        while ((restaurantNum != 1) && (restaurantNum != 2) && (restaurantNum != 3)){
            cout << endl << "Please select a restaurant (1, 2, or 3): ";
            cin >> restaurantNum;
            cout << endl << endl;
        }
    }
    
    // If no error, run code
    
    // See function section above
    menuNum = menuFunction(restaurantNum);
        
        
    // Pricing
    switch (restaurantNum){
            
        // Sonic
        case 1:
            switch (menuNum){
                case 1:
                    
                    // See function section above
                    price = numberOf() * 3.89;
                    break;
                    
                case 2:
                    price = numberOf() * 1.99;
                    break;
                    
                case 3:
                    price = numberOf() * 4.69;
                    break;
                    
                case 4:
                    price = numberOf() * 4.49;
                    break;
                    
                case 5:
                    price = numberOf() * 3.59;
                    break;
                
                default:
                    break;
            }
            break;
            
            
            // Burger King
            case 2:
                switch (menuNum){
                    case 1:
                        price = numberOf() * 5.29;
                        break;
                    
                    case 2:
                        price = numberOf() * 6.79;
                        break;
                    
                    case 3:
                        price = numberOf() * 1.39;
                        break;
                    
                    case 4:
                        price = numberOf() * 1.59;
                        break;
                    
                    case 5:
                        price = numberOf() * 3.09;
                        break;
                    
                    default:
                        break;
                }
                break;
            
            
            // Chick-fil-A
            case 3:
                switch (menuNum){
                    case 1:
                        price = numberOf() * 3.05;
                        break;
                    
                    case 2:
                        price = numberOf() * 4.45;
                        break;
                    
                    case 3:
                        price = numberOf() * 5.19;
                        break;
                    
                    case 4:
                        price = numberOf() * 1.65;
                        break;
                    
                    case 5:
                        price = numberOf() * 4.39;
                        break;
                    
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        
    // Add Tax
    price = price + (price * 0.05);
        
    // Round off to hundredths
    price = floor(price*100+0.5)/100;
        
    // Print Total
    cout << "____________________________________________" << endl << endl;
    cout << endl << "Your Total is $" << price << endl;


    
    return 0;
}




int menuFunction(int n){
    int item;
    
    
    // Sonic Menu
    if (n == 1){
        cout << "Welcome to Sonic" << endl << endl;
        cout << "____________________________________________" << endl << endl;
        cout << "Please select an option from our menu (1, 2, 3, 4, or 5):" << endl << endl;
        cout << "1. Cheeseburger" << endl << "2. New York Dog" << endl;
        cout << "3. Five-Piece Chicken Strips" << endl << "4. Six-Piece Boneless Wings";
        cout << endl << "5. Six Piece Mozzarella Sticks" << endl;
    }
    
    // Burger King Menu
    else if (n == 2){
        cout << "Welcome to Burger King" << endl << endl;
        cout << "____________________________________________" << endl << endl;
        cout << "Please select an option from our menu (1, 2, 3, 4, or 5):" << endl << endl;
        cout << "1. Double Whopper" << endl << "2. Chicken Fries" << endl;
        cout << "3. Onion Rings" << endl << "4. Smooth Roast Coffee";
        cout << endl << "5. Hand-Spun Shake" << endl;
    }
    
    // Chick-fil-A Menu
    else if (n == 3){
        cout << "Welcome to Chick-fil-A" << endl << endl;
        cout << "____________________________________________" << endl << endl;
        cout << "Please select an option from our menu (1, 2, 3, 4, or 5):" << endl << endl;
        cout << "1. Chicken Sandwich" << endl << "2. Chicken Nuggets" << endl;
        cout << "3. Chicken Wrap" << endl << "4. Fries";
        cout << endl << "5. Chicken Strips" << endl;
    }
    cin >> item;
    
    // Error Checking
    while ((item != 1) && (item != 2) && (item != 3) && (item != 4) && (item != 5)){
        cout << endl << endl << "Please select an option from our menu: ";
        cin >> item;
        cout << endl << endl;
    }
    cout << "____________________________________________" << endl << endl;
    return item;
}




int numberOf(){
    int n;
    cout << "How many would you like?" << endl;
    cin >> n;
    if (n < 1) {
        while (n < 1){
            cout << "Please select a positive number: ";
            cin >> n;
            cout << endl << endl;
        }
    }
    return n;
}


