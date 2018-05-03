#include "polinomio.h"
#include <cstdio>

Polinomio :: Polinomio(int g){
   ///@brief Empty Polynomial Constructor
  ///@detail Creates a Polinomio type object with 0 in every coeficcient
  ///@param g Degree of the Polynomial
  
  this->gra = g;
  this->coe = new float[g+1];
  for(int i = 0; i <= g; i++){
    this->coe[i] = 0;
  }
}

Polinomio :: Polinomio(int g, float* c){
  ///@brief Polynomial Constructor
  ///@detail Creates a polynomial with the give coeficcients
  ///@param g Degree of the Polynomial
  ///@param c Un array of floats that will become the coeficcients
  this->gra = g;
  this->coe = c;
}

Polinomio :: Polinomio(const Polinomio& pol){
  ///@brief Copy Constructor
  ///@detail Copies a Polinomio type object onto another
  ///@param pol Reference to they polynomial to be copied
  this->gra = pol.gra;
  this->coe = new float[this->gra + 1];
  for(int i = 0;  i <= this->gra; i++){
    pol.coe[i] = this->coe[i];
  }
}

Polinomio :: ~Polinomio(){
  ///@brief Polynomial Destructor
}

Polinomio* Polinomio :: operator+(const Polinomio& pol){
  ///@brief Overload of + operator
  ///@detail Adds two polynomials
  ///@param pol Reference to the polynomial that will be added
  ///@return A pointer to the resulting polynomial
  Polinomio* nulo = new Polinomio(0);
  if(this->gra > pol.gra){
    int diff = (this->gra - pol.gra);
    Polinomio* result = new Polinomio(this->gra);
    
    for(int i = 0; i <= this->gra; i++){
      if(i < diff){
	result->coe[i] = this->coe[i];
      }else{
	result->coe[i] = this->coe[i] + pol.coe[(i - diff)];
      }
    }
    delete nulo;
    return result;
  }else if(this->gra < pol.gra){
    int diff = (pol.gra - this->gra);
    Polinomio* result = new Polinomio(pol.gra);

    for(int i = 0; i <= pol.gra; i++){
      if(i < diff){
	result->coe[i] = pol.coe[i];
      }else{
	result->coe[i] = pol.coe[i] + this->coe[(i - diff)];
      }
    }
    delete nulo;
    return result;
  }else if(this->gra == pol.gra){
    Polinomio* result = new Polinomio(this->gra);

    for(int i =0; i <= this->gra; i++){
      result->coe[i] = this->coe[i] + pol.coe[i];
    }
    delete nulo;
    return result;
  }
  return nulo;
}

Polinomio* Polinomio :: operator-(const Polinomio& pol){
  ///@brief Overload of - Operator
  ///@detail Subtracts two polynomials
  ///@param pol Reference to the polynomial that will be subtracted
  ///@return A pointer to the resulting polynomial

  Polinomio* result = new Polinomio(this->gra);
  Polinomio* temp = new Polinomio(pol.gra);

  for(int i = 0; i <= pol.gra; i++){
    temp->coe[i] = -pol.coe[i];
  }
  result = *this + *temp;
  delete temp;
  return result;
}

Polinomio* Polinomio :: operator*(const Polinomio& pol){
  ///@brief Overload of * Operator
  ///@detail Multiplies two polynomials
  ///@param pol Reference to the polynomial that multiplies
  ///@return A pointer to the resulting polynomial
  
  Polinomio* result = new Polinomio((this->gra + pol.gra));
  for(int i = 0; i <= this->gra; i++){
    for(int j = 0; j <= pol.gra; j++){
      result->coe[i + j] += this->coe[i] * pol.coe[j];
    }
  }
  return result;
}

Polinomio* Polinomio :: operator/(const Polinomio& pol){
  ///@brief Overload of / Operator
  ///@detail Divides two polynomials through long division
  ///@param pol Reference to the dividing polynomial
  ///@return A pointer to the resulting polynomial

  Polinomio* nulo = new Polinomio(0);
  if(this->gra < pol.gra){
    return nulo;
  }else{
    int diff = this->gra - pol.gra;
    Polinomio* result = new Polinomio(diff);
    Polinomio* trabajo0 = new Polinomio(this->gra);
    Polinomio* trabajo1 = new Polinomio(this->gra);
    Polinomio* holder = new Polinomio(diff);
    Polinomio* polCopia = new Polinomio(pol.gra);
    int i;
    
    for(i = 0; i <= diff; i++){
      if(i == 0){
	result->coe[0] = this->coe[0] / pol.coe[0];
	trabajo0 = *result * pol;
	trabajo0 = *this - *trabajo0;
      }else if(i % 2 != 0){
	result->coe[i] = trabajo0->coe[i] / pol.coe[0];
	holder->coe[i] = result->coe[i];
	trabajo1 = *holder * pol;
	trabajo1 = *trabajo0 - *trabajo1;
	holder->coe[i] = 0;
      }else if(i % 2 == 0){
	result->coe[i] = trabajo1->coe[i] / pol.coe[0];
	holder->coe[i] = result->coe[i];
	trabajo0 = *holder * pol;
	trabajo0 = *trabajo1 - *trabajo0;
	holder->coe[i] = 0;
      }
    }
    for(int j = 0; j <= pol.gra; j++){
      polCopia->coe[j] = pol.coe[j];
    }
    cout << "Remainder: " << endl;
    if(i % 2 == 0){
      ~*trabajo1;
      cout << "---------------------------------------------------------------------" << endl;
      ~*polCopia;
    }else{
      ~*trabajo0;
      cout << "---------------------------------------------------------------------" << endl;
      ~*polCopia;
    }
    cout << endl;
    delete trabajo0;
    delete trabajo1;
    delete holder;
    delete polCopia;
    delete nulo;
    return result;
  }
  return nulo;
}

void Polinomio :: operator~(){
  ///@brief Overload of ~ Operator
  ///@detail Prints the polynomial in standard notation

  for(int i = 0; i <= this->gra; i++){
    if(i == this->gra){
      cout << this->coe[i] << endl;
    }else{
      cout << this->coe[i] << "x^" << (this->gra - i) << " + ";
    }
  }
}
