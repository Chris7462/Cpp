#include <iostream>
#include <omp.h>

using namespace std;

int main(){
  int thread_id;
  cout << "I am the main thread." << endl;

#pragma omp parallel private(thread_id)
  {
    thread_id = omp_get_thread_num();
#pragma omp critical
    cout << "Thread " << thread_id << ": Hello" << endl;
    //cout << thread_id << endl;
#pragma omp barrier
#pragma omp critical
    cout << "Thread " << thread_id << ": Bye bye." << endl;
  }

  cout << "I am the main thread" << endl;

  return 0;
}
