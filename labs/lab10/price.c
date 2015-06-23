#include <stdio.h>
#include <stdlib.h>

struct item{
        int bcode;
        int pcode;
        float length;
        float width;
        int sheets;
        int scode;
        float price;
        float uprice;
};

void bsort(struct item a[], int n);


int main(){

        FILE *fp;
        struct item* list;
        fp = fopen("price.in", "r");
        if(fp == NULL){
                printf("Can't open this file...\n");
                exit(1);
        }
        //struct item* list;
        int n;
        fscanf(fp, "%d", &n);
        list = (struct item*)malloc(n*sizeof(struct item));
        int i;
        for(i = 0; i<n; i++){
                fscanf(fp, "%d %d %f %f %d %d %f", &list[i].bcode, &list[i].pcode, &list[i].length, &list[i].width, &list[i].sheets, &list[i].scode, &list[i].price);
                list[i].uprice = list[i].price/(list[i].length*list[i].width*list[i].sheets);
        }
        fclose(fp);

        char *brands[] = {"", "Kleenex", "Charmin", "Delsey", "Generic"};
        char *product[] = {"", "Tissue", "TP"};
        char *store[] = {"", "Shaw's", "Walmart", "BJ's", "Mom's"};
        bsort(list, n);

        //Loop through the array list and print out the best buys in order
        int c;
        for(c=0;c<n;c++){
                printf("%s %s at %s: %f\n", brands[list[c].bcode], product[list[c].pcode], store[list[c].scode], list[c].uprice);
        }
}
void bsort(struct item a[], int n)
{
  int i, j;
  struct item temp;

  for (i = 0 ; i < n-1; i++)
  {
    for (j = 0 ; j < n-i-1; j++)
    {
      if (a[j].uprice > a[j+1].uprice)
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

