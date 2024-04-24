memset(serv_data, 0, sizeof(serv_data));
int main()
{
    memset(serv_data, 0, sizeof(serv_data)); // Initialize serv_data array
    service_data_func(text);
    printf("%d\n",serv_data[0].charge_arr[0].from);
    return 0;
}
