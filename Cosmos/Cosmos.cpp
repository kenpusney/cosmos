#include "Common.h"
#include "DataSource/DataSource.h"
#include "Service/CosmosQueryServiceFactory.h"
#include "CosmosQuery.h"

int main()
{
	MYSQL *conn = ConnectDataSource();
	
	if (!conn)
	{
		std::cout << "Error: Unable to connect to database." << std::endl;
		return 1;
	}

	CosmosQueryServiceFactory serviceFactory(conn);
	CosmosQuery cosmosQuery(serviceFactory);
	cosmosQuery.StartQuerySession();

	return 0;
}
