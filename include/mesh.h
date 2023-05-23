#ifndef MESH_H
#define MESH_H

#include <iostream>

#include "mesh.h"
#include "router.h"

class mesh {

    public:

        int mesh_dim;
        int **tasks;

        router **router_array;
        
        mesh(int mesh_dim, int **tasks);
        void Cycle();

        ~mesh()
        {

        }
};

#endif