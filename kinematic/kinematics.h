#pragma once

#include <vector>
#include "../vector2d.h"

struct IKSegment {
    Vector2D root_position;
    Vector2D tip_position;
    double length;
};

typedef struct KSegment_T* KSegment;
typedef struct IKInstance_T* IKInstance;

KSegment kin_create_segment(
    Vector2D position,
    Vector2D direction,
    double length);

IKInstance kin_create_inverse_instance(
    Vector2D position);

Vector2D kin_inverse_tip_position(
    IKInstance instance);

bool kin_inverse_add_segment(
    IKInstance instance,
    Vector2D direction,
    double length);

bool kin_inverse_remove_point(
    IKInstance instance,
    size_t index);

std::vector<IKSegment> kin_inverse_enumerate_segments(
    IKInstance instance);

void kin_inverse_update(
    IKInstance instance,
    Vector2D target);

void kin_destroy_inverse_instance(
    IKInstance instance);