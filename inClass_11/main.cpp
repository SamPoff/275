#include <Point.h>
#include <Stack.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validate()  {

    bool fail = true;
    int selection;
    while (fail)  {
        if (std::cin >> selection)  {
            if (selection >= 0 && selection <= 4)  {
                fail = false;
            }//end if
            else  {
                std::cout << "Invalid entry, please enter a number between 0 and 4." << std::endl;
            }//end else
        }//end if
        else  {
            std::cin.clear();
            std::string invalid;
            std::cin >> invalid;
            std::cout << "Invalid entry, please enter a number between 0 and 4." << std::endl;
        }//end else
    }//end while
    return selection;

}//end validate

/** Fills grid with periods.
@param array - 2d array. */
void fillGrid(char array[5][5]) {

    //Fill grid with periods.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = '.';
        }//end for
    }//end for

}//end fillGrid

/** Check user input, push Points onto vector
@param p - vector not containing points
@return p - vector yes containing points */
vector<Point> prompt_check_pushOn(vector<Point> p) {

    //Prompt user for points.
    cout << "Enter 5 Points:" << endl;

    //Initialize holding arrays.
    int holdX[5] = {0};
    int holdY[5] = {0};

    //Validate user inputs and push into vector.
    for (int i = 0; i < 5; i++) {

        holdX[i] = validate();
        holdY[i] = validate();

        p.push_back(Point(holdX[i], holdY[i]));

    }//end for

    return p;

}//end check_pushOn

/** Adds Points to grid.
@param stack - the stack of points
@param array - the grid to be displayed */
void addPoints(Stack stack, char array[5][5]) {

    //Pop from stack;
    //convert 'i' val to char;
    //add to grid.
    for (int i = 5; i > 0; i--) {

        Point arrow = stack.pop();

        char c;

        //Convert to char.
        switch (i) {
            case 1 : c = '1'; break;
            case 2 : c = '2'; break;
            case 3 : c = '3'; break;
            case 4 : c = '4'; break;
            case 5 : c = '5'; break; }

        //Add to grid;
        //check for boundaries.
        array[arrow.getX()][arrow.getY()]          = c;  //center
        if (arrow.getX() + 1 < 5)
            {array[arrow.getX() + 1][arrow.getY()] = c;} //right
        if (arrow.getY() + 1 < 5)
            {array[arrow.getX()][arrow.getY() + 1] = c;} //up
        if (arrow.getX() - 1 >= 0)
            {array[arrow.getX() - 1][arrow.getY()] = c;} //left
        if (arrow.getY() - 1 >=  0)
            {array[arrow.getX()][arrow.getY() - 1] = c;} //down

    }//end for

}//end addPoints

/** Prints grid
@param array - array of Points */
void print(char array[5][5]) {

    //Print Grid
    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << array[i][j] << " ";
        }//end for
        cout << endl;
    }//end for

}//end print

/** Main */
int main() {

    Stack stack;              //Initialize Stack
    vector<Point> p;          //Initialize Point Vector
    char array[5][5] = {{0}}; //Initialize Char Grid

    //Fills grid with periods.
    fillGrid(array);

    //Prompts user / checks user inputs and constructs / pushes Points onto vector.
    p = prompt_check_pushOn(p);

    //Push Points onto stack.
    for (int i = 0; i < 5; i++) {
        stack.push(p[i]);
    }//end for

    //Adds numbers to grid at Point locations.
    addPoints(stack, array);

    //Prints grid.
    print(array);

    return 0;

}//end main

