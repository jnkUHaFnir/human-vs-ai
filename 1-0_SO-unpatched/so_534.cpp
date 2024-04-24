    int *seriealizeNode(Node node) {
        //allocate buffer array
        int *s = new int[node.neighbors.size() + 1];
        //set the first element = Node.id
        s[0] = node.id;
        //set the rest elements to be the vector elements
        for (int i = 0; i < node.neighbors.size(); ++i) {
            s[i + 1] = node.neighbors[i];
        }
        return s;
    }
    
    Node deseriealizeNode(int buffer[], int size) {
        Node node;
        //get the Node.id
        node.id = buffer[0];
        //get the vector elements
        for (int i = 1; i < size; ++i) {
            node.neighbors.push_back(buffer[i]);
        }
        return node;
    }