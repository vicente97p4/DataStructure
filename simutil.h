#include"simlinkedqueue.h"
#ifndef _SIM_UTIL_
#define _SIM_UTIL_

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
void processArrival(int currentTIme, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *WaitQueue);
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTIme);
#endif