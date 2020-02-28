typedef struct MEM {

    char *var;
    char *value;
} MEM;


extern MEM memory_vars[];
void init_Null(MEM *variables);
int exists(char *str);

