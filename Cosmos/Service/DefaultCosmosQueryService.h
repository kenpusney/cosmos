#ifndef DEFAULT_COSMOS_QUERY_SERVICE_H
#define DEFAULT_COSMOS_QUERY_SERVICE_H

#include "../Common.h"
#include "../Entity/IdentifiedEntity.h"
#include "CosmosQueryService.h"

class DefaultCosmosQueryService : public CosmosQueryService
{
public:
	DefaultCosmosQueryService(MYSQL *dataSource);

	virtual Entity* QuerySystemStructure(const std::string &name);
	virtual Entity* QuerySystemMembership(const std::string &name);

private:
	IdentifiedEntity* QueryEntity(const std::string &name);
	bool QuerySubEntities(IdentifiedEntity &root);

private:
	MYSQL *_dataSource;
};

#endif
