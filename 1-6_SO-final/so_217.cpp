    %typemap(freearg) uint8_t * {
    	//cout << "Freeing uint8_t*!!! " << endl;
    	if ($1) free($1);
    }