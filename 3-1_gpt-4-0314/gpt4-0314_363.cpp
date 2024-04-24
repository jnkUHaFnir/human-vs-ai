ClassName (const ClassName & other);
ClassName & operator= (const ClassName & other);
class ClassName {
  ...
  ClassName(const ClassName&) = delete; // delete copy constructor
  ClassName& operator=(const ClassName&) = delete; // delete copy assignment operator
  ...
};
