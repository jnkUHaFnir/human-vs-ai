        ~person()
        {
            delete[] name;   // easy to forget the square brackets
        }
    };