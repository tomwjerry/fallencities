#include "Networker.h"

#include <iostream>
#include <sstream>
#include "App.h"

#include "Marshalling.h"
#include "ClientMessages\ClientMessageTypes.h"
#include "ClientMessages\DispatchTroopMessage.h"
#include "ClientMessages\TroopMovementOrderMessage.h"

void Networker::Init()
{
    uWS::App app;
    uWS::App::WebSocketBehavior<PerSocketData> behavior;
    /* Settings */
    behavior.compression = uWS::CompressOptions(
        uWS::DEDICATED_COMPRESSOR | uWS::DEDICATED_DECOMPRESSOR);
    behavior.maxPayloadLength = 100 * 1024 * 1024;
    behavior.idleTimeout = 16;
    behavior.maxBackpressure = 100 * 1024 * 1024;
    behavior.closeOnBackpressureLimit = false;
    behavior.resetIdleTimeoutOnSend = false;
    behavior.sendPingsAutomatically = true;
    /* Handlers */
    behavior.upgrade = nullptr,
    behavior.open = [](auto */*ws*/)
    {
        /* Open event here, you may access ws->getUserData() which points to a
            PerSocketData struct */

    };
    behavior.message = [this](auto *ws, std::string_view message, uWS::OpCode opCode)
    {
        this->handleMessage(ws, message, opCode);
    };
    behavior.dropped = [](auto */*ws*/, std::string_view /*message*/, uWS::OpCode /*opCode*/)
    {
        /* A message was dropped due to set
            maxBackpressure and closeOnBackpressureLimit limit */
    };
    behavior.drain = [](auto */*ws*/)
    {
        /* Check ws->getBufferedAmount() here */
    };
    behavior.ping = [](auto */*ws*/, std::string_view)
    {
        /* Not implemented yet */
    };
    behavior.pong = [](auto */*ws*/, std::string_view)
    {
        /* Not implemented yet */
    };
    behavior.close = [](auto */*ws*/, int /*code*/, std::string_view /*message*/)
    {
        /* You may access ws->getUserData() here */
    };

    app.ws<PerSocketData>("/*", std::move(behavior));
    app.listen(9001, [](auto *listen_socket)
    {
        if (listen_socket)
        {
            std::cout << "Listening on port " << 9001 << std::endl;
        }
    });
    app.run();
}

void Networker::handleMessage(
    uWS::WebSocket<false, true, PerSocketData> *ws,
    std::string_view message, uWS::OpCode opCode)
{
    if (opCode != uWS::OpCode::BINARY)
    {
        return;
    }

    std::string messageStr(message);
    std::istringstream istr(messageStr);
    ClientMessageType messageType =
        static_cast<ClientMessageType>(ReadNetworkUInt8(istr));
    switch (messageType)
    {
    case ClientMessageType::DispatchTroop:
        {
            DispatchTroopMessage dispatchTroopMessage;
            dispatchTroopMessage.Read(istr);
            break;
        }
    case ClientMessageType::TroopMovementOrder:
        {
            TroopMovementOrderMessage troopMovementOrderMessage;
            troopMovementOrderMessage.Read(istr);
            break;
        }
    default:
        break;
    }
}
