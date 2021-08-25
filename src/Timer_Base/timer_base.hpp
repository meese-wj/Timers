#ifndef TIMER_BASE
#define TIMER_BASE
/* This is the header file for the timer base class.
 * These objects are meant to be inherited by 
 * specialized instances of timers.
 */
#include <chrono>
#include <ctime>

namespace Timers
{
    using time_float = double;
    using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;
    using duration   = std::chrono::duration<time_float>;

    void get_time( time_point & time_pt );

    class Timer
    {
        public:
            Timer();
            virtual ~Timer();
            void start_timer();
            virtual void stop_timer();
            virtual void current_time();
            virtual void timed_duration();
            virtual void total_duration();
            virtual void print_time( bool verbose = false );
            virtual void print_duration( bool verbose = false );
            virtual void print_total_duration( bool verbose = false );
        
        protected:
            time_point timer_creation;
            time_point timer_start;
            time_point timer_end;
            time_point timer_current;
            duration   time_elapsed;
    };
}
#endif // TIMER_BASE