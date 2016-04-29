#include <rtable.h>

Wset *wset = NULL;

Rtable *createEntry(Rtable *r, char *gradx, int a){
  int i;
  char word[5];
  Rtable *new;
  Alist *aux;
  Wset *auxset;

  for(i=0; i<4; i++) word[i] = gradx[i+4];
  word[4] = '\0';

  if(r == NULL){
    //    printf("First entry\n");
    new = (Rtable*) malloc(sizeof(Rtable));
    new->grad = (char*) malloc(13*sizeof(char));
    for(i=0; i<13; i++) new->grad[i] = gradx[i];
    new->list = (Alist*) malloc(sizeof(Alist));
    new->list->a = a;
    new->list->next = NULL;
    new->next = NULL;
    wset = initSet();
    wset = insertElem(wset, gradx+4); 
  } else {
    //    printf("New entry\n");
    new = r;
    while(r->next != NULL && strcmp(r->grad, gradx)!= 0) r = r->next;
    if(strcmp(r->grad, gradx)== 0){
      //      printf("existing Grad\n");
      aux = (Alist*) malloc(sizeof(Alist));
      aux->a = a;
      aux->next = r->list;
      r->list = aux;
    } else {
      //      printf("New Grad\n");
      r->next = (Rtable*) malloc(sizeof(Rtable));
      r = r->next;
      r->grad = (char*) malloc(13*sizeof(char));
      for(i=0; i<13; i++) r->grad[i] = gradx[i];
      r->list = (Alist*) malloc(sizeof(Alist));
      r->list->a = a;
      r->list->next = NULL;
      r->next = NULL;
    }

    if(!elementExistSet(wset, gradx + 4)) wset = insertElem(wset, gradx+4);
  }
  return new;
}

void printShape(Rtable *shape){
  Alist *aux;
  while(shape != NULL){
    printf("Rtable entry: Grad = %s ", shape->grad);
    aux = shape->list;
    while(aux != NULL){
      printf("| subentry: A = %d\n                                  ", aux->a);
      aux = aux->next;
    }
    printf("\n");
    shape = shape->next;
  }
  printf("Wset: ");
  printSet(wset);
  printf("\n");

  printf("GradientSpace: \n");
  printGradientSpace(wset);
  printf("\n");

}
