#include "ECS.h"

void Entity::assignGroup(Group mGroup) {
	groupBitset[mGroup] = true;
	manager.AddToGroup(this, mGroup);
}