template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    // we know m_data points to a large enough buffer
    new ((T*)m_data) std::remove_reference<T>::type(std::forward<T>(src));
}
