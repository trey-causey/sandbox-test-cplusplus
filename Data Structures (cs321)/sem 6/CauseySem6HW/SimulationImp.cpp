

#include <iostream>
#include <string>
#include <cstdlib>

#include "Simulation.h"
#include "queueAsArray.h"
#include "myStack.h"

using namespace std;


//*************** customerType ************

customerType::customerType(int customerN, int arrvTime, int wTime,
						   int tTime)
{
	setCustomerInfo(customerN, arrvTime, wTime, tTime);
}

int customerType::getWaitingTime() const
{
	return waitingTime;
}

void customerType::incrementWaitingTime()
{
	waitingTime++;
}

void customerType::setWaitingTime(int time)
{
	waitingTime = time;
}

void customerType::setCustomerInfo(int customerN, int arrvTime, 
								   int wTime, int tTime)
{
	customerNumber = customerN;
	arrivalTime = arrvTime;
	waitingTime = wTime;
	transactionTime = tTime;
}

int customerType::getArrivalTime()
{
	return arrivalTime;
}

int customerType::getTransactionTime()
{
	return transactionTime;
}

int customerType::getCustomerNumber()
{
	return customerNumber;
}
//**************** serverType **********

serverType::serverType()
{
	status = "free";
	transactionTime = 0;
}

bool serverType::isFree() const
{
	return (status == "free");
}

void serverType::setBusy()
{
	status = "busy";
}

void serverType::setFree()
{
	status = "free";
}

void serverType::setTransactionTime(int t)
{
	transactionTime = t;
}

void serverType::setTransactionTime()
{
	int time;

	time = currentCustomer.getTransactionTime();

	transactionTime = time;
}


void serverType::decreaseTransactionTime()
{
	transactionTime--;
}

int serverType::getRemainingTransactionTime()
{
	return transactionTime;
}

void serverType::setCurrentCustomer(customerType cCustomer)
{
	currentCustomer = cCustomer;
}

int serverType::getCurrentCustomerNumber()
{
	return currentCustomer.getCustomerNumber();
}

int serverType::getCurrentCustomerArrivalTime()
{
	return currentCustomer.getArrivalTime();
}

int serverType::getCurrentCustomerWaitingTime()
{
	return currentCustomer.getWaitingTime();
}

int serverType::getCurrentCustomerTransactionTime()
{
	return currentCustomer.getTransactionTime();
}


//************** serverListType ***********

serverListType::serverListType(int num)
{
	serverType serverObject;
	numOfServers = num;
	for(int i = 0; i < num - 1; i++)
	{
		push(serverObject); //adds the original number of servers 
	}								//  specified by the user
}

serverListType::~serverListType()
{
	delete [] servers;
}

int serverListType::getFreeServerID()
{
	int serverID = -1;

	int i;

	for(i = 0; i < numOfServers; i++)
		if(servers[i].isFree())
		{
			serverID = i;
			break;
		}
	return serverID;
}

int serverListType::getNumberOfBusyServers()
{
	int busyServers = 0;

	int i;

	for(i = 0; i < numOfServers; i++)
		if(!servers[i].isFree())
			busyServers++;
	return busyServers;
}

void serverListType::setServerBusy(int serverID, 
								   customerType cCustomer, 
								   int tTime)
{
	servers[serverID].setBusy();
	servers[serverID].setTransactionTime(tTime);
	servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::setServerBusy(int serverID, 
								   customerType cCustomer)
{
	int time;

	time = cCustomer.getTransactionTime();

	servers[serverID].setBusy();
	servers[serverID].setTransactionTime(time);
	servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::updateServers()
{
	int i;

	for(i = 0; i < numOfServers; i++)
		if(!servers[i].isFree())
		{
			servers[i].decreaseTransactionTime();
			if(servers[i].getRemainingTransactionTime() == 0)
			{
				cout<<"Server No: "<<(i+1)<<" Customer number "
					<<servers[i].getCurrentCustomerNumber()
					<<" departed at "<<endl
					<<"             clock unit "
					<<servers[i].getCurrentCustomerArrivalTime() 
					+ servers[i].getCurrentCustomerWaitingTime() 
					+ servers[i].getCurrentCustomerTransactionTime()
					<<endl;
				servers[i].setFree();
			}
		}
}

void serverListType::updateServers(ofstream& outFile)
{
	int i;

	for(i = 0; i < numOfServers; i++)
		if(!servers[i].isFree())
		{
			servers[i].decreaseTransactionTime();
			if(servers[i].getRemainingTransactionTime() == 0)
			{
				outFile<<"Server No: "<<(i+1)<<" Customer number "
					   <<servers[i].getCurrentCustomerNumber()
						<<" departed at "<<endl
						<<"             clock unit "
						<<servers[i].getCurrentCustomerArrivalTime() 
						+ servers[i].getCurrentCustomerWaitingTime() 
						+ servers[i].getCurrentCustomerTransactionTime()
						<<endl;
				servers[i].setFree();
			}
		}
}

void serverListType::increaseNoOfServers()
{
	serverType serverObject;
	push(serverObject); //adds server based on criteria 
}								//specified by runSimlulation

void serverListType::decreaseNoOfServers()
{
	
	pop();  //removes sever based on criteria 
}					//specified by runSimulation

//*************** waitQueue ************


waitingCustomerQueueType::waitingCustomerQueueType(int size)
                          :queueType<customerType>(size)
{
}

waitingCustomerQueueType::~waitingCustomerQueueType()
{
}

void waitingCustomerQueueType::updateWaitingQueue()
{
	customerType cust;

	cust.setWaitingTime(-1);  
	int wTime = 0;
	
	addQueue(cust);

	while(wTime != -1)
	{
		cust = front();
        deleteQueue();

		wTime = cust.getWaitingTime();
		if(wTime == -1)
			break;
		cust.incrementWaitingTime();
		addQueue(cust);
	
	}
}
