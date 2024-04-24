    typedef uint8_t id_t;
    enum class MessageID { WorldPeace, Armaggedon };
    
    class Message {
        id_t     m_messageId;
        uint8_t* m_data;
        size_t   m_size; // amount of data used
        size_t   m_capacity; // amount of space available
        uint8_t  m_localData[64]; // up to 64 bytes.
        
    public:
        void grow (size_t new_size)
        {
            if (new_size > m_capacity)
            {
                if (m_data == m_localData)
                {
                    m_data = new uint8_t[new_size];
                    memcpy (m_data, m_localData, m_size);
                }
                else m_data = (uint8_t*) realloc (m_data, new_size);
                m_capacity = new_size;
            }
        }
        
        template<typename T>
        Message (MessageID messageId, T* item)
        {
            m_messageId = (id_t) messageId;
            m_data = (uint8_t*)item;
            if (sizeof (*item) <= sizeof (m_localData))
            {
                // use local storage
                memcpy (m_localData, m_data, sizeof(*item));
                delete m_data;
                m_data = m_localData;
                m_capacity = sizeof (m_localData);
            }
            else m_capacity = sizeof(*item);
            m_size = sizeof(*item);
        }
        ~Message ()
        {
            if (m_data != m_localData) delete m_data;
        }
        void status (const char * msg)
        {
            printf ("%s: %s storage, size %d, avail %d\n",
                msg,
                m_data == m_localData ? "local" : "dynamic",
                m_capacity,
                m_capacity - m_size);
        }
    };
    