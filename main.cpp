// #include <iostream>
// #include "vector2d.h"
// #include "kinematics.h"

// Vector2D request_vector(const std::string& prompt = "Enter vector x, y: ") {
//     double x, y;
//     std::cout << prompt;
//     std::cin >> x >> y;

//     return Vector2D(x, y);
// }

// void print_vector(const Vector2D& vector) {
//     std::cout << vector.x << ", " << vector.y << std::endl;
// }

// bool request_exit(const std::string& prompt = "Want to exit? : ") {
//     bool x;
//     std::cout << prompt;
//     std::cin >> x;
//     return !x;
// }

// int main() {
//     auto anchor = Vector2D{0, 0};

//     IKInstance ik_instance = kin_create_inverse_instance(Vector2D{0, 0});
//     kin_inverse_add_segment(ik_instance, Vector2D{1, 0}, 5);
//     kin_inverse_add_segment(ik_instance, Vector2D{0, 1}, 5);

//     while (true) {
//         Vector2D requested_target = request_vector();
//         kin_inverse_update(ik_instance, requested_target);

//         print_vector(kin_inverse_tip_position(ik_instance));
//         for (auto position : kin_inverse_enumerate_segments(ik_instance)) {
//             print_vector(position.root_position);
//         }
//     }

//     kin_destroy_inverse_instance(ik_instance);
//     return 0;
// }

#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <variant>

typedef struct {
    double x, y, z;
} Velocity, Position;

struct VelocityPosition {
    Velocity velocity;
    Position position;
}; 

void velocity_system(Velocity& velocity, Position& position) {
    position.x += velocity.x;
    position.y += velocity.y;
    position.z += velocity.z;
}

typedef int ID;

int main() {
    std::vector<VelocityPosition> velocity_positions;
    
    Velocity v{};
    Position p{};

    VelocityPosition velocity_position {};
    velocity_position.velocity = v;
    velocity_position.position = p;

    velocity_positions.push_back(velocity_position);

    for (auto& velocity_position : velocity_positions) {
        velocity_system(velocity_position.velocity, velocity_position.position);
    }

    return 0;
}