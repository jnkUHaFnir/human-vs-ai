for(i = 1; i < num_node + 1; i++) {
    fgets(buffer, sizeof(buffer), fl_read); // Read the next line for each node
    
    sscanf(buffer, "%d %d %d %d", &tag, &node[i].x, &node[i].y, &node[i].z);

    printf("--------------\n"); 
    printf("   Node %d   \n", tag); 
    printf("--------------\n"); 
    printf("node[%d].x = %d\n", i, node[i].x); 
    printf("node[%d].y = %d\n", i, node[i].y); 
    printf("node[%d].z = %d\n", i, node[i].z); 
    printf("BUFFER  ::  %s", buffer); 
} 
