Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
template<typename T, typename... Args>
static Message EmplaceMessage(id_t messageId, Args&&... args) {
    Message message(sizeof(T), messageId);
    // Construct T directly in the storage area.
    new (message.m_data) T(std::forward<Args>(args)...);
    return message; // RVO/NRVO should apply here.
}
void dispatchWorldPeace(int wpArg1, int wpArg2, int wpArg3) {
    Message outgoing = Message::EmplaceMessage<MyStruct>(
        MessageID::WorldPeace, wpArg1, wpArg2, wpArg3
    );
    outgoing.send(g_listener);
}
