#ifndef BP_StopWatch_HH
#define BP_StopWatch_HH

#include<sys/time.h>
#include <cstddef>

// //////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////
//  BP_StopWatch class

namespace BP {

  /// \ingroup BP_useful
  class BP_StopWatch {
  private:
    double start;	//seconds
    double lap;		//seconds

  public:
    BP_StopWatch() {
      reset();
    };

    void reset() {
      set_start();
      lap = start;
    };

    void set_start() {
      start = gettime();
    };

    void set_lap() {
      lap = gettime();
    };

    double gettime() {
      timeval tim;
      gettimeofday(&tim, NULL);
      return tim.tv_sec + (tim.tv_usec / 1000000.0);
    };

    double gettime_ms() {
      timeval tim;
      gettimeofday(&tim, NULL);
      return 1000.0 * (tim.tv_sec + (tim.tv_usec / 1000000.0));
    };

    double gettime_us() {
      timeval tim;
      gettimeofday(&tim, NULL);
      return 1000000.0 * (tim.tv_sec + (tim.tv_usec / 1000000.0));
    };

    double get_us() {
      timeval tim;
      gettimeofday(&tim, NULL);
      return tim.tv_usec;
    };

    double get_s() {
      timeval tim;
      gettimeofday(&tim, NULL);
      return tim.tv_sec;
    };

    double total_time_s() {
      return gettime() - start;
    };

    double lap_time_s() {
      double new_lap = gettime();
      double lap_time = new_lap - lap;
      lap = new_lap;
      return lap_time;

    };

  };

}

#endif // BP_StopWatch_HH
