#include <iostream>
#include "vector2d.h"
#include "kinematics.h"

Vector2D request_vector(const std::string& prompt = "Enter vector x, y: ") {
    double x, y;
    std::cout << prompt;
    std::cin >> x >> y;

    return Vector2D(x, y);
}

void print_vector(const Vector2D& vector) {
    std::cout << vector.x << ", " << vector.y << std::endl;
}

bool request_exit(const std::string& prompt = "Want to exit? : ") {
    bool x;
    std::cout << prompt;
    std::cin >> x;
    return !x;
}

int main() {
    auto anchor = Vector2D{0, 0};

    IKInstance ik_instance = kin_create_inverse_instance(anchor);
    kin_inverse_add_point(ik_instance, Vector2D{1, 0}, 5);

    auto positions = kin_inverse_enumerate_positions(ik_instance);
    for (auto position : positions) {
        std::cout << "(" << position.x << ", " << position.y << ")" << std::endl;
    }

    kin_destroy_inverse_instance(ik_instance);
    return 0;
}