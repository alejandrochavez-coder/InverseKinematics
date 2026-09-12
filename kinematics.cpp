#include "kinematics.h"
#include <vector>

struct IKInstance_T {
    std::vector<IKPoint> points;
    Vector2D anchor{};
};

IKInstance kin_create_inverse_instance(const Vector2D anchor) {
    auto* instance = new IKInstance_T();
    instance->anchor = anchor;
    return instance;
}

Vector2D kin_inverse_tip(IKInstance instance) {
    if (instance->points.empty()) {
        return instance->anchor;
    }

    return instance->points.front().position;
}

bool kin_inverse_add_point(IKInstance instance, const Vector2D direction, double length) {
    if (!vector_is_normalized(direction)) {
        return false;
    }

    const Vector2D tip = kin_inverse_tip(instance);
    const Vector2D offset = vector_multiply(direction, length);
    const Vector2D position = vector_add(tip, offset);

    const auto point = IKPoint{position, length};
    instance->points.push_back(point);

    return true;
}

bool kin_inverse_remove_point(IKInstance instance, const size_t index) {
    if (index < instance->points.size()) {
        instance->points.erase(instance->points.begin() + index);
        return true;
    }

    return false;
}

std::vector<IKPoint> kin_inverse_enumerate_points(IKInstance instance) {
    return instance->points;
}

std::vector<Vector2D> kin_inverse_enumerate_positions(IKInstance instance) {
    std::vector<Vector2D> positions;
    positions.reserve(instance->points.size() + 1);

    positions.emplace_back(instance->anchor);

    for (const auto& point : instance->points) {
        positions.emplace_back(point.position);
    }

    return positions;
}

void kin_destroy_inverse_instance(IKInstance instance) {
    free(instance);
}