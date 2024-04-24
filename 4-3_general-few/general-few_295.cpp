#include <unordered_map>

std::unordered_map<std::string, GLuint> textures; // Use a map to store textures with filenames
void Maze::loadTextures() {
    LoadTexture("Groundplant64x64.jpg", 64, "Ground");
    LoadTexture("Flames64x64.jpg", 64, "Flames");
    LoadTexture("FloorsMedieval64x64.jpg", 64, "Floors");
}
void Maze::LoadTexture(const char *filename, int dim, const std::string& textureName) {
    // Load texture as before

    // Store the texture in the map
    textures[textureName] = textureID;
}
void Maze::draw3D(int w, int h) {
    // Your rendering logic here
    // Instead of calling LoadTexture every time, use the textures from the map
    glBindTexture(GL_TEXTURE_2D, textures["Ground"]);
    // Render ground texture
    // ...

    glBindTexture(GL_TEXTURE_2D, textures["Flames"]);
    // Render flames texture
    // ...

    glBindTexture(GL_TEXTURE_2D, textures["Floors"]);
    // Render floors texture
    // ...
}
