template <typename T>
Message(MessageID messageId, T&& src)
    : Message(sizeof(T), messageId)
{
    // we know m_data points to a large enough buffer
    new (m_data) T(std::forward<T>(src)); // Direct construction in-place
}
``` 

With this change, copy elision will occur and no temporary object will be created when constructing the `Message` object with `Message outgoing(MessageID::WorldPeace, MyStruct(wpArg1, wpArg2, wpArg3));`.

By applying this modification, the `Message` constructor can now directly construct `T` in-place without the need for an intermediate temporary object, facilitating better efficiency and cleaner code.
