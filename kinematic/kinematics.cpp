#include "kinematics.h"

#include <ranges>
#include <vector>

struct IKInstance_T {
    std::vector<IKSegment> segments;
    Vector2D tip_position{};
};

struct KSegment_T {
    Vector2D root_position{};
    Vector2D tip_position{};
};

KSegment kin_create_segment(Vector2D root_position, Vector2D tip_position) {
    auto* instance = new KSegment_T();
    instance->root_position = root_position;
    instance->tip_position = tip_position;

    return instance;
}

IKInstance kin_create_inverse_instance(Vector2D position) {
    auto* instance = new IKInstance_T();
    instance->tip_position = position;
    return instance;
}

Vector2D kin_inverse_tip_position(IKInstance instance) {
    if (instance->segments.empty()) {
        return instance->tip_position;
    }

    return instance->tip_position;
}

bool kin_inverse_add_segment(IKInstance instance, const Vector2D direction, double length) {
    if (!vector_is_normalized(direction)) {
        return false;
    }

    const Vector2D root_position = kin_inverse_tip_position(instance);
    const Vector2D offset = vector_multiply(direction, length);
    const Vector2D tip_position = vector_add(root_position, offset);

    const auto point = IKSegment{root_position, tip_position, length};
    instance->segments.push_back(point);
    instance->tip_position = tip_position;

    return true;
}

bool kin_inverse_remove_point(IKInstance instance, const size_t index) {
    if (index < instance->segments.size()) {
        instance->segments.erase(instance->segments.begin() + index);
        return true;
    }

    return false;
}

std::vector<IKSegment> kin_inverse_enumerate_segments(IKInstance instance) {
    return instance->segments;
}

void kin_inverse_update(IKInstance instance, Vector2D target) {
    Vector2D current_target = target;

    for (int i = instance->segments.size() - 1; i >= 0; --i) {
        auto segment = instance->segments[i];

        auto direction = vector_subtract(segment.root_position, current_target);
        direction = vector_normalize(direction);

        auto offset = vector_multiply(direction, segment.length);
        const auto new_root = vector_add(current_target, offset);

        instance->segments[i].root_position = new_root;
        instance->segments[i].tip_position = current_target;

        current_target = new_root;
    }

}

void kin_destroy_inverse_instance(IKInstance instance) {
    free(instance);
}