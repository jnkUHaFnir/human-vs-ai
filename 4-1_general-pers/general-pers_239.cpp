template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageID)
{
    // we know m_data points to a large enough buffer
    new ((T*)m_data) T(std::forward<T>(src));
}
