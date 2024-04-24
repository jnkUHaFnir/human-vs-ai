#include <cstdint>
#include <utility>

typedef uint8_t id_t;
enum class MessageID { WorldPeace };

class Message
{
    uint8_t* m_data;         // current memory
    uint8_t m_localData[64]; // up to 64 bytes
    id_t m_messageId;
    size_t m_size; // amount of data used
    size_t m_capacity; // amount of space available

public:
    Message(size_t requestSize, id_t messageId)
        : m_data(m_localData)
        , m_messageId(messageId)
        , m_size(0), m_capacity(sizeof(m_localData))
    {
        grow(requestSize);
    }

    void grow(size_t newSize)
    {
        if (newSize > m_capacity)
        {
            m_data = realloc((m_data == m_localData) ? nullptr : m_data, newSize);
            assert(m_data != nullptr); // assuming safe memory management
            m_size = newSize;
        }
    }

    template<typename T>
    Message(id_t messageId, T&& src)
        : Message(sizeof(T), messageId)
    {
        // we know m_data points to a large enough buffer
        new (m_data) T(std::forward<T>(src));
    }
};

void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    // Using perfect forwarding in the constructor call
    Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
    // Perform remaining operations
    outgoing.send(g_listener);
}
