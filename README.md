# File Manager

This project implements a class that manager access to files and stores the data in a cache.

## Cache

To save the cached data, the Least recently used (LRU) algorithm was used.

The algorithm works as follows: 
When new data is added to the cache, a check is made to see if the addition of this new data will cause an overflow in the cache.
In case the addition causes an overflow the data from the last position of the Doubly Linked List (deque) is discarded and the new data is added in the first position of the deque. If the addition does not cause an overflow, the new data is added in the first position of the deque.

## Project Structure

The FileManager class depends on the ICache interface.

The LRUCache class implements the ICache interface.

## Quickstart
1. Clone this repository to your local.
> `https://github.com/Instituto-Atlantico/cplusplus-challenge-hermano-castro.git`

2. Run `mingw32-make app` on windows or `make app` on linux to build the application.
