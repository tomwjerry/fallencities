#include <istream>
#include "BaseClientMessage.h"

class DispatchTroopMessage : public BaseClientMessage
{
    private:
        unsigned int fromBase;
        unsigned char heroes[5];
        unsigned short int troop[100];

    public:
        virtual void Read(std::istream& istr);
};
