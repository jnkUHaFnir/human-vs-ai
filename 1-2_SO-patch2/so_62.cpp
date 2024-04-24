    Expression::Expression(int mctr ) {
        meanings_ctr = mctr;    // Setting the counter to 0
        meanings = new char * [meanings_ctr]; // Allocate Space for meanings
        cout << "[debug] allocated " << sizeof(char*)*meanings_ctr << " bytes @" << 
                 hex << meanings << dec << endl;
    }