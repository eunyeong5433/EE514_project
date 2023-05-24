#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>

#include "router.h"

class router {

    public: 
        int src;
        int dst; // neighbor
        int packet_length;
        int remained_cycle;
        int task_num;
        
    router(int src, int packet_length);
    void Cycle();

    ~router()
    {
        
    }
};

#endif