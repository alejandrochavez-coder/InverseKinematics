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

// struct ContainerManager {
// 	std::unordered_map<std::type_index, void*> a;
// };

// template <typename... Components>
// struct Archeotype {

// };

// template <typename T>
// void container_add_component(ContainerManager& manager, T component) {
	
// }

// template <typename... Queried>
// Archeotype<Queried...> manager_get_archeotype(Queried... queries) {

// }

// template <typename... Queried>
// std::vector<std::tuple<Queried...>> container_query(ContainerManager& manager) {
// 	std::vector<std::tuple<Queried...>> data{};
// 	Archeotype archeotype = manager_get_archeotype(Queried...);
// }

struct Entity {
	// std::vector<void*> components;
	int id;
};

struct ComponentKey {
	size_t size;
	int id;
};

struct EntityManager {
	std::vector<Entity> entities;
	std::unordered_map<int, void*> components;
	int current_id;
	int current_component_key_id;
};

Entity manager_create_entity(EntityManager& manager) {
	Entity entity{manager.current_id};
	manager.components[entity.id] = {};
	manager.current_id++;

	return entity;
}

template <typename T>
ComponentKey manager_register_component(EntityManager& manager) {
	return {typeid(T).hash_code(), sizeof(T)}
}

// void manager_set_component(EntityManager& manager) {
	
// }

int main() {
	EntityManager manager{};
	Entity entity = manager_create_entity(manager);

	std::cout << manager.current_id;

	while (true) {

	}

    return 0;
}