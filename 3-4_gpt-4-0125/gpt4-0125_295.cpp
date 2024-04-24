#include <unordered_map>
#include <string>

class TextureManager {
public:
    GLuint LoadTexture(const char* filename);
    GLuint GetTexture(const char* filename);
private:
    std::unordered_map<std::string, GLuint> textures;
    GLuint ReadAndCreateTexture(const char* filename);
};
GLuint TextureManager::LoadTexture(const char* filename) {
    auto it = textures.find(filename);
    if(it == textures.end()) {
        // Texture not loaded yet.
        GLuint textureID = ReadAndCreateTexture(filename);
        textures[filename] = textureID;
        return textureID;
    }
    return it->second;
}

GLuint TextureManager::GetTexture(const char* filename) {
    return LoadTexture(filename);
}

GLuint TextureManager::ReadAndCreateTexture(const char* filename) {
    // Your existing code to read JPEG and create a texture.
    // Make sure this function returns the generated texture ID.
}
// When initializing or needing a texture:
GLuint textureID = textureManager.GetTexture("someTexture.jpg");

// Then, use 'textureID' with glBindTexture(GL_TEXTURE_2D, textureID) before drawing.
