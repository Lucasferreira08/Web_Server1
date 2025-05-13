#include <stdio.h>             // Biblioteca padrão de entrada/saída (ex: printf)
#include <string.h>            // Biblioteca para manipulação de strings
#include "pico/stdlib.h"       // Biblioteca do SDK do Raspberry Pi Pico (funções básicas de I/O, delays, etc.)

// Inclusão de arquivos de cabeçalho específicos do projeto
#include "connect_wifi.h"      // Contém a função para conectar-se a uma rede Wi-Fi
#include "server.h"            // Contém funções relacionadas à inicialização de um servidor (provavelmente HTTP ou socket)
#include "init_config.h"       // Contém funções para inicializar periféricos e configurações gerais
#include "global_manage.h"     // Pode conter variáveis globais e funções auxiliares compartilhadas

// buzzer.c arquivo com funções para controle do buzzer
// connect_wifi.c arquivo com funções para conexão wi-fi
// global_manage.c arquivo com funções para controle das varáveis globais
// init_config.c arquivo com funções para inicialização dos periférico
// server.c arquivo com funções relativas ao web_server
// ssd1306.c arquivo com as funções de controle de display

int main()
{
    // Inicializa todas as interfaces padrão de entrada/saída
    stdio_init_all();
    
    // Inicializa o display (OLED/SSD1306)
    display_init(get_ssd_pointer());
    
    // Inicializa o buzzer
    buzzer_init();

    // Inicializa os pinos GPIO dos leds
    init_pins();

    // Conecta ao Wi-Fi; se falhar, encerra o programa retornando -1
    int result = connect_wifi();
    if (result) return -1;

    // Inicializa o servidor; se falhar, encerra o programa retornando -1
    result = server_init();
    if (result) return -1;
    
    // Se tudo ocorreu bem, retorna 0 (execução bem-sucedida)
    return 0;
}
