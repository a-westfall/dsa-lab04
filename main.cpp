/*
    main.cpp

    Example test for Network class.
    Includes UI for visualizing data being transferred from router to router along shortest path.
*/

#include "Network.hpp"
#include <iostream>

int main() {

    char input;
    std::cout << "Please enter a destination id (B, C, D, N or S) or E to exit: ";
    std::cin >> input;
    std::cin.ignore();
    
    // initialize network
    Network network; 

    while (input != 'E' && input != 'e') {

        // check if router exists
        if (network.getRouter(input) == nullptr) {
            std::cerr << "Error. Invalid destination entered.\n";

            // prompt another destination
            std::cout << "Please enter a destination id (B, C, D, N or S) or E to exit: ";
            std::cin >> input;
            std::cin.ignore();
            continue;
        }

        // check if in Cleveland
        if (input == 'C' || input == 'c') {
            std::cerr << "Error. Already in Cleveland.\n";

            // prompt another destination
            std::cout << "Please enter a destination id (B, C, D, N or S) or E to exit: ";
            std::cin >> input;
            std::cin.ignore();
            continue;
        }

        // set current and destination routers for hopping
        Network::Router* current = network.getRouter('C');
        Network::Router* destination = network.getRouter(input);
        
        // loop through hops
        while (current != destination) {

            Network::Router* nextHop = nullptr;

            // search current->routeTable for entry where entry.destination == destination
            for (auto& router : current->routeTable) {
                if (router.destination == destination) {
                    nextHop = router.nextHop;
                }
            }

            // print hop
            std::cout << "\nHop from " << current->name << " (" << current->id << ") to " << nextHop->name << " (" << nextHop->id << ")\n";

            // wait for user input 
            std::cout << "Press enter for next hop: ";
            std::cin.ignore();

            // advance current to nextHop
            current = nextHop;

        }
        std::cout << "\nArrived at " << destination->name << "!\n";

        // prompt another destination
        std::cout << "\nPlease enter a destination id (B, C, D, N or S) or E to exit: ";
        std::cin >> input;
        std::cin.ignore();
    }

    return 0;
}
