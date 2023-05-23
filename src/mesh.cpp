#include <iostream>
#include "mesh.h"
// suppose 4x4 2D-mesh topology

mesh::mesh(int mesh_dim, int **tasks)
{
    this->mesh_dim = mesh_dim;
    this->tasks = tasks;

    for (int i = 0; i < mesh_dim; i++)
    {
        this->router_array[i] = (router*)malloc(sizeof(router) * mesh_dim);
        for (int j = 0; j < mesh_dim; j++) this->router_array[i][j] = router();
    }
}


void mesh::Cycle() // cycle level simulator
{
    // compute route -> need alogrithm

    // check all route and find dead-lock (form ring)

    // find detoured route & check dead-lock again (repeat)

    // cycle
}