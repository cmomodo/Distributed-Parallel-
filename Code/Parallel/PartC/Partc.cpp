#include "omp.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>  
#include <vector>
#include <chrono>

using namespace std;

/* Display the vectors at 0, 25 and 50 steps */
void checkSteps(vector<vector<int>> &vectors, int i){

    /* It's initializing the variable that will be used to store the string that will be printed out. */
    string stepString;

    if (i == 0 || i == 24 || i == 49) { //If we're 50 steps in
        stepString += "Steps in: " + to_string(i+1) + "\n";
        for ( int i = 0; i < vectors.size(); i++ ) { //Iterate over the current matrix
            stepString += "(";
            for ( int j = 0; j < vectors[i].size(); j++ ) {
                stepString += to_string(vectors[i][j]);
                if (j != vectors[i].size() - 1) {
                    stepString += ", ";
                }
            }
            /* It's adding a new line to the string. */
            stepString += ")\n";
        }
        cout << stepString + "\n"; //Split 25 and 50
    }
}

/* Get the average of all particles in part B */
int getTargetX(vector<vector<int>> &vectors){

    int x = 0;
    int y = 0;
    int z = 0;

    for ( int i = 0; i < vectors.size(); i++ ){ //Iterate over generated numbers
        x += vectors[i][0]; //Add up all x values
        y += vectors[i][1]; //Add up all y values
        z += vectors[i][2]; //Add up all z values
    }

    x = x/vectors.size(); //Get the average of the x values
    y = y/vectors.size(); //Get the average of the y values
    z = z/vectors.size(); //Get the average of the z values

    /* Display the average position of the particles*/
    cout << "\nAiming for\nX: " + to_string(x) + "\nY: " + to_string(y) + "\nZ: " + to_string(z) + "\n" << endl;

    return x;
}

/* Get the average of all particles in part B */
int getTargetY(vector<vector<int>> &vectors){

    int x = 0;
    int y = 0;
    int z = 0;

    for ( int i = 0; i < vectors.size(); i++ ){ //Iterate over generated numbers
        x += vectors[i][0]; //Add up all x values
        y += vectors[i][1]; //Add up all y values
        z += vectors[i][2]; //Add up all z values
    }

    x = x/vectors.size(); //Get the average of the x values
    y = y/vectors.size(); //Get the average of the y values
    z = z/vectors.size(); //Get the average of the z values

    /* Display the average position of the particles*/
    //cout << "\nAiming for\nX: " + to_string(x) + "\nY: " + to_string(y) + "\nZ: " + to_string(z) + "\n" << endl;

    return y;
}


/* Get the average of all particles in part B */
int getTargetZ(vector<vector<int>> &vectors){

    /* It's initializing the variables that will be used to store the sum of the x, y, and z values. */
    int x = 0;
    int y = 0;
    int z = 0;

    for ( int i = 0; i < vectors.size(); i++ ){ //Iterate over generated numbers
        x += vectors[i][0]; //Add up all x values
        y += vectors[i][1]; //Add up all y values
        z += vectors[i][2]; //Add up all z values
    }

    x = x/vectors.size(); //Get the average of the x values
    y = y/vectors.size(); //Get the average of the y values
    z = z/vectors.size(); //Get the average of the z values

    /* Display the average position of the particles*/
    cout << "\nAiming for\nX: " + to_string(x) + "\nY: " + to_string(y) + "\nZ: " + to_string(z) + "\n" << endl;

    return z;
    }

int main() {

    // Set the number of particles and the number of steps to simulate
    int numParticles = 1000;
    int numSteps = 50;

    // Generate the initial set of random particle vectors
    vector<vector<int>> vectors;
    for ( int i = 0; i < numParticles; i++ ){
        vector<int> particle;
        particle.push_back(rand() % 100); // Generate random x value
        particle.push_back(rand() % 100); // Generate random y value
        particle.push_back(rand() % 100); // Generate random z value
        vectors.push_back(particle); // Add particle to the vector
    }

    // Get the target x, y, and z values
    int targetX = getTargetX(vectors);
    int targetY = getTargetY(vectors);
    int targetZ = getTargetZ(vectors);

    // Simulate the movement of the particles
    for ( int i = 0; i < numSteps; i++ ) {
        #pragma omp parallel for
        for ( int j = 0; j < vectors.size(); j++ ) {
            // Generate random movement values
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            int dz = rand() % 3 - 1;

            // Update the particle's position
            vectors[j][0] += dx;
            vectors[j][1] += dy;
            vectors[j][2] += dz;
        }
        /* It's checking the steps of the particles. */
        checkSteps(vectors, i);
    }

    return 0;
}

