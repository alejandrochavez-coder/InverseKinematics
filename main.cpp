#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <variant>
#include "vector2d.h"
#include <typeindex>
#include <set>
#include <any>

struct Information {
	int info;
};

struct Entity {
	int id;
};

struct EntityManager {
	std::vector<std::vector<std::any>> components;
	int current_id;
};

Entity manager_create_entity(EntityManager& manager) {
	int id = manager.current_id;

	Entity entity{id};
	manager.components.emplace_back();
	manager.current_id++;

	return entity;
}

template <typename T>
void entity_add_component(EntityManager& manager, Entity entity) {
    manager.components[entity.id].push_back(T{});
}

template <typename T>
T* entity_get_component(EntityManager& manager, Entity entity) {
	auto& components = manager.components[entity.id];

	for (auto& component : components) {
		if (component.type() == typeid(T)) {
			return &std::any_cast<T&>(component);
		}
	}

	return nullptr;
}

template <typename T>
std::vector<T*> manager_query_component(EntityManager& manager) {
	std::vector<T*> data{};

	for (auto& components : manager.components) {
		for (auto& component : components) {
			if (component.type() == typeid(T)) {
				data.push_back(std::any_cast<T>(&component));
			}
		}
	}

	return data;
}

int main() {
	EntityManager manager{};
	Entity entity = manager_create_entity(manager);
	entity_add_component<Information>(manager, entity);
	entity_get_component<Information>(manager, entity)->info = 5;

	auto component = entity_get_component<Information>(manager, entity);

	std::cout << component->info;

	while (true) {

	}

    return 0;
}