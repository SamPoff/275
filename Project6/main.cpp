// Author      : Poff, Samuel
// Project     : Project 6
// Date        : 05Dec2016
// Description : Reads in a maze from a file and allows the user to determine how it should be
//              solved (DFS or BFS), then solves and prints it accordingly.

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

#include <Point.h>

using namespace std;

/** Input validation
@param top - The high end of the possible range.
@return selection - The user's selection after validation. */
int validate(int top) {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection <= top)  {
                fail = false;
            }//end if
            else  {
                cout << "Invalid entry, please enter a number between 1 and " << top << "." << endl;
            }//end else

        }//end if

        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and " << top << "." << endl;
        }//end else

    }//end while

    return selection;

}//end validate

/** Menu for which way the user wants to solve the maze.
@return selection - the user's selection after being validated. */
int solveMenu() {

    int highest = 2;
    cout << "\nHow would you like to solve the maze?" << endl;
    cout << "\n";
    cout << "DFS: 1" << endl;
    cout << "BFS: 2" << endl;
    int selection = validate(highest);

    return selection;

}//end searchMenu

/** Fills a vector with array values.
@param fileName - name of the maze file.
@param width - width of the maze.
@param height - height of the maze.
@return maze - a vector containing all the maze values. */
vector<char> fillGrid(string fileName, int width, int height) {

    vector<char> maze;
    int counter = 0;
    fstream file;
    file.open(fileName.c_str(), ios::in);
    char input;
    if (file) {
        file >> input;
        file >> input;
        if (fileName == "Maze-Level2.txt") {
            file >> input;
        }//end if
        else if (fileName == "Maze-Level3.txt") {
            file >> input;
            file >> input;
        }//end else if
        int counterTotal = -1;
        int counter = -1;
        for (int h = 0; h < height ; h++) {
            counter++;
            for (int w = 0; w < width ; w++) {
                counterTotal++;
                while(file.get(input) && counterTotal!= (height*counter + counter)) {
                    maze.push_back(input);
                }//end while
            }//end for h
        }//end for w
        file.close();
    }//end if
    else {cout << "Couldn't open file!";}

    // Erase 'next-lines'.
    counter = 0;
    for (int i = 0; i < maze.size(); i++) {
        if (maze[i] == '\n') {
            counter++;
            maze.erase(maze.begin() + i);
            i = 0;
        }//end if
    }//end for

    return maze;

}//end fillGrid

/** Returns the maze's width.
@param fileName - the name of the maze file.
@return width - the width of the maze. */
int getWidth (string fileName) {

    fstream file;
    file.open(fileName.c_str(), ios::in);
    int width;
    if (file) {
        file >> width;
        file >> width;
        file.close();
    }//end if
    else { cout << "Could not open file!";}

    return width;

}//end getWidth

/** Returns the maze's height.
@param fileName - the name of the maze file.
@return height - the height of the maze. */
int getHeight(string fileName) {

    fstream file;
    file.open(fileName.c_str(), ios::in);
    int height;
    if (file) {
        file >> height;
        file.close();
    }//end if
    else { cout << "Could not open file!";}

    return height;

}//end getHeight

/** The main menu / maze menu.
@return selection - the user's validated selection. */
int menu() {

    int highest = 5;
    cout << "\nPlease select a maze." << endl;
    cout << "\n";
    cout << "Maze 1: 1" << endl;
    cout << "Maze 2: 2" << endl;
    cout << "Maze 3: 3" << endl;
    cout << "Maze 4: 4" << endl;
    cout << "Quit  : 5" << endl;

    int selection = validate(highest);

    return selection;

}//end menu

/** Main */
int main() {

    // Controls when the program quits.
    bool dontQuit = true;

    // Continue while don't quit.
    while(dontQuit) {


        // Initialize width and height of maze.
        int width;
        int height;


        // To hold user's selected file.
        string fileName;


        // Maze menu
        int selection = menu();


        // Decide what to do based on selection.
        // Either set the correct file name or
        // quit the program.
        if      (selection == 1) {
            fileName = "Maze-Level0.txt";
        }//end if
        else if (selection == 2) {
            fileName = "Maze-Level1.txt";
        }//end else if
        else if (selection == 3) {
            fileName = "Maze-Level2.txt";
        }//end else if
        else if (selection == 4) {
            fileName = "Maze-Level3.txt";
        }//end else if
        else {
            dontQuit = false;
            break;
        }//end else if


        // Read from file
        width  = getWidth (fileName);
        height = getHeight(fileName);
        cout << "\n";
        cout << "Width : " << width  << endl;
        cout << "Height: " << height << endl;


        // Fill vector with values (no 'next-lines').
        vector<char> mazeVec = fillGrid(fileName, width, height);


        // Initialize two dimensional array.
        char maze[width][height];


        // Push values from vector to 2D array.
        int counter = 0;
        for(int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                maze[w][h] = mazeVec[counter++];
            }//end for
        }//end for


        // Initialize stack and queue.
        stack<Point> mustack;
        queue<Point> muqueue;


        // Ask the user if they want to use DFS or BFS.
        int newselection = solveMenu();


        // Find starting point.
        int startW;
        int startH;
        for(int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                if (maze[w][h] == 's') {
                    startW = w;
                    startH = h;
                }//end if
            }//end for
        }//end for


        // Create starting point.
        Point startPoint = Point(startW, startH);


        // Instantiate current point.
        Point current;


        // User selected DFS
        if (newselection == 1) {

            // Bool for while loop.
            bool dontStop = true;

            // Push start point onto stack.
            mustack.push(startPoint);

            while (mustack.size() > 0 && dontStop) {

                // Set current to the Point on top of stack.
                current = mustack.top();

                // If current is the finish, end the program.
                if (maze[current.getX()][current.getY()] == 'f') {
                    dontStop = false;
                }//end if
                // Otherwise:
                else {

                    // Mark current location, remove top Point from stack.
                    maze[current.getX()][current.getY()] = '.';
                    mustack.pop();

                    // Check neighboring locations to see if they are a wall or
                    // have been checked already. If not, they are added to the stack.
                    if (maze[current.getX() + 1][current.getY()] != '*' &&
                        maze[current.getX() + 1][current.getY()] != '.' ){
                            Point p = Point(current.getX() + 1, current.getY());
                            mustack.push(p);
                    }//end if
                    if (maze[current.getX() - 1][current.getY()] != '*' &&
                        maze[current.getX() - 1][current.getY()] != '.' ){
                            Point p = Point(current.getX() - 1, current.getY());
                            mustack.push(p);
                    }//end else if
                    if (maze[current.getX()][current.getY() + 1] != '*' &&
                        maze[current.getX()][current.getY() + 1] != '.' ){
                            Point p = Point(current.getX(), current.getY() + 1);
                            mustack.push(p);
                    }//end else if
                    if (maze[current.getX()][current.getY() - 1] != '*' &&
                        maze[current.getX()][current.getY() - 1] != '.' ){
                            Point p = Point(current.getX(), current.getY() - 1);
                            mustack.push(p);
                    }//end else if
                }//end else
            }//end while

        }//end if

        // User selected BFS
        else if (newselection == 2) {

            // Bool for while loop.
            bool dontStop = true;

            // Push start point onto queue.
            muqueue.push(startPoint);

            while (muqueue.size() > 0 && dontStop) {

                // Set current to front Point from queue.
                current = muqueue.front();

                // If current is the finish, end the program.
                if (maze[current.getX()][current.getY()] == 'f') {
                    dontStop = false;
                }//end if
                // Otherwise:
                else {

                    // Mark current location, remove front Point from queue.
                    maze[current.getX()][current.getY()] = '.';
                    muqueue.pop();

                    // Check neighboring locations to see if they are a wall or
                    // have been checked already. If not, they are added to the stack.
                    if      (maze[current.getX() + 1][current.getY()] != '*' &&
                             maze[current.getX() + 1][current.getY()] != '.' ){
                                Point p = Point(current.getX() + 1, current.getY());
                                muqueue.push(p);
                    }//end if
                    if (maze[current.getX() - 1][current.getY()] != '*' &&
                             maze[current.getX() - 1][current.getY()] != '.' ){
                                Point p = Point(current.getX() - 1, current.getY());
                                muqueue.push(p);
                    }//end else if
                    if (maze[current.getX()][current.getY() + 1] != '*' &&
                             maze[current.getX()][current.getY() + 1] != '.' ){
                                Point p = Point(current.getX(), current.getY() + 1);
                                muqueue.push(p);
                    }//end else if
                    if (maze[current.getX()][current.getY() - 1] != '*' &&
                             maze[current.getX()][current.getY() - 1] != '.' ){
                                Point p = Point(current.getX(), current.getY() - 1);
                                muqueue.push(p);
                    }//end else if
                }//end else
            }//end while

        }//end else


        // Print the array.
        cout << "\n";
        counter = 0;
        for(int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                if ((w+1) % width == 0) {
                    cout << maze[w][h];
                    cout << "\n";
                }//end if
                else {
                    cout << maze[w][h];
                }//end else
            }//end for
        }//end for

    }//end while


    return 0;


}//end main
