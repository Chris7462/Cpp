#include <iostream>
#include <omp.h>

using namespace std;

int main(){
	int i;
	int x = 100;
#pragma omp parallel for private(x) 
//#pragma omp parallel for lastprivate(x) 
//#pragma omp parallel for firstprivate(x) 
	for( i = 0 ; i < 10 ; i++ ){
		x = i;
#pragma omp critical (out)
    cout << "Thread number: " << omp_get_thread_num() << ", x = " << x << endl;
	}
  cout << "x = " << x << endl;

	return 0;
}

