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

	int token = 1;
  int left = rank-1;
  int right = rank+1;
  if (left < 0 ){
    left = size-1;
  }
  if (right >= size){
    right = 0;
  }

  if (rank%2 == 0){
    MPI_Send(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD);
    MPI_Recv(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  } else {
    MPI_Recv(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();

  return 0;
}
