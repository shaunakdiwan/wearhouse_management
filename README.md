# Warehouse Inventory and Order Management System

This is a college minor-project for Data Structures & Algorithms (DSA), building a warehouse management system using plain C++ arrays and pointers (no STL containers).

## Part 1: Core ADT Implementations

The current version (Part 1) includes the foundational data structures built from scratch:
- **Parts Inventory (Linked List)**: A singly linked list to store warehouse parts.
- **Order Processing (Queue)**: A fixed-size array-based queue to handle incoming orders.
- **Order History (Stack)**: A fixed-size array-based stack for keeping track of processed orders for an undo feature.

Integration logic (where placing an order reduces inventory and adds to the history stack) and the Robot navigation queue will be implemented in Part 2.

A basic visual webapp skeleton (HTML/CSS) is also included in the `/webapp` directory, though it is not yet wired to any logic.
