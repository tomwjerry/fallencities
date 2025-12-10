#include <istream>
#include "BaseClientMessage.h"

class TroopMovementOrderMessage : public BaseClientMessage
{
    private:
        unsigned int troopIndex;
        unsigned char statusOrder;
        unsigned int targetX;
        unsigned int targetY;
        unsigned int targetZ;

    public:
        virtual void Read(std::istream& istr);
};
