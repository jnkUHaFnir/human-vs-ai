#include <cstdint>
#include <cstring> // for std::memcpy

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
            m_data = reinterpret_cast<uint8_t*>(realloc((m_data == m_localData) ? nullptr : m_data, newSize));
            assert(m_data != nullptr);
            m_size = newSize;
        }
    }

    template<typename T>
    Message(id_t messageId, T&& src)
        : Message(sizeof(T), messageId)
    {
        new (m_data) T(std::forward<T>(src));
    }

    template<typename T>
    T* allocatePtr()
    {
        size_t offset = m_size;
        grow(offset + sizeof(T));
        return reinterpret_cast<T*>(m_data + offset);
    }
};
void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    struct MyStruct { // Define your struct
        int a, b, c;
        MyStruct(int x, int y, int z) : a(x), b(y), c(z) {}
    };

    Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
    outgoing.send(g_listener);
}
