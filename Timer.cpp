#include "Timer.h"



Timer::Timer(const std::string& name)
    : m_name(name), m_started(false), m_stopped(false) {}

void Timer::start() {
    m_started = true;
    m_stopped = false;
    m_start = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    if (m_started && !m_stopped) {
        m_end = std::chrono::high_resolution_clock::now();
        m_stopped = true;
    }
}

void Timer::print() const {
    if (m_started && m_stopped) {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
        std::cout << m_name << " took: " << duration << " ms" << std::endl;
    } else {
        std::cerr << "Timer " << m_name << " was not properly started/stopped." << std::endl;
    }
}
