


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "Simulation.h"
#include "queueAsArray.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival);
bool isCustomerArrived(double arvTimeDiff);

void generateStatistics(serverListType& serverList, 
						waitingCustomerQueueType& CQueue, 
						int numOfCustArrived,
						int waitTimeServedCustomers);
void runSimulation();

int main()
{
	runSimulation();
	system("pause");
	return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival)
{
	cout<<"Enter the simulation time: "<<flush;
	cin>>sTime;
	cout<<endl;

	cout<<"Enter the number of servers: "<<flush;
	cin>>numOfServers;
	cout<<endl;

	cout<<"Enter the transaction time: "<<flush;
	cin>>transTime;
	cout<<endl;

	cout<<"Enter the time between customer arrivals: "<<flush;
	cin>>tBetweenCArrival;
	cout<<endl;
}

bool isCustomerArrived(double arvTimeDiff)
{
	double value;

	value = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);

	return (value > exp(- 1.0/arvTimeDiff));
}

void runSimulation()
{
	
	int simulationTime;
	int numberOfServers;
	int transactionTime;
	int timeBetweenCustomerArrival;

	waitingCustomerQueueType customerQueue;

	customerType customer;

	int custNumber = 0;
	
	int totalWaitTimeServedCustomers = 0;
	int totalWaitTime = 0;
	int numberOfCustomersServed = 0;
	int customersLeftInServers = 0;
	int clock = 0;
	int serverID;

	setSimulationParameters(simulationTime, numberOfServers,
		        transactionTime, timeBetweenCustomerArrival);

	serverListType serverList(numberOfServers);

	for(clock = 1; clock <= simulationTime; clock++)
	{
		serverList.updateServers();

		if(!customerQueue.isEmptyQueue())
			customerQueue.updateWaitingQueue();

		if(isCustomerArrived(timeBetweenCustomerArrival))
		{
			custNumber++;
			customer.setCustomerInfo(custNumber,clock,0,
									 transactionTime);
			customerQueue.addQueue(customer);
			cout<<"Customer number "<<custNumber
				<<" arrived at time unit "<<clock<<endl;
		}
		
		serverID = serverList.getFreeServerID();
		if(serverID != -1 && !customerQueue.isEmptyQueue())
		{
			customer = customerQueue.front();
			customerQueue.deleteQueue();
			totalWaitTimeServedCustomers = totalWaitTimeServedCustomers
											+ customer.getWaitingTime();
			serverList.setServerBusy(serverID, customer);
		}

		if(customerQueue.getCount() % 10 == 0 && customerQueue.getCount() == 0) //criteria to determine
		serverList.increaseNoOfServers();                                      //if new servers need to 
		else if(customerQueue.getCount() < 10)                                 //be added onto the stack
		serverList.decreaseNoOfServers();
	}

	cout<<endl;

	cout<<"Simulation ran for "<<simulationTime
		<<" time units"<<endl;
	cout<<"Number of servers: "<<numberOfServers<<endl;
	cout<<"Average transaction time: "
		<<transactionTime<<endl;
	cout<<"Average arrival time difference between customers: "
		<<timeBetweenCustomerArrival<<endl;

	generateStatistics(serverList, customerQueue, 
					   custNumber, totalWaitTimeServedCustomers);
}

void generateStatistics(serverListType& serverList, 
						waitingCustomerQueueType& CQueue, 
						int numOfCustArrived,
						int waitTimeServedCustomers)
{
	int customersLeftInQueue = 0;

	int totalWaitTime = waitTimeServedCustomers;

	customerType customer;

	while(!CQueue.isEmptyQueue())
	{
		customer = CQueue.front();
		CQueue.deleteQueue();
		totalWaitTime = totalWaitTime + customer.getWaitingTime();
		customersLeftInQueue++;
	}

			//Find number of customers left in servers
	int customersLeftInServers = serverList.getNumberOfBusyServers();
			//Find number of customers completely served
	int numberOfCustomersServed = numOfCustArrived - customersLeftInServers -
							  customersLeftInQueue;

	double averageWaitTime = 0;

	cout<<"Total wait time: "<<totalWaitTime<<endl;
	cout<<"Number of customers who completed a transaction: "
		<<numberOfCustomersServed<<endl;
	cout<<"Number of customers left in the servers: "
		<<customersLeftInServers<<endl;
	cout<<"Number of customers left in the queue: "<<customersLeftInQueue
		<<endl;
		
	if(numOfCustArrived > 0)  // If number of customers arrived is > 0
		averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustArrived;

	cout<<fixed<<showpoint;
	cout<<setprecision(2);
	cout<<"Average wait time: "<<averageWaitTime<<endl;
	cout<<"************** END SIMULATION *************"<<endl;

}