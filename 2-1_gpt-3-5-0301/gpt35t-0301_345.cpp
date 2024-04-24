LField(int rowNumVal, int colNumVal, int widthVal, const char* valVal = NULL, bool canEditVal = true)
   : val(NULL)
{
   if(valVal != NULL) {
      // create a new buffer and copy the contents
      val = new char[strlen(valVal) + 1];
      strcpy(val, valVal);
   }
}

~LField()
{
   if (val != NULL) {
      delete[] val;
      val = NULL;
   }
}

LField(const LField &clone)
   : val(NULL)
{
   if (clone.val != NULL) {
      // create a new buffer and copy the contents
      val = new char[strlen(clone.val) + 1];
      strcpy(val, clone.val);
   }
   rowNum = clone.rowNum;
   colNum = clone.colNum;
   width = clone.width;
   canEdit = clone.canEdit;
   index = clone.index;
}

LField& operator=(const LField &lfieldobj)
{
   if (this != &lfieldobj) {
      // deallocate the old buffer
      if (val != NULL) {
         delete[] val;
         val = NULL;
      }
      if (lfieldobj.val != NULL) {
         // create a new buffer and copy the contents
         val = new char[strlen(lfieldobj.val) + 1];
         strcpy(val, lfieldobj.val);
      }
      rowNum = lfieldobj.rowNum;
      colNum = lfieldobj.colNum;
      width = lfieldobj.width;
      canEdit = lfieldobj.canEdit;
      index = lfieldobj.index;
   }

   return *this;
}