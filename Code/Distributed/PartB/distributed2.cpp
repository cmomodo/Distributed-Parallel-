#include <mpi.h>
#include <iostream>
#include <vector>


/**
 * Attributes is a struct that contains a list of 15 floats, an integer size, a character letter, a
 * double number, and two integers x and y.
 * @property {float} list - a list of 15 floats
 * @property {int} size - The number of attributes in the list.
 * @property {char} letter - The letter that the user has to type to select the item.
 * @property {double} number - The number of the letter.
 * @property {int} x - The x coordinate of the object.
 * @property {int} y - The y coordinate of the letter.
 */
struct Attributes {
  float list[15];
  int size;
  char letter;
  double number;
  int x;
  int y;
};

/**
 * The Game_features type is a struct that contains an array of integers, an integer, a character
 * array, an integer, a long double, an integer, and an integer.
 * @property {int} playerlist - This is a list of all the players in the game.
 * @property {int} playerlistSize - The number of players in the game.
 * @property {char} levelName - The name of the level.
 * @property {int} levelNameSize - The size of the level name.
 * @property {long double} randVar - This is a random variable that is used to determine the randomness
 * of the game.
 * @property {int} gameBoardWidth - The width of the game board.
 * @property {int} gameBoardHeight - The height of the game board.
 */
struct Game_features{
  int playerlist[30];
  int playerlistSize;
  char levelName[50];
  int levelNameSize;
  long double randVar;
  int gameBoardWidth;
  int gameBoardHeight;  
};

/**
 * A game_player is a structure that contains a character array of 100 characters, an integer, a float,
 * a float, a character array of 50 characters, an integer, and a double.
 * @property {char} playerName - The name of the player.
 * @property {int} playerNameSize - The size of the player's name.
 * @property {float} playerHealth - The player's health.
 * @property {float} playerMana - The amount of mana the player has.
 * @property {char} itemList - This is a list of items that the player has.
 * @property {int} itemListSize - The number of items in the itemList array.
 * @property {double} warewolfPercentage - This is the percentage of the player that is a warewolf.
 */
struct game_player{
  char playerName[100];
  int playerNameSize;
  float playerHealth;
  float playerMana;
  char itemList[50];
  int itemListSize;
  double warewolfPercentage;
};

int main(int argc, char** argv) {
    /* This is initializing the MPI environment. */
    MPI_Init(&argc, &argv);

    /* This is declaring a variable called rank that is an integer. */
    int rank;
    /* This is declaring a variable called rank that is an integer. */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   /* This is declaring a variable called person1 that is of the Attributes struct type. */
    Attributes person1;
    //the rest are the struct values
    person1.list[0] = 1.2;
    person1.size = 3;
    person1.letter = 'A';
    person1.number = 3.14159;
    person1.x = 10;
    person1.y = 20;

    if (rank == 0) {
        // Send the data to node 1
        MPI_Send(&person1, sizeof(person1), MPI_BYTE, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1){
        // Receive the data from node 0
        Attributes person2;
        MPI_Recv(&person2, sizeof(person2), MPI_BYTE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        /* This is printing out the size and letter values of the person2 struct. */
        std::cout << "Size: " << person2.size << ", Letter: " << person2.letter << std::endl;
        /* This is printing out the number, x, and y values of the person2 struct. */
        std::cout << "Number: " << person2.number << ", X: " << person2.x << ", Y: " << person2.y << std::endl;
        /* This is printing out the list of the person2 struct. */
        std::cout << "List: ";

        /* This is printing out the list of the person2 struct. */
        for (int i = 0; i < 15; i++) {
            std::cout << person2.list[i] << " ";
        }

        std::cout << std::endl;
    } else if(rank == 2){

        //receive the data from node 1
        Game_features features;

        MPI_Recv(&features, sizeof(features), MPI_BYTE, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "Playerlist: ";
        for (int i = 0; i < 30; i++) {
            std::cout << features.playerlist[i] << " ";
        }

        std::cout << std::endl;

        std::cout << "PlayerlistSize: " << features.playerlistSize << std::endl;

        std::cout << "LevelName: ";
    
        for (int i = 0; i < 50; i++) {
            std::cout << features.levelName[i] << " ";
        }

        std::cout << std::endl;

        std::cout << "LevelNameSize: " << features.levelNameSize << std::endl;

        std::cout << "RandVar: " << features.randVar << std::endl;

        std::cout << "GameBoardWidth: " << features.gameBoardWidth << std::endl;

        std::cout << "GameBoardHeight: " << features.gameBoardHeight << std::endl;

    } else if(rank == 3){
            
            //send the data to node 2
            Game_features features;
            features.playerlistSize = 3;
            features.playerlist[0] = 1;
            features.playerlist[1] = 2;
            features.playerlist[2] = 3;
            features.levelNameSize = 5;
            features.levelName[0] = 's';
            features.levelName[1] = 'k';
            features.levelName[2] = 'y';
            features.levelName[3] = 'l';
            features.levelName[4] = 'a';
            features.randVar = 3.14159;
            features.gameBoardWidth = 10;
            features.gameBoardHeight = 20;
    
            MPI_Send(&features, sizeof(features), MPI_BYTE, 2, 0, MPI_COMM_WORLD);

    } else if(rank == 4){
            
            //receive the data from node 3
            game_player player;
    
            /* This is receiving the data from node 3. */
            MPI_Recv(&player, sizeof(player), MPI_BYTE, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
            std::cout << "PlayerName: ";
            for (int i = 0; i < 100; i++) {
                std::cout << player.playerName[i] << " ";
            }
    
            /* Printing a new line. */
            std::cout << std::endl;
    
            /* This is printing out the playerNameSize value of the player struct. */
            std::cout << "PlayerNameSize: " << player.playerNameSize << std::endl;
    
            /* This is printing out the playerHealth value of the player struct. */
            std::cout << "PlayerHealth: " << player.playerHealth << std::endl;
    
            /* This is printing out the playerMana value of the player struct. */
            std::cout << "PlayerMana: " << player.playerMana << std::endl;
    
            std::cout << "ItemList: ";
            for (int i = 0; i < 50; i++) {
                std::cout << player.itemList[i] << " ";
            }
    
            /* Printing a new line. */
            std::cout << std::endl;
    
            /* This is printing out the itemListSize value of the player struct. */
            std::cout << "ItemListSize: " << player.itemListSize << std::endl;
    
            /* This is printing out the warewolfPercentage value of the player struct. */
            std::cout << "WarewolfPercentage: " << player.warewolfPercentage << std::endl;
    
        } else if(rank == 5){
    
            //send the data to node 4
            game_player player;
            player.playerNameSize = 5;
            player.playerName[0] = 's';
            player.playerName[1] = 'k';
            player.playerName[2] = 'y';
            player.playerName[3] = 'l';
            player.playerName[4] = 'a';
            player.playerHealth = 100;
            player.playerMana = 100;
            player.itemListSize = 3;
            player.itemList[0] = 's';
            player.itemList[1] = 'w';
            player.itemList[2] = 'o';
            player.warewolfPercentage = 0.5;
    
            /* This is sending the data to node 4. */
            MPI_Send(&player, sizeof(player), MPI_BYTE, 4, 0, MPI_COMM_WORLD);

    }

// Receive the data from node 0
Attributes person2;
/* This is receiving the data from node 0. */
MPI_Request request;
/* This is receiving the data from node 0. */
MPI_Irecv(&person2, sizeof(person2), MPI_BYTE, 0, 0, MPI_COMM_WORLD, &request);

// Check the status of the receive operation
int flag = 0;
/* A variable that is used to store the status of the MPI_Recv function. */
MPI_Status status;
/* This is checking the status of the receive operation. */
while (!flag) {
    MPI_Test(&request, &flag, &status);
}

// Print out the received data
std::cout << "Size: " << person2.size << ", Letter: " << person2.letter << std::endl;
/* This is printing out the number, x, and y values of the person2 struct. */
std::cout << "Number: " << person2.number << ", X: " << person2.x << ", Y: " << person2.y << std::endl;
/* Printing out the list of the person2 struct. */
std::cout << "List: ";
/* This is printing out the list of the person2 struct. */
for (int i = 0; i < 15; i++) {
    std::cout << person2.list[i] << " ";
}
/* This is printing out the rank of the node that received the data successfully. */
std::cout << "Rank " << rank << " received data successfully" << std::endl;
/* Printing a new line. */
std::cout << std::endl;


    /* Shutting down the MPI environment. */
    MPI_Finalize();
   /* Returning a value of 0 to the operating system. */
    return 0;
}
