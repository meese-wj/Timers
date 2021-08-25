/* This is the implementation of the timer base class. */
#include "timer_base.hpp"
#include <iostream>
#include <chrono>

namespace Timers
{
    // Helper function definitions.
    void get_time( time_point & time_pt )
    {
        time_pt = std::chrono::high_resolution_clock::now();
    }

    /* ====================================================================== */
    // Definition of base timer functions.
    Timer::Timer()
    {
        get_time(timer_creation);
    }

    Timer::~Timer()
    {
        // intentionally empty
    }

    void Timer::start_timer()
    {
        get_time(timer_start);
    }

    void Timer::stop_timer()
    {
        get_time(timer_end);
    }

    void Timer::current_time()
    {
        get_time(timer_current);
    }

    void Timer::timed_duration()
    {
        stop_timer();
        time_elapsed = timer_end - timer_start;
    }
    
    void Timer::total_duration()
    {
        stop_timer();
        time_elapsed = timer_end - timer_creation;
    }

    void Timer::print_time( bool verbose )
    {
        current_time();
        const std::time_t current = std::chrono::system_clock::to_time_t(timer_current);
        if (verbose)
        {
            std::cout << "Current time is: " << std::ctime(&current);
            return;
        }
        std::cout << std::ctime(&current);
    }

    void Timer::print_duration( bool verbose )
    {
        timed_duration();
        if (verbose)
        {
            std::cout << "Timed duration: " << time_elapsed.count() << " seconds.";
            return;
        }
        std::cout << time_elapsed.count();
    }
    
    void Timer::print_total_duration( bool verbose )
    {
        total_duration();
        if (verbose)
        {
            std::cout << "Total timed duration: " << time_elapsed.count() << " seconds.";
            return;
        }
        std::cout << time_elapsed.count();
    }

}