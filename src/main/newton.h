#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>
#include <cmath>
#include <functional>

typedef std::function< double(double) > Function;

class Newton final                    
{
  public: 
    double find_root(Function f, Function df, double x, int max_iter, double tol) {
      
      double h = tol + 1.0;
      int iter = 0;

      while(std::abs(h) > tol) {

        h  = f(x)/df(x);
        x -= h;
        iter++;

        if(iter > max_iter) {
          throw std::runtime_error("Max iterations reached. Does not converge.");
        } else if (x != x) { // TODO does the current C++ standard define isnan()? Anyway, x!=x is IEEE compliant
          throw std::runtime_error("Does not converge. x = NaN");
        }
        
      } 

      return x;
    }
  private:
};

#endif // MY_CLASS_H