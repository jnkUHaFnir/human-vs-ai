template<typename T>
Message(id_t messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    T* obj = static_cast<T*>(reinterpret_cast<void*>(m_data));
    *obj = std::forward<T>(src);
}
