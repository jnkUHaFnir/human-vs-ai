#include <map>
#include <string>

std::map<std::string, unsigned int> textureMap;

void Maze::preloadTextures() {
    LoadTexture("Groundplant64x64.jpg", 64);
    LoadTexture("Flames64x64.jpg", 64);
    LoadTexture("FloorsMedieval64x64.jpg", 64);
    // Add more textures as needed
}

void Maze::drawTexturedObject(std::string textureName) {
    if (textureMap.find(textureName) == textureMap.end()) {
        // Texture not found, load it
        LoadTexture(textureName.c_str(), 64);
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureMap[textureName]);

    // Draw textured object here

    glDisable(GL_TEXTURE_2D);
}

void Maze::draw3D(int w, int h) {
    // Preload all textures at the beginning
    preloadTextures();

    // Use drawTexturedObject function to draw objects with textures
}
