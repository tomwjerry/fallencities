#include <istream>

class BaseClientMessage
{
    public:
        virtual ~BaseClientMessage() {}
        virtual void Read(std::istream& istr) = 0;
};
