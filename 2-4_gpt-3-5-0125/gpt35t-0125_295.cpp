// Texture IDs
GLuint wallTexture;
GLuint foodTexture;
GLuint corridorTexture;

void Maze::loadTextures() {
    glGenTextures(1, &wallTexture);
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    LoadTexture("wall_texture.jpg", 64);
    
    glGenTextures(1, &foodTexture);
    glBindTexture(GL_TEXTURE_2D, foodTexture);
    LoadTexture("food_texture.jpg", 64);
    
    glGenTextures(1, &corridorTexture);
    glBindTexture(GL_TEXTURE_2D, corridorTexture);
    LoadTexture("corridor_texture.jpg", 64);
}
void Maze::draw3D(int w, int h) {
    // Draw the maze walls, food, and corridors using the stored textures
    for(numberRow = 0; numberRow < rows; numberRow++) {
        for(numberColumn = 0; numberColumn < columns; numberColumn++) {
            if (!isCenter(numberRow, numberColumn)) {
                if (map[numberRow][numberColumn] == WALL) {
                    glBindTexture(GL_TEXTURE_2D, wallTexture);
                    // Draw wall with texture
                } else if (map[numberRow][numberColumn] == FOOD) {
                    glBindTexture(GL_TEXTURE_2D, foodTexture);
                    // Draw food with texture
                } else if (map[numberRow][numberColumn] == PASSAGE) {
                    glBindTexture(GL_TEXTURE_2D, corridorTexture);
                    // Draw corridor with texture
                }
            }
        }
    }
}
