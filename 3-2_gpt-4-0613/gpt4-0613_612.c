while (fscanf(corolla, "%lf %lf", &age, &avgprice) == 2) {
    printf("%.1f \t\t $%.2f\n", age, avgprice); //prints data from file
}
