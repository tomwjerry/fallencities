#include "DiscoverTroopMessage.h"
#include <istream>
#include "../Marshalling.h"

void DiscoverTroopMessage::Write(std::ostream& ostr)
{
    WriteNetworkUInt32(ostr, this->playerId);
    WriteNetworkUInt32(ostr, this->troopIndex);
    for (int i = 0; i < 5; i++)
    {
        WriteNetworkUInt8(ostr, this->heroTypes[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        WriteNetworkUInt8(ostr, this->heroLevels[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        WriteNetworkUInt8(ostr, this->heroEquipment[i]);
    }
    for (int i = 0; i < 100; i++)
    {
        WriteNetworkUInt16(ostr, this->troop[i]);
    }
}