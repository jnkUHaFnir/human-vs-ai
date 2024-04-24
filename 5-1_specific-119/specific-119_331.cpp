template<typename T>
Message(id_t messageId, T src)
    : Message(sizeof(T), messageId)
{
    new ((T*)m_data) T(std::move(src)); // Assuming T has a move constructor
}
Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
