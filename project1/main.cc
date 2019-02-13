#include <iostream>
#include <cstdlib>
#include "priority_queue.h"

using namespace std;

static const int kCustomerNumberMinimum = -500;
static const int kCustomerNumberMaximum = 2000;

template <typename T>
static void pushQueue(templatePriorityQueue<T>* Que, int data){
	cout << "[+] Integer "<< data <<" pushed in the Priority Queue." << endl;
	Que->push(data);
}

template<typename T>
static void popQueue(templatePriorityQueue<T>* Que){
	cout << "[+] Integer "<< Que->top() << " will be poped from the Priority Queue." << endl;
	Que->pop();
}

static void multipopQueue(templatePriorityQueue<T>* Que, const int count){
	for(int i = 0 ; i < count ; ++i){
		popQueue(Que);
	}
}

int main(int argc, char* argv[]){
	templatePriorityQueue<int> priQueue;
	int customNumber = 0;

	// push with initial condition(23, 598, 302)
	// If the more information for those values or the exact condition for initial values is given,
	// the below three lines will be updated.
	pushQueue(&priQueue,23);
	pushQueue(&priQueue,598);
	pushQueue(&priQueue,302);

	if( argc > 1 ){
		customNumber = atoi(argv[1]);
		if( customNumber > kCustomerNumberMinimum && customNumber < kCustomerNumberMaximum ){
			pushQueue(&priQueue,customNumber);
		}
		else{
			pushQueue(&priQueue,-1);
		}
	}
	else{
		pushQueue(&priQueue,-1);
	}

	//empty & size
	if(priQueue.empty()){
		cout << "[-] Priority Queue is empty. - Push method did not work!" << endl;
		return -1;
	}
	else{
		cout << "[+] Priority Queue has data. - Queue Size : " << priQueue.size() <<endl;
	}

	// pop twice
	multipopQueue(&priQueue, 2);

	cout << "[+] Now, Top element of Priority Queue is " << priQueue.top() << endl;
	
	return 0;
}
