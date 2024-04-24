template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    // Forward arguments and construct in-place without unnecessary move
    new ((T*)m_data) T (std::forward<T>(src));
}
