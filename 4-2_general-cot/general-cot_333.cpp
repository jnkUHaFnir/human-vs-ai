template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    size_t offset = m_size;
    grow(offset + sizeof(T));

    T* newObject = new (m_data + offset) T(std::forward<T>(src));
}
Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
