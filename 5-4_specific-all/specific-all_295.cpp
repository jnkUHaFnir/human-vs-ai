#include <unordered_map>

// Define a data structure to store textures
std::unordered_map<int, unsigned int> textureMap;

void Maze::loadAllTextures() {
    // Load and store all textures in memory
    unsigned int textureID;
    glGenTextures(1, &textureID);

    // Load wall texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    LoadTexture("wall.jpg", 64);
    textureMap[WALL] = textureID;

    // Load food texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    LoadTexture("food.jpg", 64);
    textureMap[FOOD] = textureID;

    // Load passage texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    LoadTexture("passage.jpg", 64);
    textureMap[PASSAGE] = textureID;
}

void Maze::draw3D(int w, int h) {
    // Your existing code...

    // Use stored textures for rendering
    for (numberRow = 0; numberRow < rows; numberRow++) {
        for (numberColumn = 0; numberColumn < columns; numberColumn++) {
            // Check maze element and use corresponding texture
            if (!isCenter(numberRow, numberColumn)) {
                if (map[numberRow][numberColumn] == WALL) {
                    glBindTexture(GL_TEXTURE_2D, textureMap[WALL]);
                    // Render wall using texture
                } else if (map[numberRow][numberColumn] == FOOD) {
                    glBindTexture(GL_TEXTURE_2D, textureMap[FOOD]);
                    // Render food using texture
                } else if (map[numberRow][numberColumn] == PASSAGE) {
                    glBindTexture(GL_TEXTURE_2D, textureMap[PASSAGE]);
                    // Render passage using texture
                }
            }
        }
    }

    // Your existing code...
}

void Maze::init(int w, int h) {
    loadAllTextures();
    // Other initialization code
}
