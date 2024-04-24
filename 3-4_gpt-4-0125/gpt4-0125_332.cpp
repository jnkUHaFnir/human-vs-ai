template<typename T, typename... Args>
Message(id_t messageId, Args&&... args)
    : Message(sizeof(T), messageId) // Make sure to use messageId, not messageID
{
    // The placement new here now directly constructs T with forwarded arguments.
    new (m_data) T(std::forward<Args>(args)...);
}
Message outgoing(MessageID::WorldPeace, MyStruct, wpArg1, wpArg2, wpArg3);
struct SimplePod {
    int a;
    char b;
    // More simple fields...
};

// Equivalent to Message outgoing(MessageID::Identifier, SimplePod{1, 'a'});
Message outgoing(MessageID::Identifier, SimplePod, 1, 'a');
