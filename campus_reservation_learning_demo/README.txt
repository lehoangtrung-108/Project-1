CAMPUS RESERVATION LEARNING DEMO
================================

This is a separate learning demo, not a submission-ready course-project implementation.
It demonstrates vector, linked list, queue, stack, file input, classes, and a CLI menu.

Build from the project root:
  g++ -std=c++17 -Iinclude src/*.cpp -o reservation_demo

Run:
  ./reservation_demo

Windows MinGW:
  reservation_demo.exe

Concepts:
  vector -> resource inventory
  linked list -> active reservations
  queue -> waiting line (FIFO)
  stack -> cancellation history / undo (LIFO)

Typical complexity:
  Resource lookup: O(n)
  Linked-list search/removal: O(n)
  Linked-list insertion at head: O(1)
  Queue add/remove: O(1)
  Stack push/pop: O(1)

Try: reserve a resource, attempt to reserve it again, inspect the waiting list,
cancel the first reservation, and observe the queued student receive the resource.
