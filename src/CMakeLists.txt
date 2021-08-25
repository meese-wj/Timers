add_subdirectory(Timer_Base)

add_executable(timers main.cpp)

target_include_directories(timers PUBLIC Timer_Base)
target_link_libraries(timers timer_base)

