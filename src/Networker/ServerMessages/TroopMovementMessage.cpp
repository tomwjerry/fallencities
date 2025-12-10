#include "TroopMovementMessage.h"
#include <istream>
#include "../Marshalling.h"

void TroopMovementMessage::Write(std::ostream& ostr)
{
    WriteNetworkUInt32(ostr, this->playerId);
    WriteNetworkUInt32(ostr, this->troopIndex);
    WriteNetworkUInt8(ostr, this->icon);
    WriteNetworkUInt8(ostr, this->banner);
    WriteNetworkUInt8(ostr, this->status);
    WriteNetworkUInt8(ostr, this->speed);
    WriteNetworkUInt32(ostr, this->x);
    WriteNetworkUInt32(ostr, this->y);
    WriteNetworkUInt32(ostr, this->z);
    WriteNetworkUInt32(ostr, this->targetX);
    WriteNetworkUInt32(ostr, this->targetY);
    WriteNetworkUInt32(ostr, this->targetZ);
}