std::map<std::string, GLuint> myTextures;
void Maze::LoadTexture(std::string name, std::string file, int dim) {
    unsigned char *buffer;
    unsigned char *buffer2;
    int width, height;
    long i, j;
    long k, h;

    ReadJPEG(file.c_str(), &buffer, &width, &height);

    buffer2 = (unsigned char *) malloc(dim * dim * 3);

    // The texture pattern is subsampled so that its dimensions become dim x dim 
    for (i=0; i<dim; i++)
        for (j=0; j<dim; j++) {
            k = i * height / dim;
            h = j * width / dim;
            buffer2[3*(i*dim+j)]   = buffer[3*(k*width + h)];
            buffer2[3*(i*dim+j)+1] = buffer[3*(k*width + h) + 1];
            buffer2[3*(i*dim+j)+2] = buffer[3*(k*width + h) + 2];
        }
    
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, dim, dim, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer2);

    myTextures[name] = tex;

    free(buffer);
    free(buffer2);
}
void Maze::draw3D(int w, int h){
   ...
       glEnable(GL_TEXTURE_2D);
       glBindTexture(GL_TEXTURE_2D, myTextures["Groundplant64x64.jpg"]);
       glBegin(GL_QUADS);
       glTexCoord2f(-4.0,0.0); glVertex3i((numberColumn*widthRatio)-(WIDTH/2),DEPTH,(numberRow*heightRatio)-(HEIGHT/2));
       glTexCoord2f(4.0,0.0); glVertex3i((numberColumn*widthRatio)-(WIDTH/2),DEPTH,(numberRow+1)*heightRatio-(HEIGHT/2));
       glTexCoord2f(4.0,4.0); glVertex3i((numberColumn+1)*widthRatio-(WIDTH/2),DEPTH,(numberRow+1)*heightRatio-(HEIGHT/2));
       glTexCoord2f(-4.0,4.0); glVertex3i((numberColumn+1)*widthRatio-(WIDTH/2),DEPTH,(numberRow)*heightRatio-(HEIGHT/2));
       glEnd();
   glColor3f(1.0,0.5,0.0); //Orange
   ...
   .
   .
   .
}
int main() {
   ...
   LoadTexture("Groundplant64x64.jpg", "Groundplant64x64.jpg", 64);
   LoadTexture("Flames64x64.jpg", "Flames64x64.jpg", 64);
   LoadTexture("FloorsMedieval64x64.jpg", "FloorsMedieval64x64.jpg", 64);
   ...
   draw3D(window_width, window_height);
   .
   .
   .
}
