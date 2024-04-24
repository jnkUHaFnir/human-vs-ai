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
            assert(m_data != nullptr); // my system uses less brutal mem mgmt
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

    template<typename T>
    Message(id_t messageId, T&& src)
        : Message(sizeof(T), messageId)
    {
        new (allocatePtr<T>()) T(std::forward<T>(src));
    }

    ~Message()
    {
        if (m_data != m_localData)
        {
            free(m_data);
        }
    }
};

struct MyStruct
{
    int x, y, z;
    MyStruct(int a, int b, int c) : x(a), y(b), z(c) {}
};

void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3)
{
    Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
    outgoing.send(g_listener);
}
