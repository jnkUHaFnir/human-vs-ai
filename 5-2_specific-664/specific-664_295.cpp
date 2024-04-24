#include <unordered_map>

std::unordered_map<int, GLuint> textureMap; // Maps texture ID to OpenGL texture object
void Maze::LoadTexture(char *filename, int dim, int textureId) {
    // Check if the texture is already loaded
    if (textureMap.find(textureId) != textureMap.end()) {
        glBindTexture(GL_TEXTURE_2D, textureMap[textureId]);
        return;
    }

    unsigned char *buffer;
    unsigned char *buffer2;
    int width, height;

    ReadJPEG(filename, &buffer, &width, &height);

    buffer2 = (unsigned char *)malloc(dim * dim * 3);

    // Subsample the texture
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            int k = i * height / dim;
            int h = j * width / dim;

            buffer2[3 * (i * dim + j)] = buffer[3 * (k * width + h)];
            buffer2[3 * (i * dim + j) + 1] = buffer[3 * (k * width + h) + 1];
            buffer2[3 * (i * dim + j) + 2] = buffer[3 * (k * width + h) + 2];
        }
    }

    GLuint textureObj;
    glGenTextures(1, &textureObj);
    glBindTexture(GL_TEXTURE_2D, textureObj);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dim, dim, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer2);

    textureMap[textureId] = textureObj;

    free(buffer);
    free(buffer2);
}
// Free all loaded textures
for (auto const& [key, val] : textureMap) {
    glDeleteTextures(1, &val);
}
textureMap.clear();
