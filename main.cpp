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

    IKInstance ik_instance = kin_create_inverse_instance(Vector2D{0, 0});
    kin_inverse_add_segment(ik_instance, Vector2D{1, 0}, 5);
    kin_inverse_add_segment(ik_instance, Vector2D{0, 1}, 5);

    while (true) {
        Vector2D requested_target = request_vector();
        kin_inverse_update(ik_instance, requested_target);

        print_vector(kin_inverse_tip_position(ik_instance));
        for (auto position : kin_inverse_enumerate_segments(ik_instance)) {
            print_vector(position.root_position);
        }
    }

    kin_destroy_inverse_instance(ik_instance);
    return 0;
}