Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
template<typename T, typename... Args>
static Message Create(id_t messageId, Args&&... args) {
    Message outgoing(sizeof(T), messageId);
    new (outgoing.allocatePtr<T>()) T(std::forward<Args>(args)...);
    return outgoing;
}
auto outgoing = Message::Create<MyStruct>(MessageID::WorldPeace, wpArg1, wpArg2, wpArg3);
