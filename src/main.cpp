#include <iostream>
#include <timer_base.hpp>

int main(const int argc, const char * argv [])
{
    Timers::Timer test_timer = Timers::Timer();
    test_timer.print_total_duration(true);
    return 0;
}