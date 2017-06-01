/*
Author       : Sam Poff
Project Name : In Class 3
Description  : This program reads a vector from a file and will find
different statistical values related to that vector.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void generateGradesFile();
void populateGrades(vector<int>& vec);
void displayGrades(vector<int> vec);
void sortVector(vector<int> vec);
int sumGrades(vector<int> vec);
int findMax(vector<int> vec);
int findMedian(vector<int> vec);
vector<int> findMode(vector<int> vec, vector<int>& modesHeyHey);

int main()  {

    vector<int> vec;
    vector<int> sortedVec;
    vector<int> modesHeyHey;
    bool dontQuit = true;
    int selection;

    //generateGradesFile();
    populateGrades(vec);

    while(dontQuit)  {

        cout << "Statistical Analysis" << endl;
        cout << "" << endl;
        cout << "1. Display Unsorted Grades" << endl;
        cout << "2. Display Sorted Grades" << endl;
        cout << "3. Display Sum of Grades" << endl;
        cout << "4. Display Average Grade" << endl;
        cout << "5. Display Max Grade" << endl;
        cout << "6. Display Median Grade" << endl;
        cout << "7. Display Mode" << endl;
        cout << "8. Quit" << endl;

        bool fail = true;

        while (fail)  {

            if (cin >> selection)  {

                if (selection >= 1 && selection  <= 8)  {

                    fail = false;

                }//end if
                else  {

                    cout << "Invalid entry, please enter a number between 1 and 8." << endl;

                }//end else

            }//end if
            else  {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid entry, please enter a number between 1 and 8." << endl;

            }//end else

        }//end while

        if (selection == 1)  {

            displayGrades(vec);

        }//end if
        else if (selection == 2)  {

            sortVector(vec);

        }//end else if
        else if (selection == 3)  {

            int sum = sumGrades(vec);
            cout << "Sum: " << sum << "\n" << endl;

        }//end else if
        else if (selection == 4)  {

            int sum = sumGrades(vec);
            double average = sum / 100.0;
            cout << "\nThe average is " << average << "." << "\n" << endl;

        }//end else if
        else if (selection == 5)  {

            int maxNum = findMax(vec);
            //Display highest grade.
            cout << "\nThe max value is " << maxNum << "\n" << endl;

        }//end else if
        else if (selection == 6)  {

            int median = findMedian(vec);
            cout << "\nThe median is " << median << ".\n" << endl;

        }//end else if
        else if (selection == 7)  {

            findMode(vec, modesHeyHey);
            for (int i = 0; i < modesHeyHey.size(); i++)  {

                cout << "Mode : " << modesHeyHey[i] << endl;

            }//end for
            cout << "\n";

        }//end else if
        else if (selection == 8)  {

            dontQuit = false;

        }//end else if
        else  {

            //The likelihood of this happening is small. Very small.
            cout << "Moo." << endl;

        }//end else

    }//end while

}//end main

/**
This function generates the grade file with fifty random numbers between one and ten.
*/

void generateGradesFile()  {

    srand (time(NULL));
    int rando;

    fstream file;
    file.open("C:\\Users\\Sam\\Desktop\\275\\inClass3_2\\Grades.txt", ios::out);
    if (file)  {

            for (int i = 0; i < 50; i++)  {

                rando = rand() % 100 + 1;
                file << rando << endl;

            }//end for

        file.close();

    }//end if
    else  {

        cout << "File not found." << endl;

    }//end else

}//end generateGradesFile()

/**
This function populates the grade vector by reading from a grade file.
@param vec - The vector with all the grades.
*/

void populateGrades(vector<int>& vec)  {

    fstream file;
    file.open("C:\\Users\\Sam\\Desktop\\275\\inClass3_2\\Grades.txt", ios::in);

    if (file)  {

        int dummyValue;

        while (file >> dummyValue)  {

            vec.push_back(dummyValue);

        }//end while

    }//end if

    file.close();

}//end populateGrades()

/**
This function displays the grades in ten rows of 5.
@param vec - The vector with all the grades.
*/

void displayGrades(vector<int> vec)  {

    cout << "\n";

    //Display grades.
    for (int i = 0; i < 100; i++)  {

        if ((i + 1) % 5 == 0)  {

            cout << vec[i] << " ";
            cout << "\n";

        }//end if
        else  {

            cout << vec[i] << " ";

        }//end else

    }//end for

    cout << "\n";

}//end displayGrades()

/**
This function sorts the grades using selection sort as shown in class.
@param vec - The vector with all the grades.
*/

void sortVector(vector<int> vec)  {

    cout << "\n";

    vector<int> sortedVec;

    //Sort the vector.
    for (int i = 0; i < vec.size(); i++)  {

        int lowest = i;
        for (int j = (i + 1); j < vec.size(); j++)  {

            if (vec[lowest] > vec[j])  {

                lowest = j;

            }//end if

        }//end for

        int swapVar = vec[i];
        vec[i] = vec[lowest];
        vec[lowest] = swapVar;

    }//end for

    for (int i = 0; i < 100; i++)  {

        sortedVec.push_back(vec[i]);

    }

    //Display the sorted vector.
    for (int i = 0; i < 100; i++)  {

        if ((i + 1) % 5 == 0)  {

            cout << sortedVec[i] << " ";
            cout << "\n";

        }//end if
        else  {

            cout << sortedVec[i] << " ";

        }//end else

    }//end for

    cout << "\n";

}//end sortVector()

/**
This function returns the sum of all the grades.
@param vec - The vector with all the grades.
@return allMyMonies - The sum of all the grades.
*/

int sumGrades(vector<int> vec)  {

    cout << "\n";

    int allMyMonies = 0;

    for (int i = 0; i < 100; i++)  {

        allMyMonies += vec[i];

    }//end sumGrades

    return allMyMonies;

}//end sumGrades()

/**
This function finds the maximum grade. It works by sorting the grades
and displaying the largest one.
@param vec - The vector with all the grades.
*/

int findMax(vector<int> vec)  {

    vector<int> sortedVec;

    //Sort
    for (int i = 0; i < vec.size(); i++)  {

        int lowest = i;
        for (int j = (i + 1); j < vec.size(); j++)  {

            if (vec[lowest] > vec[j])  {

                lowest = j;

            }//end if

        }//end for

        int swapVar = vec[i];
        vec[i] = vec[lowest];
        vec[lowest] = swapVar;

    }//end for

    for (int i = 0; i < 100; i++)  {

        sortedVec.push_back(vec[i]);

    }

    return sortedVec[99];

}//end findMax()

/**
This function finds the median grade. It works by sorting the vector
and finding the two middle numbers, adding them together and dividing by two.
@param vec - The vector containing all the grades.
*/

int findMedian(vector<int> vec)  {

    vector<int> sortedVec;

    //Sort the vector.
    for (int i = 0; i < vec.size(); i++)  {

        int lowest = i;
        for (int j = (i + 1); j < vec.size(); j++)  {

            if (vec[lowest] > vec[j])  {

                lowest = j;

            }//end if

        }//end for

        int swapVar = vec[i];
        vec[i] = vec[lowest];
        vec[lowest] = swapVar;

    }//end for

    for (int i = 0; i < 100; i++)  {

        sortedVec.push_back(vec[i]);

    }

    //Find and display the median.
    double median = (sortedVec[49] + sortedVec[50]) / 2.0;
    return median;

}//end findMedian()

/**
This function finds the mode. First it sorts the vector, then it finds out
the frequency each grade occurs, then it displays the mode. If there are more
than one with the same occurrence it is treated as though they are both the mode.
@param vec - The vector containing all the grades.
*/

vector<int> findMode(vector<int> vec, vector<int>& modesHeyHey)  {

    cout << "\n";

    //Generate sorted vector.
    vector<int> sortedVec;
    //vector<int> modesHeyHey;

    for (int i = 0; i < vec.size(); i++)  {

        int lowest = i;
        for (int j = (i + 1); j < vec.size(); j++)  {

            if (vec[lowest] > vec[j])  {

                lowest = j;

            }//end if

        }//end for

        int swapVar = vec[i];
        vec[i] = vec[lowest];
        vec[lowest] = swapVar;

    }//end for

    for (int i = 0; i < 100; i++)  {

        sortedVec.push_back(vec[i]);

    }//end for

    //Find occurrence of each possible grade.
    int occurence[100] = {0};
    int counter;

    for (int i = 0; i < 100; i++)  {

        counter = 0;

        for (int j = 0; j < 100; j++)  {

            if (sortedVec[j] == (i + 1))  {

                counter += 1;
                occurence[i] = counter;

            }//end if
            else if (sortedVec[j] > i)  {

                break;

            }//end else

        }//end for

    }//end for

    //Print out all of the highest level modes.
    bool found = false;
    bool flag4 = true;
    bool flag3 = false;
    bool flag2 = false;
    bool flag1 = false;

    while (flag4)  {

        for (int i = 0; i < 100; i++)  {

            if (occurence[i] == 4)  {
                modesHeyHey.push_back(i + 1);
                found = true;
            }//end if

        }//end for

        if (!found)  {

            flag3 = true;

        }//end if

        flag4 = false;

    }//end while

    while (flag3)  {

        for (int i = 0; i < 100; i++)  {

            if (occurence[i] == 3)  {
                modesHeyHey.push_back(i + 1);
                found = true;
            }//end if

        }//end for

        if (!found)  {

            flag2 = true;

        }//end if

        flag3 = false;

    }//end while

    while (flag2)  {

        for (int i = 0; i < 100; i++)  {

            if (occurence[i] == 2)  {
                modesHeyHey.push_back(i + 1);
                found = true;
            }//end if

        }//end for

        if (!found)  {

            flag1 = true;

        }//end if

        flag2 = false;

    }//end while

    while (flag1)  {

        for (int i = 0; i < 100; i++)  {

            if (occurence[i] == 4)  {
                modesHeyHey.push_back(i + 1);
                found = true;
            }//end if

        }//end for

        flag1 = false;

    }//end while

    cout << "\n";

    //return modesHeyHey;

}//end findMode()

