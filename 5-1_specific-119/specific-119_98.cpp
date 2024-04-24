template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    new (m_data) T(std::forward<T>(src));
}
dispatchWorldPeace(42, 100, 777);
