class ClassName {
public:
  // Some public methods and attributes

private:
  // Delete the copy constructor and copy assignment operator
  ClassName(const ClassName&) = delete;
  ClassName& operator=(const ClassName&) = delete;

  // Other private methods and attributes
};
