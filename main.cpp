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
#include <raylib.h>
#include <raymath.h>
#include "vector2d.h"

struct Segment {
	Vector2D start;
	Vector2D end;
};

struct Physics {
	Vector2D gravity;
};

struct Drawable {};

static void draw_segment(const Segment& segment) {
	Vector2 anchor = {
		GetScreenWidth() / 2.0,
		GetScreenHeight() / 2.0
	};

	Vector2 start = { static_cast<float>(segment.start.x), static_cast<float>(segment.start.y) };
	Vector2 end = { static_cast<float>(segment.end.x), static_cast<float>(segment.end.y) };
	start = Vector2Add(start, anchor);
	end = Vector2Add(end, anchor);

	DrawLineEx(start, end, 2, BLACK);
}

int main() {
	InitWindow(800, 600, "Kinematics Simulation");
    std::vector<Segment> segments;

    Segment first{};
	first.start = Vector2D{0, 0};
	first.end = Vector2D{ 10, 10 };

    segments.push_back(first);

	while (true) {
		if (WindowShouldClose()) {
			CloseWindow();
			break;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (const auto& segment : segments) {
			draw_segment(segment);
		}

		EndDrawing();
	}

    return 0;
}