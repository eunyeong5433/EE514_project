#include <iostream>
#include "mesh.h"
// suppose 4x4 2D-mesh topology

mesh::mesh(int mesh_dim, int **tasks, int transfer_num)
{
    this->mesh_dim = mesh_dim;
    this->tasks = tasks; // kinds of lookup table
    this->transfer_num = transfer_num;

    this->end = (int*)malloc(sizeof(int) * transfer_num);

    this->current_node = (int*)malloc(sizeof(int) * transfer_num);
    for (int i = 0; i < transfer_num; i ++)
    {
        this->current_node[i] = tasks[i][0];
        this->end[i] = 0;
    }
    this->router_array = (router*)malloc(sizeof(router) * mesh_dim * mesh_dim);

    for (int i = 0; i < mesh_dim * mesh_dim; i++)
    {
        this->router_array[i] = router();
    }
}


void mesh::Cycle() // cycle level simulator
{
    // compute route -> need alogrithm, 좌우 방향 선, 상하 방향 후라고 가정
    for (int i = 0; i < this->transfer_num; i++)
    {
        int src_x = this->current_node[i] % this->mesh_dim;
        int src_y = this->current_node[i] / this->mesh_dim;

        int dst_x = this->tasks[i][1] % this->mesh_dim;
        int dst_y = this->tasks[i][1] / this->mesh_dim;
        
        if (src_x < dst_x)
        {
            this->routes[i][0] = this->current_node[i];
            this->routes[i][1] = this->current_node[i] + 1;
        }
        else if (src_x > dst_x) 
        {
            this->routes[i][0] = this->current_node[i];
            this->routes[i][1] = this->current_node[i] - 1;
        }
        else
        {
            if (src_y < dst_y)
            {
                this->routes[i][0] = this->current_node[i];
                this->routes[i][1] = this->current_node[i] + 4;
            }
            else if (src_y > dst_y)
            {
                this->routes[i][0] = this->current_node[i];
                this->routes[i][1] = this->current_node[i] - 4;
            }
            else this->end[i] = 1; // end! end 아닌 것들에 대해서만 뒤에 process
        }
    }

    // check all route and find dead-lock (form ring)
    bool deadlock = true;
    while (deadlock) // such a lookup table
    {
        for (int i = 0; i < this->transfer_num; i ++)
        {

        }
    }

    // find detoured route & check dead-lock again (repeat)

    // cycle
    
    // without multiple routes (for comparison)
    // func1

    // with multiple routes
    // func2 

    // update current node
}