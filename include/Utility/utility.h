#ifndef UTILITY_H
#define UTILITY_H

enum direction {
    left,
    right,
    up,
    down
};

struct vector2f {
    float x;
    float y;

    vector2f () { x = 0; y = 0; }

    vector2f (float x, float y) {
        x = x;
        y = y;
    }

    vector2f operator +(const vector2f &other) {
        return vector2f(x + other.x, y + other.y);
    }

    vector2f operator -(const vector2f &other) {
        return vector2f(x - other.x, y - other.y);
    }

    vector2f operator *(float number) {
        return vector2f(x * number, y * number);
    }

    vector2f operator /(float number) {
        return vector2f(x / number, y / number);
    }
};

inline int stringToInt(const char *string, const int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + (string[i] - '0');
    }
    return result;
}

#endif // UTILITY_H