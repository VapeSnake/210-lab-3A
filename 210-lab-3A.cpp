// COMSC-210|Lab 3A|Noel Mier-Luna
#include <iostream>

using namespace std;

struct Restaraunt nameRestaraunt();          // Function prototype for nameRestaraunt.
void displayRestaraunt(const Restaraunt &r); // Function prototype for displayRestaraunt.
                                             // Constant reference parameter to avoid unnecessary copying of the Restaraunt struct.
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
    Restaraunt firstRestaraunt = nameRestaraunt();
    Restaraunt secondRestaraunt = nameRestaraunt();
    Restaraunt thirdRestaraunt = nameRestaraunt(); //I'm seeing how vectors will be useful for the next lab.
    Restaraunt fourthRestaraunt = nameRestaraunt();
    displayRestaraunt(firstRestaraunt);
    displayRestaraunt(secondRestaraunt);
    displayRestaraunt(thirdRestaraunt);
    displayRestaraunt(fourthRestaraunt);
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

void displayRestaraunt(const Restaraunt &r)
{ // Moved code used from main into this function.
    cout << "Restaraunt Name: " << r.name << endl;
    cout << "Restaraunt Address: " << r.address << endl;
    cout << "Restaraunt Rating: " << r.rating << "/5" << endl;
    cout << "Number of Reviews: " << r.numReviews << endl;
    cout << "Price Range: $" << r.priceRangeLow << " - $" << r.priceRangeHigh << endl;
}