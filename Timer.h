#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer {
public:
    Timer(const std::string& name);
    void start();
    void stop();
    void print() const;

private:
    std::string m_name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_end;
    bool m_started;
    bool m_stopped;
};

#endif
