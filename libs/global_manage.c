#include "global_manage.h"

#include "ssd1306.h"

static Prioridade prioridade;
static Buzzer buzzer;
static ssd1306_t ssd;

void set_prioridade(Prioridade p) 
{
    prioridade=p;
}

Prioridade get_prioridade() 
{
    return prioridade;
}

void ativar_buzzer() 
{
    buzzer=BUZZER_ATIVADO;
}

void desativar_buzzer() 
{
    buzzer=BUZZER_DESATIVADO;
}

Buzzer get_buzzer() 
{
    return buzzer;
}

ssd1306_t *get_ssd_pointer() 
{
    return &ssd;
}