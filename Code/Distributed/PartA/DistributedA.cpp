#include <iostream>
#include <mpi.h>
#include <cstring>
#include <omp.h>
#include <unistd.h>
#include <sys/sysinfo.h>

using namespace std;

int main(){

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the rank and size of the MPI process
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the name of the node that the MPI process is running on
    char node_name[MPI_MAX_PROCESSOR_NAME];
    int namelen;
    MPI_Get_processor_name(node_name, &namelen);
    memset(node_name+namelen,0,MPI_MAX_PROCESSOR_NAME-namelen);

    int dest = 1; // Rank of the destination process
    int src = 0; // Rank of the source process

    // Send a message from the source process to the destination process
    if (rank == src) {
        int send_num = 5; // The integer to be senz
        int send_result = MPI_Send(&send_num, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
        if (send_result != MPI_SUCCESS) {
            std::cerr << "Error sending message from rank " << src << " to rank " << dest << std::endl;
        }
        else {
            std::cout << "> " << node_name << " Sent " << send_num << " to node " << dest << std::endl;
        }
    }

    // Receive the message from the source process
    if (rank == dest) {
        std::cout << "Hello from " << node_name << std::endl;
        int received; // The received integer
        MPI_Status status;
        int recv_result = MPI_Recv(&received, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        if (recv_result != MPI_SUCCESS) {
            std::cerr << "Error receiving message by rank " << dest << std::endl;
        }
        else {
            int sender = status.MPI_SOURCE;
            std::cout << "> Number: " << received << " received from node " << sender << " by " << node_name << std::endl;
        }
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;

}
