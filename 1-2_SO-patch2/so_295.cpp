    /*--------------------------------------------------------*/
    /*--------------------------------------------------------*/
    #include <map>
    #include <string>
    GLuint LoadTexture(std::string const filename)
    {
    	GLuint texname = 0;
    	/* this is actually tied to the OpenGL context, so this should
    	* actually be a map GLcontext -> std::string -> texturename */
    	static std::map<std::string, GLuint> loaded_textures;
    	if( loaded_textures.find(filename) != loaded_textures.end() ) {
    		texname = loaded_textures[filename];
    		glBindTexture(GL_TEXTURE_2D, texname);
    		return texname;
    	}
    
    	int width,height;
    	std::vector<uint8_t> image;
    	if( ReadJPEG(filename, &image, &width, &height) ) {
    		std::cerr
    			<< "error reading JPEG"
    			<< std::endl;
    		return 0;
    	}
    
    	glGenTextures(1, &texname);
    	if( !texname ) {
    		std::cerr
    			<< "error generating OpenGL texture name"
    			<< std::endl;
    		return 0;
    	}
    
    	glBindTexture(GL_TEXTURE_2D, texname);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    
    	glTexImage2D(
    		GL_TEXTURE_2D, 0, GL_RGB,
    		width, height, 0,
    		GL_RGB,
    		GL_UNSIGNED_BYTE, buffer );
    
    	loaded_textures[filename] = texname;
    
    	return texname;
    }