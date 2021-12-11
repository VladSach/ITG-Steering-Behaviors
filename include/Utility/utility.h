#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/Graphics.hpp>

#include <cmath>
#include <random>

enum direction {
    left,
    right,
    up,
    down
};

typedef float time64;
typedef sf::Vector2f vector2f;

/*
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
*/

int getRandomNumber(int upperBound, int lowerBound);

vector2f normalize(vector2f vector);
vector2f truncate(vector2f vector, float max);
float deg2rad(float deg);

inline int stringToInt(const char *string, const int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + (string[i] - '0');
    }
    return result;
}

#endif // UTILITY_H