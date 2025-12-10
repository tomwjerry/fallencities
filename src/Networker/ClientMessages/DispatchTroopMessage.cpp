#include "DispatchTroopMessage.h"
#include <istream>
#include "../Marshalling.h"

void DispatchTroopMessage::Read(std::istream& istr)
{
    this->fromBase = ReadNetworkUInt32(istr);
    for (int i = 0; i < 5; i++)
    {
        this->heroes[i] = ReadNetworkUInt8(istr);
    }
    int32_t troopCount = ReadNetworkUInt32(istr);
    for (int i = 0; i < troopCount; i++)
    {
        this->troop[i] = ReadNetworkUInt16(istr);
    }
}
