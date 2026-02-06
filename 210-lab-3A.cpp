// COMSC-210|Lab 3A|Noel Mier-Luna
#include <iostream>

using namespace std;

struct Restaraunt nameRestaraunt(); // Function prototype for nameRestaraunt.

struct Restaraunt
{
    string name;        // Name of the restaurant
    string address;     // Address of the restaurant
    double rating;      // Rating out of 5
    int numReviews;     // Number of reviews
    int priceRangeLow;  // Lower bound of price range
    int priceRangeHigh; // Upper bound of price range
};

int main()
{
    Restaraunt myRestaraunt = nameRestaraunt(); // Create a Restaraunt struct from function.
    cout << "Restaraunt Name: " << myRestaraunt.name << endl;
    cout << "Restaraunt Address: " << myRestaraunt.address << endl;
    cout << "Restaraunt Rating: " << myRestaraunt.rating << "/5" << endl;
    cout << "Number of Reviews: " << myRestaraunt.numReviews << endl;
    cout << "Price Range: $" << myRestaraunt.priceRangeLow << " - $" << myRestaraunt.priceRangeHigh << endl;
    return 0;
}

struct Restaraunt nameRestaraunt()
{                              // Creates Restaraunt from user input
    Restaraunt tempRestaraunt; // and returns it to main.
    cout << "Enter the name of the restaurant: ";
    getline(cin, tempRestaraunt.name);
    cout << "Enter the address of the restaurant: ";
    getline(cin, tempRestaraunt.address);
    cout << "Enter the rating of the restaurant (0-5): ";
    while (true)
    { // Loop to validate rating input
        cin >> tempRestaraunt.rating;
        if (tempRestaraunt.rating >= 0 && tempRestaraunt.rating <= 5)
        {
            break; // Valid rating, exit loop
        }
        else
        {
            cout << "Invalid rating. Please enter a value between 0 and 5: ";
        }
    }
    while (true)
    { // Loop to validate number of reviews input
        cout << "Enter the number of reviews for the restaurant: ";
        cin >> tempRestaraunt.numReviews;
        if (tempRestaraunt.numReviews >= 0)
        {
            break; // Valid number of reviews, exit loop
        }
        else
        {
            cout << "Invalid number of reviews. Please enter a non-negative integer: ";
        }
    }
    while (true)
    { // Loop to validate price range input
        cout << "Enter the lower bound of price range: ";
        cin >> tempRestaraunt.priceRangeLow;
        cout << "Enter the upper bound of price range: ";
        cin >> tempRestaraunt.priceRangeHigh;
        if (tempRestaraunt.priceRangeLow >= 0 && tempRestaraunt.priceRangeHigh >= tempRestaraunt.priceRangeLow)
        {
            break; // Valid price range, exit loop
        }
        else
        {
            cout << "Invalid price range. Please enter non-negative integers with upper price greater than or equal to lower price ." << endl;
        }
    }
    return tempRestaraunt; // Return the Restaraunt struct
}