#ifndef MESH_H
#define MESH_H

#include <iostream>

#include "mesh.h"
#include "router.h"

class mesh {

    public:

        int mesh_dim;
        int **tasks;
        int transfer_num;

        router *router_array; // router array
        int **routes; // 다음 cycle에 지나갈 경로
        int *current_node; // 현재 각 task별 위치        
        int *end;
        
        mesh(int mesh_dim, int **tasks, int transfer_num);
        void Cycle();

        ~mesh()
        {

        }
};

#endif