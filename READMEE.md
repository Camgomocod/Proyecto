# Proyecto

# Bro mira esta es un procedimiento para imprimir files, para cuando hagas el menu para eso :

void LeerTxt()
{
    FILE *fp = fopen("gaming-economico.txt","r");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    char c;
    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c",c);
        c = fgetc(fp);
    }
    
    fclose(fp);    
}
