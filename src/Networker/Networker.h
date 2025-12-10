struct PerSocketData
{
};

class Networker
{
public:
    void Init();
    void handleMessage(uWS::WebSocket<false, true, PerSocketData> *ws,
        std::string_view message, uWS::OpCode opCode);
    void 
};