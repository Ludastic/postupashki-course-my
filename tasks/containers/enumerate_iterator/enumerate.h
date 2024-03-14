#include <cstddef>
#include <utility>


template<typename It>
class EnumerateIt{
private:
    size_t i;
    It iter;
public:
    EnumerateIt(size_t ind, It it) : i(ind), iter(it){};

    bool operator!= (const EnumerateIt &other) const {
        return iter != other.iter;
    }

    void operator++ () {
        ++i;
        ++iter;
    }

    auto operator* () const {
        return std::make_pair(i, *iter);
    }
};
template<typename It>
class Enumerate {
private:
    It Begin, End;
public:

    Enumerate(It Begin, It End) : Begin(Begin), End(End) {};

    EnumerateIt<It> begin() {
        return EnumerateIt{0, Begin};
    }

    EnumerateIt<It> end() {
        return EnumerateIt{0, End};
    }
};
