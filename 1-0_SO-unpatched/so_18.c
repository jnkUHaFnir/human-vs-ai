    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    
    static const int cols = 16;
    static const int rows = 8;
    
    
    void format_line(char *out_text, char line[], int col)
    {
        int nspaces;
    
        // Back off the last space if there is one
        //
        if ( line[col-1] == ' ' )
            col -= 1;
    
        line[col] = '\0';
    
        // Center the text to the output buffer
        //
        nspaces = cols - col;
    
        memset(out_text, ' ', nspaces/2);
        out_text += nspaces/2;
    
        *out_text = '\0';
    
        strcat(out_text, line);
        out_text += strlen(line);
    
        memset(out_text, ' ', nspaces - nspaces/2);
        out_text += nspaces - nspaces/2;
    
        *out_text = '\0';
    }
    
    
    char *align_text(char *text)
    {
        int col, row;
        char *fit_text, *ret_text;
        char *np;
        char line[cols+1];
        char *ptext;
    
        // Copy the input text so we don't destroy the original w/strtok
        ptext = malloc(strlen(text) + 1);
        strcpy(ptext, text);
    
        // Create the buffer for the output text
        ret_text = fit_text = malloc(cols * rows + 1);
    
        // Initialize the working line/row
        line[col = 0] = '\0';
        row = 0;
    
        // Parse each string in the input text with space as delimeter
        //
        for (np = strtok(ptext, " "); (np != NULL) && (row < rows); np = strtok(NULL, " "))
        {
            // If the next string fits on the current line
            //   then we'll put it there
            //
            if ((col + strlen(np)) < cols)
            {
                col += strlen(np);
                strcat(line, np);
    
                // Append a space delimeter if there's room
                //
                if (col < cols)
                    line[col++] = ' ';
    
                line[col] = '\0';
    
                // If we hit the end of the line, copy it to the output text
                // buffer and reset the to the beginning of the working line
                //
                if (col == cols)
                {
                    memcpy(fit_text, line, col);
                    fit_text += cols;
                    line[col = 0] = '\0';
                    row += 1;
                }
            }
            else  // The next string doesn't fit on the current line
            {
                // If there is text on the current line, then
                //    space pad it, append it to the output (centered), and reset working line
                //
                if ( col > 0 )
                {
                    format_line(fit_text, line, col);
                    fit_text += cols;
                }
    
                // If the current string is longer than a line, then
                // copy over the long chunks
                //
                while ( strlen(np) >= cols )
                {
                    memcpy(fit_text, np, cols);
                    fit_text += cols;
                    np += cols;
                    row += 1;
                }
    
                // Copy the rest of the current string to the fresh working line
                //
                strcpy(line, np);
                col = strlen(np);
                line[col++] = ' ';
                line[col] = '\0';
                row += 1;
            }
        }
    
        // Copy over and center the last one
        //
        if ( (col > 0) && (row < rows) )
        {
            format_line(fit_text, line, col);
            fit_text += cols;
        }
    
        *fit_text = '\0';
    
        return ret_text;
    }
    
    int main(int argc, char *argv[])
    {
        if ( argc > 1 )
        {
            printf("%s\n", align_text(argv[1]));
            printf("0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF\n");
        }
    
        return 0;
    }