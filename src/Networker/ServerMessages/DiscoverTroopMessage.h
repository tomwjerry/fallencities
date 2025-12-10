#include <ostream>
#include "BaseServerMessage.h"

class DiscoverTroopMessage : public BaseServerMessage
{
    private:
        unsigned int playerId;
        unsigned int troopIndex;
        unsigned char heroTypes[5];
        unsigned char heroLevels[5];
        unsigned char heroEquipment[20];
        unsigned short int troop[100];
    public:
        virtual void Write(std::ostream& ostr);
};
