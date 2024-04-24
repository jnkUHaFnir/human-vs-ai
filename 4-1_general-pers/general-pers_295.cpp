#include <unordered_map>
#include <string>

std::unordered_map<int, GLuint> textureMap; // Mapping from texture ID to texture data
void Maze::LoadTexture(char *filename, int dim, int textureID) {
    if (textureMap.find(textureID) != textureMap.end()) {
        // Texture already loaded, return
        return;
    }

    unsigned char *buffer;
    unsigned char *buffer2;
    int width, height;

    ReadJPEG(filename, &buffer, &width, &height);

    buffer2 = (unsigned char *)malloc(dim*dim*3);

    // Subsample and store the texture in buffer2

    // Store the texture in OpenGL
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dim, dim, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer2);

    // Store the texture ID in the map
    textureMap[textureID] = // Generated texture ID;

    free(buffer);
    free(buffer2);
}
void Maze::draw3D(int w, int h) {
    // Other code...

    if (map[numberRow][numberColumn] == WALL) {
        // Load and use the wall texture
        LoadTexture("WallTexture.jpg", 64, 1); // Assuming 1 is the ID for wall texture
        glBindTexture(GL_TEXTURE_2D, textureMap[1]); // Use the texture
        // Render the wall with the texture
    }
    else if (map[numberRow][numberColumn] == FOOD) {
        // Load and use the food texture
        LoadTexture("FoodTexture.jpg", 64, 2); // Assuming 2 is the ID for food texture
        glBindTexture(GL_TEXTURE_2D, textureMap[2]); // Use the texture
        // Render the food with the texture
    }
    else if (map[numberRow][numberColumn] == PASSAGE) {
        // Load and use the passage texture
        LoadTexture("PassageTexture.jpg", 64, 3); // Assuming 3 is the ID for passage texture
        glBindTexture(GL_TEXTURE_2D, textureMap[3]); // Use the texture
        // Render the passage with the texture
    }

    // Other code...
}
