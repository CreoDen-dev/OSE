#include "Entity.h"

namespace OSE {
	Entity::Entity() {
	}

	Entity::~Entity() {
	}

	void Entity::onRender(Renderer* renderer) {
	}

	RigidBody* Entity::getPhysicsBody() {
		return nullptr;
	}
}