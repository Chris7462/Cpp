#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
	// Initialize the MPI environment
	MPI_Init(&argc,&argv);
	// Find out rank, size
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int token = -1;
	// Receive from the lower process and send to the higher process. Take care
	// of the special case when you are the first process to prevent deadlock.
	if (rank != 0) {
    //MPI_Recv (&buf,count,datatype,source,tag,comm,&status) 
		MPI_Recv(&token, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process %d received token %d from process %d\n", rank, token, rank-1);
	} else {
		// Set the token's value if you are process 0
		token = -1;
	}
  //MPI_Send (&buf,count,datatype,dest,tag,comm) 
	MPI_Send(&token, 1, MPI_INT, (rank+1)%size, 0,MPI_COMM_WORLD);
	// Now process 0 can receive from the last process. This makes sure that at
	// least one MPI_Send is initialized before all MPI_Recvs (again, to prevent
	// deadlock)
	if (rank == 0) {
		MPI_Recv(&token, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process %d received token %d from process %d\n", rank, token,size-1);
	}
	MPI_Finalize();

	return 0;
}
