#include <unordered_map>

std::unordered_map<std::string, GLuint> textureMap;
void Maze::LoadTexture(char *filename, int dim, std::string textureName) {
    unsigned char *buffer;
    unsigned char *buffer2;
    int width, height;
    long i, j;
    long k, h;

    ReadJPEG(filename, &buffer, &width, &height);

    buffer2 = (unsigned char *)malloc(dim * dim * 3);

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            k = i * height / dim;
            h = j * width / dim;

            buffer2[3 * (i * dim + j)] = buffer[3 * (k * width + h)];
            buffer2[3 * (i * dim + j) + 1] = buffer[3 * (k * width + h) + 1];
            buffer2[3 * (i * dim + j) + 2] = buffer[3 * (k * width + h) + 2];
        }
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dim, dim, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer2);

    textureMap[textureName] = textureID;

    free(buffer);
    free(buffer2);
}
void Maze::preloadTextures() {
    LoadTexture("Groundplant64x64.jpg", 64, "groundTexture");
    LoadTexture("Flames64x64.jpg", 64, "foodTexture");
    LoadTexture("FloorsMedieval64x64.jpg", 64, "passageTexture");
}
void Maze::draw3D(int w, int h) {
    // Your existing code here...

    // Example usage of textures from textureMap
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureMap["groundTexture"]);
    // Render the ground texture

    glBindTexture(GL_TEXTURE_2D, textureMap["foodTexture"]);
    // Render the food texture

    glBindTexture(GL_TEXTURE_2D, textureMap["passageTexture"]);
    // Render the passage texture

    glDisable(GL_TEXTURE_2D);

    // Your existing code here...
}
