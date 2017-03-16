#include "../Common.h"
#include "IdentifiedEntity.h"

IdentifiedEntity::IdentifiedEntity(int id, const std::string &name)
	: Entity(name)
	, _id(id)
{
}

int IdentifiedEntity::ID() const
{
	return _id;
}

void IdentifiedEntity::SetID(int id)
{
	_id = id;
}
