typedef void (*fn_ptr)();

void call_many(fn_ptr fns[], int count) {
  // manually unroll the loop
  if (count > 0) fns[0]();
  if (count > 1) fns[1]();
  if (count > 2) fns[2]();
  // ... and so on ...
}
template<int N>
class CallF {
public:
  template<typename F>
  static void callF(F f) {
    f();
    CallF<N - 1>::callF(f);
  }
};

template<>
class CallF<0> {
public:
   template<typename F>
   static void callF(F f) {}
};

// Usage
CallF<10>::callF([](){ std::cout << "Hello\n"; });
