#ifdef USE_CPP11
template<typename T, typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(sizeof(T), messageId) // corrected minor typo: messageID -> messageId
{
    new ((T*)m_data) T(std::forward<Args>(args)...);
}
#endif
Message outgoing(MessageID::WorldPeace, MyStruct{wpArg1, wpArg2, wpArg3});
// or, preferably for uniform initialization syntax avoiding narrowing conversions
Message outgoing(MessageID::WorldPeace, MyStruct{wpArg1, wpArg2, wpArg3});
Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));
