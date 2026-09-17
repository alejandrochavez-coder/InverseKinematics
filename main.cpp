#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <variant>
#include "vector2d.h"
#include <typeindex>
#include <set>

struct Segment {
	Vector2D start;
	Vector2D end;
};

struct Container {
	int id;
};

struct ContainerManager {
	std::unordered_map<std::type_index, void*> a;
};

template <typename... Components>
struct Archeotype {

};

template <typename T>
void container_add_component(ContainerManager& manager, T component) {
	
}

template <typename... Queried>
Archeotype<Queried...> manager_get_archeotype(Queried... queries) {

}



template <typename... Queried>
std::vector<std::tuple<Queried...>> container_query(ContainerManager& manager) {
	std::vector<std::tuple<Queried...>> data{};
	Archeotype archeotype = manager_get_archeotype(Queried...);
}

int main() {
	ContainerManager manager{};


    std::vector<Segment> segments;


    Segment first{};
	first.start = Vector2D{0, 0};
	first.end = Vector2D{ 10, 10 };

    segments.push_back(first);

	for (const auto& [segment] : container_query<Segment>(manager)) {
		
	}

	while (true) {

		for (const auto& segment : segments) {
			std::cout << "PEPE";
		}
	}

    return 0;
}