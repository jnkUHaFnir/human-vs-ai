    #include <stdio.h>
    #include <string.h>
    #include <sys/mman.h>
    #include <unistd.h>
    
    #define __PMAX__ 500
    
    typedef struct __membin__ __membin__;
    int freebin(__membin__ * bin);
    void * _requestMem( size_t size );
    void * __requestMem( size_t size );
    void * ___requestMem( size_t size );
    
    /* Memory Bin is membin */
    __membin__ membin;
    /*
     * Use requestMem to request memory from membin.
     * Read the comments from main() to understand more 
     * about requestMem.
     * 
     **/
    void * (*requestMem)(size_t) = &_requestMem;
    
    /* 
     * Struct for memory bin
     */
    typedef struct __membin__ {
        void * mempage;
        intptr_t from;               /* <- memory page from: inclusive */
        intptr_t to;                 /* <- memory page to: inclusive */
    
        intptr_t pointer[__PMAX__];  /* <- Pointers */
        intptr_t pTo[__PMAX__];      /* <- Address to for pointer: inclusive */    
        size_t pUsed;                /* <- Pointer used */
        
        size_t size;                 /* <- Actual size */
        size_t sUsed;                /* <- Size Used */
    } __membin__;
    
    /* Free the memory bin */
    int freebin(__membin__ * bin){
        int code = munmap(bin->mempage, bin->size);
        if ( code == 0 ){
            bin->size = 0;
        }
        return code;
    }
    
    /* 
     * This function initialize the memory bin.
     * This function use mmap to allocate a large memory block with the 
     * size of sysconf(_SC_PAGESIZE) * 20. That memory block is converted
     * to a void pointer then assigned to membin->mempage.
     * 
     * Initial size of membin can be configured to be larger.
     **/
    int membinInit(__membin__ * bin){
        size_t initSize = sysconf(_SC_PAGESIZE) * 20;
        bin->mempage = (void *)mmap(NULL, initSize, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE,-1,0);
    
        if (bin->mempage == MAP_FAILED) return 1;  
      
        bin->from = (intptr_t) bin->mempage;
        bin->to = bin->from + (intptr_t) initSize - 1;
      
        bin->pUsed = 0;
        bin->size = initSize;
        bin->sUsed = 0;
        
        return 0;
    }
    
    /*
     * On first run, requestMem is assigned to this function _requestMem.
     * After this function initialize the memory bin successfully it will 
     * assign requestMem to be a pointer of function __requestMem. 
     * 
     * On unsuccessful case of membin initialization, requestMem will be a 
     * pointer to the ___requestMem function that always return null.
     *
     */ 
    void * _requestMem( size_t size ){
        int code = membinInit(&membin);
        if ( code == 1 ) {
            requestMem = &___requestMem;
            return NULL;
        } 
    
        requestMem = &__requestMem;
        return __requestMem(size);
    }
    
    /*
     * __requestMem is a function that will get a block of memory from the
     * unused portion of memory of membin->mempage. 
     * 
     * If the requested size is larger than what available in membin then 
     * NULL will be returned. 
     * 
     * If the requested size is 0 then a value NULL will also be returned.
     */
    void * __requestMem( size_t size ){
        size_t new_sUsed = size + membin.sUsed;
        if ( size == 0 
             || new_sUsed > membin.size 
             || membin.pUsed >= __PMAX__ ) return NULL;
        
        intptr_t p = membin.from + membin.sUsed;
        
        membin.pointer[membin.pUsed] = p;
        membin.pTo[membin.pUsed] = p + size - 1;
        membin.pUsed++;
        
        membin.sUsed = new_sUsed;
        
        return (void * ) p;
    }
    
    /*
     * This function will always return NULL.
     * This function name can be changed to NULL returned function.
     */
    void * ___requestMem( size_t size ){
        return NULL;
    }
    
    typedef struct {
        char * content; // Address of the text in the file
        char * name;    // Filename
        size_t size;    // Included from stddef.h - set by the function
    } file;
    
    typedef struct {
        file * files[256]; // The files in the directory
        char * name;       // The directory name
        size_t index;      // The index of the next file - basically the length of the files array - starts at 0
    } dir;
    
    void new_file(dir* folder, char* name, char* content);
    void add_file(dir* folder, file * f);
    char* read2(dir* folder, char* name);
    file * find_file(dir * folder, char * name);
    
    void new_file(dir* folder, char * name, char * content){ 
        // Folder is a dir * so we can modify the actual struct, not a copy   
        /*
         * Using requestMem to request a block of memory from membin for f.
         *
         **/
        file * f = (file * ) requestMem(sizeof(file));
        f->name = name;
        f->content = content;
        folder->files[folder->index] = f;
        folder->index++;
    }
    
    void add_file(dir* folder, file * f) {
        folder->files[folder->index] = f;
        folder->index++;
    }
    
    char * read2(dir * folder, char* name) {
        file * f = find_file(folder, name);
        if ( f != NULL ) return f->content;
        else return NULL;
    }
    
    file * find_file(dir * folder, char * name) {
        for (size_t i = 0; i < folder->index; i++) {
            if (strcmp(folder->files[i]->name, name) == 0 ) {
                return folder->files[i];
            }
        }
        
        return NULL;
    }
    
    int main(void) {
        
        /* Testing membin */
        char * s = requestMem( sizeof(char) * 15 );
        char * s2 = requestMem( sizeof(char) * 24 );
    
        /* Check for membin size */
        printf("membin size : %zu bytes \n\n", membin.size);
        /* checking if the pointer address of s is equal to the pointer of
         * membin.pointer[0]. They should be equal.
         * 
         * membin.pTo[0] should be the last memory address for s. Of which should
         * be s' address + s' size - 1.
         */
        printf("pointer s: %lld, membin.pointer[0]: %lld, membin.pTo[0]: %lld \n\n", (long long)s,(long long) membin.pointer[0], (long long)membin.pTo[0]);
        /* checking if the pointer address of s2 is equal to the pointer of
         * membin.pointer[1]. They should be equal. Also s2 pointer 
         * should be the value of membin.pTo[0] + 1.
         * 
         * membin.pTo[1] should be the last memory address for s2. Of which should
         * be s2's address + s2's size - 1.
         */
        printf("pointer s2: %lld, membin.pointer[1]: %lld, membin.pTo[1]: %lld \n\n", (long long)s2, (long long)membin.pointer[1], (long long)membin.pTo[1]);
        /* 
         * If requestMem worked correctly, when membin is not yet initialized
         * requestMem will have same address of _requestMem.
         * 
         * If after first run sucessful and membin is initialized requestMem
         * will have the same address as __requestMem.
         * 
         * If initialize of membin fail, requestMem will have the
         * same address as ___requestMem.
         */
        printf("requestMem:    %p\
              \n_requestMem:   %p\
              \n__requestMem:  %p\
              \n___requestMem: %p\
              \n\n", requestMem, _requestMem, __requestMem, ___requestMem);
    
        /* File Testing */
        dir root;
        root.name = "root";
        root.index = 0;
        
        new_file(&root, "Hi", "I am the content.");
        
        file * foundFile = find_file(&root,"Hi");
        if ( foundFile != NULL ){
          printf("Found the file:\n");
          printf("Name: %s\n", foundFile->name);
          printf("Content: %s\n\n", foundFile->content);
        }
        /* End File Testing*/
        
    
        /* Add all the sizes together to see if the size used in membin is right.*/
        printf("Size of struct file: %zu bytes\n", sizeof(file));    
        printf("membin sUsed: %zu bytes\n", membin.sUsed);
    
        /* 
         * Only free bin when everything is finished, because this code is an example, 
         * it did not contain a reinitialize code.
         */
        freebin( &membin );
        /* membin size should be a value of after using freebin */
        printf("membin size after freed: %zu", membin.size);
        
        return 0;
    }