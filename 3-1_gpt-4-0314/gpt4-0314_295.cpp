GLuint wallTexture;
GLuint foodTexture;
GLuint passageTexture;
void Maze::initializeTextures() {
    glGenTextures(1, &wallTexture);
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    LoadTexture("Groundplant64x64.jpg", 64);

    glGenTextures(1, &foodTexture);
    glBindTexture(GL_TEXTURE_2D, foodTexture);
    LoadTexture("Flames64x64.jpg", 64);

    glGenTextures(1, &passageTexture);
    glBindTexture(GL_TEXTURE_2D, passageTexture);
    LoadTexture("FloorsMedieval64x64.jpg", 64);
}
// In the wall drawing section
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, wallTexture);
// ... rest of the code to draw the wall with texture coordinates
glDisable(GL_TEXTURE_2D);
// In the food drawing section
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, foodTexture);
// ... rest of the code to draw the food with texture coordinates
glDisable(GL_TEXTURE_2D);
// In the passage drawing section
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, passageTexture);
// ... rest of the code to draw the passage with texture coordinates
glDisable(GL_TEXTURE_2D);
