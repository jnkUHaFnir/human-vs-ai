template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    new ((T*)m_data) T(std::forward<T>(src));
}
