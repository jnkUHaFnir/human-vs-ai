template<typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(messageId, std::in_place_t{}, (std::forward<Args>(args))...)
{
    // ... other code ...
}

void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    Message outgoing(MessageID::WorldPeace, wpArg1, wpArg2, wpArg3);
    outgoing.send(g_listener);
}
