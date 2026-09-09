#include <cmath>
#include <iostream>
#include <cmath>
#include <vector>

struct Vector2 {
    double x, y;
};

double vector_length_sqr(const Vector2& vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

double vector_length(const Vector2& vector) {
    return sqrt(vector_length_sqr(vector));
}

Vector2 vector_normalize(const Vector2& vector) {
    if (vector_length_sqr(vector) == 0.0) {
        return Vector2(0.0, 0.0);
    }

    const double length = vector_length(vector);
    return Vector2(vector.x / length, vector.y / length);
}

Vector2 vector_add(const Vector2& a, const Vector2& b) {
    return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 vector_multiply(const Vector2& a, double b) {
    return Vector2(a.x * b, a.y * b);
}

Vector2 vector_request(const std::string& prompt = "Enter vector x, y: ") {
    double x, y;
    std::cout << prompt;
    std::cin >> x >> y;

    return Vector2(x, y);
}

void vector_print(const Vector2& vector) {
    std::cout << vector.x << ", " << vector.y << std::endl;
}

bool request_exit(const std::string& prompt = "Want to exit? : ") {
    bool x;
    std::cout << prompt;
    std::cin >> x;
    return !x;
}

Vector2 vector_subtract(const Vector2& a, const Vector2& b) {
    return Vector2(a.x - b.x, a.y - b.y);
}

int main() {
    int joins_number;
    int joins_length = 1;
    std::cout << "Enter the number of joints: ";
    std::cin >> joins_number;

    const auto start_direction = vector_normalize(Vector2(-1, 1));

    Vector2 anchor{0, 0};
    std::vector<Vector2> points;

    // for (int i = 0; i < joins_number; i++) {
    //     const auto offset = vector_multiply(direction, (i + 1) * joins_length);
    //     const auto point = vector_add(anchor, offset);
    //     points.push_back(point);
    // }

    for (int i = joins_number; i >= 1; i--) {
        const auto offset = vector_multiply(start_direction, i * joins_length);
        const auto point = vector_add(anchor, offset);
        points.push_back(point);
    }

    bool should_continue = true;

    while (should_continue) {
        Vector2 requested_target = vector_request("Target position x, y: ");
        Vector2 direction = vector_subtract(points[0], requested_target);
        direction = vector_normalize(direction);

        points[0] = vector_multiply(direction, joins_length);

        for (int i = 1; i < points.size(); i++) {
            const auto current = points[i];
            const auto target = points[i - 1];

            Vector2 current_direction = vector_subtract(current, target);
            current_direction = vector_normalize(current_direction);

            points[i] = vector_multiply(current_direction, joins_length);
        }

        Vector2 offset = vector_subtract(points[points.size() - 1], anchor);
        offset = vector_normalize(offset);
        offset = vector_multiply(offset, joins_length);

        offset = vector_subtract(offset, points[points.size() - 1]);

        for (auto & point : points) {
            point = vector_add(point, offset);
            vector_print(point);
        }
        
        should_continue = request_exit();
    }

    // Vector2 target = vector_request("Target position x, y: ");
    //
    // for (int i = points.size() - 1; i >= 0; i--) {
    //     const auto current = points[i];
    // }

    return 0;
}