#include <cstdint>
#include <utility>

typedef uint8_t id_t;
enum class MessageID { WorldPeace };

class Message
{
    uint8_t* m_data;
    uint8_t m_localData[64];
    id_t m_messageId;
    size_t m_size;
    size_t m_capacity;

public:
    Message(size_t requestSize, id_t messageId)
        : m_data(m_localData), m_messageId(messageId), m_size(0), m_capacity(sizeof(m_localData)) {}

    void grow(size_t newSize)
    {
        if (newSize > m_capacity)
        {
            m_data = realloc((m_data == m_localData) ? nullptr : m_data, newSize);
            assert(m_data != nullptr);
            m_size = newSize;
        }
    }

    template<typename T>
    T* allocatePtr()
    {
        size_t offset = m_size;
        grow(offset + sizeof(T));
        return reinterpret_cast<T*>(m_data + offset);
    }

    template<typename T, typename... Args>
    Message(id_t messageId, Args&&... args)
        : Message(sizeof(T), messageId)
    {
        new (allocatePtr<T>()) T(std::forward<Args>(args)...);
    }
};
void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    Message outgoing(MessageID::WorldPeace, wpArg1, wpArg2, wpArg3);
    outgoing.send(g_listener);
}
