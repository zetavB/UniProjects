#ifndef _mpf_h_
#define _mpf_h_

#include <iostream>

using namespace std;
///@mainpage Polynomial Calculator
///@autor zetavB
///@date 20/04/18
///@par Descripcion
///A simple program to run operations on polynomials

///@class Polinomio
class Polinomio{
 public:
  Polinomio(int g);
  Polinomio(int g, float* c);
  Polinomio(const Polinomio& pol);
  virtual ~Polinomio();
  Polinomio* operator+(const Polinomio& pol);
  Polinomio* operator-(const Polinomio& pol);
  Polinomio* operator*(const Polinomio& pol);
  Polinomio* operator/(const Polinomio& pol);
  void operator~();
 private:
  /// @var int gra
  /// @brief Contains the degree of the polynomial
  int gra;
  /// @var float* coe
  /// @brief Contains an array of floats which house the coeficcients
  float* coe;
};

#endif
