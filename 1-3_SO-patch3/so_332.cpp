    #include <cstdint>
    #include <cstdio>
    #include <new>
    
    typedef uint8_t id_t;
    enum class MessageID { WorldPeace, Armaggedon };
    
    #define SMALL_BUF_SIZE 64
    
    class Message {
        id_t     m_messageId;
        uint8_t* m_data;
        uint8_t  m_localData[SMALL_BUF_SIZE];
    	
    public:
        
    	// choose the proper location for contents
        Message (MessageID messageId, size_t size)
        {
    		m_messageId = (id_t)messageId;
    		m_data = size <= SMALL_BUF_SIZE ? m_localData : new uint8_t[size];
        }
    
    	// dispose of the contents if need be
        ~Message ()
        {
            if (m_data != m_localData) delete m_data;
        }
    	
    	// let placement new know about the contents location
    	void * location (void)
    	{
    		return m_data;
    	}
    };
    
    // a macro to do the in-place construction
    #define BuildMessage(msg, id, obj, ...   )       \
    		Message msg(MessageID::id, sizeof(obj)); \
    		new (msg.location()) obj (__VA_ARGS__);  \
    
    // example uses
    struct small {
        int a, b, c;
        small (int a, int b, int c) :a(a),b(b),c(c) {}
    };
    struct big {
        int lump[1000];
    };
    
    int main(void)
    {
    	BuildMessage(msg1, WorldPeace, small, 1, 2, 3)
    	BuildMessage(msg2, Armaggedon, big)
    }