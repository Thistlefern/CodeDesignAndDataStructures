#pragma once
#include <chrono>

class Stopwatch
{
    // Total number of milliseconds elapsed with this stopwatch
    std::chrono::milliseconds totalMilliseconds;
    // The time at which the stopwatch was last started
    std::chrono::high_resolution_clock::time_point lastStartTime;

    public:
        // Initialize the stopwatch
        stopwatch();
        // Start the stopwatch
        void start();
    
        // Stop the stopwatch and update the total time
        void stop();
    
        // Return a copy of the underlying count of milliseconds
        std::chrono::milliseconds elapsed();
    
        // Return the number of milliseconds recorded by this stopwatch
        double millisecondCount();
        // Return the number of seconds recorded by this stopwatch
        double secondCount();
        
        // Clear the stopwatch, zeroing out any time accumulated
        void reset();
};

