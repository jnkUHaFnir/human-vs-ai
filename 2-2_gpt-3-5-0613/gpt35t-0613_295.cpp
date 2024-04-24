#include <map>
#include <string>
#include <GL/glut.h>

class TextureManager {
public:
    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    }

    GLuint getTexture(const std::string& filename) {
        if (textureCache.find(filename) == textureCache.end()) {
            // Texture not yet loaded, load it
            textureCache[filename] = loadTexture(filename);
        }

        return textureCache[filename];
    }

private:
    TextureManager() {} // Private constructor to enforce singleton pattern
    TextureManager(TextureManager const&) = delete; // Delete copy constructor
    void operator=(TextureManager const&) = delete; // Delete assignment operator

    std::map<std::string, GLuint> textureCache;

    GLuint loadTexture(const std::string& filename) {
        GLuint textureId;
        // Load texture here and generate texture ID
        // ...

        return textureId;
    }
};
void Maze::draw3D(int w, int h) {
    // ...

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0); // Bind the default texture

    TextureManager& textureManager = TextureManager::getInstance();

    // Textura pared techo
    glBindTexture(GL_TEXTURE_2D, textureManager.getTexture("Groundplant64x64.jpg"));
    // ...

    // Texture for other objects
    glBindTexture(GL_TEXTURE_2D, textureManager.getTexture("Flames64x64.jpg"));
    // ...

    // Disable texture after use
    glDisable(GL_TEXTURE_2D);

    // ...
}
