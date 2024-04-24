    class Message {
        id_t    m_messageId;
        uint8_t* m_data;
        
    public:
        Message (MessageID messageId, uint8_t * item)
        {
            m_messageId = (id_t) messageId;
            m_data = item;
        }
        ~Message ()
        {
            delete m_data;
        }
    };
    #define new_Message (id,item,prm) (MessageID::id, (uint8_t)new item prm)
    Message msg1 new_Message (WorldPeace, small, (1,2,3));