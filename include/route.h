#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <queue>

#include "route.h"

class route {

    public:

        int task_num;
        std::queue <int> route_by_task;

        route();

        ~route()
        {

        }
};

#endif