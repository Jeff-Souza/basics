/*
Convert Mass

User inputs a weight in kg, output the conversion to pounds

First set of consecutive digits are taken from user input
Input can handle signed and decimal numbers
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    // prompt user for weight
    cout << "Enter a weight in kilograms" << endl;

    string input;
    float kilograms;
    float pounds;
   
    getline (cin, input);
    
    stringstream(input) >> kilograms;
    
    // kilograms will be false if conversion failed
    if(!kilograms)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
   
    pounds = kilograms*2.20462; // convert pounds to kg
    
    cout << kilograms << " kg is " << setprecision(2) << fixed << pounds << " pounds" << endl;
   
    return 0;
}
