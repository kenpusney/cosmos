#ifndef COSMOS_QUERY_H
#define COSMOS_QUERY_H

#include "Common.h"
#include "Service/CosmosQueryServiceFactory.h"
#include "Entity/Entity.h"

class CosmosQuery
{
public:
	CosmosQuery(CosmosQueryServiceFactory &serviceFactory);

	void StartQuerySession();

private:
	void PrintQueryMenu();
	void PrintEntityTree(const Entity &entity, int level);
	void Pause();
	void HandleQueryOption(const std::string &option, bool &terminateSession);
	void PerformStructureQuery();
	void PerformMembershipQuery();

private:
	CosmosQueryServiceFactory &_serviceFactory;
};

#endif
