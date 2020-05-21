#pragma once
#include "Date.h"
#include "Client.h"
#include "Room.h"
#include "Event.h"
#include "EventArr.h"
#include <functional>
class SortClass
{
public:
    using comparatorFunction = std::function<bool(Event, Event)>;

    static void sort(EventArr &, size_t, comparatorFunction);
};

