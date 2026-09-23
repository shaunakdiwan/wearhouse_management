#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 20

// Order structure
struct Order {
  int orderId;
  int partId;
  int qtyRequested;
};

// Global Array-based Queue
Order orderQueue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
bool isFull() { return (rear == MAX_SIZE - 1); }

// Check if the queue is empty
bool isEmpty() { return (front == -1 || front > rear); }

// Add an order to the rear of the queue
void enqueueOrder(Order order) {
  if (isFull()) {
    cout << "Queue Overflow: Order queue is full\n";
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear++;
  orderQueue[rear] = order;
  cout << "Order added to queue.\n";
}

// Remove and return an order from the front of the queue
Order dequeueOrder() {
  Order emptyOrder = {-1, -1, -1}; // Return this if empty

  if (isEmpty()) {
    cout << "Queue Underflow: No orders to process\n";
    return emptyOrder;
  }

  Order temp = orderQueue[front];
  front++;

  // Reset queue if all items are dequeued
  if (front > rear) {
    front = -1;
    rear = -1;
  }

  return temp;
}

// View the order at the front without removing it
Order peekFront() {
  Order emptyOrder = {-1, -1, -1};
  if (isEmpty()) {
    cout << "Queue is empty.\n";
    return emptyOrder;
  }
  return orderQueue[front];
}

// Display all orders in the queue
void displayQueue() {
  if (isEmpty()) {
    cout << "Order queue is empty.\n";
    return;
  }
  cout << "\n--- Order Processing Line ---\n";
  for (int i = front; i <= rear; i++) {
    cout << "Order ID: " << orderQueue[i].orderId
         << " | Part ID: " << orderQueue[i].partId
         << " | Qty: " << orderQueue[i].qtyRequested << "\n";
  }
  cout << "-----------------------------\n";
}

// ----------------------------------------------------
// ROBOT TASK QUEUE (String-based Queue)
// ----------------------------------------------------
string robotQueue[MAX_SIZE];
int robotFront = -1;
int robotRear = -1;

bool isRobotQueueFull() { return (robotRear == MAX_SIZE - 1); }

bool isRobotQueueEmpty() {
  return (robotFront == -1 || robotFront > robotRear);
}

void addWaypoint(string waypoint) {
  if (isRobotQueueFull()) {
    cout << "Robot Queue Overflow: Cannot add more waypoints.\n";
    return;
  }
  if (robotFront == -1) {
    robotFront = 0;
  }
  robotRear++;
  robotQueue[robotRear] = waypoint;
}

string getNextWaypoint() {
  if (isRobotQueueEmpty()) {
    return ""; // Return empty string if underflow
  }
  string temp = robotQueue[robotFront];
  robotFront++;

  if (robotFront > robotRear) {
    robotFront = -1;
    robotRear = -1;
  }
  return temp;
}

void displayRoute() {
  if (isRobotQueueEmpty()) {
    cout << "Robot route is currently empty.\n";
    return;
  }
  cout << "\n--- Robot Task Route ---\n";
  for (int i = robotFront; i <= robotRear; i++) {
    cout << i - robotFront + 1 << ". Visit: " << robotQueue[i] << "\n";
  }
  cout << "------------------------\n";
}

#endif
