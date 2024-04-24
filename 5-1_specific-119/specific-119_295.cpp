#include <unordered_map>

class Maze {
private:
    std::unordered_map<std::string, GLuint> textures; // Map to store textures

    // Add this private helper method to load texture into memory
    void LoadTextureToMemory(const std::string& filename, int dim);

public:
    // Modify your public LoadTexture method to utilize texture memory storage
    void LoadTexture(const std::string& filename, int dim);

    // Add a new method to bind a texture by its filename
    void BindTexture(const std::string& filename);
};
void Maze::LoadTextureToMemory(const std::string& filename, int dim) {
    unsigned char *buffer;
    unsigned char *buffer2;
    int width, height;

    ReadJPEG(const_cast<char *>(filename.c_str()), &buffer, &width, &height);

    buffer2 = (unsigned char *)malloc(dim * dim * 3);

    // The texture pattern is subsampled so that its dimensions become dim x dim
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            int k = i * height / dim;
            int h = j * width / dim;

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

    free(buffer);
    free(buffer2);

    textures[filename] = textureID; // Store the texture ID in the map
}

void Maze::LoadTexture(const std::string& filename, int dim) {
    // Check if the texture is already loaded
    if (textures.find(filename) == textures.end()) {
        LoadTextureToMemory(filename, dim); // Load the texture into memory
    }
}

void Maze::BindTexture(const std::string& filename) {
    if (textures.find(filename) != textures.end()) {
        glBindTexture(GL_TEXTURE_2D, textures[filename]); // Bind the texture
    } else {
        std::cerr << "Texture not found: " << filename << std::endl;
    }
}
void Maze::draw3D(int w, int h) {
    // Your existing code

    // Inside the if conditions where you set textures, e.g., LoadTexture("Groundplant64x64.jpg", 64);
    BindTexture("Groundplant64x64.jpg"); // Bind the appropriate texture

    // Your existing code

}
