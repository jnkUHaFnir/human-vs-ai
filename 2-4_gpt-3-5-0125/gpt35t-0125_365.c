char fav_nums[5];
// fav_nums = [0] [1] [2] [3] [4]
//             -   -   -   -   -
scanf("%d", &fav_nums[i]);
fav_nums[4] = '\0';
// fav_nums = [0] [1] [2] [3] [4]
//             2   3   6   7   \0
printf(" %d", fav_nums[i]);
