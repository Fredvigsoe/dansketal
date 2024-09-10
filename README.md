# Dansketal Aflevering

[Link til opgavebeskrivelse](https://petlatkea.notion.site/dansketal-c-62af565a80094b658dee90a82bab83b7)

Testet på Mac(ARM64)

## Hvordan virker det?

Du vælger i menuen om du vil have printet nogle predefinerede eksempler på konvertering af tal til tekst, eller om du selv vil indtaste et heltal. (kommatal virker IKKE)

## Eksempel
```
--------------------------------------------------------------------------------------
Danske-tal Converter, få printet nogle eksempler af tal som tekst eller vælg dine egne
--------------------------------------------------------------------------------------
1. Tilfældige tal
2. Vælg dine egne
Q. Afslut
Vælg en mulighed ved hjælp af 1, 2 eller Q: 2

Du har valgt: Vælg dine egne tal
Indtast et heltal (positiv eller negativ): 50
50 -> halvtreds
```


## Compile & kør programmet

For at kompilere og køre programmet, brug følgende kommando i terminalen:

```bash
gcc demo.c dansketal.c -o dansketal_demo
./dansketal_demo
