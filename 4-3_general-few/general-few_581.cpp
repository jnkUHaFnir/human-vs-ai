class NoCopy {
public:
    NoCopy() {}

private:
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
};
