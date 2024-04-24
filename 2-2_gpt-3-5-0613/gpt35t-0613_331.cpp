template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageID)
{
    new ((T*)m_data) std::remove_reference_t<T>(std::forward<T>(src));
}
