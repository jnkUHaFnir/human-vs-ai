template<typename T, typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(sizeof(T), messageId) // Ensure messageId is correct
{
    // Directly construct T with forwarded arguments
    new ((T*)m_data) T(std::forward<Args>(args)...);
}
Message outgoing(MessageID::WorldPeace, MyStruct, wpArg1, wpArg2, wpArg3);
