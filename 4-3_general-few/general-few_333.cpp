template<typename T, typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(sizeof(T), messageId)
{
    // we know m_data points to a large enough buffer
    new ((T*)m_data) T(std::forward<Args>(args)...);
}
Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
