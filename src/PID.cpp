#include "PID.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;
  
  this->total_cte = 0;
  this->prev_cte = 0;
}



double PID::getMeDirection(double cte, double speed, double angle){

  using namespace std::chrono;

  if (!initialized) {
    prev_cte = cte;
    prev_t = high_resolution_clock::now();
    initialized = true;    
  }
  
  total_cte += cte;
  
  high_resolution_clock::time_point t = high_resolution_clock::now();
  duration<double, std::milli> time_span = t - prev_t;
  double delta_t = time_span.count();  
  
  double res = 0.0;
  if (delta_t > 0) {
    std::cout << "delta_t: " << delta_t << endl;
    res = -Kp*cte - Kd*(cte - prev_cte)/delta_t - Ki*total_cte;
  }
  std::cout << "RES: " << res << endl;
  
  prev_t = high_resolution_clock::now();
  prev_cte = cte;
  return std::max(-1.0, std::min(1.0, res));
}

