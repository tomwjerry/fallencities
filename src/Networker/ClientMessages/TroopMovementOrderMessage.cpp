#include "TroopMovementOrderMessage.h"
#include <istream>
#include "../Marshalling.h"

void TroopMovementOrderMessage::Read(std::istream& istr)
{
    this->troopIndex = ReadNetworkUInt32(istr);
    this->statusOrder = ReadNetworkUInt8(istr);
    this->targetX = ReadNetworkUInt32(istr);
    this->targetY = ReadNetworkUInt32(istr);
    this->targetZ = ReadNetworkUInt32(istr);
}
