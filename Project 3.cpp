// Author: Jason Long 
// Project 3 PF1

#include <iostream>
#include <iomanip>

// Added this in solely for the round function...
#include <cmath>

using namespace std;

// Function: ErrorChecker
// Description: Handles user input errors
double ErrorChecker(double input, string prompt, double limit)
{
    switch ((int)limit){
        
        // Donations
        case 0:
            while (input <= limit) {
                cout << "Invalid Input\n\n\n" << prompt;
                cin >> input;
            }
            break;
        
        // Percent Growth and Return on Investment
        case 100:
            while ((input > limit) || (input < 0.00)) {
                cout << "Invalid Input\n\n\n" << prompt;
                cin >> input;
            }
            break;
        
        // Year
        case 2020:
            while (input < limit){
                cout << "Invalid Input\n\n\n" << prompt;
                cin >> input;
            }
            break;
        
        default:
            break;
    }
    // Just makes the output a little nicer :)
    cout << "__________________________________________________" 
    << "___________________________________________\n";
    
    return input;
}

//Function: MathLooper
// Description: Handles math and printing values in succession

void MathLooper(double year, double donations, double donationsGrowth, 
double investmentsReturn, double investments)
{
    year = round(year);
    bool firstLoop = false;
    double endowment = donations;

    // Looping time ...
    while (endowment < 1000000000){
        
        // After the first loop this code runs to do the math.
        // Had to do this to fix the issue of the loop 
        // not happening after endowment hit 1 billion.
        if (firstLoop == true){
            investments = donations + (donations * (investmentsReturn/100));
            donations = donations + (donations * (donationsGrowth/100));
            endowment = donations + investments;
            year++;
        }
        
        // Column titles only happens at beginning
        else if (firstLoop == false){
            cout << setw(20) << "Year" << setw(20) << "Donations" 
            << setw(20) << "Investments" << setw(20) << "Endowment\n";
        }
        
        // Spacing.. just for appearances
        cout << setw(20) << " "  << setw(20) << " " 
        << setw(20) << " " << setw(20) << " " << endl;
        
        // Printing each row
        cout << setw(20) << setprecision(0) << fixed << year 
        << setw(20) << setprecision(2) << fixed << donations 
        << setw(20) << setprecision(2) << fixed << investments 
        << setw(20) << setprecision(2) << fixed << endowment << endl;
        
        firstLoop = true;
    }
}


// Main
int main()
{
    // Initializing Variables
    double yearInput;
    double year;
    double donations;
    double donationsGrowth;
    double investmentsReturn;
    double investments;
    
    // Prompts for each variable
    string yearPrompt = "Enter the starting year (Must be 2020 or later): ";
    string donationsPrompt = "Enter the alumni donations for the first year "
    "(Must be greater than $0): $";
    string growthPrompt = "Enter the estimated annual percentage growth in "
    "donations (Percent must be between 0% and 100%): %";
    string investmentsPrompt = "Enter the estimated annual percentage return "
    "on investments (Percent must be between 0% and 100%): %";
    
    // Limitations for Inputs
    double yearLimit = 2020;
    double donationsLimit = 0.00;
    double percentLimit = 100;
    
    // Starting year
    cout << endl << yearPrompt;
    cin >> yearInput;
    
        // Call to Error Checker
        yearInput = ErrorChecker(yearInput, yearPrompt, yearLimit);
    
    // Starting donation amount
    cout << endl << donationsPrompt;
    cin >> donations;
    
        // Call to Error Checker
        donations = ErrorChecker(donations, donationsPrompt, donationsLimit);
    
    
    
    // Annual percentage growth in donations
    cout << endl << growthPrompt;
    cin >> donationsGrowth;
    
        // Call to Error Checker
        donationsGrowth = ErrorChecker(donationsGrowth, growthPrompt, percentLimit);
    
    
    // Annual percentage return on investments
    cout << endl << investmentsPrompt;
    cin >> investmentsReturn;
    
        // Call to Error Checker
        investmentsReturn = ErrorChecker(investmentsReturn, investmentsPrompt, percentLimit);
    
    // Call to function to start printing the table
    MathLooper(yearInput, donations, donationsGrowth, investmentsReturn, investments);
    
    return 0;
}


