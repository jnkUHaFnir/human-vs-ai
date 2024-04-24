// Define variables to store loaded textures
GLuint wallTexture;
GLuint foodTexture;
GLuint passageTexture;

// Load textures during initialization
void Maze::initTextures() {
    glGenTextures(1, &wallTexture);
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    LoadTexture("wall.jpg", 64); // Example: replace "wall.jpg" with the actual filename

    glGenTextures(1, &foodTexture);
    glBindTexture(GL_TEXTURE_2D, foodTexture);
    LoadTexture("food.jpg", 64); // Example: replace "food.jpg" with the actual filename

    glGenTextures(1, &passageTexture);
    glBindTexture(GL_TEXTURE_2D, passageTexture);
    LoadTexture("passage.jpg", 64); // Example: replace "passage.jpg" with the actual filename
}

// Use the loaded textures when drawing the maze
void Maze::draw3D(int w, int h) {
    // Other existing code...

    // During initialization, before drawing maze
    initTextures();

    // Other existing code...

    // Use the loaded textures based on the type of cell
    if (map[numberRow][numberColumn] == WALL) {
        glBindTexture(GL_TEXTURE_2D, wallTexture);
        // Draw wall using the loaded wall texture
    } else if (map[numberRow][numberColumn] == FOOD) {
        glBindTexture(GL_TEXTURE_2D, foodTexture);
        // Draw food using the loaded food texture
    } else if (map[numberRow][numberColumn] == PASSAGE) {
        glBindTexture(GL_TEXTURE_2D, passageTexture);
        // Draw passage using the loaded passage texture
    }

    // Other existing code...

    // Ensure to call glDeleteTextures when the program exits to release the texture memory
}
