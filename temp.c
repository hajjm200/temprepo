struct movie {
    char* title; // A pointer to a string 
    int year;
    char* languages; // ??char languages [5][21]
    float rating;
    struct movie* next; // a pointer to the next movie
};

/*
 * Reads a CSV file and builds a linked list of movie structs.
 * Parameters: 
 *  filename: The name of the file to read
 *  count:    pointer to an integer where the number of movies will be stored
 * Returns: Pointer to the head of the linked list of movies
 */
struct movie* processFile(char* filename, int* count) {
    // Open the specified file for reading only
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    fgets(line, sizeof(line), file); // Skip header line

    struct movie* head = NULL;
    struct movie* tail = NULL;
    *count = 0;

    while (fgets(line, sizeof(line), file)) {
        struct movie* newNode = malloc(sizeof(struct movie));

        // Tokenize the line
        char* saveptr;
        char* token = strtok_r(line, ",", &saveptr);
        newNode->title = strdup(token);

        token = strtok_r(NULL, ",", &saveptr);
        newNode->year = atoi(token);

        token = strtok_r(NULL, ",", &saveptr);
        newNode->languages = strdup(token);

        token = strtok_r(NULL, ",", &saveptr);
        newNode->rating = strtof(token, NULL);

        newNode->next = NULL;

        // Append to the linked list
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        (*count)++;
    }

    fclose(file);
    return head;
}

int main()
{
    
}
