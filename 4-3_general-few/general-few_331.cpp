template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    // We know m_data points to a large enough buffer
    new ((T*)m_data) T(std::forward<T>(src));
}
Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
