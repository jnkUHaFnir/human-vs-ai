    Expression::~Expression() {
        while(meanings_ctr-- > 0){
    //       if(meanings[meanings_ctr]) delete [] (meanings[meanings_ctr]);
        }
        cout << "[debug] to deallocate @" << hex << meanings << dec << endl;
    //   delete [] meanings; // Deleting the memory we allocated
    //    delete [] word_with_several_meanings; // Deleting the memory we allocated
    }