GLuint wallTextureID, foodTextureID, passageTextureID;

void Maze::initTextures() {
    wallTextureID = loadAndBindTexture("wall_texture.jpg");
    foodTextureID = loadAndBindTexture("food_texture.jpg");
    passageTextureID = loadAndBindTexture("passage_texture.jpg");
}

GLuint Maze::loadAndBindTexture(const char *filename) {
    unsigned char *image;
    int width, height;
    
    ReadJPEG(filename, &image, &width, &height);
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    
    free(image); // Don't forget to free the memory!
    
    return textureID;
}
void Maze::draw3D(int w, int h){
    // ... other initialization code ...
    
    for (numberRow = 0; numberRow < rows; numberRow++) {
        for (numberColumn = 0; numberColumn < columns; numberColumn++) {
            // ... draw other parts of the maze ...

            if (map[numberRow][numberColumn] == WALL) {
                // Bind wall texture.
                glBindTexture(GL_TEXTURE_2D, wallTextureID);
                // ... draw wall ...

            } else if (map[numberRow][numberColumn] == FOOD) {
                // Bind food texture.
                glBindTexture(GL_TEXTURE_2D, foodTextureID);
                // ... draw food ...

            } else if (map[numberRow][numberColumn] == PASSAGE) {
                // Bind passage texture.
                glBindTexture(GL_TEXTURE_2D, passageTextureID);
                // ... draw passage ...
            }
        }
    }
}
