    Dummies ** loadDummies(int numPointers, int numDummiesPerPointer)
     {
    	 int i;
    	 Dummies **d = {0};
    	 d = malloc(numPointers * sizeof(Dummies *));
    	 if(!d) return NULL;
    	 for(i=0;i<numDummiesPerPointer;i++)
    	 {
    		 p[i] = malloc(80*sizeof(Dummies)); //random size for illustration
    		 if(!p[i]) return NULL;
    	 }
    	 return d;
     }