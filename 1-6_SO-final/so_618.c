       char inputPlate[LINE_SIZE];
       int mileage;
       int n = -1;
       sscanf(fileOutput, "%s%d %n", inputPlate, &mileage, &n);
       // Was `n` set? Was the entire line scanned?
       if (n >= 0 || fileOutput[n] != '\0') {
         Handle_Bad_input();
         break;
       } else {
         car = initializeCar(mileage, dateNULL, inputPlate);
         avail->next = addList(avail->next,car,0);
       }
    }
    