#ifndef PID_H
#define PID_H

#include <chrono>

class PID {
public:
  /*
  * Errors
  */
  double prev_cte;
  double total_cte;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  bool initialized;
  std::chrono::high_resolution_clock::time_point prev_t;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Kd, double Ki);


  double getMeDirection(double cte, double speed, double angle);
};

#endif /* PID_H */
