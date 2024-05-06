#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void simulatePPA(int vectors[10][3]) {
    //print out the original state
    cout << "The original state is: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vectors[i][j] << " ";
        }
        cout << endl;
    }

    //randomly increase the PPA by any integer value from one to five on each iteration
    srand(time(0));
    int PPA = 2;
    for (int step = 1; step <= 50; step++) {
        PPA += (rand() % 5) + 1;
        if (step == 25) {
            //print out the PPA state at twenty-five steps
            cout << "The PPA state at twenty-five steps is: " << endl;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << vectors[i][j] + PPA << " ";
                }
                cout << endl;
            }
        }
        if (step == 50) {
            //print out the PPA state at fifty steps
            cout << "The PPA state at fifty steps is: " << endl;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << vectors[i][j] + PPA << " ";
                }
                cout << endl;
            }
        }
        //add the PPA to each of the three integers in each set
        #pragma omp parallel for
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                vectors[i][j] += ((rand() % 2 == 0) ? 1 : -1) * PPA; //Randomly increment or decrement each coordinate
            }
        }   
    }
}


int main() {
    
     int vectors[10][3] = { //Define the vectors used
        {5, 14, 10},
        {7, -8, -14},
        {-2, 9, 8},
        {15, -6, 3},
        {12, 4, -5},
        {4, 20, 17},
        {-16, 5, -1},
        {-11, 3, 16}, 
        {3, 10, -19}, 
        {-16, 7, 4}
    };

    //print out the original state
    cout << "The original state is: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vectors[i][j] << " ";
        }
        cout << endl;
    }

    //randomly increase the PPA by any integer value from one to five on each iteration
    srand(time(0));
    int PPA = 2;

    //add the PPA to each of the three integers in each set
    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            vectors[i][j] += ((rand() % 2 == 0) ? 1 : -1) * PPA; //Randomly increment or decrement each coordinate
        }
    }

    //print out the PPA state at twenty-five steps
    cout << "The PPA state at twenty-five steps is: " << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vectors[i][j] << " ";
        }
        cout << endl;
    }

    //add the PPA to each of the three integers in each set
    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            vectors[i][j] += ((rand() % 2 == 0) ? 1 : -1) * PPA; //Randomly increment or decrement each coordinate
        }
    }

    //print out the PPA state at fifty steps
    cout << "The PPA state at fifty steps is: " << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vectors[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}