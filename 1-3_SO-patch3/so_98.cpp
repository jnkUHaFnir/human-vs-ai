    #include <cstdint>
    #include <new>
    
    // ==========================================================================
    // Common definitions
    // ==========================================================================
    
    // message header
    enum class MessageID : uint8_t { WorldPeace, Armaggedon };
    struct MessageHeader {
        MessageID id;
    	uint8_t   __padding; // one free byte here
    	uint16_t  size;
    };
    
    // small buffer size
    #define SMALL_BUF_SIZE 64
    
    // dummy send function
    int some_DMA_trick(int destination, void * data, uint16_t size);
    
    // ==========================================================================
    // Macro solution
    // ==========================================================================
    
    // -----------------------------------------
    // Message class
    // -----------------------------------------
    class mMessage {
    	// local storage defined even for big messages
        MessageHeader   m_header;
        uint8_t         m_localData[SMALL_BUF_SIZE];
    
    	// pointer to the actual message
        MessageHeader * m_head;
    public:  
    	// choose the proper location for contents
        mMessage (MessageID messageId, uint16_t size)
        {
    		m_head = size <= SMALL_BUF_SIZE 
    			? &m_header
    			: (MessageHeader *) new uint8_t[size + sizeof (m_header)];
     		m_head->id   = messageId;
    		m_head->size = size;
       }
    
    	// dispose of the contents if need be
        ~mMessage ()
        {
            if (m_head != &m_header) delete m_head;
        }
    	
    	// let placement new know about the contents location
    	void * location (void)
    	{
    		return m_head+1;
    	}
    
    	// send a message
    	int send(int destination)
    	{
    		return some_DMA_trick (destination, m_head, (uint16_t)(m_head->size + sizeof (m_head)));
    	}
    };
    
    // -----------------------------------------
    // macro to do the in-place construction
    // -----------------------------------------
    #define BuildMessage(msg, obj, id, ...   )       \
    		mMessage msg (MessageID::id, sizeof(obj)); \
    		new (msg.location()) obj (__VA_ARGS__);  \
    
    // ==========================================================================
    // Template solution
    // ==========================================================================
    #include <utility>
    
    // -----------------------------------------
    // template to check storage capacity
    // -----------------------------------------
    template<typename T>
    struct storage
    {
        enum { local = sizeof(T)<=SMALL_BUF_SIZE };
    };
    
    // -----------------------------------------
    // base message class
    // -----------------------------------------
    class tMessage {
    protected:
        MessageHeader * m_head;
    	tMessage(MessageHeader * head, MessageID id, uint16_t size) 
    		: m_head(head)
    	{
    		m_head->id = id;
    		m_head->size = size;
    	}
    public:
    	int send(int destination)
    	{
    		return some_DMA_trick (destination, m_head, (uint16_t)(m_head->size + sizeof (*m_head)));
    	}
    };
    
    // -----------------------------------------
    // general message template
    // -----------------------------------------
    template<bool local_storage, typename message_contents>
    class aMessage {};
    
    // -----------------------------------------
    // specialization for big messages
    // -----------------------------------------
    template<typename T>
    class aMessage<false, T> : public tMessage
    {
    public:
    	// in-place constructor
    	template<class... Args>
    	aMessage(MessageID id, Args...args) 
    		: tMessage(
    			(MessageHeader *)new uint8_t[sizeof(T)+sizeof(*m_head)], // dynamic allocation
    			id, sizeof(T))
    	{
    		new (m_head+1) T(std::forward<Args>(args)...);
    	}
    
    	// destructor
        ~aMessage ()
        {
            delete m_head;
        }
    
    	// syntactic sugar to access contents
    	T& contents(void) { return *(T*)(m_head+1); }
    };
    
    // -----------------------------------------
    // specialization for small messages
    // -----------------------------------------
    template<typename T>
    class aMessage<true, T> : public tMessage
    {
    	// message body defined locally
    	MessageHeader m_header;
        uint8_t       m_data[sizeof(T)]; // no need for 64 bytes here
    
    public:
    	// in-place constructor
    	template<class... Args>
    	aMessage(MessageID id, Args...args) 
    		: tMessage(
    			&m_header, // local storage
    			id, sizeof(T))
    	{
    		new (m_head+1) T(std::forward<Args>(args)...);
    	}
    
    	// syntactic sugar to access contents
    	T& contents(void) { return *(T*)(m_head+1); }
    };
    
    
    // -----------------------------------------
    // helper macro to hide template ugliness
    // -----------------------------------------
    #define Message(T) aMessage<storage<T>::local, T>
    //typedef aMessage<storage<T>::local, T> toto;
    
    // ==========================================================================
    // Example
    // ==========================================================================
    #include <cstdio>
    #include <cstring>
    
    // message sending
    int some_DMA_trick(int destination, void * data, uint16_t size)
    {
    	printf("sending %d bytes @%p to %08X\n", size, data, destination);
    	return 1;
    }
    
    // some dynamic contents
    struct gizmo {
        char * s;
    	gizmo(void) { s = nullptr; };
    	gizmo (const gizmo&  g) = delete;
    
        gizmo (const char * msg)
    	{
    		s = new char[strlen(msg) + 3];
    		strcpy(s, msg);
    		strcat(s, "#");
    	}
    
    	gizmo (gizmo&& g)
    	{
    		s = g.s;
    		g.s = nullptr;
    		strcat(s, "*");
    	}
    
    	~gizmo() 
    	{ 
    		delete s;
    	}
    
    	gizmo& operator=(gizmo g)
    	{
            std::swap(s, g.s);
            return *this;
    	}
    	bool operator!=(gizmo& g)
    	{
            return strcmp (s, g.s) != 0;
    	}
    
    };
    
    // some small contents
    struct small {
        int a, b, c;
    	gizmo g;
        small (gizmo g, int a, int b, int c)
    		: a(a), b(b), c(c), g(std::move(g)) 
    	{
    	}
    
    	void trace(void) 
    	{ 
    		printf("small: %d %d %d %s\n", a, b, c, g.s);
    	}
    };
    
    // some big contents
    struct big {
        gizmo lump[1000];
    
    	big(const char * msg = "?")
    	{ 
    		for (size_t i = 0; i != sizeof(lump) / sizeof(lump[0]); i++)
    			lump[i] = gizmo (msg);
    	}
    
    	void trace(void)
    	{
    		printf("big: set to ");
    		gizmo& first = lump[0];
    		for (size_t i = 1; i != sizeof(lump) / sizeof(lump[0]); i++)
    			if (lump[i] != first) { printf(" Erm... mostly "); break; }
    		printf("%s\n", first.s);
    	}
    };
    
    int main(void)
    {
    	// macros
    	BuildMessage(mmsg1, small, WorldPeace, gizmo("Hi"), 1, 2, 3);
    	BuildMessage(mmsg2, big  , Armaggedon, "Doom");
    	((small *)mmsg1.location())->trace();
    	((big   *)mmsg2.location())->trace();
    	mmsg1.send(0x1000);
    	mmsg2.send(0x2000);
    
    	// templates
    	Message (small) tmsg1(MessageID::WorldPeace, gizmo("Hello"), 4, 5, 6);
    	Message (big  ) tmsg2(MessageID::Armaggedon, "Damnation");
    	tmsg1.contents().trace();
    	tmsg2.contents().trace();
    	tmsg1.send(0x3000);
    	tmsg2.send(0x4000);
    }