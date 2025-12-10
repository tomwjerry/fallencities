#include <ostream>
#include "BaseServerMessage.h"

class TroopMovementMessage : public BaseServerMessage
{
    private:
        unsigned int playerId;
        unsigned int troopIndex;
        unsigned char icon;
        unsigned char banner;
        unsigned char status;
        unsigned char speed;
        unsigned int x;
        unsigned int y;
        unsigned int z;
        unsigned int targetX;
        unsigned int targetY;
        unsigned int targetZ;
    public:
        virtual void Write(std::ostream& ostr);
};
