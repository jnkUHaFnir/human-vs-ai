    template<class T>
    struct Mallocator11 {
      template<class U> friend struct Mallocator11;
      using value_type = T;
      using pointer = T*;
      using propagate_on_container_copy_assignment = std::true_type;
      using propagate_on_container_move_assignment = std::true_type;
      using propagate_on_container_swap = std::true_type;
      Mallocator11(Mallocator11 const&)=default;
      Mallocator11& operator=(Mallocator11 const&)=default;
      Mallocator11()=default;
      // cross compatible:
      template<class U> Mallocator11(Mallocator11<U> const&){}
      template<class U> Mallocator11& operator=(Mallocator11<U> const&){return *this;}
      pointer allocate(std::size_t n) {
        return static_cast<pointer>(malloc(n * sizeof(T)));
      }
      void deallocate(pointer p, std::size_t n) {
        free(p);
      }
      template<class U> bool operator==(Mallocator11<U> const& rhs) const {
        return true; // stateless and cross-compatible
      }
      template<class U> bool operator!=(Mallocator11<U> const& rhs) const {
        return false;
      }
    };