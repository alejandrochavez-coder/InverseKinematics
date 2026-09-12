#pragma once

#include <vector>
#include "vector2d.h"

struct IKPoint {
    Vector2D position;
    double length;
};

typedef struct IKInstance_T* IKInstance;

IKInstance kin_create_inverse_instance(
    Vector2D anchor);

Vector2D kin_inverse_tip(
    IKInstance instance);

bool kin_inverse_add_point(
    IKInstance instance,
    Vector2D direction,
    double length);

bool kin_inverse_remove_point(
    IKInstance instance,
    size_t index);

std::vector<IKPoint> kin_inverse_enumerate_points(
    IKInstance instance);

void kin_destroy_inverse_instance(
    IKInstance instance);