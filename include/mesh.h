#ifndef MESH_H
#define MESH_H

#include <iostream>

#include "mesh.h"
#include "router.h"
#include "route.h"

class mesh {

    public:

        int mesh_dim;
        int **tasks;
        int transfer_num;

        router *router_array; // router array
        int *current_node; // 현재 각 task별 위치       
        int *detour; // 각 task별 우회 여부 
        int *end;
        int *total_latency;

        route route_array[10];

        mesh(int mesh_dim, int **tasks, int transfer_num, int packet_length);
        void compute_route();
        void Cycle();

        ~mesh()
        {

        }
};

#endif