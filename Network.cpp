/*
    Network.cpp

    Implementation of Network class.
*/

#include "Network.hpp"

Network::Network() {

    // prevent invalidation issue
    routers.reserve(5);

    // add routers
    routers.push_back({'N', "Norcal", {}});
    routers.push_back({'S', "Socal", {}});
    routers.push_back({'C', "Cleveland", {}});
    routers.push_back({'B', "Boston", {}});
    routers.push_back({'D', "DC", {}});

    Router* N = &routers[0];
    Router* S = &routers[1];
    Router* C = &routers[2];
    Router* B = &routers[3];
    Router* D = &routers[4];

    // Cleveland's route table
    C->routeTable = {
        {N, B, 2},
        {S, D, 2},
        {C, C, 0},
        {B, B, 1},
        {D, D, 1}
    };

    // NorCal's route table
    N->routeTable = {
        {N, N, 0},
        {S, S, 1}, 
        {B, B, 1},
        {C, B, 2},  
        {D, B, 2}, 
    };

    // SoCal's route table
    S->routeTable = {
        {S, S, 0},
        {N, N, 1},
        {D, D, 1},
        {C, D, 2},
        {B, N, 2}
    };

    // Boston's route table
    B->routeTable = {
        {B, B, 0},
        {C, C, 1},
        {D, D, 1},
        {N, N, 1},
        {S, N, 2}
    };

    // D.C's route table
    D->routeTable = {
        {D, D, 0},
        {C, C, 1},
        {B, B, 1},
        {S, S, 1},
        {N, S, 2}
    };
}

Network::Router* Network::getRouter(char id) {

    // find router matching id
    for (auto& router : routers) {
        if (router.id == id) {
            return &router;
        }
    }

    // no router found
    return nullptr;
}
