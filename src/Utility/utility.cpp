#include "utility.h"

int getRandomNumber(int lowerBound, int upperBound) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
    return  distribution(generator);
}

vector2f normalize(vector2f vector) {
    // Length of vector: |V| = sqrt(V.x^2 + V.y^2)
    // Normalize vector: |V| = V / |V|
    float len = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

    // If length of vector is zero
    if (!len) return vector;

    vector2f normal = vector / len;

    return normal;
}

vector2f truncate(vector2f vector, float max) {
    vector2f truncated = vector;

    float len = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
    if (len > max) {
        truncated = normalize(vector);
        truncated *= max;
    }

    return truncated;
}

float deg2rad(float deg) {
    return deg * M_PI / 180.0;
}