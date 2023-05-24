#include <iostream>
#include <random>

#include "mesh.h"

// generate randomized transfer

using namespace std;

int main(int argc, char *argv[])
{
    int transfer_num = (unsigned)atoi(argv[1]);
    int mesh_dim = (unsigned)atoi(argv[2]);
    int packet_length = (unsigned)atoi(argv[2]);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, mesh_dim*mesh_dim-1);

    int **tasks = (int**)malloc(sizeof(int*) * transfer_num);
    
    for (int i = 0; i < transfer_num; i ++)
    {
        tasks[i] = (int*)malloc(sizeof(int) * 2);
        tasks[i][0] = dis(gen);
        tasks[i][1] = dis(gen);
    }

    // check routes

    for (int i = 0; i < transfer_num; i ++)
    {
        printf("%d, %d\n", tasks[i][0], tasks[i][1]);
    }

    mesh Mesh(mesh_dim, tasks, transfer_num, packet_length);
    Mesh.compute_route();

    // Simualtion
}