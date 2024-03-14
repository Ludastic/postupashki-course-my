#pragma once

#include <cassert>

class RangeIt {
private:
    int position = 0, step = 1;
public:

    RangeIt(int p, int s) : position(p), step(s) {}


    //operators
    RangeIt &operator++() {
        position += step;
        return *this;
    }
    RangeIt operator++(int) {
        RangeIt temp {*this};
        operator++();
        return temp;
    }

    bool operator!=(const RangeIt &other) const {
        return (step < 0) ? position > other.position : position < other.position;
    }

    const int &operator*() const {
        return position;
    }
};

class Range {
private:
    int start=0, End, step=1;
public:
    Range(int start, int end, int step) : start(start), End(end), step(step) {
        assert(step!=0);
    };

    Range(int start, int end) : start(start), End(end) {};

    Range(int end) : End(end) {};

    RangeIt begin() const {
        return RangeIt(start, step);
    }

    RangeIt end() const {
        return RangeIt(End, step);
    }
};
