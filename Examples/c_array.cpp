#include <iostream>
#include <iterator> 

// This is a fixed array as input argument that passed by reference
void FixArrayPassByReference (int (&arr)[4]) {
  std::cout << "The address of the reference for the fixed array in the function is: " << &arr << std::endl;

  int length{ static_cast<int>(std::size(arr)) }; // we can now do this since the array won't decay

  for (int i{ 0 }; i < length; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return;
}

// This is a fixed array as input argument that passed by pointer
// It can also write in this way since array will decay to a pointer when pass into a function
//void FixArrayPassByPointer (int *arr, int n) {
void FixArrayPassByPointer (int arr[], int n) {
  std::cout << "The address of the pointer for the fixed array in the function is: " << &arr << std::endl;
  std::cout << "The value of the pointer for the fixed array in the function is: " << arr << std::endl;
  //std::cout << sizeof(arr) << std::endl; // warning: ‘sizeof’ on array function parameter ‘arr’ will return size of ‘int*’ 
  for (int i{ 0 }; i < 4; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return;
}

// This is a dynamic array as input argument that passed by reference
void DynArrayPassByReference (int *&arr, int n) {
  std::cout << "The address of the reference for the dynamic array in the function is: " << &arr << std::endl;
  std::cout << "The value of the reference for the dynamic array in the function is: " << arr << std::endl;
  for (int i{ 0 }; i < n; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return;
}

// This is a dynamic array as input argument that passed by pointer
void DynArrayPassByPointer (int *arr, int n) {
  std::cout << "The address of the pointer for the dynamic array in the function is: " << &arr << std::endl;
  std::cout << "The value of the pointer for the dynamic array in the function is: " << arr << std::endl;
  for (int i{ 0 }; i < n; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return;
}

int main()
{
  int fix_arr[]{ 99, 20, 14, 80 };
  std::cout << "The address of the fixed array is: " << &fix_arr << std::endl;
  FixArrayPassByReference(fix_arr);
  FixArrayPassByPointer(fix_arr, 4);

  std::cout << "\n=============================================================\n";

  int *dyn_arr { new int[4] {99, 20, 14, 80} };
  std::cout << "The address of the dynamic array is: " << &dyn_arr << std::endl;
  std::cout << "The value of the dynamic array is: " << dyn_arr << std::endl;
  DynArrayPassByReference(dyn_arr, 4);
  DynArrayPassByPointer(dyn_arr, 4);

  delete[] dyn_arr;

  return 0;
}
