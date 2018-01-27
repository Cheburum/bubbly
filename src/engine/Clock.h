#ifndef BUBBLY_CLOCK_H
#define BUBBLY_CLOCK_H

namespace Bubbly {
    class Clock {
    private:
        double start_time;
    public:
        Clock();

        void restart();

        double getElapsedTime() const;
    };
}

#endif
