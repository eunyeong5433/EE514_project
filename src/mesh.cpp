#include <iostream>
#include "mesh.h"
#include "route.h"
#include <queue>
// suppose 4x4 2D-mesh topology

mesh::mesh(int mesh_dim, int **tasks, int transfer_num, int packet_length)
{
    this->mesh_dim = mesh_dim;
    this->tasks = tasks; // kinds of lookup table
    this->transfer_num = transfer_num;

    this->end = (int*)malloc(sizeof(int) * transfer_num);
    this->total_latency = (int*)malloc(sizeof(int) * transfer_num);

    this->current_node = (int*)malloc(sizeof(int) * transfer_num); // 각 task별로 현재 node
    this->detour = (int*)malloc(sizeof(int) * transfer_num);

    for (int i = 0; i < transfer_num; i ++)
    {
        this->current_node[i] = tasks[i][0];
        this->end[i] = 0;
        this->total_latency[i] = 0;
        this->detour[i] = 0;
        this->route_array[i].task_num = i;
    }
    this->router_array = (router*)malloc(sizeof(router) * mesh_dim * mesh_dim);


    for (int i = 0; i < mesh_dim * mesh_dim; i++)
    {
        this->router_array[i] = router(i, packet_length);
    }
}

void mesh::compute_route()
{
    for (int i = 0; i < this->transfer_num; i ++)
    {
        int current_idx = tasks[i][0];
        int dst_idx = tasks[i][1];
        
        int dst_x = dst_idx % this->mesh_dim;
        int dst_y = dst_idx / this->mesh_dim;

        this->route_array[i].route_by_task.push(current_idx);

        while (true)
        {
            int src_x = current_idx % this->mesh_dim;
            int src_y = current_idx / this->mesh_dim;
    
            if (src_x < dst_x) 
            {
                this->route_array[i].route_by_task.push(current_idx + 1);
                current_idx = current_idx + 1;
            }
            else if (src_x > dst_x) 
            {
                this->route_array[i].route_by_task.push(current_idx - 1);
                current_idx = current_idx - 1;
            }
            else
            {
                if (src_y < dst_y) 
                {
                    this->route_array[i].route_by_task.push(current_idx + 4);
                    current_idx = current_idx + 4;
                }
                else if (src_y > dst_y) 
                {
                    this->route_array[i].route_by_task.push(current_idx - 4);
                    current_idx = current_idx - 4;
                }
                else break;
            }
        }
        printf("for %d task, route is \n", i);
        while (!this->route_array[i].route_by_task.empty())
        {
            std::cout << this->route_array[i].route_by_task.front() << " ";
            this->route_array[i].route_by_task.pop();
        }
        std::cout << std::endl;
    }
}

void mesh::Cycle() // cycle level simulator
{

    // check all route and find dead-lock (form ring)
    for (int i = 0; i < this->mesh_dim * this->mesh_dim; i++)
    {
        bool end = false;

        int current_idx = i;
        int next_idx = -1;

        std::queue<int> loop;
        loop.push(current_idx);

        while(!end)
        {
            next_idx = this->router_array[current_idx].dst;
            if (next_idx == -1) 
            {
                end = true;
                while(!loop.empty()) loop.pop();
            }
            else 
            {
                if (next_idx == i) end = true;
                else 
                {
                    loop.push(next_idx);
                    current_idx = next_idx;
                }
            }
        }

        if (!loop.empty()) // deadlock exists, find detoured route
        {
            // check possible all detour

            // if detour is impossible, 일부만 processing using multiple packets
        }
    }

    // cycle
    
    // without multiple routes (for comparison)
    // func1

    // with multiple routes
    // func2 

    // update current node
}