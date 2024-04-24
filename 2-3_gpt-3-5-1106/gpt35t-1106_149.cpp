void Expression::add_meaning( char  * p2c)
{

    if (meanings_ctr < 1){
        meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
        strcpy(meanings[ meanings_ctr++ ] , p2c);
    }
    else {
        char **temp_meaning = new char * [meanings_ctr];
        std::copy(meanings, meanings + meanings_ctr, temp_meaning);

        for (int i = 0; i < meanings_ctr; i++) {
            delete[] meanings[i];
        }
        delete[] meanings;

        meanings = new char * [meanings_ctr + 1];
        std::copy(temp_meaning, temp_meaning + meanings_ctr, meanings);
        delete[] temp_meaning;

        meanings[ meanings_ctr ] = new char [strlen(p2c) + 1];
        strcpy(meanings[ meanings_ctr++ ] , p2c);
    }
}
