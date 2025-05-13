#include <stdio.h>
#include <string.h>          
#include "pico/stdlib.h"

#include "connect_wifi.h"
#include "server.h"
#include "init_config.h"
#include "global_manage.h"

int main()
{
    stdio_init_all();
    
    display_init(get_ssd_pointer());
    buzzer_init();
    init_pins();

    int result = connect_wifi();
    if (result) return -1;

    result = server_init();
    if (result) return -1;
    
    return 0;
}