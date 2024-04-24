template<typename T, typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(sizeof(T), messageId)
{
    new ((T*)m_data) T(std::forward<Args>(args)...);
}
Message outgoing(MessageID::WorldPeace, wpArg1, wpArg2, wpArg3);
