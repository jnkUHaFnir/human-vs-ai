template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageID)
{
    new (m_data) T (std::forward<T>(src));
}
