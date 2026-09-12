#pragma once
#include <cmath>

struct Vector2D {
    double x, y;
};

inline double vector_length_squared(const Vector2D& vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

inline double vector_length(const Vector2D& vector) {
    return sqrt(vector_length_squared(vector));
}

inline Vector2D vector_divide(const Vector2D& vector, double x) {
    return Vector2D(vector.x / x, vector.y / x);
}

inline Vector2D vector_multiply(const Vector2D& vector, double x) {
    return Vector2D(vector.x * x, vector.y * x);
}

inline Vector2D vector_normalize(const Vector2D& vector) {
    if (vector_length_squared(vector) == 0) {
        return vector;
    }

    return vector_divide(vector, vector_length(vector));
}

inline Vector2D vector_add(const Vector2D& a, const Vector2D& b) {
    return Vector2D(a.x + b.x, a.y + b.y);
}

inline Vector2D vector_subtract(const Vector2D& a, const Vector2D& b) {
    return Vector2D(a.x - b.x, a.y - b.y);
}

inline bool vector_is_normalized(const Vector2D& vector) {
    return std::abs(vector_length_squared(vector) - 1) < 0.000001;
}