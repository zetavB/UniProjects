#include "polinomio.h"

int main(){
  int gra1;
  int gra2;
  cout << "Please enter the degree of your first polynomial: " << endl;
  cin >> gra1;
  float *arr1 = new float[gra1 + 1];
  for(int i = 0; i < gra1+1; i++){
    cout << "Please enter value " << i <<": " << endl;
    cin >> arr1[i];
  }
  cout << "Please enter the degree of your second polynomial: " << endl;
  cin >> gra2;
  float *arr2 = new float[gra2+1];
  for(int i = 0; i < gra2+1; i++){
    cout << "Please enter value " << i <<": " << endl;
    cin >> arr2[i];
  }
  
  
  Polinomio* test = new Polinomio(gra1, arr1);
  Polinomio* test2 = new Polinomio(gra2, arr2);
  Polinomio* test3 = new Polinomio(0);
  
  cout << "First Polynomial: " << endl;
  ~*test;
  cout << "Second Polynomial: " << endl;
  ~*test2;

  cout << "Addition: " << endl;
  test3 = *test + *test2;
  ~*test3;

  cout << "Subtraction: " << endl;
  test3 = *test - *test2;
  ~*test3;
  
  cout << "Multiplication: " << endl;
  test3 = *test * *test2;
  ~*test3;

   cout << "Division: " << endl;
  test3 = *test / *test2;
  ~*test3;
  
  delete test;
  delete test2;
  delete test3;
}
