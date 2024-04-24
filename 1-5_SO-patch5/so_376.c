    Dummies ** loadDummies(int numPointers, int numDummiesPerPointer)
     {
    	 int i;
    	 Dummies **d = {0};
    	 d = malloc(numPointers * sizeof(Dummies *));//Create Dummies **
    	 if(!d) return NULL;
    	 for(i=0;i<numDummiesPerPointer;i++)
    	 {   //Now create Dummies *
    		 d[i] = malloc(80*sizeof(Dummies)); //random size for illustration
    		 if(!d[i]) return NULL;
    	 }
    	 return d;
     }