#include "db/Pin.h"

PROJECT_NAMESPACE_BEGIN

PinType Pin::nextPinType(PinType type) 
{
    if (type == PinType::SOURCE ||
        type == PinType::GATE)
        return PinType::DRAIN;
    if (type == PinType::DRAIN)
        return PinType::SOURCE;
}

PROJECT_NAMESPACE_END

