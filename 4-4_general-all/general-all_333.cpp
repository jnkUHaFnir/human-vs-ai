template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    // we know m_data points to a large enough buffer
    new (m_data) T(std::forward<T>(src));
}
void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
    outgoing.send(g_listener);
}
