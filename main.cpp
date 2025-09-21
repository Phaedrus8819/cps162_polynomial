#include "Polynomial.h"
#include <iostream>
#include <cstdlib>
//#include <windows.h>


using namespace std;

void displayMenu(int *);
//void createTerm(Polynomial *);

int main()
{
    /*
    //font and system color --->>>
    system("Color 8a");
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 18;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    cfi.FaceName, "forte";
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //--->>>
    */

    int choice, *choicePtr = &choice;
    bool go = true;

    Polynomial firstPoly;
    Polynomial secondPoly;
    
    do
    {
        displayMenu(choicePtr);

        switch(choice)
        {
            case 1:
            {   
                int x, y;
                cout << "Enter the coefficient:\n ";
                cin >> x;
                cout << "Enter the exponent:\n ";
                cin >> y;
                Polynomial::Term term{x, y};
                firstPoly.insertTerm(term);
                break;
            }
            case 2:
            {   
                int x, y;
                cout << "Enter the coefficient:\n ";
                cin >> x;
                cout << "Enter the exponent:\n ";
                cin >> y;
                Polynomial::Term term{x, y};
                secondPoly.insertTerm(term);
                break;
            }
            case 3:
                firstPoly.display(); // Display the first polynomial
                break;
            case 4:
                secondPoly.display(); // Display the second polynomial
                break;
            case 5:
                Polynomial::printSum(firstPoly, secondPoly);
                break;
            case 6:
                Polynomial::printDiff(firstPoly, secondPoly);
                break;
            case 7: 
                int x, y;
                cout << "Please enter the coefficient:\n";
                cin >> x;
                cout << "Please enter the exponent:\n";
                cin >> y;
                Polynomial::multPoly(firstPoly, x, y);
                break;
            case 8:
                go = false; // Exit the loop
                break;
        }
        if (go)    
            system("pause"); // Prompts "Press any key to continue"
            system("cls");
    } while (go);

    return 0;
}

void displayMenu(int *choicePtr)
{
    cout << "====Menu====" << endl;
    cout << "1. Add a term to the first polynomial" << endl;
    cout << "2. Add a term to the second polynomial" << endl;
    cout << "3. Display the first polynomial" << endl;
    cout << "4. Display the second polynomial" << endl;
    cout << "5. Display the sum of the two polynomials"  << endl;
    cout << "6. Display polynomial 1 minus polynomial 2" << endl;
    cout << "7. Multiply polynomial 1 by a single term and display" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> *choicePtr;
}

/*
void createTerm(Polynomial *poly)
{
    int x, y;
    cout << "Enter the coefficient:\n ";
    cin >> x;
    cout << "Enter the exponent:\n ";
    cin >> y;
    Polynomial::Term term{x, y};
    poly.insertTerm(term);
}
    */