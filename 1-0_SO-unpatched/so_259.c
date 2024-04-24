    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <ctype.h>
    #include <errno.h>
    #include <limits.h>
    #ifndef TRUE
    enum { FALSE= 0, TRUE = !FALSE };
    #endif
    #define MAX_LINE_LENGTH 80
    
    void strcpy_(char* s, const char* t) {
        while ((*s++ = *t++) != '\0')
            ;
    }
    
    char* strncpy_(char* s, const char* t) {
        s = realloc(s, strlen(t) + 1);
    
        int flag_filler = FALSE;
    
        for (size_t i = 0; i < strlen(t); ++i) {
            if (t[i] == '\n' || t[i] == '\t') {
                flag_filler = TRUE;
            }
            
            if (flag_filler == TRUE) {
                s[i] = '\0';
            } else {
                s[i] = t[i];
            }
        }
    
        return s;
    }
    
    char* strdup_(const char* s) {
        char* str = calloc(strlen(s) + 1, sizeof (char));
    
        if (str == NULL) {
            fprintf(stderr, "[Error] Memory allocation failure\n");
    
            exit(EXIT_FAILURE);
        }
    
        strncpy_(str, s);
    
        return str;
    }
    
    enum position_t {
        POSITION_UNDEFINED,
        POSITION_STRIKER,
        POSITION_MIDFIELDER,
        POSITION_DEFENDER,
        POSITION_GOALKEEPER
    };
    
    const char* position_striker_strings[] = {
        "Striker",
        "striker",
        "False 9",
        "false 9"
    };
    
    const char* position_midfielder_strings[] = {
        "Midfielder",
        "midfielder",
        "Centerback",
        "centerback"
    };
    
    const char* position_defender_strings[] = {
        "Defender",
        "defender",
        "Fullback",
        "fullback"
    };
    
    const char* position_goalkeeper_strings[] = {
        "Goalkeeper",
        "goalkeeper",
        "Goalie",
        "goalie"
    };
    
    int position_read(const char* s) {
        for (size_t i = 0; i < (sizeof (position_striker_strings) / sizeof(const char*)); ++i) {
            if (strcmp(s, position_striker_strings[i]) == 0)
                return POSITION_STRIKER;
        }
    
        for (size_t i = 0; i < (sizeof (position_midfielder_strings) / sizeof(const char*)); ++i) {
            if (strcmp(s, position_midfielder_strings[i]) == 0)
                return POSITION_MIDFIELDER;
        }
    
        for (size_t i = 0; i < (sizeof (position_defender_strings) / sizeof(const char*)); ++i) {
            if (strcmp(s, position_defender_strings[i]) == 0)
                return POSITION_DEFENDER;
        }
    
        for (size_t i = 0; i < (sizeof (position_goalkeeper_strings) / sizeof(const char*)); ++i) {
            if (strcmp(s, position_goalkeeper_strings[i]) == 0)
                return POSITION_GOALKEEPER;
        }
    
        return POSITION_UNDEFINED;
    }
    
    char* position_str(int position) {
        switch (position) {
            case POSITION_STRIKER: {
                return "Striker";
            } break;
    
            case POSITION_MIDFIELDER: {
                return "Midfielder";
            } break;
    
            case POSITION_DEFENDER: {
                return "Defender";
            } break;
    
            case POSITION_GOALKEEPER: {
                return "Goalkeeper";
            } break;
    
            default: {
                return "Unknown Position Code";
            }
        }
    }
    
    struct player_t {
        char* first_name;
        char* last_name;
        int position;
        int year;
    };
    
    struct player_t* player_allocate() {
        struct player_t* player = calloc(1, sizeof(struct player_t));
    
        if (player == NULL) {
            fprintf(stderr, "[Error] Memory allocation failure\n");
    
            exit(EXIT_FAILURE);
        }
    
        return player;
    }
    
    struct player_t* player_new(const char* first_name, const char* last_name, int position, int year) {
        struct player_t* p = player_allocate();
    
        p->first_name = strdup_(first_name);
        p->last_name = strdup_(last_name);
        p->position = position;
        p->year = year;
    
        return p;
    }
    
    void player_print(struct player_t* player) {
        if (player == NULL)
            return;
        
        printf("\t%s, %s\n", player->last_name, player->first_name);
        printf("\t\tPosition: %s\n", position_str(player->position));
        printf("\t\tYear: %d\n", player->year);
    }
    
    void player_list_print(struct player_t** player_list, size_t n) {
        if (player_list == NULL)
            return;
        
        printf("\n\nPlayer List: \n\n");
    
        for (size_t i = 0; i < n; ++i) {
            if (player_list[i] == NULL)
                continue;
            
            player_print(player_list[i]);
        }
    
        printf("\n\n");
    }
    
    void clear_buffer(char* buffer, size_t n) {
        memset(buffer, 0, n * sizeof(char));
    }
    
    int main(void)
    {
        char input_buffer[MAX_LINE_LENGTH];
        clear_buffer(input_buffer, MAX_LINE_LENGTH);
    
        printf("How many players would you like to enter? ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    
        errno = 0;
        char* endptr = NULL;
        long n = strtol(input_buffer, &endptr, 10);
    
        if ((errno == ERANGE && (n == LONG_MAX || n == LONG_MIN)) || (errno != 0 && n == 0)) {
            perror("strtol");
    
            return EXIT_FAILURE;
        }
    
        if (endptr == input_buffer) {
            fprintf(stderr, "No digits were found\n");
    
            return EXIT_FAILURE;
        }
    
        printf("Enter %ld player(s).\n", n);
    
        struct player_t** player_list = calloc(n, sizeof (struct player_t *));
    
        for (size_t i = 0; i < (size_t) n; ++i) {
            player_list[i] = player_allocate();
    
            printf("\nFirst Name: ");
            clear_buffer(input_buffer, MAX_LINE_LENGTH);
            fgets(input_buffer, MAX_LINE_LENGTH, stdin);
            player_list[i]->first_name = strdup_(input_buffer);
    
            printf("Last Name: ");
            clear_buffer(input_buffer, MAX_LINE_LENGTH);
            fgets(input_buffer, MAX_LINE_LENGTH, stdin);
            player_list[i]->last_name = strdup_(input_buffer);
    
            printf("Position: ");
            clear_buffer(input_buffer, MAX_LINE_LENGTH);
            fgets(input_buffer, MAX_LINE_LENGTH, stdin);
            player_list[i]->position = position_read(strdup_(input_buffer));
    
            printf("Year: ");
            clear_buffer(input_buffer, MAX_LINE_LENGTH);
            fgets(input_buffer, MAX_LINE_LENGTH, stdin);
            player_list[i]->year = atoi(input_buffer);
        }
    
        player_list_print(player_list, n);
    
        return EXIT_SUCCESS;
    }