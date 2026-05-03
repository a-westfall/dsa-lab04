/*
    Network.hpp

    Include file for Network class. 
*/

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>
#include <vector>

class Network {
public:
    
    // forward declare router
    struct Router;
    
    // entry on the route table
    struct RouteEntry {
        Router* destination;
        Router* nextHop;
        int cost;
    };

    // router on the map
    struct Router {
        // id of router name
        char id;

        // full router name
        std::string name;

        // table of shortest path to each node
        std::vector<RouteEntry> routeTable;
    };

    // default constructor
    Network();

    // get router to start from
    Router* getRouter(char id);

private:

    // map of routers
    std::vector<Router> routers; 
};

#endif
