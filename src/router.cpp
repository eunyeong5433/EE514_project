#include <iostream>
#include "router.h"
// suppose 4x4 2D-mesh topology

router::router(int src, int packet_length)
{
    this->src = src;
    this->packet_length = packet_length;
    this->dst = -1;
    this->task_num = -1;
    this->remained_cycle = packet_length;
}


void router::Cycle() // cycle level simulator
{
    
}