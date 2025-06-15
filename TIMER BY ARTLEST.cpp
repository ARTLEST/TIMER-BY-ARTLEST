/*
 * Simple Countdown Timer Implementation
 * Basic C++ timer with visual countdown display
 * Code hints and optimizations by artlest
 * 
 * This creates a simple countdown timer that counts down from
 * a specified number of seconds with visual display updates.
 */

#include <iostream>
#include <ctime>

// This function displays the timer application header
void display_timer_header() {
    std::cout << "================================\n";
    std::cout << "    SIMPLE COUNTDOWN TIMER\n";
    std::cout << "================================\n\n";
}

// This function creates a one-second delay using CPU cycles
void wait_one_second() {
    clock_t start_time = clock();
    clock_t end_time = start_time + CLOCKS_PER_SEC;
    
    while (clock() < end_time) {
        // This creates a busy-wait loop for one second
    }
}

// This function displays the current countdown value with formatting
void display_countdown(int seconds_remaining) {
    // This calculates minutes and seconds for better display
    int minutes = seconds_remaining / 60;
    int seconds = seconds_remaining % 60;
    
    // This clears the current line and displays the countdown
    std::cout << "\r";  // This moves cursor to beginning of line
    std::cout << "Time Remaining: ";
    
    if (minutes > 0) {
        std::cout << minutes << "m ";
    }
    
    std::cout << seconds << "s ";
    
    // This adds visual bars to show progress
    int total_bars = 20;
    int filled_bars = (seconds_remaining > 0) ? (seconds_remaining % total_bars) : 0;
    
    std::cout << "[";
    for (int i = 0; i < total_bars; i++) {
        if (i < filled_bars) {
            std::cout << "#";
        } else {
            std::cout << "-";
        }
    }
    std::cout << "]";
    
    std::cout.flush();  // This ensures immediate display
}

// This function runs the main countdown timer
void run_countdown_timer(int total_seconds) {
    std::cout << "Starting countdown from " << total_seconds << " seconds...\n";
    std::cout << "Press Ctrl+C to stop the timer\n\n";
    
    // This loops through each second of the countdown
    for (int current_second = total_seconds; current_second >= 0; current_second--) {
        display_countdown(current_second);
        
        if (current_second > 0) {
            wait_one_second();
        }
    }
    
    std::cout << "\n\n";
}

// This function displays the completion message
void display_completion_message() {
    std::cout << "*** TIMER COMPLETED! ***\n";
    std::cout << "Time's up!\n\n";
    
    // This creates a simple alert pattern
    for (int i = 0; i < 3; i++) {
        std::cout << "BEEP! ";
        
        // This creates a short delay for the beep effect
        clock_t beep_start = clock();
        clock_t beep_end = beep_start + (CLOCKS_PER_SEC / 4);  // Quarter second
        while (clock() < beep_end) {
            // Short delay for beep timing
        }
    }
    std::cout << "\n";
}

// This function gets user input for timer duration
int get_timer_duration() {
    int seconds;
    
    std::cout << "Enter timer duration:\n";
    std::cout << "Seconds (1-3600): ";
    std::cin >> seconds;
    
    // This validates the input range
    if (seconds < 1) {
        seconds = 1;
        std::cout << "Minimum 1 second, setting to 1 second.\n";
    } else if (seconds > 3600) {
        seconds = 3600;
        std::cout << "Maximum 1 hour, setting to 3600 seconds.\n";
    }
    
    std::cout << "\n";
    return seconds;
}

// This function displays timer statistics
void display_timer_stats(int duration_seconds) {
    int minutes = duration_seconds / 60;
    int remaining_seconds = duration_seconds % 60;
    
    std::cout << "TIMER STATISTICS\n";
    std::cout << "================\n";
    std::cout << "Total Duration: ";
    
    if (minutes > 0) {
        std::cout << minutes << " minute(s) ";
    }
    if (remaining_seconds > 0) {
        std::cout << remaining_seconds << " second(s)";
    }
    
    std::cout << "\nTimer Type: Countdown\n";
    std::cout << "Status: Completed Successfully\n\n";
}

// This is the main program entry point
int main() {
    display_timer_header();
    
    // This gets the timer duration from user
    int timer_seconds = get_timer_duration();
    
    // This runs the actual countdown timer
    run_countdown_timer(timer_seconds);
    
    // This shows completion message and stats
    display_completion_message();
    display_timer_stats(timer_seconds);
    
    std::cout << "================================\n";
    std::cout << "     TIMER SESSION COMPLETE\n";
    std::cout << "================================\n";
    
    return 0;
}